// This Software demo for the Precision Microdrives Haptic Shield is provided
// under the MIT License

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to 
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

// Include system headers
#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#include <EEPROM.h>
#include <SPI.h>

// Debug
#include "debug.h"

// Include our headers

#include "defs.h"
#include "Metro.h"
#include "menu.h"
#include "motor.h"

// Libraries
#include "mpr121.h"
#include "i2c.h"


#define SLIDER_ENABLE 0     // Enable (1) or disable (0) slider function


Menu menu = Menu();
Metro timer = Metro( 100 );

static volatile uint16_t touchstatus, old_touchstatus, keylock;
static volatile long keypresstime;

static uint16_t lock_keys = 0;      // store code of which key is pressed and not released
static uint8_t keys_state_change = 0, current_key_motor;



void setup(){
  
  pinMode( LRA_SEL, OUTPUT ); // Output for LRA  (0 = connected)
  pinMode( ERM_SEL, OUTPUT ); // Output for ERM  (0 = connected)
  pinMode( GRIP_SEL,  OUTPUT ); // Output for GRIP (0 = connected)
  pinMode( SRC_SEL, OUTPUT ); // Output for switching DRV(1) or MOSFET(0)
  pinMode( DRV_2605_EN, OUTPUT ); // Output for ERV2605 ENable
  pinMode( PWM_OUT, OUTPUT ); // Output for PWM
  pinMode( GR_SEL1, OUTPUT ); // Motor select 1
  pinMode( GR_SEL2, OUTPUT ); // Motor select 2
  pinMode( IRQ_PIN, INPUT );

  digitalWrite( LRA_SEL,          HIGH );         // SelectLRA
  digitalWrite( ERM_SEL,          HIGH );         // ERM disconnected
  digitalWrite( GRIP_SEL,         HIGH );         // GRIP disconnected
  digitalWrite( SRC_SEL,          HIGH );         // DRV connected
  digitalWrite( DRV_2605_EN,  LOW );          // Disable the DRV2605 (low power mode)
  digitalWrite( PWM_OUT,    LOW );          // PWM output low for now 
  digitalWrite( GR_SEL1,  LOW );          // select motor 0
  digitalWrite( GR_SEL2,  LOW );          //  
  digitalWrite( IRQ_PIN, HIGH );


  // Setup serial
  Serial.begin( 9600 );

 // #ifdef _DEBUG
  Serial.print(F("FreeMem=") );
  Serial.println( freeRAM() );
 // #endif // _DEBUG
  
	setupTouchPad();

	// Init controllers
	timer.interval( 100 );

	menu.init();
	motor.init( KEY_MOTOR_LRA );
	
	// Ensure all motors are calibrated
	for( uint8_t motorId = 0 ; motorId < 4 ; motorId++ )
	{
		motor.selectMotor( motorId );
	}

	// Start PMD logo animation
	menu.playLogo( &timer );

	// Show first menu page
	menu.displayPage( 0 );
}

//--------------------------------------------------------------------------------------------------------

void loop()
{
   //  updateInput();  // calculate time for long play
     keys_service();  // moved from interrupt controlled by flag key_down_flag 
	   menu.update();
	 
}

//========================================================================================================

void setupTouchPad()
{
	//make sure the interrupt pin is an input and pulled high
	pinMode( IRQ_PIN, INPUT );
	digitalWrite( IRQ_PIN, HIGH );
	
	// only Pull-ups on I2C Bus SDA, SCL don't set it as output
	PORTC = 0b00110000; 
	// initalize I2C bus. Wiring lib not used. 
       
  i2cInit(200);    // f_SCL = 200kHz
       
	timer.reset();                // from metro
	while( 0 == timer.check() );
	while( 0 == timer.check() ); // wait at least 1/10 sec.
	
	// initialize mpr121
	mpr121QuickConfig();
	
  attachInterrupt( 0, keyPressed, FALLING );


} // setupTouchPad

//--------------------------------------------------------------------------------------------------------

void keys_service()
{
   if (keys_state_change){
 
      if( motor.isPlaying() )  return;
      menu.input( keylock );      // if PLAY - play haptics for short
   
      keys_state_change = 0;          // 
   }   
}  

//========================================================================================================

// this is interrupt INT0 triggered always when one or more of keys is released or pressed
// routines output is "keys_state_change" with number of key being pressed
void keyPressed()
{

  static char old_slide_pos;
  char  slide_pos = 0, zeroes = 0;


   touchstatus = mpr121Read( 0x01 ) << 8;   //read MSB
   touchstatus |= mpr121Read( 0x00 );       //read LSB
    
    if( touchstatus & OVCF )
    {
        // Serial.println( F("OVER VOLT. !!!" ));
    		mpr121Write( 0x80, 0x63 ); // Perform soft reset
    		mpr121Write( 0x01, 0x80 ); // clear overcurrent flag
    		mpr121Write( 0x80, 0x63 ); // Perform soft reset
    		mpr121Write( 0x01, 0x80 ); // clear overcurrent flag
    		mpr121Write( 0x80, 0x63 ); // Perform soft reset
    		mpr121Write( 0x01, 0x80 ); // clear overcurrent flag
    		mpr121QuickConfig();       // re-init mpr121
    }


     if (touchstatus){                  //if one or more keys is pressed and no one was pressed
             
              
            if(!keylock){ 
              
               if ((touchstatus & ELE0 ) || (touchstatus & ELE1) || (touchstatus & ELE2 )) { keylock = RIGHT; old_slide_pos = 0;}         // slide is from right to left  //keylock = RIGHT;   //RIGHT KEY
               else if ((touchstatus & ELE3 ) || (touchstatus & ELE4) || (touchstatus & ELE5)) keylock = SELECT;     //SELECT KEY
               else if ((touchstatus & ELE6 ) || (touchstatus & ELE7) || (touchstatus & ELE8)) {keylock = LEFT; old_slide_pos = 10;}       // slide from left to right // keylock = LEFT;   //LEFT KEY
               else   keylock = touchstatus;          // BACK, PLAY or PMD_BUTTON 

               keypresstime = millis();        // time when first  key was pressed
               
              if ((keylock == LEFT) || (keylock == RIGHT)) keys_state_change = 1;// 0; // do not pass input for LEFT and RIGHT ???????
              else keys_state_change = 1;
            
             }else{ //if key wasn't released i.ex. - slider
 
             
                    touchstatus &= 0x01FF;  //clear BACK, PLAY, PMD_BUTTON
               
                    while (touchstatus){        
                       
                       if (!(touchstatus & 0x1)) zeroes++;    //search position on slider ,for last MSB 1      -> 00000111000 pos = 6
                        touchstatus >>= 1;
                        slide_pos++;
                     }
                     slide_pos += zeroes;
                     slide_pos /= 2;
                     
                   #if SLIDER_ENABLE == 1  
                   // if (!(slide_pos % 1)){       
                        if (slide_pos > old_slide_pos ){    //if position changed to the left
                             keys_state_change = 1;
                             keylock = LEFT;            //if slide on left send LEFT event
                        }else if(slide_pos < old_slide_pos ){
                             keys_state_change = 1;
                            keylock = RIGHT;            //if slide on right send RIGHT event
                        }
                    //}
                   #endif 
                    old_slide_pos = slide_pos;         
            }
           
      
         }else if(!touchstatus ){// if all key are released
               keylock = 0;  
         }



  
} // keyPressed


//=========================================================================================================
// for long press if long press take action only for BACK and PMD for long press
void updateInput()
{
} // updateInput


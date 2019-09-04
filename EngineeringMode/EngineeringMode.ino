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


#define SLIDER_ENABLE 0       //Enable (1) or disable (0) slider function

Menu menu = Menu();
Metro timer = Metro( 100 );


static volatile uint16_t touchstatus, keylock;//old_touchstatus, 
static volatile long keypresstime;

static uint16_t lock_keys = 0;      // store code of which key is pressed and not released
static uint8_t keys_state_change = 0, current_key_motor;

void setup()
{
	// Setup pins
  pinMode( LRA_SEL,	OUTPUT );	// Output for LRA  (0 = connected)
	pinMode( ERM_SEL,	OUTPUT );	// Output for ERM  (0 = connected)
	pinMode( GRIP_SEL,	OUTPUT );	// Output for GRIP (0 = connected)
	pinMode( SRC_SEL,	OUTPUT );	// Output for switching DRV(1) or MOSFET(0)
	pinMode( DRV_2605_EN,	OUTPUT );	// Output for ERV2605 ENable
	pinMode( PWM_OUT,	OUTPUT );	// Output for PWM
	pinMode( GR_SEL1,	OUTPUT );	// Motor select 1
	pinMode( GR_SEL2,	OUTPUT );	// Motor select 2

  pinMode( IRQ_PIN, INPUT );



	digitalWrite( LRA_SEL,	        HIGH );	        // SelectLRA
	digitalWrite( ERM_SEL,	        HIGH );	        // ERM disconnected
	digitalWrite( GRIP_SEL,	        HIGH );	        // GRIP disconnected
	digitalWrite( SRC_SEL,	        HIGH );	        // DRV connected
	digitalWrite( DRV_2605_EN,	LOW );	        // Disable the DRV2605 (low power mode)
  digitalWrite( PWM_OUT,		LOW );	        // PWM output low for now 
	

	digitalWrite( GR_SEL1,	LOW );	        // select motor 0
  digitalWrite( GR_SEL2,	LOW );	        //  

  digitalWrite( IRQ_PIN, HIGH );


	// Setup serial
	Serial.begin( 9600 );

	#ifdef _DEBUG
	Serial.print(F("FreeMem=") );
	Serial.println( freeRAM() );
	#endif // _DEBUG
  
	setupTouchPad();

	// Init controllers
	timer.interval( 100 );

	menu.init();

	motor.init( KEY_MOTOR_LRA);

	// Start PMD logo animation
	
  menu.playLogo( &timer );

	// Show first menu page
	menu.displayPage( 0 );
}

void loop()
{
	updateInput();	// calculate time for long play
	keys_service();	// moved from interrupt controlled by flag key_down_flag 
}

void setupTouchPad()
{
	// make sure the interrupt pin is an input and pulled high
	

	// only Pull-ups on I2C Bus SDA, SCL don't set it as output
	PORTC = 0b00110000; 
	
	// initalize I2C bus. Wiring lib not used. 
	i2cInit( 200 );    // f_SCL = 200kHz

	timer.reset();                // from metro
	while( 0 == timer.check() );
	while( 0 == timer.check() ); // wait at least 1/10 sec.

	// initialize mpr121
	mpr121QuickConfig();

	attachInterrupt( 0, keyPressed, FALLING );
} // setupTouchPad

//--------------------------------------------------------------------------------------------

void keys_service()
{
  
  uint8_t playKeyPress;
  
	if( keys_state_change ){        //indicates is key state is changed and need nay action
        
     if( motor.isPlaying() )  return;
     playKeyPress = menu.input( keylock );      // if PLAY - play haptics for short
	  
		if( menu.atPage( PAGE_DEBUG ) && keylock == SELECT )      //if PAGE_DEBUG and press select don't play haptics
		{
			//playKeyPress = 1;
			switch( menu.selectedTab() )
			{
				case 0:	dumpSettings();		break;
				case 1:	motor.resetAutoCal();	break;
				case 2:	printFirmwareInfo();	break;
				default: playKeyPress = 0;	break;
			}
		}


		if( !(menu.atPage( PAGE_DEBUG )) && keylock == PMD_BUTTON )    // change motor
		{
			// Change motor if we're not playing an effect
			if( !motor.isPlaying() )
			{
				motor.selectMotor( (motor.getMotorId()+1 ) % NUM_MOTORS );      // increment and loop when last motor !!! 
				menu.refresh();                                                 // select motor also playing 
			//	playKeyPress = 0; 
			}
		}

            keys_state_change = 0;          // 
	}   
}  

// this is interrupt INT0 triggered always when one or more of keys is released or pressed
void keyPressed()
{

 static char old_slide_pos;
 char  slide_pos = 0, zeroes = 0;
 uint16_t touch_temp;
 static char play_haptic = 0;

long timeNow = millis();
   
	touchstatus = mpr121Read( 0x01 ) << 8;
	touchstatus |= mpr121Read( 0x00 );

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
              
     //    Serial.println(touchstatus);
     //    Serial.println(keylock);
       
            if(!keylock){                   //(0 when released)
              
                     if ((touchstatus & ELE0 ) || (touchstatus & ELE1) || (touchstatus & ELE2 )) { keylock = RIGHT; old_slide_pos = 0;}         // slide is from right to left  //keylock = RIGHT;   //RIGHT KEY
                     else if ((touchstatus & ELE3 ) || (touchstatus & ELE4) || (touchstatus & ELE5)) keylock = SELECT;                          //SELECT KEY
                     else if ((touchstatus & ELE6 ) || (touchstatus & ELE7) || (touchstatus & ELE8)) {keylock = LEFT; old_slide_pos = 10;}       // slide from left to right // keylock = LEFT;   //LEFT KEY
                     else   keylock = touchstatus;          // BACK, PLAY or PMD_BUTTON 

                      play_haptic = 1;
                      keypresstime = millis();        // time when first  key was pressed
                      keys_state_change = 1;        //pass keyservice()
                 
 #if SLIDER_ENABLE == 1          
  
              }else if  (keylock !=  PLAY ) { //if key wasn't released i.ex. - slider (keylock store the number of last pressed and not released button)
              
                    touchstatus &= 0x01FF;  //clear BACK, PLAY, PMD_BUTTON
                                                   
                    while ( touchstatus) {        //search position on slider ,for last MSB 1      -> 00000111000 pos = 6
                       
                       if (!(touchstatus & 0x1)) zeroes++;
                        touchstatus >>= 1;
                        slide_pos++;
                     }
                     slide_pos += zeroes;
                     slide_pos /= 2;

  
                        if (slide_pos > old_slide_pos ){
                             keys_state_change = 1;
                             keylock = LEFT;						//if slide on left send LEFT event
                        }else if(slide_pos < old_slide_pos ){
                             keys_state_change = 1;
                            keylock = RIGHT;						//if slide on right send RIGHT event
                        }
                            if ((timeNow - keypresstime) > 60) 
                            play_haptic = 1;   //if time betwen two keys is shorter don't play Haptic effect
                            
                            keypresstime = millis();        // time when first  key was pressed
                  
                    old_slide_pos = slide_pos;
                    
  #endif
                             
               
               }
          
           
  // if PLAY is pressed when playing - stop playing terminate PlayVibrating Alerts
	// other keys are locked when playing Vibration Alerts

               if( motor.isPlayingVIB() || motor.isPlayingAudio() ){
                
                    keys_state_change = 0;        //don't pass keyservice()          		    
            		
            		    if( keylock & PLAY ){ 
                          motor.playKeyPress( false );	// short press for PLAY BUTTON when playing Vibration Alerts 
            		          motor.stop();					// stop motor and break Vibrating alerts loop
  
            	      }
                }else{
                   
                    if(!( (keylock & PLAY)||(keylock & PMD_BUTTON)||(keylock & SELECT) )&&play_haptic){   // only for slider and select,  for PLAY or PMD _BUTTON Haptic click is generated in menu.info short=0 long=1) 
                                            motor.playKeyPress(0); 
                                            play_haptic = 0;
                    }
               }

        
         }else if(!touchstatus ){// if all key are released
            
             keylock = 0;  
          
        }
           
	

} // keyPressed

//-------------------------------------------------------------------------------------------------------------------------------

void updateInput()
{
	long timeNow = millis();
	static uint8_t play_long_done=0;

	// for long press if long press take action only for BACK and PMD for long press
	// if one of button is pressed take action lock is incremented 

        if( keylock ){      //if key is hold (first key)
        
                if( !play_long_done && IS_LONG_PRESS( timeNow - keypresstime) ){  // > 500ms
                                       
                      if( BACK == keylock  && (!menu.atPage( PAGE_MAINMENU )) )
			{
				// Long press of back back makes us go back to main menu
				//Serial.println( F("BACK long" ));
				menu.displayPage( PAGE_MAINMENU );
	                        motor.playKeyPress( true );        //true for long press

                        }

			if( PMD_BUTTON == keylock && menu.atPage( PAGE_MAINMENU ) )
			{
				// Long press of PMD button at main menu shows debug menu
				//Serial.println( F("PMD long" ));
				menu.displayPage( PAGE_DEBUG );
			        motor.playKeyPress( true );        //true for long press

                        }
			
			play_long_done = 1;  // play long only once time after pressed
              
                }
       
        }else play_long_done = 0;    // if key was unlock ready to check next key // if key_lock

} // updateInput


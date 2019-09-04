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

#include <SPI.h>
#include <mpr121.h>
#include <i2c.h>

// Debug
#include "debug.h"

// Include our headers
#include "Metro.h"
#include "motor.h"

// Init timer for 2s, and auto-reset when we get a positive check
Metro timer( 2000, 1 );
Motor motor = Motor();


void setup()
{
	// Setup serial
	Serial.begin( 9600 );
	Serial.print( F("FreeMem=") );
	Serial.println( freeRAM() );
	
	setupPins();
	i2cInit( 200 );
	
	// Set up the motor
	motor.selectMotor( 6 );
	motor.autoCalibrate();

	// Ensure any time for calibration is ignored.
	timer.reset();

}


void loop()
{
	// Example code - check for some condition
	// N.B. We play an effect every 2 seconds
	uint8_t condition = timer.check();

  
	if( condition )
	{
		// Do an effect
   condition = 0;
		motor.playFullHaptic( 1, 53 );
	}
}

void setupPins()
{
	  pinMode( DRV_2605_EN,       OUTPUT );   // Output for DRV2605 Enable
    pinMode( PWM_OUT,           OUTPUT );   // Output for PWM
    pinMode( SRC_SEL,           OUTPUT );   // HIGH = DRV, LOW = MOS 
    pinMode( GRIP_SEL,	        OUTPUT );   // LOW = Haptic Grip Connected
    pinMode( LRA_SEL,           OUTPUT );   // LOW = Haptic Shield LRA Connected
    pinMode( ERM_SEL,	          OUTPUT );   // LOW = Haptic Shield ERM Connected

    pinMode( MOTOR_PIN_0,       OUTPUT );   // Motor select 1
    pinMode( MOTOR_PIN_1,       OUTPUT );   // Motor select 2
    
    digitalWrite( PWM_OUT,      LOW );      // PWM output low
    digitalWrite( SRC_SEL,      HIGH );     // Select DRV
    digitalWrite( GRIP_SEL,     HIGH  );    // Select none 
    digitalWrite( ERM_SEL,      HIGH  );    // Select none
    digitalWrite( LRA_SEL,      HIGH  );    // Select none 
}	// setupPins

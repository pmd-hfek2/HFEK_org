// This Software is part of the Precision Microdrives Haptic Shield demo and is
// provided under the MIT License

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

#ifndef include_menu_defs_h
#define include_menu_defs_h

#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


// ---
// String table
// ---
//									  "123456789012345678901";

// Titles
const char Menu_String_000[] PROGMEM = "";
const char Menu_String_001[] PROGMEM = "1 Quick-Start Demo";
const char Menu_String_002[] PROGMEM = "2 Haptic Feedback ";
const char Menu_String_003[] PROGMEM = "3 Vib. Alerting   ";
const char Menu_String_004[] PROGMEM = "4 DRV2605 Overview";
// Main menu
// - Quick-Start Demo
const char Menu_String_005[] PROGMEM = "Experience haptic";
const char Menu_String_006[] PROGMEM = "feedback and";
const char Menu_String_007[] PROGMEM = "vibration alerting in";
const char Menu_String_008[] PROGMEM = "1 minute!";
// - Haptic Feedback Tutorial
const char Menu_String_009[] PROGMEM = "An in-depth look at";
const char Menu_String_010[] PROGMEM = "haptic feedback";
const char Menu_String_011[] PROGMEM = "vibrations";
// - Vibration Alerting Tutorial
const char Menu_String_012[] PROGMEM = "An introduction to";
const char Menu_String_013[] PROGMEM = "a simpler alerting";
const char Menu_String_014[] PROGMEM = "alternative";
// - DRV2605 Overview
const char Menu_String_015[] PROGMEM = "Information on the";
const char Menu_String_016[] PROGMEM = "DRV2605 chip used by";
const char Menu_String_017[] PROGMEM = "this kit";
// Navigation
const char Menu_String_018[] PROGMEM = "Use the arrow keys or";

const char Menu_String_019[] PROGMEM = "navigate the tutorial";
const char Menu_String_020[] PROGMEM = " ";

//const char Menu_String_019[] PROGMEM = "swipe the slider to  ";     //for slider
//const char Menu_String_020[] PROGMEM = "navigate the tutorial";     //for slider

const char Menu_String_021[] PROGMEM = " ";
const char Menu_String_022[] PROGMEM = "You will be prompted";
const char Menu_String_023[] PROGMEM = "to press the play";
const char Menu_String_024[] PROGMEM = "button to experience";
const char Menu_String_025[] PROGMEM = "the effects";
const char Menu_String_026[] PROGMEM = "vibration patterns";
// Quick-Start Demo
// N.B: Reusing the first tabs lines from main menu and navigation in the tabs
const char Menu_String_027[] PROGMEM = "Vibration alerting is";
const char Menu_String_028[] PROGMEM = "a simple on/off";
const char Menu_String_029[] PROGMEM = "pattern to alert the";
const char Menu_String_030[] PROGMEM = "user, like a mobile";
const char Menu_String_031[] PROGMEM = "phone ringing";
const char Menu_String_032[] PROGMEM = "Haptic feedback uses";
const char Menu_String_033[] PROGMEM = "advance patterns to";
const char Menu_String_034[] PROGMEM = "convery information";
const char Menu_String_035[] PROGMEM = "to the user...";
const char Menu_String_036[] PROGMEM = "... such as when you";
const char Menu_String_037[] PROGMEM = "press a button on the";
const char Menu_String_038[] PROGMEM = "haptic controller,";
const char Menu_String_039[] PROGMEM = "just like a";
const char Menu_String_040[] PROGMEM = "touchscreen";
const char Menu_String_041[] PROGMEM = "Haptic feedback";
const char Menu_String_042[] PROGMEM = "covers many effects.";
const char Menu_String_043[] PROGMEM = "Try the tutorial for";
const char Menu_String_044[] PROGMEM = "a closer look";
// Haptic Feedback Tutorial
const char Menu_String_045[] PROGMEM = "Haptic feedback uses";
const char Menu_String_046[] PROGMEM = "advanced vibration";
const char Menu_String_047[] PROGMEM = "patterns and drive";
const char Menu_String_048[] PROGMEM = "techniques to convey";
const char Menu_String_049[] PROGMEM = "information to a user";
const char Menu_String_050[] PROGMEM = "For your application,";
const char Menu_String_051[] PROGMEM = "some effects will be";
const char Menu_String_052[] PROGMEM = "more useful than";
const char Menu_String_053[] PROGMEM = "others";
const char Menu_String_054[] PROGMEM = "Such as 'clicks' on a";
const char Menu_String_055[] PROGMEM = "touchscreen...";
const char Menu_String_056[] PROGMEM = "...or even a double";
const char Menu_String_057[] PROGMEM = "or triple click for";
const char Menu_String_058[] PROGMEM = "different";
const char Menu_String_059[] PROGMEM = "confirmations";
const char Menu_String_060[] PROGMEM = "The same haptic";
const char Menu_String_061[] PROGMEM = "effect will feel";
const char Menu_String_062[] PROGMEM = "different depending";
const char Menu_String_063[] PROGMEM = "on the actuator";
const char Menu_String_064[] PROGMEM = "Example: A parking";
const char Menu_String_065[] PROGMEM = "sensor using haptics";
const char Menu_String_066[] PROGMEM = "to alert the driver";
const char Menu_String_067[] PROGMEM = "of object proximity";
const char Menu_String_068[] PROGMEM = "As the car reverses";
const char Menu_String_069[] PROGMEM = "closer, the vibration";
const char Menu_String_070[] PROGMEM = "gets more intense";
const char Menu_String_071[] PROGMEM = "Pulses could be used";
const char Menu_String_072[] PROGMEM = "instead, with a";
const char Menu_String_073[] PROGMEM = "constant vibration";
const char Menu_String_074[] PROGMEM = "signalling imminent";
const char Menu_String_075[] PROGMEM = "contact";
const char Menu_String_076[] PROGMEM = "Download the";
const char Menu_String_077[] PROGMEM = "engineering firmware";
const char Menu_String_078[] PROGMEM = "to test bumps,";
const char Menu_String_079[] PROGMEM = "buzzes, ramps,";
const char Menu_String_080[] PROGMEM = " clicks, and more!";
// Vibration Alerting Tutorial
const char Menu_String_081[] PROGMEM = "Vibration alerting is";
const char Menu_String_082[] PROGMEM = "a simpler alternative";
const char Menu_String_083[] PROGMEM = "to haptic feedback";
const char Menu_String_084[] PROGMEM = "Instead of advanced";
const char Menu_String_085[] PROGMEM = "effects, it is a";
const char Menu_String_086[] PROGMEM = "simple on/off";
const char Menu_String_087[] PROGMEM = "pattern, repeated";
const char Menu_String_088[] PROGMEM = "You can change the";
const char Menu_String_089[] PROGMEM = "wave shape, power, on";
const char Menu_String_090[] PROGMEM = "time, and off time";
const char Menu_String_091[] PROGMEM = "Its simplicity makes";
const char Menu_String_092[] PROGMEM = "it great for";
const char Menu_String_093[] PROGMEM = "emergency warnings";
const char Menu_String_094[] PROGMEM = "Example: Gas safety";
const char Menu_String_095[] PROGMEM = "monitor alerting";
const char Menu_String_096[] PROGMEM = "battery level is";
const char Menu_String_097[] PROGMEM = "low...";
const char Menu_String_098[] PROGMEM = "...and the toxicity";
const char Menu_String_099[] PROGMEM = "level is too high";
const char Menu_String_100[] PROGMEM = "to build your own";// NB: Reuse string 076 and 077 before these
const char Menu_String_101[] PROGMEM = "vibration alerts!";
// DRV2605 Overview
const char Menu_String_102[] PROGMEM = "This kit uses the";
const char Menu_String_103[] PROGMEM = "DRV2065 from Texas";
const char Menu_String_104[] PROGMEM = "Instruments to play";
const char Menu_String_105[] PROGMEM = "123 pre-built haptic";
const char Menu_String_106[] PROGMEM = "effects";
const char Menu_String_107[] PROGMEM = "Overdrive and Active";
const char Menu_String_108[] PROGMEM = "Braking (OD & AB) are";
const char Menu_String_109[] PROGMEM = "drive techniques to";
const char Menu_String_110[] PROGMEM = "start and stop the";
const char Menu_String_111[] PROGMEM = "motor quicker";
const char Menu_String_112[] PROGMEM = "Press play to feel a";
const char Menu_String_113[] PROGMEM = "double click without";
const char Menu_String_114[] PROGMEM = "OD & AB, followed by";
const char Menu_String_115[] PROGMEM = "a double click with";
const char Menu_String_116[] PROGMEM = "OD & AB";
const char Menu_String_117[] PROGMEM = "Auto-Calibration";
const char Menu_String_118[] PROGMEM = "normalises the back-";
const char Menu_String_119[] PROGMEM = "EMF from the ERM/LRA";
const char Menu_String_120[] PROGMEM = "to ensure consistent";
const char Menu_String_121[] PROGMEM = "performance";
const char Menu_String_122[] PROGMEM = "Auto-resonance can";
const char Menu_String_123[] PROGMEM = "solve resonance";
const char Menu_String_124[] PROGMEM = "shift by calibrating";
const char Menu_String_125[] PROGMEM = "to the LRA resonant";
const char Menu_String_126[] PROGMEM = "frequency";
const char Menu_String_127[] PROGMEM = "There are 6 libraries";
const char Menu_String_128[] PROGMEM = "that each contain all";
const char Menu_String_129[] PROGMEM = "of the 123 haptic";
const char Menu_String_130[] PROGMEM = "effects, but play";
const char Menu_String_131[] PROGMEM = "them differently";
const char Menu_String_132[] PROGMEM = "5 libraries work with";
const char Menu_String_133[] PROGMEM = "ERMs, 1 is for LRAs.";
const char Menu_String_134[] PROGMEM = "Different actuators";
const char Menu_String_135[] PROGMEM = "work better with";
const char Menu_String_136[] PROGMEM = "specific libraries";
const char Menu_String_137[] PROGMEM = "Feel the same effect";
const char Menu_String_138[] PROGMEM = "cycled through 5 ERM";
const char Menu_String_139[] PROGMEM = "libraries, all on the";
const char Menu_String_140[] PROGMEM = "same ERM (306-109)";
const char Menu_String_141[] PROGMEM = "You can access the";
const char Menu_String_142[] PROGMEM = "DRV2605 via the I2C";
const char Menu_String_143[] PROGMEM = "bus, and connect";
const char Menu_String_144[] PROGMEM = "external actuators";
const char Menu_String_145[] PROGMEM = "and input signals";
const char Menu_String_146[] PROGMEM = "The full source code";
const char Menu_String_147[] PROGMEM = "and additional";
const char Menu_String_148[] PROGMEM = "tutorials are";
const char Menu_String_149[] PROGMEM = "available at";
const char Menu_String_150[] PROGMEM = "www.pmdri.com/haptics";


const char * const MENU_STRS[] PROGMEM = {
	&Menu_String_000[ 0 ],
	&Menu_String_001[ 0 ],
	&Menu_String_002[ 0 ],
	&Menu_String_003[ 0 ],
	&Menu_String_004[ 0 ],
	&Menu_String_005[ 0 ],
	&Menu_String_006[ 0 ],
	&Menu_String_007[ 0 ],
	&Menu_String_008[ 0 ],
	&Menu_String_009[ 0 ],
	&Menu_String_010[ 0 ],
	&Menu_String_011[ 0 ],
	&Menu_String_012[ 0 ],
	&Menu_String_013[ 0 ],
	&Menu_String_014[ 0 ],
	&Menu_String_015[ 0 ],
	&Menu_String_016[ 0 ],
	&Menu_String_017[ 0 ],
	&Menu_String_018[ 0 ],
	&Menu_String_019[ 0 ],
	&Menu_String_020[ 0 ],
	&Menu_String_021[ 0 ],
	&Menu_String_022[ 0 ],
	&Menu_String_023[ 0 ],
	&Menu_String_024[ 0 ],
	&Menu_String_025[ 0 ],
	&Menu_String_026[ 0 ],
	&Menu_String_027[ 0 ],
	&Menu_String_028[ 0 ],
	&Menu_String_029[ 0 ],
	&Menu_String_030[ 0 ],
	&Menu_String_031[ 0 ],
	&Menu_String_032[ 0 ],
	&Menu_String_033[ 0 ],
	&Menu_String_034[ 0 ],
	&Menu_String_035[ 0 ],
	&Menu_String_036[ 0 ],
	&Menu_String_037[ 0 ],
	&Menu_String_038[ 0 ],
	&Menu_String_039[ 0 ],
	&Menu_String_040[ 0 ],
	&Menu_String_041[ 0 ],
	&Menu_String_042[ 0 ],
	&Menu_String_043[ 0 ],
	&Menu_String_044[ 0 ],
	&Menu_String_045[ 0 ],
	&Menu_String_046[ 0 ],
	&Menu_String_047[ 0 ],
	&Menu_String_048[ 0 ],
	&Menu_String_049[ 0 ],
	&Menu_String_050[ 0 ],
	&Menu_String_051[ 0 ],
	&Menu_String_052[ 0 ],
	&Menu_String_053[ 0 ],
	&Menu_String_054[ 0 ],
	&Menu_String_055[ 0 ],
	&Menu_String_056[ 0 ],
	&Menu_String_057[ 0 ],
	&Menu_String_058[ 0 ],
	&Menu_String_059[ 0 ],
	&Menu_String_060[ 0 ],
	&Menu_String_061[ 0 ],
	&Menu_String_062[ 0 ],
	&Menu_String_063[ 0 ],
	&Menu_String_064[ 0 ],
	&Menu_String_065[ 0 ],
	&Menu_String_066[ 0 ],
	&Menu_String_067[ 0 ],
	&Menu_String_068[ 0 ],
	&Menu_String_069[ 0 ],
	&Menu_String_070[ 0 ],
	&Menu_String_071[ 0 ],
	&Menu_String_072[ 0 ],
	&Menu_String_073[ 0 ],
	&Menu_String_074[ 0 ],
	&Menu_String_075[ 0 ],
	&Menu_String_076[ 0 ],
	&Menu_String_077[ 0 ],
	&Menu_String_078[ 0 ],
	&Menu_String_079[ 0 ],
	&Menu_String_080[ 0 ],
	&Menu_String_081[ 0 ],
	&Menu_String_082[ 0 ],
	&Menu_String_083[ 0 ],
	&Menu_String_084[ 0 ],
	&Menu_String_085[ 0 ],
	&Menu_String_086[ 0 ],
	&Menu_String_087[ 0 ],
	&Menu_String_088[ 0 ],
	&Menu_String_089[ 0 ],
	&Menu_String_090[ 0 ],
	&Menu_String_091[ 0 ],
	&Menu_String_092[ 0 ],
	&Menu_String_093[ 0 ],
	&Menu_String_094[ 0 ],
	&Menu_String_095[ 0 ],
	&Menu_String_096[ 0 ],
	&Menu_String_097[ 0 ],
	&Menu_String_098[ 0 ],
	&Menu_String_099[ 0 ],
	&Menu_String_100[ 0 ],
	&Menu_String_101[ 0 ],
	&Menu_String_102[ 0 ],
	&Menu_String_103[ 0 ],
	&Menu_String_104[ 0 ],
	&Menu_String_105[ 0 ],
	&Menu_String_106[ 0 ],
	&Menu_String_107[ 0 ],
	&Menu_String_108[ 0 ],
	&Menu_String_109[ 0 ],
	&Menu_String_110[ 0 ],
	&Menu_String_111[ 0 ],
	&Menu_String_112[ 0 ],
	&Menu_String_113[ 0 ],
	&Menu_String_114[ 0 ],
	&Menu_String_115[ 0 ],
	&Menu_String_116[ 0 ],
	&Menu_String_117[ 0 ],
	&Menu_String_118[ 0 ],
	&Menu_String_119[ 0 ],
	&Menu_String_120[ 0 ],
	&Menu_String_121[ 0 ],
	&Menu_String_122[ 0 ],
	&Menu_String_123[ 0 ],
	&Menu_String_124[ 0 ],
	&Menu_String_125[ 0 ],
	&Menu_String_126[ 0 ],
	&Menu_String_127[ 0 ],
	&Menu_String_128[ 0 ],
	&Menu_String_129[ 0 ],
	&Menu_String_130[ 0 ],
	&Menu_String_131[ 0 ],
	&Menu_String_132[ 0 ],
	&Menu_String_133[ 0 ],
	&Menu_String_134[ 0 ],
	&Menu_String_135[ 0 ],
	&Menu_String_136[ 0 ],
	&Menu_String_137[ 0 ],
	&Menu_String_138[ 0 ],
	&Menu_String_139[ 0 ],
	&Menu_String_140[ 0 ],
	&Menu_String_141[ 0 ],
	&Menu_String_142[ 0 ],
	&Menu_String_143[ 0 ],
	&Menu_String_144[ 0 ],
	&Menu_String_145[ 0 ],
	&Menu_String_146[ 0 ],
	&Menu_String_147[ 0 ],
	&Menu_String_148[ 0 ],
	&Menu_String_149[ 0 ],
	&Menu_String_150[ 0 ]
};

// ---
// Haptic effect numbers
// -- 

#define VIB_ALERT	0
#define HAPTIC		1
// Formats
// - Vibration Alerting:	{ VIB_ALERT, motorId, onTime (1=0.1s), offTime (1=0.1s), power (0-100), waveformId, numberOfCycles, waitTime (1=0.1s) }
//							N.B. waveformId: 0=Square, 1=Sine, 2=Triangle, 3=Sawtooth
//							N.B. waitTime is after this effect is finished (not between cycles)
// - Haptic Feedback:		{ HAPTIC, motorId, library, effect, waitTime (1=0.1s) }
//							N.B. motorId=4 means C10-100 on the controller
//							N.B. waitTime is at the end of the effect
const uint8_t quickstartdemo_0[] PROGMEM = { VIB_ALERT, 1, 10, 20, 70, 0, 3, 0 };
const uint8_t quickstartdemo_1[] PROGMEM = { HAPTIC, 4, 1, 34, 0 };
const uint8_t haptic_tut_1[] PROGMEM = { HAPTIC, 1, 1, 52, 1 };
const uint8_t haptic_tut_2[] PROGMEM = { HAPTIC, 2, 1, 15, 1 };
const uint8_t haptic_tut_3[] PROGMEM = { HAPTIC, 3, 1, 10, 1 };
const uint8_t haptic_tut_4[] PROGMEM = { HAPTIC, 0, 1, 72, 0 };
const uint8_t haptic_tut_5[] PROGMEM = { HAPTIC, 3, 1, 4, 0 };
const uint8_t haptic_tut_6[] PROGMEM = { HAPTIC, 3, 1, 10, 1 };
const uint8_t haptic_tut_7[] PROGMEM = { HAPTIC, 2, 1, 12, 0 };
const uint8_t haptic_tut_8[] PROGMEM = { HAPTIC, 0, 1, 84, 1 };
const uint8_t haptic_tut_9[] PROGMEM = { HAPTIC, 2, 1, 84, 0 };
const uint8_t haptic_tut_10[] PROGMEM = { HAPTIC, 2, 1, 6, 1 };
const uint8_t haptic_tut_11[] PROGMEM = { HAPTIC, 2, 1, 5, 1 };
const uint8_t haptic_tut_12[] PROGMEM = { HAPTIC, 2, 1, 4, 1 };
const uint8_t haptic_tut_13[] PROGMEM = { HAPTIC, 2, 1, 3, 1 };
const uint8_t haptic_tut_14[] PROGMEM = { HAPTIC, 2, 1, 2, 1 };
const uint8_t haptic_tut_15[] PROGMEM = { HAPTIC, 2, 1, 1, 1 };
const uint8_t haptic_tut_16[] PROGMEM = { HAPTIC, 2, 1, 57, 1 };
const uint8_t haptic_tut_17[] PROGMEM = { HAPTIC, 2, 1, 56, 1 };
const uint8_t haptic_tut_18[] PROGMEM = { HAPTIC, 2, 1, 55, 1 };
const uint8_t haptic_tut_19[] PROGMEM = { HAPTIC, 2, 1, 53, 1 };
const uint8_t haptic_tut_20[] PROGMEM = { HAPTIC, 2, 1, 52, 1 };
const uint8_t haptic_tut_21[] PROGMEM = { HAPTIC, 2, 1, 16, 0 };
const uint8_t haptic_tut_22[] PROGMEM = { HAPTIC, 1, 1, 7, 3 };
const uint8_t haptic_tut_23[] PROGMEM = { HAPTIC, 2, 1, 118, 1 };
const uint8_t haptic_tut_24[] PROGMEM = { HAPTIC, 0, 1, 112, 1 };
const uint8_t haptic_tut_25[] PROGMEM = { HAPTIC, 3, 1, 10, 0 };
const uint8_t vibalert_tut_1[] PROGMEM = { VIB_ALERT, 1, 30,  0, 80, 0, 1, 0 };  //simpler alternative
const uint8_t vibalert_tut_2[] PROGMEM = { VIB_ALERT, 1, 10, 5, 70, 0, 3, 0 };  // simple on / off cycle
const uint8_t vibalert_tut_3[] PROGMEM = { VIB_ALERT, 1, 30, 10, 60, 1, 1, 1 };  // change shape power on off
const uint8_t vibalert_tut_4[] PROGMEM = { VIB_ALERT, 2, 30, 10, 80, 3, 1, 0 };  // change shape power on off
const uint8_t vibalert_tut_5[] PROGMEM = { VIB_ALERT, 1, 30, 50, 30, 2, 2, 0 };  // gas monitor battery low
const uint8_t vibalert_tut_6[] PROGMEM = { VIB_ALERT, 2, 5, 10, 100, 0, 4, 0 };  //gas monitor emergency
const uint8_t drv_overview_0[] PROGMEM = { VIB_ALERT, 2, 1, 1, 100, 0, 2, 1 };
const uint8_t drv_overview_1[] PROGMEM = { VIB_ALERT, 2, 10, 10, 0, 0, 1, 0 };	// 2 second wait
const uint8_t drv_overview_2[] PROGMEM = { HAPTIC, 2, 1, 30, 0 };
const uint8_t drv_overview_3[] PROGMEM = { HAPTIC, 1, 1, 56, 7 };
const uint8_t drv_overview_4[] PROGMEM = { HAPTIC, 1, 2, 56, 7 };
const uint8_t drv_overview_5[] PROGMEM = { HAPTIC, 1, 3, 56, 7 };
const uint8_t drv_overview_6[] PROGMEM = { HAPTIC, 1, 4, 56, 7 };
const uint8_t drv_overview_7[] PROGMEM = { HAPTIC, 1, 5, 56, 0 };

const uint8_t * const EFFECTS_DATA[] PROGMEM = { 
	&quickstartdemo_0[ 0 ],		// 0 
	&quickstartdemo_1[ 0 ],		// 1 
	&haptic_tut_1[ 0 ],	    	// 2 
	&haptic_tut_2[ 0 ],	    	// 3 
	&haptic_tut_3[ 0 ],	    	// 4 
	&haptic_tut_4[ 0 ],	    	// 5 
	&haptic_tut_5[ 0 ],	    	// 6 
	&haptic_tut_6[ 0 ],	    	// 7 
	&haptic_tut_7[ 0 ],	    	// 8 
	&haptic_tut_8[ 0 ],	    	// 9 
	&haptic_tut_9[ 0 ],	    	// 10
	&haptic_tut_10[ 0 ],		// 11
	&haptic_tut_11[ 0 ],		// 12
	&haptic_tut_12[ 0 ],		// 13
	&haptic_tut_13[ 0 ],		// 14
	&haptic_tut_14[ 0 ],		// 15
	&haptic_tut_15[ 0 ],		// 16
	&haptic_tut_16[ 0 ],		// 17
	&haptic_tut_17[ 0 ],		// 18
	&haptic_tut_18[ 0 ],		// 19
	&haptic_tut_19[ 0 ],		// 20
	&haptic_tut_20[ 0 ],		// 21
	&haptic_tut_21[ 0 ],		// 22
	&haptic_tut_22[ 0 ],		// 23
	&haptic_tut_23[ 0 ],		// 24
	&haptic_tut_24[ 0 ],		// 25
	&haptic_tut_25[ 0 ],		// 26
	&vibalert_tut_1[ 0 ],		// 27
	&vibalert_tut_2[ 0 ],		// 28
	&vibalert_tut_3[ 0 ],		// 29
	&vibalert_tut_4[ 0 ],		// 30
	&vibalert_tut_5[ 0 ],		// 31
	&vibalert_tut_6[ 0 ],		// 32
	&drv_overview_0[ 0 ],		// 33
	&drv_overview_1[ 0 ],		// 34
	&drv_overview_2[ 0 ],		// 35
	&drv_overview_3[ 0 ],		// 36
	&drv_overview_4[ 0 ],		// 37
	&drv_overview_5[ 0 ],		// 38
	&drv_overview_6[ 0 ],    	// 39
	&drv_overview_7[ 0 ]    	// 40
};



// ---
// Tabs
// ---

#define NUM_LINES		5

#define	NO_MOVE_ON		0
#define FLASH_MOVE_ON	1
#define	DONE_MOVE_ON	2
#define FLASH_PLAY		3
#define	DONE_FLASH_PLAY	4

typedef struct {
	uint8_t		titleIndex;					// String index
	uint8_t		textIndices[ NUM_LINES ];	                // Lines of text to print
	uint8_t		moveOn;						// Should the tab flash the right arrow
	uint8_t		numData;					// Number for use with data
	uint8_t*	data;						// Modifiable info. List of indices into EFFECTS_DATA
} Tab;

uint8_t QUICK_START_ARRAY_0[] =		{ 0 };
uint8_t QUICK_START_ARRAY_1[] =		{ 1 };
uint8_t HAPTIC_TUT_ARRAY_0[] =		{ 2, 3, 4, 5 };
uint8_t HAPTIC_TUT_ARRAY_1[] =		{ 6 };
uint8_t HAPTIC_TUT_ARRAY_2[] =		{ 7, 8 };
uint8_t HAPTIC_TUT_ARRAY_3[] =		{ 9, 10 };
uint8_t HAPTIC_TUT_ARRAY_4[] =		{ 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16 };
uint8_t HAPTIC_TUT_ARRAY_5[] =		{ 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22 };
uint8_t HAPTIC_TUT_ARRAY_6[] =		{ 23, 24, 25, 26 };
uint8_t VIBALERT_TUT_ARRAY_0[] =	{ 27 };
uint8_t VIBALERT_TUT_ARRAY_1[] =	{ 28 };
uint8_t VIBALERT_TUT_ARRAY_2[] =	{ 29, 30 };
uint8_t VIBALERT_TUT_ARRAY_3[] =	{ 31 };
uint8_t VIBALERT_TUT_ARRAY_4[] =	{ 32 };
uint8_t DRV_OVERVIEW_ARRAY_0[] =	{ 33, 34, 35 };
uint8_t DRV_OVERVIEW_ARRAY_1[] =	{ 36, 37, 38, 39, 40 };

// Tabs
Tab tabs[] = {

	{  1, {  5,  6,  7,  8,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  0 Quick-Start Demo.
	{  2, {  9, 10, 11,  0,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  1 Haptic Feedback Tutorial
	{  3, { 12, 13, 14,  0,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  2 Vibration Alerting Tutorial
	{  4, { 15, 16, 17,  0,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  3 DRV2605 Overview
	
	// Quick start demo tabs
	{  1, { 18, 19, 20, 21,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  4 Navigation
	{  1, { 22, 23, 24, 25,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  5 Navigation
	{  1, { 27, 28, 29, 30, 31 }, FLASH_PLAY,		1,	QUICK_START_ARRAY_0 },	//  6 Quick-Start Tab
	{  1, { 32, 33, 34, 35,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  7 Quick-Start Tab
	{  1, { 36, 37, 38, 39, 40 }, FLASH_PLAY,		1,	QUICK_START_ARRAY_1 },	//  8 Quick-Start Tab
	{  1, { 41, 42, 43, 44,  0 }, FLASH_MOVE_ON,		0,	NULL },	//  9 Quick-Start Tab
	
	// Haptic Feedback Tutorial tabs
	{  2, { 18, 19, 20, 21,  0 }, FLASH_MOVE_ON,		0,	NULL },	// 10 Navigation
	{  2, { 22, 23, 24, 25,  0 }, FLASH_MOVE_ON,		0,	NULL },	// 11 Navigation
	{  2, { 45, 46, 47, 48, 49 }, FLASH_PLAY,		4,	HAPTIC_TUT_ARRAY_0 },	// 12 Haptic Feedback Tut. Tab
	{  2, { 50, 51, 52, 53,  0 }, FLASH_MOVE_ON,		0,	NULL },	// 13 Haptic Feedback Tut. Tab
	{  2, { 54, 55,  0,  0,  0 }, FLASH_PLAY,		1,	HAPTIC_TUT_ARRAY_1 },	// 14 Haptic Feedback Tut. Tab
	{  2, { 56, 57, 58, 59,  0 }, FLASH_PLAY,		2,	HAPTIC_TUT_ARRAY_2 },	// 15 Haptic Feedback Tut. Tab
	{  2, { 60, 61, 62, 63,  0 }, FLASH_PLAY,		2,	HAPTIC_TUT_ARRAY_3 },	// 16 Haptic Feedback Tut. Tab
	{  2, { 64, 65, 66, 67,  0 }, FLASH_MOVE_ON,		0,	NULL },	// 17 Haptic Feedback Tut. Tab
	{  2, { 68, 69, 70,  0,  0 }, FLASH_PLAY,		30,	HAPTIC_TUT_ARRAY_4 },	// 18 Haptic Feedback Tut. Tab
	{  2, { 71, 72, 73, 74, 75 }, FLASH_PLAY,		24,	HAPTIC_TUT_ARRAY_5 },	// 19 Haptic Feedback Tut. Tab
	{  2, { 76, 77, 78, 79, 80 }, FLASH_PLAY,		4,	HAPTIC_TUT_ARRAY_6 },	// 20 Haptic Feedback Tut. Tab
	
	// Vibration Alerting Tutorial
	{  3, {  18,  19,  20,  21,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 21 Navigation
	{  3, {  22,  23,  24,  26,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 22 Navigation
	{  3, {  81,  82,  83,   0,   0 }, FLASH_PLAY,		1,	VIBALERT_TUT_ARRAY_0 },	// 23 Vibration Alerting Tut. Tab
	{  3, {  84,  85,  86,  87,   0 }, FLASH_PLAY,		1,	VIBALERT_TUT_ARRAY_1 },	// 24 Vibration Alerting Tut. Tab
	{  3, {  88,  89,  90,   0,   0 }, FLASH_PLAY,		2,	VIBALERT_TUT_ARRAY_2 },	// 25 Vibration Alerting Tut. Tab
	{  3, {  91,  92,  93,   0,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 26 Vibration Alerting Tut. Tab
	{  3, {  94,  95,  96,  97,   0 }, FLASH_PLAY,		1,	VIBALERT_TUT_ARRAY_3 },	// 27 Vibration Alerting Tut. Tab
	{  3, {  98,  99,   0,   0,   0 }, FLASH_PLAY,		1,	VIBALERT_TUT_ARRAY_4 },	// 28 Vibration Alerting Tut. Tab
	{  3, {  76,  77, 100, 101,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 29 Vibration Alerting Tut. Tab
	
	// DRV2605 Overview tabs
	{  4, {  18,  19,  20,  21,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 30 Navigation
	{  4, {  22,  23,  24,  26,   0 }, FLASH_MOVE_ON,	0,	NULL },	// 31 Navigation
	{  4, { 102, 103, 104, 105, 106 }, FLASH_MOVE_ON,	0,	NULL },	// 32 DRV2605 Overview Tab
	{  4, { 107, 108, 109, 110, 111 }, FLASH_MOVE_ON,	0,	NULL },	// 33 DRV2605 Overview Tab
	{  4, { 112, 113, 114, 115, 116 }, FLASH_PLAY,		3,	DRV_OVERVIEW_ARRAY_0 },	// 34 DRV2605 Overview Tab
	{  4, { 117, 118, 119, 120, 121 }, FLASH_MOVE_ON,	0,	NULL },	// 35 DRV2605 Overview Tab
	{  4, { 122, 123, 124, 125, 126 }, FLASH_MOVE_ON,	0,	NULL },	// 36 DRV2605 Overview Tab
	{  4, { 127, 128, 129, 130, 131 }, FLASH_MOVE_ON,	0,	NULL },	// 37 DRV2605 Overview Tab
	{  4, { 132, 133, 134, 135, 136 }, FLASH_MOVE_ON,	0,	NULL },	// 38 DRV2605 Overview Tab
	{  4, { 137, 138, 139, 140,   0 }, FLASH_PLAY,		5,	DRV_OVERVIEW_ARRAY_1 },	// 39 DRV2605 Overview Tab
	{  4, { 141, 142, 143, 144, 145 }, FLASH_MOVE_ON,	0,	NULL },	// 40 DRV2605 Overview Tab
	{  4, { 146, 147, 148, 149, 150 }, FLASH_MOVE_ON,	0,	NULL },	// 41 DRV2605 Overview Tab
};

// Tabs lists
Tab* MAIN_MENU_TABS[]  = { &tabs[ 0 ], &tabs[ 1 ], &tabs[ 2 ], &tabs[ 3 ] };
Tab* QUICK_START_TABS[] = { &tabs[ 0 ], &tabs[ 4 ], &tabs[ 5 ], &tabs[ 6 ], &tabs[ 7 ], &tabs[ 8 ], &tabs[ 9 ] };
Tab* HAPTIC_TUT_TABS[]  = { &tabs[ 10 ], &tabs[ 11 ], &tabs[ 12 ], &tabs[ 13 ], &tabs[ 14 ], &tabs[ 15 ], &tabs[ 16 ], &tabs[ 17 ], &tabs[ 18 ], &tabs[ 19 ], &tabs[ 20 ] };
Tab* VIBALERT_TUT_TABS[] = { &tabs[ 21 ], &tabs[ 22 ], &tabs[ 23 ], &tabs[ 24 ], &tabs[ 25 ], &tabs[ 26 ], &tabs[ 27 ], &tabs[ 28 ], &tabs[ 29 ] };
Tab* DRV2605_TABS[]    = { &tabs[ 30 ], &tabs[ 31 ], &tabs[ 32 ], &tabs[ 33 ], &tabs[ 34 ], &tabs[ 35 ], &tabs[ 36 ], &tabs[ 37 ], &tabs[ 38 ], &tabs[ 39 ], &tabs[ 40 ], &tabs[ 41 ] };


// ---
// Page list
// ---

typedef struct {
  uint8_t	page;			// So we know where we are
  uint8_t	numTabs;		// Number of tabs to draw at top of the page
  Tab**	        tabs;			// Tabs
  int8_t	selectedTab;	        // Selected tab index
} Page;

Page pages[ NUM_PAGES ] = {
  { PAGE_MAINMENU,			4,	MAIN_MENU_TABS,		0 },
  { PAGE_QUICK_START,		7,	QUICK_START_TABS,	0 },
  { PAGE_HAPTIC_TUT,		11,	HAPTIC_TUT_TABS,	0 },
  { PAGE_VIBALERT_TUT,		9,	VIBALERT_TUT_TABS,	0 },
  { PAGE_DRV2605,			12,	DRV2605_TABS,		0 },
};

int8_t DEMO_PAGES[] = { PAGE_QUICK_START, PAGE_HAPTIC_TUT, PAGE_VIBALERT_TUT, PAGE_DRV2605 };

#endif // include_menu_defs_h

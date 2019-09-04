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

#include "icons.h"

// --- 
// Icons
// ---
typedef struct {
  const unsigned char*	image;			// The pixel data of the icon
  uint8_t				width, height;	// Dimension information
} Icon;

Icon icons[] = {                                                               // one icon = 4bytes more SRAM amount now 44Bytes
  {(const unsigned char*)&PLAY_HAPTICS_ICON, ICON_WIDTH, ICON_HEIGHT },        // 0 play haptics
  {(const unsigned char*)&PLAY_VIB_ALERTS_ICON, ICON_WIDTH, ICON_HEIGHT },     // 1 play vibrating alerts
  {(const unsigned char*)&WAVE_FORM_ICON, ICON_WIDTH, ICON_HEIGHT },           // 2 wave forms icon
  {(const unsigned char*)&POWER_ICON, ICON_WIDTH, ICON_HEIGHT },               // 3 power settings
  {(const unsigned char*)&ON_ICON, ICON_WIDTH, ICON_HEIGHT },                  // 4 on time settings
  {(const unsigned char*)&OFF_ICON, ICON_WIDTH, ICON_HEIGHT },                 // 5 off time settings
  {(const unsigned char*)&AUDIO_ICON, ICON_WIDTH, ICON_HEIGHT },               // 6 Audio icon
  
};

// ---
// String table
// ---
const char Menu_String_00[] PROGMEM = "True Haptic";
const char Menu_String_01[] PROGMEM = "Vib. Alert";
const char Menu_String_02[] PROGMEM = "Waveform";
const char Menu_String_03[] PROGMEM = "Power";
const char Menu_String_04[] PROGMEM = "On Time";
const char Menu_String_05[] PROGMEM = "Off Time";
const char Menu_String_06[] PROGMEM = "Clicks";
const char Menu_String_07[] PROGMEM = "Ramps";
const char Menu_String_08[] PROGMEM = "Other";
const char Menu_String_09[] PROGMEM = "Alerts";
const char Menu_String_10[] PROGMEM = "Single";
const char Menu_String_11[] PROGMEM = "Double";
const char Menu_String_12[] PROGMEM = "Triple";
const char Menu_String_13[] PROGMEM = "Up";
const char Menu_String_14[] PROGMEM = "Down";
const char Menu_String_15[] PROGMEM = "Buzzes";
const char Menu_String_16[] PROGMEM = "Bumps";
const char Menu_String_17[] PROGMEM = "Pulses";
const char Menu_String_18[] PROGMEM = "Hums";
const char Menu_String_19[] PROGMEM = "Strong";
const char Menu_String_20[] PROGMEM = "Medium";
const char Menu_String_21[] PROGMEM = "Sharp";
const char Menu_String_22[] PROGMEM = "Transition";
const char Menu_String_23[] PROGMEM = "Short";
const char Menu_String_24[] PROGMEM = "Long";
const char Menu_String_25[] PROGMEM = "Library";
const char Menu_String_26[] PROGMEM = "Debug";
const char Menu_String_27[] PROGMEM = "Audio";                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const char Menu_String_28[] PROGMEM = "Select";                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


const char * const MENU_STRS[] PROGMEM= {
	&Menu_String_00[ 0 ],
	&Menu_String_01[ 0 ],
	&Menu_String_02[ 0 ],
	&Menu_String_03[ 0 ],
	&Menu_String_04[ 0 ],
	&Menu_String_05[ 0 ],
	&Menu_String_06[ 0 ],
	&Menu_String_07[ 0 ],
	&Menu_String_08[ 0 ],
	&Menu_String_09[ 0 ],
	&Menu_String_10[ 0 ],
	&Menu_String_11[ 0 ],
	&Menu_String_12[ 0 ],
	&Menu_String_13[ 0 ],
	&Menu_String_14[ 0 ],
	&Menu_String_15[ 0 ],
	&Menu_String_16[ 0 ],
	&Menu_String_17[ 0 ],
	&Menu_String_18[ 0 ],
	&Menu_String_19[ 0 ],
	&Menu_String_20[ 0 ],
	&Menu_String_21[ 0 ],
	&Menu_String_22[ 0 ],
	&Menu_String_23[ 0 ],
	&Menu_String_24[ 0 ],
	&Menu_String_25[ 0 ],  //Library
	&Menu_String_26[ 0 ],
	&Menu_String_27[ 0 ],
        &Menu_String_28[ 0 ],
};

// Empty string
const char Tab_String_00[] PROGMEM = "";
// True haptics brief
const char Tab_String_01[] PROGMEM = "Play true haptic";
const char Tab_String_02[] PROGMEM = "effects with the";
const char Tab_String_03[] PROGMEM = "DRV2605. Comes ";
const char Tab_String_04[] PROGMEM = "with 123 effects";
// Vibr. alert brief
const char Tab_String_05[] PROGMEM = "Play vibration";
const char Tab_String_06[] PROGMEM = "alerts. Select";
const char Tab_String_07[] PROGMEM = "waveform, power,";
const char Tab_String_08[] PROGMEM = "on and off time.";
// Vibr. alert settings
const char Tab_String_09[] PROGMEM = "Wave:%s";
const char Tab_String_10[] PROGMEM = "Power:%s";
const char Tab_String_11[] PROGMEM = "On Time:%s";
const char Tab_String_12[] PROGMEM = "Off Time:%s";
// True Haptics settings
const char Tab_String_13[] PROGMEM = "Library:%s";
const char Tab_String_14[] PROGMEM = "Effect:%s";
// Debug settings
const char Tab_String_15[] PROGMEM = "Dump settings";
const char Tab_String_16[] PROGMEM = "Reset autocalibration";
const char Tab_String_17[] PROGMEM = "Firmware information";
// Motor info
const char Tab_String_18[] PROGMEM = "Motor:%s";
// LRA use 6
const char Tab_String_19[] PROGMEM = "LRA uses lib. 6%s";
// Audio settings
const char Tab_String_20[] PROGMEM = "Play audio";
const char Tab_String_21[] PROGMEM = "connect jack ";
const char Tab_String_22[] PROGMEM = "3.5mm max 1Vrms";

// Select settings
const char Tab_String_23[] PROGMEM = "Select haptic";
const char Tab_String_24[] PROGMEM = "drv. on shield";
//const char Tab_String_25[] PROGMEM = "Shield:";
//const char Tab_String_26[] PROGMEM = "STOP";


const char * const TAB_STRS[] PROGMEM = {
	&Tab_String_00[ 0 ],        //0
	&Tab_String_01[ 0 ],        //1
	&Tab_String_02[ 0 ],        //2
	&Tab_String_03[ 0 ],
	&Tab_String_04[ 0 ],
	&Tab_String_05[ 0 ],
	&Tab_String_06[ 0 ],
	&Tab_String_07[ 0 ],
	&Tab_String_08[ 0 ],
	&Tab_String_09[ 0 ],
	&Tab_String_10[ 0 ],
	&Tab_String_11[ 0 ],
	&Tab_String_12[ 0 ],
	&Tab_String_13[ 0 ],
	&Tab_String_14[ 0 ],
	&Tab_String_15[ 0 ],
	&Tab_String_16[ 0 ],
	&Tab_String_17[ 0 ],
	&Tab_String_18[ 0 ],
	&Tab_String_19[ 0 ],          //19
	&Tab_String_20[ 0 ],          //20
	&Tab_String_21[ 0 ],
	&Tab_String_22[ 0 ],
	&Tab_String_23[ 0 ],
	&Tab_String_24[ 0 ],
	//&Tab_String_25[ 0 ],
 // &Tab_String_26[ 0 ],
};

const char Wave_String_0[] PROGMEM = "Sqr. %s";
const char Wave_String_1[] PROGMEM = "Sin. %s";
const char Wave_String_2[] PROGMEM = "Tri. %s";
const char Wave_String_3[] PROGMEM = "Saw. %s";
const char Wave_String_4[] PROGMEM = "LRA not supp.";

const char * const WAVE_STRS[] PROGMEM= {
	&Wave_String_0[ 0 ],
	&Wave_String_1[ 0 ],
	&Wave_String_2[ 0 ],
	&Wave_String_3[ 0 ],
	&Wave_String_4[ 0 ],
};

const char Select_String_0[] PROGMEM = "LRA%s";
const char Select_String_1[] PROGMEM = "ERM%s";
const char Select_String_2[] PROGMEM = "Shield: ERM%s";
const char Select_String_3[] PROGMEM = "Shield: LRA%s";


const char * const SELECT_STRS[] PROGMEM= {
	&Select_String_0[ 0 ],
	&Select_String_1[ 0 ],
  &Select_String_2[ 0 ],
  &Select_String_3[ 0 ],
  
};

// ---
// Tabs
// ---

// Longest string times char width
#define TAB_PX_WIDTH	( 11 * 6 )

// Tab types
#define  TT_NONE		0
#define  TT_PWR_BAR		1
#define  TT_ON_TIME		2
#define  TT_OFF_TIME	        3
#define  TT_BAR			4
#define  TT_LIST		5
#define  TT_FULL_EFFECT         6
#define  TT_LEAF		7
#define  TT_WAVE		8
#define  TT_AUDIO		9
#define  TT_SELECT		10


// Data indices
#define DATA_VAL	0
#define DATA_MIN	1
#define	DATA_MAX	2
#define DATA_DELTA	3

// Motor power data
#define NUM_PWRS	10
static const uint8_t powers[ NUM_PWRS ] PROGMEM =
				{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
// Vibration Alert on time
#define NUM_ON	7
static const uint8_t onTimes[ NUM_ON ] PROGMEM =
				{ 3, 5, 10, 20, 30, 50, 100 };
// Vibration Alert off time
#define NUM_OFF	8
static const uint8_t offTimes[ NUM_OFF ] PROGMEM =
				{ 0, 3, 5, 10, 20, 30, 50, 100 };


uint8_t PWR_BAR_DATA[] = { 4, 0, NUM_PWRS - 1, 1 };		// Default index is 50%
uint8_t BASIC_ON_TIME_DATA[] = { 4, 0, NUM_ON - 1, 1 };		// Default index is 2secs
uint8_t BASIC_OFF_TIME_DATA[] = { 4, 0, NUM_OFF - 1, 1 };	// Default index is 2secs
uint8_t WAV_BAR_DATA[] = { 0, 0, 3, 1 };			// Default value is Square
uint8_t LIB_BAR_DATA[] = { 1, 1, 5, 1 };			// Libraries 1-5 (6 is LRA)

uint8_t SELECT_BAR_DATA[] = { 0, 0, 1, 1 };			// Default value is Square


typedef struct {
  int8_t	titleIndex;			// String index
  Icon*		icon;				// Icon to show in page
  uint8_t	textIndices[ 4 ];	// Lines of text to print
  uint8_t	type;				// Tab type
  uint8_t*	data;				// Modifiable info. See arrays above
} Tab;

// Tabs
Tab tabs[] = {
	{  0, &(icons[ 0 ]), {  1,  2,  3,  4 }, TT_NONE },							//  0 Haptic Feedback
	{  1, &(icons[ 1 ]), {  5,  6,  7,  8 }, TT_NONE },							//  1 Vibration Alerting
	{  2, &(icons[ 2 ]), {  9, 10, 11, 12 }, TT_NONE },							//  2 Waveform
	{  3, &(icons[ 3 ]), {  9, 10, 11, 12 }, TT_NONE },							//  3 Power
	{  4, &(icons[ 4 ]), {  9, 10, 11, 12 }, TT_NONE },							//  4 On Time Basic
	{  5, &(icons[ 5 ]), {  9, 10, 11, 12 }, TT_NONE },							//  5 Off time Basic
	{  6, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							//  6 Clicks
	{  7, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							//  7 Ramps
	{  8, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							//  8 Other
	{  9, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							//  9 Alerts
	{ 10, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 10 Single
	{ 11, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 11 Double
	{ 12, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 12 Triple
	{ 13, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 13 Up
	{ 14, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 14 Down
	{ 15, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 15 Buzzes
	{ 16, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 16 Bumps
	{ 17, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 17 Pulses
	{ 18, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 18 Hums
	{ 19, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 19 Strong
	{ 20, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 20 Medium
	{ 21, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 21 Sharp
	{ 22, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 22 Transition
	{ 23, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 23 Short
	{ 24, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_NONE },							// 24 Long
	{ 25, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_BAR, LIB_BAR_DATA },			                // 25 Selected Library
	
	{ -1, &(icons[ 0 ]), { 13, 14, 18,  0 }, TT_LEAF },							// 26 Leaf
	{ 26, &(icons[ 0 ]), { 15, 16, 17,  0 }, TT_NONE },							// 27 Debug
	
	{  2, &(icons[ 2 ]), {  9, 10, 11, 12 }, TT_WAVE, WAV_BAR_DATA },			                // 28 Waveform
	{  3, &(icons[ 3 ]), {  9, 10, 11, 12 }, TT_PWR_BAR, PWR_BAR_DATA },		                        // 29 Power
	{  4, &(icons[ 4 ]), {  9, 10, 11, 12 }, TT_ON_TIME, BASIC_ON_TIME_DATA },	                        // 30 On Time Basic
	{  5, &(icons[ 5 ]), {  9, 10, 11, 12 }, TT_OFF_TIME, BASIC_OFF_TIME_DATA },                            // 31 Off time Basic
	
        { 27, &(icons[ 6 ]), { 20, 21, 22, 0 }, TT_AUDIO  },					// 32 AUDIO
        { 28, &(icons[ 0 ]), { 23, 24, 0, 0 }, TT_SELECT, SELECT_BAR_DATA  },					// 33 SELECT

};

// Tabs lists
/*
static Tab* __attribute__ ((progmem)) MAIN_MENU_TABS[] = { &tabs[ 0 ], &tabs[ 1 ] };
static Tab* __attribute__ ((progmem)) HAPTIC_TABS[] = { &tabs[ 6 ], &tabs[ 7 ], &tabs[ 8 ], &tabs[ 9 ], &tabs[ 25 ] };  //library
static Tab* __attribute__ ((progmem)) VIB_ALERT_TABS[] = { &tabs[ 2 ], &tabs[ 3 ], &tabs[ 4 ], &tabs[ 5 ] };

static Tab* __attribute__ ((progmem)) VIB_ALERT_WAV_TABS[] = { &tabs[ 28 ] };
static Tab* __attribute__ ((progmem)) VIB_ALERT_PWR_TABS[] = { &tabs[ 29 ] };
static Tab* __attribute__ ((progmem)) VIB_ALERT_ON_TABS[] = { &tabs[ 30 ] };
static Tab* __attribute__ ((progmem)) VIB_ALERT_OFF_TABS[] = { &tabs[ 31 ] };

static Tab* __attribute__ ((progmem)) HAPT_CLICKS_TABS[] = { &tabs[ 10 ], &tabs[ 11 ], &tabs[ 12 ] };
static Tab* __attribute__ ((progmem)) HAPT_RAMPS_TABS[] = { &tabs[ 13 ], &tabs[ 14 ] };
static Tab* __attribute__ ((progmem)) HAPT_OTHER_TABS[] = { &tabs[ 15 ], &tabs[ 16 ], &tabs[ 17 ], &tabs[ 18 ] };
static Tab* __attribute__ ((progmem)) HAPT_ALERTS_TABS[] = { &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) CLKS_SINGLE_TABS[] = { &tabs[ 19 ], &tabs[ 20 ], &tabs[ 21 ], &tabs[ 22 ] };
static Tab* __attribute__ ((progmem)) CLKS_DOUBLE_TABS[] = { &tabs[ 19 ], &tabs[ 20 ], &tabs[ 21 ] };
static Tab* __attribute__ ((progmem)) CLKS_TRIPLE_TABS[] = { &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) CLKS_SG_STRONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) CLKS_SG_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) CLKS_SG_SHARP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) CLKS_SG_TRANS_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) CLKS_DB_STRONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) CLKS_DB_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) CLKS_DB_SHARP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) RMPS_UP_TABS[] = { &tabs[ 23 ], &tabs[ 20 ], &tabs[ 24 ] };
static Tab* __attribute__ ((progmem)) RMPS_DOWN_TABS[] = { &tabs[ 23 ], &tabs[ 20 ], &tabs[ 24 ] };
  
static Tab* __attribute__ ((progmem)) RMPS_UP_SHORT_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) RMPS_UP_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) RMPS_UP_LONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) RMPS_DW_SHORT_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) RMPS_DW_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) RMPS_DW_LONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* __attribute__ ((progmem)) MORE_BUZZ_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) MORE_BUMP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) MORE_PULSE_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* __attribute__ ((progmem)) MORE_HUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf


static Tab* __attribute__ ((progmem)) DEBUG_TABS[] = { &tabs[ 27 ] }; // Debug

*/

static Tab* MAIN_MENU_TABS[] = { &tabs[ 0 ], &tabs[ 1 ] };
static Tab* HAPTIC_TABS[] = { &tabs[ 6 ], &tabs[ 7 ], &tabs[ 8 ], &tabs[ 9 ], &tabs[ 25 ], &tabs[ 32 ], &tabs[ 33 ] };  //library, AUDIO, SELECT  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
static Tab* VIB_ALERT_TABS[] = { &tabs[ 2 ], &tabs[ 3 ], &tabs[ 4 ], &tabs[ 5 ] };

static Tab* VIB_ALERT_WAV_TABS[] = { &tabs[ 28 ] };
static Tab* VIB_ALERT_PWR_TABS[] = { &tabs[ 29 ] };
static Tab* VIB_ALERT_ON_TABS[] = { &tabs[ 30 ] };
static Tab* VIB_ALERT_OFF_TABS[] = { &tabs[ 31 ] };

static Tab* HAPT_CLICKS_TABS[] = { &tabs[ 10 ], &tabs[ 11 ], &tabs[ 12 ] };
static Tab* HAPT_RAMPS_TABS[] = { &tabs[ 13 ], &tabs[ 14 ] };
static Tab* HAPT_OTHER_TABS[] = { &tabs[ 15 ], &tabs[ 16 ], &tabs[ 17 ], &tabs[ 18 ] };
static Tab* HAPT_ALERTS_TABS[] = { &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* CLKS_SINGLE_TABS[] = { &tabs[ 19 ], &tabs[ 20 ], &tabs[ 21 ], &tabs[ 22 ] };
static Tab* CLKS_DOUBLE_TABS[] = { &tabs[ 19 ], &tabs[ 20 ], &tabs[ 21 ] };
static Tab* CLKS_TRIPLE_TABS[] = { &tabs[ 26 ] }; // Leaf

static Tab* CLKS_SG_STRONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ]}; // Leaf
static Tab* CLKS_SG_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* CLKS_SG_SHARP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* CLKS_SG_TRANS_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* CLKS_DB_STRONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* CLKS_DB_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* CLKS_DB_SHARP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* RMPS_UP_TABS[] = { &tabs[ 23 ], &tabs[ 20 ], &tabs[ 24 ] };
static Tab* RMPS_DOWN_TABS[] = { &tabs[ 23 ], &tabs[ 20 ], &tabs[ 24 ] };
  
static Tab* RMPS_UP_SHORT_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* RMPS_UP_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* RMPS_UP_LONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* RMPS_DW_SHORT_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* RMPS_DW_MEDIUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* RMPS_DW_LONG_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* MORE_BUZZ_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* MORE_BUMP_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* MORE_PULSE_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf
static Tab* MORE_HUM_TABS[] = { &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ], &tabs[ 26 ] }; // Leaf

static Tab* AUDIO_TABS[] = { &tabs[ 32 ]}; // Leaf
static Tab* SELECT_TABS[] = { &tabs[ 33 ] }; // Leaf


static Tab* DEBUG_TABS[] = { &tabs[ 27 ] }; // Debug
// ---
// Page list
// ---

typedef struct {
  uint8_t	page;			// So we know where we are
  uint8_t	numTabs;		// Number of tabs to draw at top of the page
  Tab**		tabs;			// Tabs
  int8_t	selectedTab;	// Selected tab lets us go back through pages in the order we went through them
} Page;

Page pages[ NUM_PAGES ] = {
  { PAGE_MAINMENU,		2,	MAIN_MENU_TABS, 0 },          //0
  { PAGE_HAPTICS,		7,	HAPTIC_TABS, 0 },            //1
  { PAGE_VIBALERT,		4,	VIB_ALERT_TABS, 0 },          //2

  { PAGE_HAPT_CLICKS,		3,	HAPT_CLICKS_TABS, 0 },
  { PAGE_HAPT_RAMPS,		2,	HAPT_RAMPS_TABS, 0 },
  { PAGE_HAPT_OTHER,		4,	HAPT_OTHER_TABS, 0 },
  { PAGE_HAPT_ALERTS,		2,	HAPT_ALERTS_TABS, 0 },

  { PAGE_CLKS_SINGLE,		4,	CLKS_SINGLE_TABS, 0 },
  { PAGE_CLKS_DOUBLE,		3,	CLKS_DOUBLE_TABS, 0 },
  { PAGE_CLKS_TRIPLE,		1,	CLKS_TRIPLE_TABS, 0 },

  { PAGE_CLKS_SG_STRONG,	7,	CLKS_SG_STRONG_TABS, 0 },
  { PAGE_CLKS_SG_MEDIUM,	3,	CLKS_SG_MEDIUM_TABS, 0 },
  { PAGE_CLKS_SG_SHARP,		7,	CLKS_SG_SHARP_TABS, 0 },
  { PAGE_CLKS_SG_TRANS,		6,	CLKS_SG_TRANS_TABS, 0 },

  { PAGE_CLKS_DB_STRONG,	9,	CLKS_DB_STRONG_TABS, 0 },
  { PAGE_CLKS_DB_MEDIUM,	6,	CLKS_DB_MEDIUM_TABS, 0 },
  { PAGE_CLKS_DB_SHARP,		7,	CLKS_DB_SHARP_TABS, 0 },

  { PAGE_RMPS_UP,		3,	RMPS_UP_TABS, 0 },
  { PAGE_RMPS_DOWN,		3,	RMPS_DOWN_TABS, 0 },

  { PAGE_RMPS_UP_SHORT,		8,	RMPS_UP_SHORT_TABS, 0 },
  { PAGE_RMPS_UP_MEDIUM,	8,	RMPS_UP_MEDIUM_TABS, 0 },
  { PAGE_RMPS_UP_LONG,		8,	RMPS_UP_LONG_TABS, 0 },

  { PAGE_RMPS_DW_SHORT,		8,	RMPS_DW_SHORT_TABS, 0 },
  { PAGE_RMPS_DW_MEDIUM,	8,	RMPS_DW_MEDIUM_TABS, 0 },
  { PAGE_RMPS_DW_LONG,		8,	RMPS_DW_LONG_TABS, 0 },

  { PAGE_MORE_BUZZ,		8,	MORE_BUZZ_TABS, 0 },
  { PAGE_MORE_BUMP,		3,	MORE_BUMP_TABS, 0 },
  { PAGE_MORE_PULSE,		6,	MORE_PULSE_TABS, 0 },
  { PAGE_MORE_HUM,		11,	MORE_HUM_TABS, 0 },
  
  { PAGE_DEBUG,			3,	DEBUG_TABS, 0 },
  
  { PAGE_VIBALERT_WAV,		1,	VIB_ALERT_WAV_TABS, 0 },
  { PAGE_VIBALERT_PWR,		1,	VIB_ALERT_PWR_TABS, 0 },
  { PAGE_VIBALERT_ON,		1,	VIB_ALERT_ON_TABS, 0 },
  { PAGE_VIBALERT_OFF,		1,	VIB_ALERT_OFF_TABS, 0 },

//  { PAGE_AUDIO,		        1,	AUDIO_TABS, 0 },
//  { PAGE_SELECT,		1,	SELECT_TABS, 0 },
  
};

int8_t NEXT_PAGES_MAIN_MENU[]		= { PAGE_HAPTICS, PAGE_VIBALERT };
int8_t NEXT_PAGES_VIB_ALERT[]		= { PAGE_VIBALERT_WAV, PAGE_VIBALERT_PWR, PAGE_VIBALERT_ON, PAGE_VIBALERT_OFF };
int8_t NEXT_PAGES_HAPT_FEEDBACK[]	= { PAGE_HAPT_CLICKS, PAGE_HAPT_RAMPS, PAGE_HAPT_OTHER, PAGE_HAPT_ALERTS, PAGE_AUDIO, PAGE_SELECT, PAGE_HAPTICS };
int8_t NEXT_PAGES_FULL_CLICKS[]		= { PAGE_CLKS_SINGLE, PAGE_CLKS_DOUBLE, PAGE_CLKS_TRIPLE };
int8_t NEXT_PAGES_FULL_RAMPS[]		= { PAGE_RMPS_UP, PAGE_RMPS_DOWN };
int8_t NEXT_PAGES_FULL_OTHER[]		= { PAGE_MORE_BUZZ, PAGE_MORE_BUMP, PAGE_MORE_PULSE, PAGE_MORE_HUM };
int8_t NEXT_PAGES_CLKS_SINGLE[]		= { PAGE_CLKS_SG_STRONG, PAGE_CLKS_SG_MEDIUM, PAGE_CLKS_SG_SHARP, PAGE_CLKS_SG_TRANS };
int8_t NEXT_PAGES_CLKS_DOUBLE[]		= { PAGE_CLKS_DB_STRONG, PAGE_CLKS_DB_MEDIUM, PAGE_CLKS_DB_SHARP };
int8_t NEXT_PAGES_RMPS_UP[]		= { PAGE_RMPS_UP_SHORT, PAGE_RMPS_UP_MEDIUM, PAGE_RMPS_UP_LONG };
int8_t NEXT_PAGES_RMPS_DOWN[]		= { PAGE_RMPS_DW_SHORT, PAGE_RMPS_DW_MEDIUM, PAGE_RMPS_DW_LONG };
int8_t NEXT_PAGES_AUDIO[]		= { PAGE_AUDIO };
int8_t NEXT_PAGES_SELECT[]		= { PAGE_SELECT };


int8_t* NEXT_PAGES[] = {
	NEXT_PAGES_MAIN_MENU,		// PAGE_MAINMENU
	NEXT_PAGES_HAPT_FEEDBACK,	// PAGE_HAPTICS
	NEXT_PAGES_VIB_ALERT,		// PAGE_VIBALERT
	NEXT_PAGES_FULL_CLICKS,		// PAGE_HAPT_CLICKS
	NEXT_PAGES_FULL_RAMPS,		// PAGE_HAPT_RAMPS
	NEXT_PAGES_FULL_OTHER,		// PAGE_HAPT_OTHER
	NULL,				// PAGE_HAPT_ALERTS
	NEXT_PAGES_CLKS_SINGLE,		// PAGE_CLKS_SINGLE
	NEXT_PAGES_CLKS_DOUBLE,		// PAGE_CLKS_DOUBLE
	NULL,						// PAGE_CLKS_TRIPLE 
	NULL,						// PAGE_CLKS_SG_STRONG
	NULL,						// PAGE_CLKS_SG_MEDIUM
	NULL,						// PAGE_CLKS_SG_SHARP
	NULL,						// PAGE_CLKS_SG_TRANS
	NULL,						// PAGE_CLKS_DB_STRONG
	NULL,						// PAGE_CLKS_DB_MEDIUM
	NULL,						// PAGE_CLKS_DB_SHARP
	NEXT_PAGES_RMPS_UP,	    // PAGE_RMPS_UP
	NEXT_PAGES_RMPS_DOWN,	    // PAGE_RMPS_DOWN
	NULL,			    // PAGE_RMPS_UP_SHORT
	NULL,			    // PAGE_RMPS_UP_MEDIUM
	NULL,			    // PAGE_RMPS_UP_LONG
	NULL,			    // PAGE_RMPS_DW_SHORT
	NULL,			    // PAGE_RMPS_DW_MEDIUM
	NULL,			    // PAGE_RMPS_DW_LONG
	NULL,			    // PAGE_MORE_BUZZ
	NULL,			    // PAGE_MORE_BUMP
	NULL,			    // PAGE_MORE_PULSE
	NULL,			    // PAGE_MORE_HUM
	NULL,			    // PAGE_DEBUG
	NULL,			    // PAGE_VIBALERT_WAV
	NULL,                       // PAGE_VIBALERT_PWR
	NULL,                       // PAGE_VIBALERT_ON
	NULL,                       // PAGE_VIBALERT_OFF
	NULL,                       // AUDIO
        NULL,                       // SELECT
};

int8_t PREV_PAGES[] = {
	-1, // PAGE_MAINMENU
	PAGE_MAINMENU,		// PAGE_HAPTICS
	PAGE_MAINMENU,		// PAGE_VIBALERT
	PAGE_HAPTICS,		// PAGE_HAPT_CLICKS
	PAGE_HAPTICS,		// PAGE_HAPT_RAMPS
	PAGE_HAPTICS,		// PAGE_HAPT_OTHER
	PAGE_HAPTICS,		// PAGE_HAPT_ALERTS
	PAGE_HAPT_CLICKS,	// PAGE_CLKS_SINGLE
	PAGE_HAPT_CLICKS,	// PAGE_CLKS_DOUBLE
	PAGE_HAPT_CLICKS,	// PAGE_CLKS_TRIPLE 
	PAGE_CLKS_SINGLE,	// PAGE_CLKS_SG_STRONG
	PAGE_CLKS_SINGLE,	// PAGE_CLKS_SG_MEDIUM
	PAGE_CLKS_SINGLE,	// PAGE_CLKS_SG_SHARP
	PAGE_CLKS_SINGLE,	// PAGE_CLKS_SG_TRANS
	PAGE_CLKS_DOUBLE,	// PAGE_CLKS_DB_STRONG
	PAGE_CLKS_DOUBLE,	// PAGE_CLKS_DB_MEDIUM
	PAGE_CLKS_DOUBLE,	// PAGE_CLKS_DB_SHARP
	PAGE_HAPT_RAMPS,	// PAGE_RMPS_UP
	PAGE_HAPT_RAMPS,	// PAGE_RMPS_DOWN
	PAGE_RMPS_UP,		// PAGE_RMPS_UP_SHORT
	PAGE_RMPS_UP,		// PAGE_RMPS_UP_MEDIUM
	PAGE_RMPS_UP,		// PAGE_RMPS_UP_LONG
	PAGE_RMPS_DOWN,		// PAGE_RMPS_DW_SHORT
	PAGE_RMPS_DOWN,		// PAGE_RMPS_DW_MEDIUM
	PAGE_RMPS_DOWN,		// PAGE_RMPS_DW_LONG
	PAGE_HAPT_OTHER,	// PAGE_MORE_BUZZ
	PAGE_HAPT_OTHER,	// PAGE_MORE_BUMP
	PAGE_HAPT_OTHER,	// PAGE_MORE_PULSE
	PAGE_HAPT_OTHER,	// PAGE_MORE_HUM
	PAGE_MAINMENU,		// PAGE_DEBUG
	PAGE_VIBALERT,		// PAGE_VIBALERT_WAV
	PAGE_VIBALERT,		// PAGE_VIBALERT_PWR
	PAGE_VIBALERT,		// PAGE_VIBALERT_ON
	PAGE_VIBALERT,		// PAGE_VIBALERT_OFF
        PAGE_HAPTICS,		// PAGE_AUDIO
        PAGE_HAPTICS,		// PAGE_SELECT
};

// ---
// Haptic effect numbers
// -- 

// CLICKS
static const uint8_t clicks_single_strong[] PROGMEM = { 1, 2, 3, 17, 18, 19, 20 };
static const uint8_t clicks_single_medium[] PROGMEM = { 21, 22, 23 };
static const uint8_t clicks_single_sharp[]  PROGMEM = { 4, 5, 6, 7, 24, 25, 26 };      //Added effect 4!!!!
static const uint8_t clicks_single_trans[]  PROGMEM = { 58, 59, 60, 61, 62, 63 };

static const uint8_t clicks_double_strong[] PROGMEM = { 10, 11, 27, 28, 29, 37, 38, 39, 40 };    //added effects 10, 11
static const uint8_t clicks_double_medium[] PROGMEM = { 31, 32, 33, 41, 42, 43 };
static const uint8_t clicks_double_sharp[]  PROGMEM = { 30, 34, 35, 36, 44, 45, 46 };            // added 30

static const uint8_t clicks_triple[]       PROGMEM  = { 12 };

// RAMPS
static const uint8_t ramps_up_short[]       PROGMEM = { 86, 110, 87, 111, 92, 116, 93, 117 };
static const uint8_t ramps_up_medium[]      PROGMEM = { 84, 108, 85, 109, 90, 114, 91, 115 };
static const uint8_t ramps_up_long[]        PROGMEM = { 82, 106, 83, 107, 88, 112, 89, 113 };

static const uint8_t ramps_down_short[]     PROGMEM = { 74, 98, 75, 99, 80, 104, 81, 105 };
static const uint8_t ramps_down_medium[]    PROGMEM = { 72, 96, 73, 97, 78, 102, 79, 103 };
static const uint8_t ramps_down_long[]      PROGMEM = { 70, 94, 71, 95, 76, 100, 77, 101 };

// MORE EFFECTS
static const uint8_t more_buzz[]            PROGMEM = { 13, 14, 47, 48, 49, 50, 51, 118 };
static const uint8_t more_bump[]            PROGMEM = { 7, 8, 9 };
static const uint8_t more_pulse[]           PROGMEM = { 52, 53, 54, 55, 56, 57 };
static const uint8_t more_hum[]             PROGMEM = { 64, 65, 66, 67, 68, 69, 119, 120, 121, 122, 123 };

// ALERTS
static const uint8_t alerts[]              PROGMEM  = { 15, 16 };

//static uint8_t __attribute__ ((progmem)) alerts[]               = { 46, 47 };

#endif // include_menu_defs_h

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

#ifndef include_menu_h
#define include_menu_h

#include "Metro.h"

#define IS_LONG_PRESS(x) (x >= LONG_PRESS)

class Menu 
{
public:
	Menu();

	void	init();

	void	playLogo( Metro* timer );
	void	displayPage( uint8_t pageId );
	void	refresh();
//	uint8_t	input( KeyInfo* key, long heldTime );
	uint8_t	input( uint16_t ckey);
//	void	input( uint16_t ckey);

	bool	atPage( uint8_t pageId );
	int8_t	selectedTab();

private:
	void	drawTabs( uint8_t numTabs, uint8_t selTab );
	void	drawPage();
	void	drawDebugPage();

	void	getPageText( uint8_t lineNum, char* buffer, uint8_t selTab, char* data=0 );
	void	makeTimeMsg( uint8_t time, char* line );
	void	getEffect( uint8_t* effect, uint8_t pageId );
	bool	changePageVal( bool up );

	void	drawBar( uint8_t y, int filledPixels, bool selected );
	void	drawBottomBar();

	void	clearTmpBuf( uint8_t bufW, uint8_t bufH );
	void	flushTmpBuf( uint8_t x, uint8_t y, uint8_t bufW, uint8_t bufH );
	void	drawToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const uint8_t* data, uint8_t w, uint8_t h );
	void	printToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const char* text, uint8_t colour );

	void	flushIconTextLine( const uint8_t xPos, const uint8_t lineNum, char* text, uint8_t colour );

	void	getFullHapticTabName( char* buffer);

	void	playBasic();
};

// ---
// Page list
// ---
#define PAGE_MAINMENU			0	// The start page after the PMD logo
#define PAGE_HAPTICS			1	// Haptic Feedback
#define PAGE_VIBALERT			2	// Vibration Alerting
	    
#define PAGE_HAPT_CLICKS		3	// Haptic Feedback -> Clicks 
#define PAGE_HAPT_RAMPS			4	// Haptic Feedback -> Ramps
#define PAGE_HAPT_OTHER			5	// Haptic Feedback -> Other
#define PAGE_HAPT_ALERTS		6	// Haptic Feedback -> Alerts

#define PAGE_CLKS_SINGLE		7	// Clicks -> Single
#define PAGE_CLKS_DOUBLE		8	// Clicks -> Double
#define PAGE_CLKS_TRIPLE		9	// Clicks -> Triple
	    
#define PAGE_CLKS_SG_STRONG		10	// Clicks, Single -> Strong
#define PAGE_CLKS_SG_MEDIUM		11	// Clicks, Single -> Medium
#define PAGE_CLKS_SG_SHARP		12	// Clicks, Single -> Sharp
#define PAGE_CLKS_SG_TRANS		13	// Clicks, Single -> Transition
	    
#define PAGE_CLKS_DB_STRONG		14	// Clicks, Double -> Strong
#define PAGE_CLKS_DB_MEDIUM		15	// Clicks, Double -> Medium
#define PAGE_CLKS_DB_SHARP		16	// Clicks, Double -> Sharp
	    
#define PAGE_RMPS_UP			17	// Ramps -> Up
#define PAGE_RMPS_DOWN			18	// Ramps -> Down
	    
#define PAGE_RMPS_UP_SHORT		19	// Ramps, Up -> Short
#define PAGE_RMPS_UP_MEDIUM		20	// Ramps, Up -> Medium
#define PAGE_RMPS_UP_LONG		21	// Ramps, Up -> Long
	    
#define PAGE_RMPS_DW_SHORT		22	// Ramps, Down -> Short
#define PAGE_RMPS_DW_MEDIUM		23	// Ramps, Down -> Medium
#define PAGE_RMPS_DW_LONG		24	// Ramps, Down -> Long
	    
#define PAGE_MORE_BUZZ			25	// More -> Buzzes
#define PAGE_MORE_BUMP			26	// More -> Bumps
#define PAGE_MORE_PULSE			27	// More -> Pulses
#define PAGE_MORE_HUM			28	// More -> Hums

#define PAGE_DEBUG			29

#define PAGE_VIBALERT_WAV		30
#define PAGE_VIBALERT_PWR		31
#define PAGE_VIBALERT_ON		32
#define PAGE_VIBALERT_OFF		33


#define PAGE_AUDIO		        34  	    

#define PAGE_SELECT			35

#define NUM_PAGES			36

#endif // include_menus_h


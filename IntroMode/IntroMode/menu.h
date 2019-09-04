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
#define FLASH_SPEED	100.0f

class Menu 
{
private:
	int8_t	flashOn;
public:
	Menu();

	void	init();
	void	update();

	void	playLogo( Metro* timer );
	void	displayPage( uint8_t pageId );
	void	refresh();
//	void	input( KeyInfo* key, long heldTime );
  void  input( uint16_t ckey );

	bool	atPage( uint8_t pageId );
	int8_t	selectedTab();

private:
	void	drawPage();
	void	drawBottomLine( uint8_t override );

	void	clearTmpBuf( uint8_t bufW, uint8_t bufH );
	void	flushTmpBuf( uint8_t x, uint8_t y, uint8_t bufW, uint8_t bufH );
	void	drawToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const uint8_t* data, uint8_t w, uint8_t h );
	void	printToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const char* text, uint8_t colour );
};

// ---
// Page list
// ---
#define PAGE_MAINMENU			0	// The start page after the PMD logo
#define PAGE_QUICK_START		1
#define PAGE_HAPTIC_TUT			2
#define PAGE_VIBALERT_TUT		3
#define PAGE_DRV2605			4

#define NUM_PAGES			5

#endif // include_menus_h


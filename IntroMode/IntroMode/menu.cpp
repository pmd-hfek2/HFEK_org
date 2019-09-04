#include "menu.h"
#include "defs.h"
#include "icons.h"
#include "SSD1306LessRAM.h"
#include "glcdfont.h"
#include "menu_defs.h"
#include "debug.h"
#include "motor.h"

// Screen
SSD1306	oled( OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS );
Page*	currentPage = NULL;

// Useful for additive drawing
static uint8_t tempBuffer[ 256 ];

// For text printing
char lineBuf[ LINE_BUF_LEN ];

Menu::Menu()
{
	flashOn = -1;
}

void Menu::init()
{
	oled.ssd1306_init( SSD1306_SWITCHCAPVCC );
	oled.clear_display();
} // init

void Menu::refresh()
{
	drawPage();
} // refresh


void Menu::input( uint16_t  ckey )

{
	uint8_t keyPressEffect = 0;


		if( ckey == RIGHT )       //------------------------ RIGHT Key 
		{
			keyPressEffect = 1;
			if( currentPage->page != PAGE_MAINMENU && currentPage->tabs[ currentPage->selectedTab ]->moveOn == FLASH_MOVE_ON )
			{
				currentPage->tabs[ currentPage->selectedTab ]->moveOn = DONE_MOVE_ON;
			}
			
			if( ++currentPage->selectedTab >= currentPage->numTabs )
			{
				if( currentPage->page == PAGE_MAINMENU )
				{
					currentPage->selectedTab = 0;
				}
				else
				{
					keyPressEffect = 0;
					currentPage->selectedTab = currentPage->numTabs - 1;
				}
			}

			drawPage();
		}
		else if( ckey == LEFT )     //------------------------ LEFT Key
		{
			keyPressEffect = 1;
			if( --currentPage->selectedTab < 0 )
			{
				if( currentPage->page == PAGE_MAINMENU )
				{
					currentPage->selectedTab = currentPage->numTabs - 1;
				}
				else
				{
					keyPressEffect = 0;
					currentPage->selectedTab = 0;
				}
			}
			
			drawPage();
		}
		else if( ckey == SELECT ) //------------------------ SELECT Key
		{
			if( currentPage->page == PAGE_MAINMENU )
			{
				keyPressEffect = 1;
				displayPage( DEMO_PAGES[ currentPage->selectedTab ] );
			}
		}
		else if( ckey == BACK )   //-------------------------- BACK
		{
			if( currentPage->page != PAGE_MAINMENU )
			{
				keyPressEffect = 1;
				currentPage->selectedTab = 0;
				
				for( uint8_t i = 0 ; i < currentPage->numTabs ; ++i )
				{
					if( currentPage->tabs[ i ]->moveOn == DONE_MOVE_ON )
					{
						currentPage->tabs[ i ]->moveOn = FLASH_MOVE_ON;
					} 
					else if( currentPage->tabs[ i ]->moveOn == DONE_FLASH_PLAY )
					{
						currentPage->tabs[ i ]->moveOn = FLASH_PLAY;
					}
				}
				
				displayPage( PAGE_MAINMENU );
			}
		}
		else if( ckey == PLAY )     //---------------------------PLAY 
		{
			if( currentPage->page != PAGE_MAINMENU && currentPage->tabs[ currentPage->selectedTab ]->moveOn == FLASH_PLAY )
			{
				currentPage->tabs[ currentPage->selectedTab ]->moveOn = DONE_FLASH_PLAY;
			}
			
			if( currentPage->tabs[ currentPage->selectedTab ]->numData > 0 )
			{
				motor.playKeyPress( SHORT_PRESS_EFF );
			}
			
			for( uint8_t i = 0 ; i < currentPage->tabs[ currentPage->selectedTab ]->numData ; ++i )
			{
				uint8_t* data = (uint8_t*)pgm_read_word( &(EFFECTS_DATA[ currentPage->tabs[ currentPage->selectedTab ]->data[ i ] ] ) );
				
				uint8_t value = pgm_read_byte( &(data[ 0 ]) );
				unsigned long delayTime = 0;
				
				if( value == VIB_ALERT )
				{
					Serial.println( "Playing vib alert " );
					Serial.println( pgm_read_byte( &(data[ 1 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 2 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 3 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 4 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 5 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 6 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 7 ]) ) );

					motor.selectMotor( pgm_read_byte( &(data[ 1 ]) ) );

					motor.playVibAlert( 
						pgm_read_byte( &(data[ 5 ]) ),		// Waveform
						pgm_read_byte( &(data[ 4 ]) ),		// Power
						pgm_read_byte( &(data[ 2 ]) ),		// On time
						pgm_read_byte( &(data[ 3 ]) ),		// Off time
						pgm_read_byte( &(data[ 6 ]) ) );	// Cycles
					
					delayTime = pgm_read_byte( &(data[ 7 ]) );
				}
				else if( value == HAPTIC )
				{
					Serial.println( F("Playing haptic effect ") );
					Serial.println( pgm_read_byte( &(data[ 1 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 2 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 3 ]) ) );
					Serial.println( pgm_read_byte( &(data[ 4 ]) ) );
					
					value = pgm_read_byte( &(data[ 1 ]) );
					if( value == 4 )
					{
						motor.selectMotor( 3 );
						motor.playKeyPress( pgm_read_byte( &(data[ 3 ]) ) );
					}
					else
					{
						motor.selectMotor( value );
						motor.playFullHaptic( pgm_read_byte( &(data[ 2 ]) ), pgm_read_byte( &(data[ 3 ]) ) );
					}
					
					delayTime = pgm_read_byte( &(data[ 4 ]) );
				}
				
				delayTime *= 100;
				delay( delayTime );
			}
		}
		
		if( keyPressEffect )
		{
			motor.playKeyPress( SHORT_PRESS_EFF );
		}
	
	
} // input

void Menu::update()
{
	drawBottomLine( 0 );
}

void Menu::playLogo( Metro* timer )
{
	// Start the logo off screen (by 1 pixel)
	uint8_t counter = SSD1306_LCDWIDTH;
	
	// Find the coordinates for the logo to be centered
	uint8_t x = ( SSD1306_LCDWIDTH - LOGO_WIDTH ) / 2;
	uint8_t y = ( SSD1306_LCDHEIGHT - LOGO_HEIGHT ) / 2;
	
	oled.clear_display();
	timer->interval( 32 );
	timer->reset();

	while( counter > x ) 
	{
		if( 1 == timer->check() )
		{
			oled.drawbitmap( counter, y, PMD_LOGO_GLCD_BMP, LOGO_WIDTH, LOGO_HEIGHT, WHITE );
			counter -= ANIM_SPEED;
		}
	}
	
	oled.drawbitmap( x, y,	PMD_LOGO_GLCD_BMP, LOGO_WIDTH, LOGO_HEIGHT, WHITE );
	
	// Display for 2 seconds
	timer->interval( 100 );
	timer->reset();
	counter = 20;
	while( counter	> 0 )
	{
		if( 1 == timer->check() ) {
			--counter;
		}
	}
	
	oled.clear_display();
	
	// Tidy up
	timer->reset();
} // playLogo

void Menu::displayPage( uint8_t pageId )
{
	if( pageId != currentPage->page )
	{
		currentPage = &(pages[ pageId ]);
	}

	drawPage();
} // displayPage

bool Menu::atPage( uint8_t pageId )
{
	return currentPage && currentPage->page == pageId;
} // atPage

int8_t Menu::selectedTab()
{
	if( currentPage )
		return currentPage->selectedTab;
	else
		return 0;
} // selectedTab

void Menu::drawPage()
{
  
	if( NULL == currentPage )
		return;
	
 	// Title
 
     char* str = (char*)pgm_read_word( &(MENU_STRS[ currentPage->tabs[ currentPage->selectedTab ]->titleIndex ]) );
     
  //   Serial.println( currentPage->selectedTab);  //ok 0-3 for main
      
     Serial.println( currentPage->tabs[ currentPage->selectedTab ]->titleIndex);  //ok 0-3 for main
      
	sprintf_P( lineBuf, str );
	uint8_t len = strlen( lineBuf ) * 6;
	oled.clear_buf();
	oled.drawstring( (LOGO_WIDTH-len)/2, 0, lineBuf, WHITE );
	
	// Text lines

	for( uint8_t i = 0 ; i < 5 ; ++i )
	{
		str = (char*)pgm_read_word( &(MENU_STRS[ currentPage->tabs[ currentPage->selectedTab ]->textIndices[ i ] ]) );
		sprintf_P( lineBuf, str );
		len = strlen( lineBuf ) * 6;
		oled.clear_buf();
		oled.drawstring( (LOGO_WIDTH-len)/2, i + 2, lineBuf, WHITE );
	}


	
	drawBottomLine( 1 );
	
} // drawPage

void Menu::drawBottomLine( uint8_t override )
{
	uint8_t flash = sin( millis() / FLASH_SPEED ) > 0.0f ? 1 : 0;
	if( currentPage->page == PAGE_MAINMENU )
		flash = 0;

	if( !override && flash == flashOn )
		return;
		
	flashOn = flash;

	uint8_t moveOn = currentPage->tabs[ currentPage->selectedTab ]->moveOn;
		
	// Bottom line	
	clearTmpBuf( SSD1306_LCDWIDTH, 8 );
	
	if( currentPage->page == PAGE_MAINMENU || currentPage->selectedTab > 0 )
	{
		lineBuf[ 0 ] = '<';
		lineBuf[ 1 ] = '-';
		lineBuf[ 2 ] = '\0';
		printToTmpBuf( SSD1306_LCDWIDTH, 8, 0, 0, lineBuf, WHITE );
	}
	
	if( currentPage->page != PAGE_MAINMENU && (moveOn == FLASH_PLAY || moveOn == DONE_FLASH_PLAY || currentPage->selectedTab == currentPage->numTabs - 1) )
	{
		uint8_t col = WHITE;
		if( moveOn == FLASH_PLAY || (moveOn == DONE_FLASH_PLAY && currentPage->selectedTab != currentPage->numTabs - 1) )
		{
			lineBuf[ 0 ] = ' ';
			lineBuf[ 1 ] = 'P';
			lineBuf[ 2 ] = 'L';
			lineBuf[ 3 ] = 'A';
			lineBuf[ 4 ] = 'Y';
			lineBuf[ 5 ] = ' ';
			lineBuf[ 6 ] = '\0';
			if( moveOn == FLASH_PLAY && flash )
				col = BLACK;
		}
		else
		{
			if( flash )
				col = BLACK;
		}
			
		printToTmpBuf( SSD1306_LCDWIDTH, 8, ( SSD1306_LCDWIDTH - ( strlen( lineBuf ) * 6 ) ) / 2, 0, lineBuf, col );
	}
	
	if( currentPage->page == PAGE_MAINMENU || currentPage->selectedTab < currentPage->numTabs - 1 )
	{
		lineBuf[ 0 ] = '-';
		lineBuf[ 1 ] = '>';
	  lineBuf[ 2 ] = '\0';

    
		uint8_t col = (moveOn == FLASH_MOVE_ON || moveOn == DONE_FLASH_PLAY) &&	flash ? BLACK : WHITE;
			
		printToTmpBuf( SSD1306_LCDWIDTH, 8, SSD1306_LCDWIDTH - 12, 0, lineBuf, col );
	}
	
	
	flushTmpBuf( 0, SSD1306_LCDHEIGHT - 8, SSD1306_LCDWIDTH, 8 );	
}

// Helper functions
void Menu::clearTmpBuf( uint8_t bufW, uint8_t bufH ) 
{
	memset( &(tempBuffer[ 0 ]), 0x00, sizeof( uint8_t ) * bufW * bufH / 8 );
} // clearTmpBuf

void Menu::flushTmpBuf( uint8_t x, uint8_t y, uint8_t bufW, uint8_t bufH )
{
	oled.clear_buf();
	oled.drawbitmap( x, y, tempBuffer, bufW, bufH, WHITE, false );
} // flushTmpBuf

// Copy from a data source (usually an icon array) to the tmp buffer, so that a single draw call can be made to the oled.
void Menu::drawToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const uint8_t* data, uint8_t w, uint8_t h )
{
	bufH /= 8;
	h /= 8;
	y /= 8;
	
	for( uint8_t i = 0 ; i < h ; ++i ) 
	{
		for( uint8_t j = 0 ; j < w ; ++j )
		{
			tempBuffer[ ( ( i + y ) * bufW ) + j + x ] |= pgm_read_byte( &(data[ ( i * w ) + j ]) );
		}
	}
} // drawToTmpBuf

// Add some text to the temp buffer. Lets us draw text over items
void Menu::printToTmpBuf( uint8_t bufW, uint8_t bufH, uint8_t x, uint8_t y, const char* text, uint8_t colour )
{
	y -= 8;
	
	uint8_t c, top, bottom, mod = y % 8;
	y /= 8;
	
	while( text[ 0 ] != '\0' )
	{
		for( uint8_t i = 0 ; i < 5 ; ++i ) 
		{
			c = pgm_read_byte( font + ( text[ 0 ] * 5 ) + i );
			
			bottom = c >> mod;
			top = c - (bottom << mod);
			top <<= (8 - mod);
			
			//tempBuffer[ ( y * bufW ) + x ] |= colour == WHITE ? top :~top;
			tempBuffer[ ( (y + 1) * bufW ) + x ] |= colour == WHITE ? bottom : ~bottom;
			++x;
		}
		++text;
	}
} // printToTmpBuf

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
uint8_t	lastEffect = 1;
bool	inTab = false;

// Useful for additive drawing, which is currently not supported in the SSD1306 class
// Move into SSD1306 to stop using these 256 bytes
static uint8_t tempBuffer[ 256 ];

// For text printing
char lineBuf[ LINE_BUF_LEN ];

Menu::Menu()
{
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


uint8_t Menu::input( uint16_t ckey ){
  
	uint8_t keyPressEffect = 0;

	if( NULL == currentPage ) return keyPressEffect;

  		if( ckey == RIGHT ){
			// Either increase the tab value if we are "in" the tab, or scroll to the next tab
			if( inTab ){
  
				changePageVal( true );
				drawPage();
			}else{
				if( ++currentPage->selectedTab >= currentPage->numTabs )
					//currentPage->selectedTab = 0;
                                        currentPage->selectedTab = currentPage->numTabs-1;
				displayPage( currentPage->page );
			}

			keyPressEffect = 1;
		}
                else if( ckey == LEFT )
		{
			// Either decrease the tab value if we are "in" the tab, or scroll to the previous tab
			if( inTab )
			{
				changePageVal( false );
				drawPage();
			}
			else
			{
				if( --currentPage->selectedTab < 0 )
					//currentPage->selectedTab = currentPage->numTabs - 1;
                                        currentPage->selectedTab = 0;
				displayPage( currentPage->page );
			}

			keyPressEffect = 1;
		}
		else if( ckey == SELECT && PAGE_DEBUG != currentPage->page )
		{
                        if (!SELECT_BAR_DATA[ DATA_VAL ])
                            motor.setupKeyMotor(  KEY_MOTOR_LRA);
                        else motor.setupKeyMotor( KEY_MOTOR_ERM );   
  
                      //  Serial.println(currentPage->selectedTab);
                      //  Serial.println(currentPage->page);
                        
			if( TT_LEAF == currentPage->tabs[ currentPage->selectedTab ]->type )
			{
                          	// If we're in a leaf tab, we'll be selecting a haptic effect, so work out what it is
				getEffect( &lastEffect, currentPage->page );
				drawPage();
				keyPressEffect = 1;
			}
			else if( TT_NONE != currentPage->tabs[ currentPage->selectedTab ]->type )
			{
                               
				// If it's any other valid type of tab, we can modify the data value, so go "into" the tab
				inTab = true;
				drawPage();
				keyPressEffect = 1;
			}
			else if( NULL != NEXT_PAGES[ currentPage->page ] )
			{
                               
				// If it's a tab of type none, and we have a valid next page, go to that page
				Page* nextPage = &(pages[ NEXT_PAGES[ currentPage->page ][ currentPage->selectedTab ] ]);
						
				inTab = nextPage->numTabs == 1 && nextPage->tabs[ 0 ]->type != TT_NONE;
						
				displayPage( NEXT_PAGES[ currentPage->page ][ currentPage->selectedTab ] );
				keyPressEffect = 1;
			}
		}
		else if( ckey == BACK )
		{
			// Either stop being "in" a tab, or go to the previous page
			if( inTab && currentPage->numTabs > 1 )
			{
				inTab = false;
				drawPage();
				keyPressEffect = 1;
			}
			else if( currentPage->page != PAGE_MAINMENU )
			{
				inTab = false;
				displayPage( PREV_PAGES[ currentPage->page ] );
				keyPressEffect = 1;
			}
		}
		else if( ckey == PLAY )
		{
  
                   //     Serial.println("Sel.Page");
                   //     Serial.println(currentPage->page);
                   //     Serial.println("Sel.tab");
                   //     Serial.println(currentPage->selectedTab);
  
  
			if( TT_LEAF == currentPage->tabs[ currentPage->selectedTab ]->type )
			{
				// Play the effect we are currently looking at, but make sure to look it up first
				getEffect( &lastEffect, currentPage->page );
				drawPage();
				motor.playFullHaptic( LIB_BAR_DATA[ DATA_VAL ], lastEffect );
				keyPressEffect = 0;
			}
			else if( PAGE_VIBALERT == currentPage->page || PAGE_VIBALERT_WAV == currentPage->page || PAGE_VIBALERT_PWR == currentPage->page || PAGE_VIBALERT_ON == currentPage->page || PAGE_VIBALERT_OFF == currentPage->page )
			{
				playBasic();
			}

 



			else if( PAGE_MAINMENU == currentPage->page )
			{
                      
				
                                // If we're at the main menu, pressing play will do the last haptic effect or a basic vibalert depending on which tab we are looking at
				switch( currentPage->selectedTab )
				{
					case 0:	motor.playFullHaptic( LIB_BAR_DATA[ DATA_VAL ], lastEffect );	break;	// selctedTab = 0 if True Haptics menu/tab
					case 1:	playBasic();	break;	// selctedTab = 1 if Vibrating Alerts
                                       // case 
				}
			
			}
			else if( PAGE_DEBUG != currentPage->page )
			{
				// Must be a haptics menu selecte

                                if (currentPage->selectedTab == 5)    //if in Audio to Haptic
                                {
                                  
/*                                        if(  motor.isPlayingAudio()){   
                                           motor.StopAudio2Haptic();
                            
                                      }else {
*/
                                           motor.Audio2Haptic( true );   //short click on LRA on shield
                              //        }
                                 }else{
                             
                        				    motor.playFullHaptic( LIB_BAR_DATA[ DATA_VAL ], lastEffect );
                        				    keyPressEffect = 1;
                              }	        	
                    }
		}//else if key == PLAY

	//} //if key down
	
	return keyPressEffect;
} // input

void Menu::playBasic()
{
	uint8_t waveform = WAV_BAR_DATA[ DATA_VAL ];
	uint8_t pwr = pgm_read_byte( &powers[ PWR_BAR_DATA[ DATA_VAL ] ] );
	uint8_t onTime = pgm_read_byte( &onTimes[ BASIC_ON_TIME_DATA[ DATA_VAL ] ] );
	uint8_t offTime = pgm_read_byte( &offTimes[ BASIC_OFF_TIME_DATA[ DATA_VAL ] ] );
		
	motor.playVibAlert( waveform, pwr, onTime, offTime );
} // playBasic

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

//---------------------------------------------------------------------------------

void Menu::displayPage( uint8_t pageId )
{
	if( pageId != currentPage->page )
	{
		currentPage = &(pages[ pageId ]);
	}

	if( pageId == PAGE_DEBUG )
	{
		// Special case for debug page, as it's not rendered in the same way
		drawTabs( 1, 0 );
		drawDebugPage();
	}
	else
	{
		drawTabs( currentPage->numTabs, currentPage->selectedTab );
		drawPage();
	}
} // displayPage

bool Menu::atPage( uint8_t pageId )
{
	return currentPage && currentPage->page == pageId;
}

int8_t Menu::selectedTab()
{
	if( currentPage )
		return currentPage->selectedTab;
	else
		return 0;
}

void Menu::drawTabs( uint8_t numTabs, uint8_t selTab )
{
	if( NULL == currentPage )
		return;

	uint8_t i = 0;
	uint8_t bW = SSD1306_LCDWIDTH, bH = TAB_END_HEIGHT;
	uint8_t x = 0, tsY = bH - TAB_SMALL_HEIGHT, tY = bH - TAB_END_HEIGHT;

	if( currentPage->tabs[ selTab ]->type == TT_LEAF )
		getFullHapticTabName( lineBuf );
	else
		strcpy_P( lineBuf, (char*)pgm_read_word( &(MENU_STRS[ currentPage->tabs[ selTab ]->titleIndex ]) ) );
	
	clearTmpBuf( bW, bH );

	// Additive rendering
	
	// Draw left tabs
	for( ; i < selTab ; ++i )
	{
		drawToTmpBuf( bW, bH, x, tsY, TAB_LEFT, TAB_SMALL_WIDTH, TAB_SMALL_HEIGHT );
		x += TAB_SMALL_WIDTH - 3;
	}
	
	++x;
	
	// Draw current tab
	// - Left end
	drawToTmpBuf( bW, bH, x, tY, TAB_FULL_LEFT, TAB_END_WIDTH, TAB_END_HEIGHT );
	x += TAB_END_WIDTH;
	// - Tab title
	printToTmpBuf( bW, bH, x + (TAB_PX_WIDTH / 2) - (strlen(lineBuf)*3), bH - 4, lineBuf, WHITE );
	// - Middle section
	for( uint8_t w = 0 ; w < TAB_PX_WIDTH ; ++w )
	{
		drawToTmpBuf( bW, bH, x, tY, TAB_FULL_MID, TAB_MID_WIDTH, TAB_MID_HEIGHT );
		x += TAB_MID_WIDTH;
	}
	// - Right end
	drawToTmpBuf( bW, bH, x, tY, TAB_FULL_RIGHT, TAB_END_WIDTH, TAB_END_HEIGHT );
	++i;
	x += TAB_END_WIDTH - 2;
	
	// Draw right tabs
	for( ; i < numTabs ; ++i ) 
	{
		drawToTmpBuf( bW, bH, x, tsY, TAB_RIGHT, TAB_SMALL_WIDTH, TAB_SMALL_HEIGHT );
		x += TAB_SMALL_WIDTH - 3;
	}
	
	// Draw a bar at the bottom of the tabs
	uint8_t y = ( bH / 8 ) - 1;
	y *= bW;
	for( i = 0 ; i < bW ; ++i )
	{
		tempBuffer[ y + i ] |= 0x80;
	}
	
	flushTmpBuf( 0, 0, bW, bH );
} // drawTabs

//-------------------------------------------------------------------------------------------------------

void Menu::drawPage()
{
  
//    Serial.println(currentPage->selectedTab);
//    Serial.println(currentPage->page);
  
	if( NULL == currentPage )
		return;

	uint8_t xPos = ICON_WIDTH + 2;
	uint8_t i;
	char temp[ 12 ];

	static const char pwr[] PROGMEM ={'%','u','%','%','\0'}; 

	if( currentPage->page == PAGE_MAINMENU )
	{
		// Main menu, just show the lines

  
        		for( uint8_t i = 0 ; i < 4 ; ++i )
        		{
        			getPageText( i, lineBuf, currentPage->selectedTab );
        			flushIconTextLine( xPos, i, lineBuf, WHITE );
        		}
               
	}
	else if( currentPage->page == PAGE_VIBALERT ||
			 currentPage->page == PAGE_VIBALERT_WAV ||
			 currentPage->page == PAGE_VIBALERT_PWR ||
			 currentPage->page == PAGE_VIBALERT_ON ||
			 currentPage->page == PAGE_VIBALERT_OFF  )
	{
		if( motor.getMotorId()==3 )
		{			  
			// LRA not supported for basic effects
			const char* str = (char*)pgm_read_word( &(WAVE_STRS[ 4 ]) );
			sprintf_P( lineBuf, str );
			flushIconTextLine( xPos, 0, lineBuf, WHITE );
		}
		else
		{ 
			const char* str = (char*)pgm_read_word( &(WAVE_STRS[ WAV_BAR_DATA[ DATA_VAL ] ]) );	//this take string sqr. sin. tri. saw.  !!! formatter %s
			sprintf(temp, motor.getMotorName() );		//get motor number
			sprintf_P( lineBuf, str , temp);
			flushIconTextLine( xPos, 0, lineBuf, WHITE );
		}
		
		// - Power
		sprintf_P( temp, pwr, pgm_read_byte( &powers[ PWR_BAR_DATA[ DATA_VAL ] ] ) );
		getPageText( 1, lineBuf, currentPage->selectedTab, temp );
		flushIconTextLine( xPos, 1, lineBuf, WHITE );
		// - On time
		makeTimeMsg( pgm_read_byte( &onTimes[ BASIC_ON_TIME_DATA[ DATA_VAL ] ] ), temp );
		getPageText( 2, lineBuf, currentPage->selectedTab, temp );
		flushIconTextLine( xPos, 2, lineBuf, WHITE );
		// - Off time
		makeTimeMsg( pgm_read_byte( &offTimes[ BASIC_OFF_TIME_DATA[ DATA_VAL ] ] ), temp );
		getPageText( 3, lineBuf, currentPage->selectedTab, temp );
		flushIconTextLine( xPos, 3, lineBuf, WHITE );
	}
	else 
	{
		// Haptic Feedback ------------------

    // - Library
		sprintf_P( temp, pwr, LIB_BAR_DATA[ DATA_VAL ] );  // DATA_VAL - 0
		temp[ strlen( temp ) - 1 ] = '\0';	// Remove %
		getPageText( 0, lineBuf, currentPage->selectedTab, temp );
		flushIconTextLine( xPos, 0, lineBuf, WHITE );
		
		// - Effect
		sprintf_P( temp, pwr, lastEffect );
		temp[ strlen( temp ) - 1 ] = '\0';	// Remove %
		getPageText( 1, lineBuf, currentPage->selectedTab, temp );
		flushIconTextLine( xPos, 1, lineBuf, WHITE );
		
		// - Motor
  /*  if(currentPage->selectedTab == 6){      //Select LRA or ERM
                  
          lineBuf[ 0 ] = '\0';
          flushIconTextLine( xPos, 2, lineBuf, WHITE );            
     
     }else{
    */ 
		      sprintf( temp, motor.getMotorName() );
          temp[ strlen( temp ) - 1 ] = '\0';  // Remove %
		      getPageText( 2, lineBuf, currentPage->selectedTab, temp );
		      flushIconTextLine( xPos, 2, lineBuf, WHITE );
//		}
    
    // - 4th line 
 	
 			if(( motor.getMotorId()==3)&&(currentPage->selectedTab != 5)){			  // if selected LRA and not Audio- LRA uses lib. 6
    		  const char* str = (char*)pgm_read_word( &(TAB_STRS[19 ]) );
    			sprintf_P( lineBuf, str, NULL);	
    			flushIconTextLine( xPos, 3, lineBuf, WHITE );
						
       }else{                                                               //for Haptic added 4th line for ERM or LRA on shield info

          const char*  str = (char*)pgm_read_word( &(SELECT_STRS[motor.getKeyMotorId()]) );  //this take string sqr. sin. tri. saw.  !!! formatter %s
     	    //const char* str = (char*)pgm_read_word( &(SELECT_STRS[ SELECT_BAR_DATA[ DATA_VAL] + 2 ]) );  //this take string sqr. sin. tri. saw.  !!! formatter %s
                     
            sprintf_P( lineBuf, str);                           
 			      
 			      //  const char* str = (char*)pgm_read_word( &(TAB_STRS[25]) );
 			      //  sprintf_P( lineBuf, str, NULL );
 
 			        flushIconTextLine( xPos, 3, lineBuf, WHITE );
			}
         
     //5-th   
/*
       if(currentPage->selectedTab == 5){
           
          str = (char*)pgm_read_word( &(TAB_STRS[27 ]) );
          sprintf_P( lineBuf, str, NULL); 
          oled.clear_buf();
          oled.drawstring( 10,6,lineBuf, BLACK);
      
      }else{  
              oled.clear_buf();
              oled.displayLine( 6 );
      }
 */

           
   }

	drawBottomBar();
} // drawPage

// Draws the bottom of the screen, depending on the tab type
void Menu::drawBottomBar()
{
	uint8_t data;
	switch( currentPage->tabs[ currentPage->selectedTab ]->type )
	{
		case TT_BAR:
			{
				data = currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] - currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_MIN ];
				data = (data * SSD1306_LCDWIDTH) / (currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_MAX ] - currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_MIN ]);

				drawBar( SSD1306_LCDHEIGHT - 8, data, inTab );
			}
			break;

		case TT_PWR_BAR:
			{
				data = pgm_read_byte( &powers[ currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] ] );
				data = (data * SSD1306_LCDWIDTH) / 100;
				drawBar( SSD1306_LCDHEIGHT - 8, data, inTab );
			}
			break;

		case TT_OFF_TIME:
			if( inTab )
			{
				data = 0;
				oled.clear_buf();
				
				for( uint8_t i = 0 ; i < NUM_OFF ; ++i )
				{
					makeTimeMsg( pgm_read_byte( &offTimes[ i ] ), lineBuf );

					oled.drawstring( 
						data,	// xPos
						7,		// Line
						lineBuf[ 0 ] == '0' ? &(lineBuf[ 1 ]) : lineBuf, 
						i == currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] ? BLACK : WHITE );

					data += ((strlen( lineBuf ) - 1) * 5) + 3;
				}
				break;
			}
			// else fall through

		case TT_ON_TIME:
			if( inTab )
			{
				data = 0;
				oled.clear_buf();
				
				for( uint8_t i = 0 ; i < NUM_ON ; ++i )
				{
					makeTimeMsg( pgm_read_byte( &onTimes[ i ] ), lineBuf );

					oled.drawstring( 
						data,	// xPos
						7,		// Line
						lineBuf[ 0 ] == '0' ? &(lineBuf[ 1 ]) : lineBuf, 
						i == currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] ? BLACK : WHITE );

					data += ((strlen( lineBuf ) - 1) * 5) + 4;
				}
				break;
			}
			// else fall through
			
		case TT_WAVE:
			if( inTab )
			{
				data = 0;
				oled.clear_buf();
				
				for( uint8_t i = 0 ; i < 4 ; ++i )
				{
					const char* str = (char*)pgm_read_word( &(WAVE_STRS[ i ]) );
					sprintf_P( lineBuf, str, "" );	// This string is a formatter, so give it an empty string
					lineBuf[ 3 ] = '\0';

					oled.drawstring( 
						data,	// xPos
						7,		// Line
						lineBuf, 
						i == currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] ? BLACK : WHITE );
					//	Serial.println( currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] );

					data += (strlen( lineBuf ) * 5) + 18;
				}
				break;
			}
			// else fall through
		
      case TT_SELECT:
			if( inTab )
			{
				data = 0;
				oled.clear_buf();
				
				for( uint8_t i = 0 ; i < 2 ; ++i )
				{
					const char* str = (char*)pgm_read_word( &(SELECT_STRS[ i ]) );
					sprintf_P( lineBuf, str, "" );	// This string is a formatter, so give it an empty string
					lineBuf[ 3 ] = '\0';

					oled.drawstring( 
						data,	// xPos
						7,		// Line
						lineBuf, 
						i == currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] ? BLACK : WHITE );
						//Serial.println( currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] );

					data += (strlen( lineBuf ) * 5) + 18;
				}
				break;
			}
			// else fall through

		default:
			// Clear the line
			oled.clear_buf();
			oled.displayLine( 7 );

	}
} // drawPage

bool Menu::changePageVal( bool up )
{
	bool isPWR = TT_PWR_BAR == currentPage->tabs[ currentPage->selectedTab ]->type;
	switch( currentPage->tabs[ currentPage->selectedTab ]->type )
	{
		case TT_PWR_BAR:
		case TT_ON_TIME:
		case TT_OFF_TIME:
		case TT_BAR:
		case TT_WAVE:
                case TT_SELECT:
			if( up && currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] < currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_MAX ] )
			{
				// Incr if < max
				currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] += currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_DELTA ];
			}
			else if( !up && currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] > currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_MIN ] )
			{
				// Decr if > min
				currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_VAL ] -= currentPage->tabs[ currentPage->selectedTab ]->data[ DATA_DELTA ];
			}
			return true;
			break;
	}
	
	return false;
} // changePageVal

void Menu::getEffect( uint8_t* effect, uint8_t pageId )
{
	switch( pageId )
	{
		case PAGE_HAPT_ALERTS:		*effect = pgm_read_byte_near( alerts + currentPage->selectedTab );			break;
		case PAGE_CLKS_TRIPLE:		*effect = pgm_read_byte_near( clicks_triple + currentPage->selectedTab );		break;
		case PAGE_CLKS_SG_STRONG:	*effect = pgm_read_byte_near( clicks_single_strong + currentPage->selectedTab );	break;
		case PAGE_CLKS_SG_MEDIUM:	*effect = pgm_read_byte_near( clicks_single_medium + currentPage->selectedTab );	break;
		case PAGE_CLKS_SG_SHARP:	*effect = pgm_read_byte_near( clicks_single_sharp + currentPage->selectedTab );	        break;
		case PAGE_CLKS_SG_TRANS:	*effect = pgm_read_byte_near( clicks_single_trans + currentPage->selectedTab );	        break;
		case PAGE_CLKS_DB_STRONG:	*effect = pgm_read_byte_near( clicks_double_strong + currentPage->selectedTab );	break;
		case PAGE_CLKS_DB_MEDIUM:	*effect = pgm_read_byte_near( clicks_double_medium + currentPage->selectedTab );	break;
		case PAGE_CLKS_DB_SHARP:	*effect = pgm_read_byte_near( clicks_double_sharp + currentPage->selectedTab );	        break;
		case PAGE_RMPS_UP_SHORT:	*effect = pgm_read_byte_near( ramps_up_short + currentPage->selectedTab );		break;
		case PAGE_RMPS_UP_MEDIUM:	*effect = pgm_read_byte_near( ramps_up_medium + currentPage->selectedTab );		break;
		case PAGE_RMPS_UP_LONG:		*effect = pgm_read_byte_near( ramps_up_long + currentPage->selectedTab );		break;
		case PAGE_RMPS_DW_SHORT:	*effect = pgm_read_byte_near( ramps_down_short + currentPage->selectedTab );		break;
		case PAGE_RMPS_DW_MEDIUM:	*effect = pgm_read_byte_near( ramps_down_medium + currentPage->selectedTab );	        break;
		case PAGE_RMPS_DW_LONG:		*effect = pgm_read_byte_near( ramps_down_long + currentPage->selectedTab );		break;
		case PAGE_MORE_BUZZ:		*effect = pgm_read_byte_near( more_buzz + currentPage->selectedTab );		        break;
		case PAGE_MORE_BUMP:		*effect = pgm_read_byte_near( more_bump + currentPage->selectedTab );		        break;
		case PAGE_MORE_PULSE:		*effect = pgm_read_byte_near( more_pulse + currentPage->selectedTab );		        break;
		case PAGE_MORE_HUM: 		*effect = pgm_read_byte_near( more_hum + currentPage->selectedTab );			break;
	}
}	//getEffect

void Menu::drawDebugPage()
{
	for( uint8_t i = 0 ; i < 4 ; ++i )
	{
		getPageText( i, lineBuf, 0 );
		oled.clear_buf();
		oled.displayLine( i + 2 );
		oled.drawstring( 0, i + 2, lineBuf, i == currentPage->selectedTab ? BLACK : WHITE );
	}
} // drawDebugPage

void Menu::getPageText( uint8_t lineNum, char* buffer, uint8_t selTab, char* data )
{
	const char* str = (char*)pgm_read_word( &(TAB_STRS[ currentPage->tabs[ selTab ]->textIndices[ lineNum ] ]) );
	sprintf_P( buffer, str, data );
} // getPageText

void Menu::makeTimeMsg( uint8_t time, char* line )
{
	static const char i[] PROGMEM ={'%','0','2','.','2','u','s','\0'};	
	static const char f[] PROGMEM ={'0','.','%','1','.','1','u','s','\0'}; 

	if( time < 10 )
	{
		sprintf_P( line, f, time % (uint8_t)10 );
	}
	else
	{
		sprintf_P( line, i, time / (uint8_t)10 );
	}
} // makeTimeMsg

void Menu::drawBar( uint8_t y, int filledPixels, bool selected ) 
{
	uint8_t on = selected ? 0xFF : 0x7E;
	uint8_t off = selected ? 0x81 : 0x18;
	
	clearTmpBuf( SSD1306_LCDWIDTH, 8 );
	for( uint8_t i = 0 ; i < SSD1306_LCDWIDTH ; ++i )
	{
		tempBuffer[ i ] = i < filledPixels ? on : off;
	}
	tempBuffer[ 0 ] = tempBuffer[ SSD1306_LCDWIDTH - 1 ] = 0xFF;
	flushTmpBuf( 0, y, SSD1306_LCDWIDTH, 8 );
} // draw_bar

void Menu::flushIconTextLine( const uint8_t xPos, const uint8_t lineNum, char* text, uint8_t colour )
{
	// Renders a single line with the SSD1306 with both the icon and the text. Allows us to show both on the same line
	uint8_t bW = SSD1306_LCDWIDTH, bH = 8;
	clearTmpBuf( bW, bH );
	
	uint8_t w, y = lineNum + 2;
	
	if( NULL != currentPage->tabs[ currentPage->selectedTab ]->icon )
	{
		w = currentPage->tabs[ currentPage->selectedTab ]->icon->width;
		drawToTmpBuf( bW, bH, 0, 0, &(currentPage->tabs[ currentPage->selectedTab ]->icon->image[ ( w * lineNum ) ]), w, 8 );
	}
	
	printToTmpBuf( bW, bH, xPos, 0, text, colour );
	
	flushTmpBuf( 0, y * 8, bW, bH );
} // flushIconTextLine

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
			
			tempBuffer[ ( y * bufW ) + x ] |= colour == WHITE ? top :~top;
			tempBuffer[ ( (y + 1) * bufW ) + x ] |= bottom;
			++x;
		}
		++x;
		++text;
	}
} // printToTmpBuf

void Menu::getFullHapticTabName( char* buffer)
{
	char temp[ 32 ];
	const char* str;
	switch( currentPage->page )
	{
		case PAGE_HAPT_ALERTS:		str = (char*)pgm_read_word( &(MENU_STRS[ 9 ]) );	break;
		case PAGE_CLKS_TRIPLE:		str = (char*)pgm_read_word( &(MENU_STRS[ 12 ]) );	break;
		case PAGE_CLKS_SG_STRONG:	str = (char*)pgm_read_word( &(MENU_STRS[ 19 ]) );	break;
		case PAGE_CLKS_SG_MEDIUM:	str = (char*)pgm_read_word( &(MENU_STRS[ 20 ]) );	break;
		case PAGE_CLKS_SG_SHARP:	str = (char*)pgm_read_word( &(MENU_STRS[ 21 ]) );	break;
		case PAGE_CLKS_SG_TRANS:	str = (char*)pgm_read_word( &(MENU_STRS[ 22 ]) );	break;
		case PAGE_CLKS_DB_STRONG:	str = (char*)pgm_read_word( &(MENU_STRS[ 19 ]) );	break;
		case PAGE_CLKS_DB_MEDIUM:	str = (char*)pgm_read_word( &(MENU_STRS[ 20 ]) );	break;
		case PAGE_CLKS_DB_SHARP:	str = (char*)pgm_read_word( &(MENU_STRS[ 21 ]) );	break;
		case PAGE_RMPS_UP_SHORT:	str = (char*)pgm_read_word( &(MENU_STRS[ 23 ]) );	break;
		case PAGE_RMPS_UP_MEDIUM:	str = (char*)pgm_read_word( &(MENU_STRS[ 20 ]) );	break;
		case PAGE_RMPS_UP_LONG:		str = (char*)pgm_read_word( &(MENU_STRS[ 24 ]) );	break;
		case PAGE_RMPS_DW_SHORT:	str = (char*)pgm_read_word( &(MENU_STRS[ 23 ]) );	break;
		case PAGE_RMPS_DW_MEDIUM:	str = (char*)pgm_read_word( &(MENU_STRS[ 20 ]) );	break;
		case PAGE_RMPS_DW_LONG:		str = (char*)pgm_read_word( &(MENU_STRS[ 24 ]) );	break;
		case PAGE_MORE_BUZZ:		str = (char*)pgm_read_word( &(MENU_STRS[ 15 ]) );	break;
		case PAGE_MORE_BUMP:		str = (char*)pgm_read_word( &(MENU_STRS[ 16 ]) );	break;
		case PAGE_MORE_PULSE:		str = (char*)pgm_read_word( &(MENU_STRS[ 17 ]) );	break;
		case PAGE_MORE_HUM: 		str = (char*)pgm_read_word( &(MENU_STRS[ 18 ]) );	break;
		case PAGE_AUDIO: 		str = (char*)pgm_read_word( &(MENU_STRS[ 27 ]) );	break;
		case PAGE_SELECT: 		str = (char*)pgm_read_word( &(MENU_STRS[ 28 ]) );	break;
						
	}
	
	sprintf_P( temp, str );
	if( strlen( temp ) > 7 )
	{
		temp[ 5 ] = ' ';
		temp[ 6 ] = '\0';
	}
	sprintf( buffer, "%s %d", temp, currentPage->selectedTab + 1 );
} // getFullHapticTabName

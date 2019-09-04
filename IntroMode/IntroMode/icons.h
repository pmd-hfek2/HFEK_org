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

//------------------------------------------------------------------------------
// Icons generated by LCD Assistant
// http://en.radzio.dxp.pl/bitmap_converter/
//------------------------------------------------------------------------------

#ifndef include_icons_h
#define include_icons_h

#define __PROG_TYPES_COMPAT__
#include <avr/pgmspace.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

// PMD Logo
#define LOGO_WIDTH   128
#define LOGO_HEIGHT  32
#define LOGO_SIZE    ( LOGO_WIDTH * LOGO_HEIGHT / 8 )

const unsigned char PMD_LOGO_GLCD_BMP[ LOGO_SIZE ] PROGMEM ={ 
      0xFC, 0xFE, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F, 0x4F, 0x67, 0x67, 0x67, 0x67, 0xE7, 0xE7, 0xE7, 0xE7,
      0xE7, 0xE7, 0xC7, 0xCF, 0x8F, 0x1F, 0x3F, 0x3F, 0x07, 0x07, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00,
      0xFE, 0xFF, 0x63, 0x63, 0x63, 0x63, 0x7F, 0x3E, 0x00, 0xF8, 0xFC, 0x8C, 0x8C, 0x8C, 0x7C, 0x78,
      0x00, 0x00, 0xFC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00, 0x00, 0xF0, 0xF8, 0x1C, 0x0C, 0x0C, 0x0C, 0x0C,
      0x08, 0x00, 0xFC, 0xFC, 0x00, 0x38, 0x7C, 0xCC, 0xCC, 0x8C, 0x0C, 0x00, 0xFC, 0xFC, 0x00, 0xC0,
      0xF0, 0x38, 0x1C, 0x0C, 0x0C, 0x0C, 0x1C, 0x38, 0xF0, 0xC0, 0x00, 0xFC, 0xFC, 0x3C, 0xF8, 0xE0,
      0xC0, 0x00, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0xFF, 0xFF, 0x07, 0x00, 0xF0, 0xFE, 0xFF, 0x1F, 0xCF, 0xE7, 0xE7, 0x3E, 0x80, 0xE9, 0x1D, 0xCD,
      0x6D, 0x19, 0xC3, 0xF7, 0xF7, 0x27, 0x8E, 0xF8, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
      0x0F, 0x0F, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xE0, 0x80, 0x0F, 0x0F, 0x01, 0x81, 0xE7, 0xEF, 0xEC,
      0xC0, 0x00, 0x0F, 0x8F, 0x8C, 0x0C, 0x0C, 0x00, 0x80, 0x87, 0x8F, 0x8E, 0x8C, 0x0C, 0x0C, 0x0C,
      0x80, 0x80, 0x8F, 0x8F, 0x00, 0x0C, 0x0C, 0x0C, 0x0D, 0x0F, 0x87, 0x80, 0x8F, 0x8F, 0x80, 0x01,
      0x03, 0x07, 0x0E, 0x8C, 0x8C, 0x8C, 0x8E, 0x87, 0x83, 0x81, 0x00, 0x0F, 0x0F, 0x00, 0x80, 0x83,
      0x87, 0x8F, 0x0F, 0x0F, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
      0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x02, 0x1E, 0x82, 0x9E, 0x86, 0x8C, 0x86, 0x1E,
      0xFF, 0xFF, 0x00, 0x00, 0xE3, 0xC7, 0x8F, 0x1C, 0x3B, 0x39, 0x7C, 0x7E, 0x7F, 0x7C, 0x7A, 0x7B,
      0x7C, 0x7F, 0x7F, 0x3D, 0x3C, 0x1E, 0x8F, 0xC3, 0xE0, 0xF8, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x03, 0x1F, 0xFE, 0xE0, 0xFE, 0x1F, 0x03, 0x00, 0xFF,
      0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFE, 0xFF, 0xC3, 0x81, 0x81, 0x81, 0x81, 0x01, 0x00, 0xFF,
      0xFF, 0x31, 0x31, 0xF1, 0xEF, 0x8F, 0x00, 0x38, 0x7E, 0xE7, 0xC3, 0x81, 0x81, 0x81, 0xC3, 0xE7,
      0x7E, 0x38, 0x00, 0xFF, 0xFF, 0x81, 0x81, 0x81, 0x81, 0xC3, 0xFF, 0x7C, 0x00, 0xFF, 0xFF, 0x31,
      0x31, 0xF1, 0xEF, 0x8F, 0x00, 0xFF, 0xFF, 0x00, 0x07, 0x1F, 0x7E, 0xF8, 0xE0, 0xF8, 0x3E, 0x0F,
      0x03, 0x00, 0xFF, 0xFF, 0x99, 0x99, 0x99, 0x00, 0x00, 0x87, 0x8F, 0x99, 0xB9, 0x71, 0xE1, 0x00,
      0x03, 0x07, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E,
      0x0E, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01,
      0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01,
      0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
      0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00,
      0x00, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
      0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00
};

#endif // include_icons_h
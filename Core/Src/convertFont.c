/*
 * RDB_Depth.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Sam Neumann
 *
 */


#include "ST7565.h"
#include "Syncopate Bold_48.h"


//each digit needs to be 43L * 64 H pixels

depthDigit1

depthDigit2

depthDigit3


// write a function that writes coloumn wise
void convert_column_to_page{

}

void ST7565_drawbitmap(uint8_t x, uint8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color)
{
	  unsigned Column_Address=0;
	  unsigned Row_Address=0;
	  unsigned int k,i;


	  for(k=0; k<8; k++)
	  {
		  ST7565_command(0x40);                                       // Line   Address
		  ST7565_command(0xB0+k+Row_Address);                         // Page   Address
		  ST7565_command(0x10);                                       // Column Address-4-H-bits
		  ST7565_command(0x00);                                       // Column Address-4-L-bits

		  ST7565_command(0x10 + ((Column_Address&0xF0)>>4));          // Column Address-4-H-bits
		  ST7565_command(0x00 +  (Column_Address&0x0F));              // Column Address-4-L-bits

	      for(i=0;i<128; i++)
	      {
	    	  ST7565_data(*bitmap);
	    	  bitmap++;
	      }
	  }
	  ST7565_updateBoundingBox(x, y, x+w, y+h);
}

/*
 * RDB_Functions.c
 *
 *  Created on: Nov 7, 2025
 *      Author: Sam Neumann
 */


#include "RDB_depth_digits_36x58.h"
#include "ST7565.h"

const unsigned char *depthDigitArray[10]= {BM0_36x58_block, BM1_36x58_block, BM2_36x58_block, BM3_36x58_block, BM4_36x58_block, BM5_36x58_block, BM6_36x58_block,BM7_36x58_block,BM8_36x58_block,BM9_36x58_block};


void countTestRDBlcd(){

	for(int i=0; i<10; i++){

		HAL_Delay(200);
		ST7565_drawbitmapNew(10,0, depthDigitArray[i], 36, 58, 1);
		updateDisplay();


	}



}

#include <stdio.h>
#include <stdlib.h>

#include "mycolor.h"

#define T 24 // period
#define blue 0x000211
#define red 0x110001

// Multiplier between 0 and 0xf
const uint32_t mult_table[T] = {
0,0,1,3,5,8,0xb,0xf,0xf,0xb,0x8,0x9,0xa,0xf,0xf,0xe,0xa,7,5,2,1,1,0,0}; 

uint32_t police()
{
	static int count = 0;
	static uint32_t color = blue;
	if (count == T) { // Switch color
		count = 0; // Reset count
		color = (color==blue) ? red : blue;
	}
	return color * mult_table[++count];	
}

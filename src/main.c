#include "util.h"
#include "strips.h"
#include "socket.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char **argv){
	Strip s;
	Socket sock;
	unsigned int i;
	socket_start();
	socket_open(&sock);
	strip_zero(&s);

	uint8_t color[3] = {0,0,0};

	while(1){
		// Enter an RGB color in this format: "xx xx xx" 
		scanf("%hhx %hhx %hhx", color, color+1, color+2);
		// Set the leds
		for (i=0; i<LED_COUNT; i++) {
			s.leds[i].r = color[0];
			s.leds[i].g = color[1];
			s.leds[i].b = color[2];
		}
		
		// All the strips do the same thing
		for(i=0; i<STRIP_COUNT; i++){
			s.index=(unsigned char)i;
			strip_update(&sock, &s);
		}
		Barco_sleep_ms(30);
	}
	socket_close(&sock);
	socket_stop();
	return 0;
}

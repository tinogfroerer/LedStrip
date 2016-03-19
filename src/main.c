#include "util.h"
#include "strips.h"
#include "socket.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	Strip s;
	Socket sock;
	unsigned int i;
	socket_start();
	socket_open(&sock);
	strip_zero(&s);

	uint32_t color =0x000000;

	while(1){
		// Enter an RGB color in this format: "xxxxxx" 
		scanf("%x", &color);
		// Set the leds
		for (i=0; i<LED_COUNT; i++) {
			setLed(color, s.leds + i);
		}
		// All the strips do the same thing
		for(i=0; i<STRIP_COUNT; i++){
			s.index=(unsigned char)i;
			strip_update(&sock, &s);
		}
		Barco_sleep_ms(30);
	}
	
	// Disconnect sequence
	socket_close(&sock);
	socket_stop();
	return 0;
}

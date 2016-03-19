#include "strips.h"
#include <string.h>

RETURN_CODE strip_update_buffer(Socket *sock, union Strip_Buffer *buf){
	return ( socket_send(sock, (Socket_Message){buf->buf,sizeof(buf->buf)}) == sizeof(buf->buf) ) ? RETURN_OK : RETURN_ERROR;
}


RETURN_CODE strip_update(Socket *sock, Strip *strip){
	return strip_update_buffer(sock, (union Strip_Buffer*)strip);
}

RETURN_CODE strip_zero(Strip *strip){
	memset(strip->leds, 0, sizeof(strip->leds));
	return RETURN_OK;
}

void setLed(uint32_t val, LED *led)
{
	led->r = (uint8_t)((val >> 16) & 0xff);
	led->g = (uint8_t)((val >> 8) & 0xff);
	led->b = (uint8_t)(val & 0xff);
}

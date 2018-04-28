/* gcc -Wall net.c */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint8_t add[] = {129, 169,  25, 100};
	uint8_t sub[] = {255, 255, 240,   0};
	uint8_t net[4];

	net[0] = add[0] & sub[0];
	net[1] = add[1] & sub[1];
	net[2] = add[2] & sub[2];
	net[3] = add[3] & sub[3];

	printf("net address: %u.%u.%u.%u\n", net[0], net[1], net[2], net[3]);

	return 0;
}

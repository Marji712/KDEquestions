// Marji Symonds
// Array Bit Unpacking

#include<stdint.h>
#include<stdio.h>

void unpacker(uint8_t bits[]);

int main()
{
	uint8_t bits[] = {0x3e, 0x83, 0xe9, 0x3e, 0xa3, 0xeb};

	unpacker(bits);

	return 0;
}

void unpacker(uint8_t bits[])
{
	int i;
	uint8_t unpacked[7];
	uint16_t temp = 0x00;

	printf("Input: ");
	for(i = 0; i < 5; i++) {
		printf("%04x ", bits[i]);
	}
	temp = (bits[0] << 8) | bits[1]; 
	unpacked[0] = temp >> 12;
	unpacked[1] = (temp << 4 >> 8);
	temp <<= 12 ;
	unpacked[2] = (temp >> 12);
	temp = (bits[2] << 8) | bits[3];
	unpacked[3] = temp >> 8;
	temp <<= 8;
	unpacked[4] = (temp >> 12);
	temp = temp | bits[4];
	unpacked[5] = temp >> 4;
	temp <<= 12;
	temp >>= 4;
	temp = temp | bits[5];
	unpacked[6] = temp >> 8;
	temp <<= 8;
	unpacked[7] = temp >> 8;

	printf("\nOutput: ");
	for(i = 0; i < 8; i++) {
		printf("%04x ", unpacked[i]);
	}
	printf("\n");

}
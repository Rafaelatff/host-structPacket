/*
 * main.c
 *
 *  Created on: 7 de dez de 2022
 *      Author: r.freitas
 */
#include <stdio.h>
#include <stdint.h>

typedef struct{
	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shortAddr;
	uint8_t addrMode;
} Packet_t;

int main(void){
	uint32_t packetValue;
	printf("Enter the 32bit packet value:");
	scanf("%X",&packetValue);

	Packet_t packet;
	packet.crc = (uint8_t)(packetValue & 0x3); // Only 2 first bits
	packet.status = (uint8_t) ((packetValue >> 2)& 0x1); //Shift 3rd bit to LSB position and do mask to get only 1 bit
	packet.payload = (uint16_t)((packetValue >> 3)& 0xFFF); //shift 4 bits to LSB pos. and mask 12 bits
	packet.bat = (uint8_t)((packetValue >> 15)& 0x7); //Shift 16 bits left and mask 0b111
	packet.sensor = (uint8_t)((packetValue >> 18)& 0x7);//Shift 19 bits left and mask 3 bits
	packet.longAddr = (uint8_t)((packetValue >> 21)& 0xFF);//Shift 22 bits left and mask 1 byte
	packet.shortAddr = (uint8_t)((packetValue >> 29)& 0x3);//Shift 30 bits left and mask 3 bits
	packet.addrMode = (uint8_t)((packetValue >> 31)& 0x1); //Shift MSB to LSB position and mask it


	printf ("crc      :%#x\n",packet.crc);
	printf ("statys   :%#x\n",packet.status);
	printf ("payload  :%#x\n",packet.payload);
	printf ("bat      :%#x\n",packet.bat);
	printf ("sensor   :%#x\n",packet.sensor);
	printf ("longAddr :%#x\n",packet.longAddr);
	printf ("shortAddr:%#x\n",packet.shortAddr);
	printf ("addrMode :%#x\n\n",packet.addrMode);

	printf ("Size of struct is %u Bytes\n",sizeof(packet));	// 10 Bytes
	//Next we need to learn to minimize it, using structure bit fields

	getchar();
	getchar();
}

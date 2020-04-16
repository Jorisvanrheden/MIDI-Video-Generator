// project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <winsock.h>

int readShort(FILE* file)
{
	char buffer[2];
	fread(&buffer, 2, 1, file);

	short value = *((short*)buffer);

	//convert endianness (we're on little endian, but need to go to big endian)
	return _byteswap_ushort(value);
}

int readInt(FILE* file) 
{
	char buffer[4];
	fread(&buffer, 4, 1, file);

	int value = *((int*)buffer);

	//convert endianness (we're on little endian, but need to go to big endian)
	return _byteswap_ulong(value);
}

int main()
{
	printf("Hello World!\n");

	FILE* file = fopen("C:\\Users\\joris.vanrheden\\Documents\\repositories\\MIDI Video Generator\\file.MID", "rb");
	if (!file) 
	{
		printf("No valid file\n");
	}

	char header[4];
	fread(&header, 4, 1, file);

	//Read length
	int chunkLength = readInt(file);

	//format
	short format = readShort(file);

	//ntracks
	short ntracks = readShort(file);

	//tickdiv
	short tickdiv = readShort(file);

	char header2[4];
	fread(&header2, 4, 1, file);

	int trackChunkLength = readInt(file);

	for (int i = 0; i < trackChunkLength; i++) 
	{
		/*char deltaTime[2];
		fread(&deltaTime, 4, 1, file);*/

		//read 4 bytes big endian
		//check bit 
		char buf[4];
		fread(&buf, 4, 1, file);

		for (int i = 0; i < 4; i++) 
		{
			//If the first bit is set
			int n = 7;
			if (buf[i] & (1 << n)) 
			{
				printf("No idea what im doing\n");
			}
		}

		printf("%02X:%02X:%02X:%02X", buf[0], buf[1], buf[2], buf[3]);

		int id3 = buf[1] + (buf[2] << 8) + (buf[3] << 16);




		char events[4];
		fread(&events, 4, 1, file);
	}

    return 0;
}


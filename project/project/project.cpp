#include <stdio.h>
#include <winsock.h>

#include "MIDIFile.h"
#include "MIDIParser.h"

int includeNextByte(char byte)
{
	int n = 7;

	for (int i = 0; i < 8; i++)
	{
		printf("%u\n", byte & (1 << i));
	}

	if (byte & (1 << 8))
	{
		printf("Testing\n");
	}

	return 0;
	/*if (byte & (1 << n))
	{
		printf("No idea what im doing\n");
	}*/
}

int main()
{
	const std::string filePath = "D:\\repos\\MIDI-Video-Generator\\file.MID";
	MIDIParser* file = new MIDIParser(filePath);

	//char header[4];
	//fread(&header, 4, 1, file);

	////Read length
	//int chunkLength = readInt(file);

	////format
	//short format = readShort(file);

	////ntracks
	//short ntracks = readShort(file);

	////tickdiv
	//short tickdiv = readShort(file);

	//char header2[4];
	//fread(&header2, 4, 1, file);

	//int trackChunkLength = readInt(file);

	//for (int i = 0; i < trackChunkLength; i++) 
	//{
	//	//Read deltatime
	//	/*char deltaTime[2];
	//	fread(&deltaTime, 4, 1, file);*/

	//	short d = readShort(file);
	//	short remainder = readShort(file);

	//	/*char buf[4];
	//	fread(&buf, 4, 1, file);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		includeNextByte(buf[i]);
	//	}*/




	//	//Read event
	//	char events[4];
	//	fread(&events, 4, 1, file);
	//}

    return 0;
}


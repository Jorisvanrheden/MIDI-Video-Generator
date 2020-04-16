#include "MIDIParser.h"
#include <fstream>
#include <string>
#include <iostream>

#include <climits>
#include <bitset>

template <typename T>
T swap_endian(T u)
{
	union
	{
		T u;
		unsigned char u8[sizeof(T)];
	} source, dest;

	source.u = u;

	for (int i = 0; i < sizeof(T); i++)
	{
		dest.u8[i] = source.u8[sizeof(T) - i - 1];
	}

	return dest.u;
}

template <typename T>
T read_type(std::ifstream& stream)
{
	T value;
	stream.read((char*)&value, sizeof(T));

	return swap_endian<T>(value);
}

MIDIParser::MIDIParser(const std::string file)
{
	std::ifstream stream(file, std::ios::binary);

	if (!stream)
	{
		std::cout << "File not found" << std::endl;
		return;
	}

	stream.seekg(0, std::ios::beg);

	char header[4];
	stream.read(header, 4);

	int chunkLength = read_type<int>(stream);
	short format = read_type<short>(stream);
	short ntracks = read_type<short>(stream);
	short tickdiv = read_type<short>(stream);

	char trackHeader[4];
	stream.read(trackHeader, 4);

	int trackChunkLength = read_type<int>(stream);
	for (int i = 0; i < trackChunkLength; i++)
	{
		//Read deltatime
		//VLQ (variable length quantity)??

		char buf[4];
		stream.read(buf, 4);

		for (int j = 0; j < 4; j++)
		{
			if (isBitSet(buf[j]))
			{
				std::cout << "HERE IS DA BOY" << std::endl;
			}
		}

		short deltaTime = read_type<short>(stream);


		short remainder = read_type<short>(stream);

		int test = read_type<int>(stream);
		//	//Read event
		//	char events[4];
		//	fread(&events, 4, 1, file);
		//}
		int b = 0;
	}

	stream.close();
}


MIDIParser::~MIDIParser()
{
}

bool MIDIParser::isBitSet(char byte)
{
	int n = 7;

	std::bitset<8> x(byte);
	std::cout << x << '\n';

	return (byte & (1 << 8));
}

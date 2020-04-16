#pragma once
#include <iostream>
#include <fstream>
class MIDIParser
{
public:
	MIDIParser(const std::string file);
	~MIDIParser();

private:
	short readShort(std::ifstream& stream);
	int readInt(std::ifstream& stream);

	bool isBitSet(char byte);
};


#include "IO.hpp"
#include <iostream>

IO::IO(const std::string& filePath) {
	fileStream.open(filePath, std::ios::in | std::ios::out | std::ios::binary);
	if(!fileStream.is_open()) {
		std::cout<<"Error: File not found, file path was: "<<filePath<<std::endl;

		
	}
	
	
}

std::fstream IO::getFileStream()
{
	return std::move(fileStream);

}


IO::~IO() {
	fileStream.close();
}
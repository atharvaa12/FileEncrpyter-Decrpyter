#include<iostream>
#include<string>
#include<fstream>
#include "IO.hpp"
#include<sstream>
class readEnv {
public:
	std::string getEnv() {
		std::string env_path = ".env";
		IO io(env_path);
		std::fstream envFileStream=io.getFileStream();
		std::stringstream buffer;

		buffer << envFileStream.rdbuf();
		std::string content= buffer.str();
		return content;
	}
};

#ifndef TASK_HPP
#define TASK_HPP
#include<string>
#include<fstream>
#include<sstream>
#include "IO.hpp"

enum class action {
	ENCRYPT,
	DECRYPT
};
struct task {
	
	std::string filePath;
	std::fstream fileStream;
	action taskType;

	task(std::fstream&& stream, action actionType, std::string path) :filePath(path), fileStream(std::move(stream)), taskType(actionType) {};
	 std::string toString() const {
		std::ostringstream oss;
		oss<<filePath<<","<<(taskType==action::ENCRYPT?"ENCRYPT":"DECRYPT");
		return oss.str();

		
	}
	static task fromString(const std::string& str) {
		std::istringstream iss(str);
		std::string path;
		std::string actionstr;
		if (std::getline(iss, path, ',') && std::getline(iss, actionstr)) {
			action act=(actionstr=="ENCRYPT")?action::ENCRYPT:action::DECRYPT;
			IO io(path);
			std::fstream taskFileStream=std::move(io.getFileStream());
			if (taskFileStream.is_open()) {
				return task(std::move(taskFileStream), act, path);
			}
			else {
				throw std::runtime_error("in class task Failed to open file found : "+path);


			}


		}
		else {
			throw std::runtime_error("in class task Failed to parse string : " + str);
		}
	}



	
};
#endif // !TASK_HPP

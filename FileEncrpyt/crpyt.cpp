#include "crpyt.hpp"
#include "task.hpp"

#include "IO.hpp"
#include "readEnv.cpp"

int executeCrpyt(const std::string& taskData)
{
	task currentTask=task::fromString(taskData);
	
	readEnv envReader;
	int key=std::stoi(envReader.getEnv());	
	if (currentTask.taskType == action::ENCRYPT) {
		char ch;
		while(currentTask.fileStream.get(ch)) {
			std::cout << "encrypting " << ch << std:: endl;
			ch=(ch+key)%256;
			currentTask.fileStream.seekp(-1, std::ios::cur);	
			currentTask.fileStream.put(ch);
			currentTask.fileStream.seekg(currentTask.fileStream.tellg(), std::ios::beg);
		}
		currentTask.fileStream.close();
	}
	else {
		char ch;
		while(currentTask.fileStream.get(ch)) {
			ch=(ch-key+256)%256;
			currentTask.fileStream.seekp(-1, std::ios::cur);	
			currentTask.fileStream.put(ch);
			currentTask.fileStream.seekg(currentTask.fileStream.tellg(), std::ios::beg);
		}
		currentTask.fileStream.close();

	}
	return 0;

	



}

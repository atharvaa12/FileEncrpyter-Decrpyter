#include<iostream>
#include <filesystem>
#include "processManager.hpp"
#include "task.hpp"

int main(int argc, char* argv[]) {
	std::string directory;
	std::string actionType;
	std::cout<<"Enter the directory path: "<<std::endl;
	std::getline(std::cin, directory);
	std::cout<<"Enter the action to perform (encrypt/decrypt): "<<std::endl;
	std::getline(std::cin, actionType);
	try {
		if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory)) {
			processManager manager;
			for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
				if (entry.is_regular_file()) {
					std::string filePath = entry.path().string();
					IO io(filePath);
					std::fstream fileStream = std::move(io.getFileStream());
					if (fileStream.is_open()) {
						action act = (actionType == "encrypt") ? action::ENCRYPT : action::DECRYPT;
						auto currentTask = std::make_unique<task>(std::move(fileStream), act, filePath);

						manager.addTask(std::move(currentTask));
					}
					else {
						std::cout << "Error: Failed to open file: " << filePath << std::endl;
					}


				}

			}
			manager.executeTasks();
		}
		else {
			std::cout << "Error: Directory not found: " << directory << std::endl;
		}
	}
	catch (const std::filesystem::filesystem_error & err) {
		std::cout<<"Error: "<<err.what()<<std::endl;

	}
}
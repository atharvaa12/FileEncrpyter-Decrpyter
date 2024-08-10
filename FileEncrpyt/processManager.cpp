#include "processManager.hpp"
#include <iostream>
#include "crpyt.hpp"
processManager::processManager()
{
}


bool processManager::addTask(std::unique_ptr<task> taskToAdd)
{	taskQueue.push(std::move(taskToAdd));
return true;

}

void processManager::executeTasks()
{
		while(!taskQueue.empty()) {
			std::unique_ptr<task> currentTask=std::move(taskQueue.front());
			taskQueue.pop();
			std::cout<<"Executing task: "<<currentTask->toString()<<std::endl;
			executeCrpyt(currentTask->toString());
		}
	
}

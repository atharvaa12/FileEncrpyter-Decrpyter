#include "processManager.hpp"
#include <iostream>
#include "crpyt.hpp"
#include "threadManager.hpp"
processManager::processManager()
{
}


bool processManager::addTask(std::unique_ptr<task> taskToAdd)
{	taskQueue.push(std::move(taskToAdd));
return true;

}

void processManager::executeTasks()
{
	threadManager threads;
		while(!taskQueue.empty()) {
			std::unique_ptr<task> currentTask=std::move(taskQueue.front());
			taskQueue.pop();
			std::cout<<"Executing task: "<<currentTask->toString()<<std::endl;
			threads.addThread(currentTask->toString());
		}
		threads.joinAllThreads();
	
}

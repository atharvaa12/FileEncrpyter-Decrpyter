#ifndef PROCESSMANAGER_HPP
#define PROCESSMANAGER_HPP
#include <queue>
#include "task.hpp"
class processManager {
private:
	std::queue<std::unique_ptr<task>> taskQueue;
public:
	processManager();
	bool addTask(std::unique_ptr<task> taskToAdd);
	void executeTasks();


		
		
	
};

#endif // !1

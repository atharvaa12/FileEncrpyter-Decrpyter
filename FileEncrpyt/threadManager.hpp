#ifndef THREADMANAGER_HPP
#define THREADMANAGER_HPP
#include<vector>
#include <thread>
#include <string>
#include<functional>
#include <mutex>
#include <queue>
class threadManager {
private:
	std::vector<std::thread>threads;
	std::queue<std::function<void()>>jobQueue;
	std::mutex jobQueueMutex;
	std::condition_variable jobQueueCondition;
	bool stop;
	void getJob();

	
public:
	threadManager(size_t threadPoolSize);
	void  addJob( std::string dataForThread);
	void  joinAllThreads();
	
		
	
	

};
#endif // !THREADMANAGER_HPP


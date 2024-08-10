#ifndef THREADMANAGER_HPP
#define THREADMANAGER_HPP
#include<vector>
#include <thread>
#include <string>

class threadManager {
private:
	static std::vector<std::unique_ptr<std::thread>>threads;
public:
	threadManager();
	void  addThread( std::string dataForThread);
	void  joinAllThreads();
		
	
	

};
#endif // !THREADMANAGER_HPP


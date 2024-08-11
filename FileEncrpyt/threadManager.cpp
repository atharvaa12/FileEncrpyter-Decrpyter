#include "threadManager.hpp"
#include "crpyt.hpp"
#include <iostream>

threadManager::threadManager(size_t threadPoolSize)
{	stop = false;
	for(size_t i=0;i<threadPoolSize; i++) {
		threads.emplace_back(std::thread(&threadManager::getJob,this));


	}

}

void threadManager::addJob(std::string dataForThread)
{
	std::function<void()> job = [dataForThread] {
		executeCrpyt(dataForThread);
		};
	{
		
				std::unique_lock<std::mutex> lock(jobQueueMutex);
				
				
				jobQueue.push(std::move(job));
	
	}
	jobQueueCondition.notify_one();
}

void threadManager::joinAllThreads()
{
	
	{
		std::unique_lock<std::mutex> lock(jobQueueMutex);
		jobQueueCondition.wait(lock, [this] { return jobQueue.empty(); });
		stop = true;
	}

	// Signal to stop the threads
	

	// Notify all threads so they can wake up and check the stop condition
	
	//std::cout<<"changed stop to true"<<std::endl;
	jobQueueCondition.notify_all();
	
	for (size_t i = 0; i < threads.size(); i++) {
		if(threads[i].joinable()) {
			
			std::cout<<"joining thread "<<i<<std::endl;
			threads[i].join();
		}
	}
	std::cout<<"joined all threads"<<std::endl;
	

}

void threadManager::getJob()	
{	//std::cout<<"here in getJob stop is "<<stop<<std::endl;
	while (true) {
		std::function<void()> job;
		//std::cout << "entered getJob" << std::endl;
		{
			std::unique_lock<std::mutex> lock(jobQueueMutex);
			jobQueueCondition.wait(lock, [this] {return stop || !jobQueue.empty(); });
			if (stop && jobQueue.empty()) {

				std::cout << "exiting getJob" << std::endl;
				return;
			}
			//std::cout << "picked a job from queue\n";
			job = std::move(jobQueue.front());
			jobQueue.pop();
		}
		jobQueueCondition.notify_one();
		job();

		
	}
	
}


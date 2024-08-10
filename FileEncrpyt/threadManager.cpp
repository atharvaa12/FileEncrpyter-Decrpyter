#include "threadManager.hpp"
#include "crpyt.hpp"
std::vector<std::unique_ptr<std::thread>> threadManager::threads;
threadManager::threadManager()
{
}

void threadManager::addThread(std::string dataForThread)
{
	threads.push_back(std::make_unique<std::thread>(std::move(executeCrpyt), dataForThread));
}

void threadManager::joinAllThreads()
{
	for (auto &t: threads) {
		if (t->joinable()) {
			t->join();
		}

	}
}





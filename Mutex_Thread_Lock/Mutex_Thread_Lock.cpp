 // Mutex_Thread_Lock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// mutex::lock/unlock
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <fstream>
#include <string>

std::mutex mtx;           // mutex for critical section

void threadID(int id) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	std::cout << "thread #" << id << '\n';
	for (int i = 0; i < 10; ++i)
	{
		std::ofstream myfile;
		///std::string filename = ("Thread%i.txt", i);
		myfile.open("Thread%d.txt",i);
		std::cout << "Thread Loop Test: " << i << " ." << std::endl;
		system("pause");
	}
	mtx.unlock();
}

int main()
{
	std::thread arrayOfThreads[10];
	// spawn 10 threads:
	for (int i = 0; i < 10; ++i)
		arrayOfThreads[i] = std::thread(threadID, i + 1);

	for (auto& th : arrayOfThreads) th.join();
	system("pause");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

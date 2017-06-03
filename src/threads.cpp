#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex t_m;
std::condition_variable cv;

void threadPrint()
{
	static int i = 0;
	std::unique_lock<mutex> u_mL(t_m);
	i++;
	cout << "i is: " << i << endl;
	if (i == 3) {
		cout << "3" << endl;
		cv.notify_all();
		return;
	} 
	cv.wait(u_mL);
}

int main()
{
	std::thread t1(threadPrint), t2(threadPrint), t3(threadPrint);
	t1.join();
	t2.join();
	t3.join();
	
	std::cout << "All threads are synced\n" ;
	return 0;
}

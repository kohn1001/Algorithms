
class MyMutex {
	public:
	MyMutex() : mut(0) {}
	~Mymutex() {}

	void lock();
	void unlock();
	bool tryLock();

	private:

	int mut;
	queue<int> q;

};

void MyMutex::lock()
{
	auto threadId = getThreadId();
	while(!testNset(mut)) {
		q.push(threadId);
		markNotRunning(threadId);
		callSched();
	}
}

void MyMutex::unlock()
{
	spin_lock();
	if (!q.empty()) {
		auto threadId = q.front(); q.pop();
		atomic_set(mut, 0);
		markRunning(threadId);
		
		//lock();
	}
	else {
		atomic_set(mut, 0); 
	}
	spin_unlock();
}

void MyMutex::tryLock()
{
}


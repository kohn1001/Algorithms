
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
	if (!q.empty()) {
		auto threadId = q.front(); q.pop();
		markRunning(threadId);
		callSched();
		lock();
	}
	else {
		mut = 0;
	}
}

void MyMutex::tryLock()
{
}


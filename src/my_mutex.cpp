
class MyMutex {
	public:
	MyMutex() : mut(0) {}
	~Mymutex() {}

	void lock();
	void unlock();
	bool tryLock();
	q_push();
	q_front();
	q_pop();

	private:

	int mut;
	queue<int> q;

};

void MyMutex::lock()
{
	auto threadId = getThreadId();
	while(!testNset(mut)) {
		q_push(threadId);
		markNotRunning(threadId);
		callSched();
	}
}

int MyMutex::q_front()
{
	spinlock();
	int ret = q.front();
	spinunlock();
	return ret;
}

int MyMutex::q_pop()
{
	spinlock();
	q.pop();
	spinunlock();
}

void MyMutex::q_push(int tid)
{
	spinlock();
	q.push(tid);
	spinunlock();
}

void MyMutex::unlock()
{
	if (!q_empty()) {
		auto threadId = q_front(); q_pop();
		atomic_set(mut, 0);
		markRunning(threadId);
		
		//lock();
	}
	else {
		atomic_set(mut, 0); 
	}
	
}

void MyMutex::tryLock()
{
}


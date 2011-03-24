#ifndef MUTEXLOCKER_H
#define MUTEXLOCKER_H

#include <pthread.h>

class MutexLocker
{
public:
	MutexLocker(pthread_mutex_t* pMutex) : mpMutex(pMutex)
	{
		pthread_mutex_lock(mpMutex);
	}
	
	virtual ~MutexLocker()
	{
		pthread_mutex_unlock(mpMutex);
	}

private:
	pthread_mutex_t* mpMutex;
};

#endif  // MUTEXLOCKER_H

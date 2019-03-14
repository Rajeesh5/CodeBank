
#include<string>

class IFwThread
{
	// @access Public Members
public:
	// @group  Interface operations

	// @cmember Initialize the thread instance.<nl>
	//         
	virtual int Init(IFwCallback* pThrFunction, int Priority, std::string pThreadName) = 0;

	// @cmember Starts the execution of the thread.
	virtual void  Start(void* pThrParam) = 0;

	// @cmember Waits for the thread to terminate.<nl>
	virtual int Wait(long pThrResult) = 0;

	// @cmember Signals the thread implementation to destroy all internal resources on
	//  exit of the callback function (the deletion is delayed until then) or immediately.<nl>
	//  You must not use a pointer to this instance after this method is called.
	virtual void  Release(void) = 0;

	// @cmember Sets the priority of this thread instance.
	virtual void SetPriority(int Priority) = 0;

	// @cmember Gets the priority of this thread instance.
	virtual int GetPriority(void) = 0;

	// @cmember Returns a unique id for this thread instance ( should be the same as
	//          the thread id from the DebugTool)
	// USE OF THIS METHOD IS DEPRECIATED (only for debugging purposes).
	virtual int GetThreadId(void) = 0;

};




class IFwCallback{
public:
	// @cmember Gets called on thread start or timer expiration.
	virtual void DoCallback(void *) = 0;

	// @cmember This method gets called at execution end of the thread.
	virtual void  ReleaseCallback(void) = 0;
};


class CFwCycleCallback : public IFwCallback{
public:
		
	CFwCycleCallback(/*CFwDataCollector* 
					 m_pDataColl*/int TimeToWait);	// constructor.	
	virtual ~CFwCycleCallback();					// constructor.	
	virtual void DoCallback(void * pParameter);		// Thread callback function.	
	virtual void  ReleaseCallback();				// destroy this instance.
	void Terminate();								// for terminating the thread.
	void Start();									// starts working.
	void Stop();									// stops working.

private:
	int	m_TimeToWait;
	//CFwDataCollector*	m_pDataColl;				// Pointer to data Collector.
};



void finalConstruct() {

	//Creation of cycle thread & association with callBack.
	IFwThread* m_pCycleThread;				// create the cycle thread using Factory method.
	CFwCycleCallback *m_pCycleCallback = new CFwCycleCallback(/*m_pDataColl,*/ 100);
	m_pCycleThread->Init(m_pCycleCallback,  0, "Name::DoCallback");
	m_pCycleThread->Start(NULL);
	//Similarly recive handler thread also created & get started..

}



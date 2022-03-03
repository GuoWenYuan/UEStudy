#pragma once
#include "AEvent.h"

class TestEvent :public AEvent
{
public:
	
	TestEvent();
	~TestEvent();

	template<typename T>
	void Run(T a);
};

template<typename T>
inline void TestEvent::Run(T t)
{
	UE_LOG(LogTemp, Warning, t)

}

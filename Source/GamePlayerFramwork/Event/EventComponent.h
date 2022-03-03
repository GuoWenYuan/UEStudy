#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AEvent.h"
#include <GamePlayerFramwork/Event/EventComponent.h>

class EventComponent
{
private:
	TMap<FString, AEvent*> eventPool;

public:
	void AddEvent(FString eventName, AEvent* eventActor);
	AEvent* GetEvent(FString eventName);
	void RemoveEvent(FString eventName);


	void RunEvent(FString eventName);
	template<typename T>
	void RunEvent(FString eventName, T t);
	template<typename T, typename T1>
	void RunEvent(FString eventName, T t,T1 t1);
};



inline void EventComponent::RunEvent(FString eventName)
{
	UE_LOG(LogTemp, Log, TEXT("inline void EventComponent::RunEvent(FString eventName) %s , %d"), __FILE__, __LINE__);
	AEvent *m_Event = this->GetEvent(eventName);
	if (NULL == m_Event)
	{
		m_Event->Run();
	}
}

template<typename T>
inline void EventComponent::RunEvent(FString eventName, T t)
{
	UE_LOG(LogTemp, Log, TEXT("inline void EventComponent::RunEvent(FString eventName, T t) %s , %d"), &eventName, __LINE__);
	if (this->GetEvent(eventName) != NULL)
	{
		UE_LOG(LogTemp, Log, TEXT("if (this->GetEvent(eventName) != NULL) %s , %d"), __FILE__, __LINE__);
		this->GetEvent(eventName)->Run(t);
	}
}



template<typename T, typename T1>
inline void EventComponent::RunEvent(FString eventName, T t, T1 t1)
{
	UE_LOG(LogTemp, Log, TEXT("inline void EventComponent::RunEvent(FString eventName, T t, T1 t1) %s , %d"), __FILE__, __LINE__);
	if (this->GetEvent(eventName) != NULL)
	{
		this->GetEvent(eventName)->Run(t, t1);
	}
}

inline void EventComponent::AddEvent(FString eventName, AEvent* eventActor)
{
	UE_LOG(LogTemp, Log, TEXT("AddEvent %s , %d"),__FILE__,__LINE__);
	if (this->eventPool.Contains(eventName))
	{
		return;
	}
	this->eventPool.Add(eventName, eventActor);

}

inline AEvent* EventComponent::GetEvent(FString eventName)
{
	UE_LOG(LogTemp, Log, TEXT("GetEvent % s, % d"),__FILE__,__LINE__);
	return this->eventPool[eventName];
}

inline void EventComponent::RemoveEvent(FString eventName)
{
	if (this->eventPool.Contains(eventName))
	{
		this->eventPool.Remove(eventName);
	}
}



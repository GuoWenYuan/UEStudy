#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"



class AEvent
{
public:
	int refCount;

public:
	AEvent() {}
	~AEvent() {}

public:
	void Run() {}

	template<typename T>
	void Run(T a);

};

template<typename T>
inline void AEvent::Run(T t)
{
	UE_LOG(LogTemp, Warning,TEXT("%s"),t)

}

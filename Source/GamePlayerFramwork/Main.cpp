// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "Event/EventComponent.h"
#include <GamePlayerFramwork/Event/TestEvent.h>
// Sets default values for this component's properties
UMain::UMain()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMain::BeginPlay()
{
	Super::BeginPlay();
	EventComponent* eventComponet = new EventComponent;

	TestEvent* testEvent = new TestEvent();
	eventComponet->AddEvent("Test", testEvent);
	eventComponet->RunEvent("Test", TEXT("11111 a") );
	// ...

}


// Called every frame
void UMain::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


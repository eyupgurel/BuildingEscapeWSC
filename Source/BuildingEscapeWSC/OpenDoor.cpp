// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp,Warning, TEXT("Open door begun"));
	// ...
	auto Rotation = FRotator(0.f,60.f,0.f);
    UE_LOG(LogTemp,Warning,TEXT("rotation is %s"), *Rotation.ToString());
	auto Owner = GetOwner();
	auto res = Owner->SetActorRotation(Rotation);
    UE_LOG(LogTemp,Warning,TEXT("result is %d"), res);


}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


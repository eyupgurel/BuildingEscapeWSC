// Fill out your copyright notice in the Description page of Project Settings.


#include "PositionRecorderComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionRecorderComponent::UPositionRecorderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UPositionRecorderComponent::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp,Warning, TEXT("Player begun"));
    auto ObjectName = GetOwner()->GetName();
    UE_LOG(LogTemp,Warning, TEXT("Position report for %s"), *ObjectName);
    auto ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
    UE_LOG(LogTemp,Warning,TEXT("%s is at %s"), *ObjectName, *ObjectPos);
	// ...
	
}


// Called every frame
void UPositionRecorderComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


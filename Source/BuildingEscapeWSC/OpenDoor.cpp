// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"





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
    //UE_LOG(LogTemp, Warning, TEXT("Begun play"));
	Owner = GetOwner();
    PawnThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor() const {
    auto res = Owner->SetActorRotation(FRotator(0.f,OpenAngle,0.f));
}
void UOpenDoor::CloseDoor() const {
    auto res = Owner->SetActorRotation(FRotator(0.f,0.0,0.f));
}
// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if(PressurePlate->IsOverlappingActor((AActor*) PawnThatOpens)){
        OpenDoor();
        LastDoorOpenTime = GetWorld()->GetTimeSeconds();
    }

    if(GetWorld()->GetTimeSeconds()-LastDoorOpenTime>DoorCloseDelay)
        CloseDoor();

	// ...
}


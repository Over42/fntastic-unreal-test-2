// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ATurtle::ATurtle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurtle::Move(float Value)
{
	FVector Direction = (EndLocation - StartLocation).GetSafeNormal();
	AddActorWorldOffset(Direction * Value);

	if (GetActorLocation().Equals(EndLocation, 1.0f))
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, FinishParticle, GetActorLocation());
		UGameplayStatics::PlaySoundAtLocation(this, FinishSound, GetActorLocation());
		Destroy();
	}
}

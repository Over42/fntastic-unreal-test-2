// Fill out your copyright notice in the Description page of Project Settings.


#include "Nest.h"
#include "Turtle.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ANest::ANest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));
	RootComponent = SceneRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ANest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ATurtle* ANest::SpawnTurtle()
{
	FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = SpawnPoint->GetComponentRotation();
	UGameplayStatics::SpawnEmitterAtLocation(this, SpawnParticle, SpawnLocation);
	UGameplayStatics::PlaySoundAtLocation(this, SpawnSound, SpawnLocation);
	return GetWorld()->SpawnActor<ATurtle>(TurtleClass, SpawnLocation, SpawnRotation);
}

FVector ANest::GetTargetLocation()
{
	return GetTransform().TransformPosition(TurtleTargetLocation);
}

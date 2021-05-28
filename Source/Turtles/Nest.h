// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Nest.generated.h"

UCLASS()
class TURTLES_API ANest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	class ATurtle* SpawnTurtle();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetTargetLocation();

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ATurtle> TurtleClass;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget="true"))
	FVector TurtleTargetLocation;

	UPROPERTY(VisibleDefaultsOnly)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly)
	USceneComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* SpawnParticle;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* SpawnSound;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turtle.generated.h"

UCLASS()
class TURTLES_API ATurtle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void MoveTo(FVector Location) { EndLocation = Location; };

protected:
	UFUNCTION(BlueprintCallable)
	virtual void Move(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 100.f;

private:
	FVector StartLocation;
	FVector EndLocation;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* FinishParticle;

	UPROPERTY(EditAnywhere, Category = "Effects")
	USoundBase* FinishSound;
};

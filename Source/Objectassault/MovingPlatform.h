// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBJECTASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category="Moving platform")
	FVector Platformvelociity=FVector(100,0,0);
	FVector Startlocation;
	UPROPERTY(EditAnywhere, Category="Moving platform")
	float Moveddistance=100;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	void moveplatform(float);
	void RotatePlatform(float);
	bool Shouldplatformreturn()const;
	float distancemove()const;
	



};

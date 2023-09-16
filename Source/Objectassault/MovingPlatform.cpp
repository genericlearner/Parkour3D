// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	Startlocation=GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Your message"));

	

	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	moveplatform(DeltaTime);
	RotatePlatform(DeltaTime);
}
void AMovingPlatform::moveplatform(float DeltaTime)
{
	

	
	if(Shouldplatformreturn()){
		
		FVector Movedirection= Platformvelociity.GetSafeNormal();
		Startlocation= Startlocation+Movedirection*Moveddistance;
		Platformvelociity=-Platformvelociity;		
	}
	else
	{
		FVector Currentlocation= GetActorLocation();
		Currentlocation=Currentlocation+(Platformvelociity*DeltaTime);
		SetActorLocation(Currentlocation);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator Currentrotation=GetActorRotation();
	Currentrotation=Currentrotation+(RotationVelocity*DeltaTime);
	AddActorLocalRotation(RotationVelocity*DeltaTime);


}
bool AMovingPlatform::Shouldplatformreturn()const
{
	return distancemove()>Moveddistance;
}
float AMovingPlatform::distancemove()const
{
	return FVector::Dist(Startlocation,GetActorLocation());
}


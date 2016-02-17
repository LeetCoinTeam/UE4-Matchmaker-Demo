// Fill out your copyright notice in the Description page of Project Settings.

#include "MMDEMO1.h"
#include "MyPickup.h"


// Sets default values
AMyPickup::AMyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


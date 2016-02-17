// Fill out your copyright notice in the Description page of Project Settings.

#include "MMDEMO1.h"
#include "Engine.h"
#include "MyPlayerController.h"
// Include the engine for casting
#include "Engine.h"
// Incude our game mode and instance
#include "MyGameMode.h"
#include "MyGameInstance.h"
#include "MyPlayerState.h"



void AMyPlayerController::GetAuthorizationInfo_Implementation(const FString& PlatformID, const FString& MatchKey, const int& playerID)
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] [AMyPlayerController] PlatformID: %s"), *PlatformID);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [AMyPlayerController] MatchKey: %s"), *MatchKey); 
	SendAuthorizationInfo(PlatformID, MatchKey, playerID);
	//UE_LOG(LogTemp, Log, TEXT("do stuff on server here"));

	

	// Use Game Instance because it does not get erased on level change
	// Get the game instance and cast to our game instance.
	UMyGameInstance* TheGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	TheGameInstance->AuthorizePlayer(PlatformID, MatchKey, playerID);

}

bool AMyPlayerController::GetAuthorizationInfo_Validate(const FString& PlatformID, const FString& MatchKey, const int32& playerID)
{
	UE_LOG(LogTemp, Log, TEXT("Validate"));
	return true;
}

void AMyPlayerController::SendAuthorizationInfo_Implementation(const FString& PlatformID, const FString& MatchKey, const int32& playerID)
{
	// do stuff on client here
	UE_LOG(LogTemp, Log, TEXT("do stuff on client here"));
}


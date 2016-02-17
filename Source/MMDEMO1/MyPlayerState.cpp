// Fill out your copyright notice in the Description page of Project Settings.

#include "MMDEMO1.h"
#include "MyPlayerState.h"




void AMyPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	//DOREPLIFETIME(AMyPlayerState, test);

}

bool AMyPlayerState::AuthorizePlayer(FString PlatformID, FString MatchKey)
{

	UE_LOG(LogTemp, Log, TEXT("PlatformID: %s"), *PlatformID);
	UE_LOG(LogTemp, Log, TEXT("MatchKey: %s"), *MatchKey);


	return true;

}
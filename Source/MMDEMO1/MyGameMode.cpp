// Fill out your copyright notice in the Description page of Project Settings.

#include "MMDEMO1.h"
#include "MyGameMode.h"




AMyGameMode::AMyGameMode()
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] GAME MODE INIT"));
	AMyGameMode::bUseSeamlessTravel = true;
}

bool AMyGameMode::AuthorizePlayer(FString PlatformID, FString MatchKey)
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] GAME MODE AuthorizePlayer"));
	UE_LOG(LogTemp, Log, TEXT("PlatformID: %s"), *PlatformID);
	UE_LOG(LogTemp, Log, TEXT("MatchKey: %s"), *MatchKey);
	if (PlayerOneJoined)
	{
		UE_LOG(LogTemp, Log, TEXT("[LEET] GAME MODE PlayerOneJoined"));
		if (MatchKeyFromPlayerOne == MatchKey)
		{
			UE_LOG(LogTemp, Log, TEXT("[LEET] GAME MODE MatchKeyValid"));
			MatchKeyValid = true;
			PlayerTwoJoined = true;
			PlayerTwoPlatformId = PlatformID;

			//FName LevelName = "/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap";
			//UGameplayStatics::OpenLevel(GWorld, LevelName, false);

			FString UrlString = TEXT("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
			GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
			GetWorld()->ServerTravel(UrlString);

			//UGameplayStatics::OpenLevel(this, TEXT("ThirdPersonExampleMap"), false);
		}
		else {
			return false;
		}
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[LEET] GAME MODE NOT PlayerOneJoined"));
		MatchKeyFromPlayerOne = MatchKey;
		PlayerOneJoined = true;
		PlayerOnePlatformId = PlatformID;
	}

	return true;

}



bool AMyGameMode::SubmitMatchMakerResults()
{
	return true;


}

void AMyGameMode::SubmitMatchMakerResultsRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{

}

void AMyGameMode::PostSeamlessTravel()
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] PostSeamlessTravel"));
}
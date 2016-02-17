// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "Http.h"
#include "Json.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MMDEMO1_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool AuthorizePlayer(FString PlatformID, FString MatchKey);

	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool SubmitMatchMakerResults();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString MatchKeyFromPlayerOne;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool PlayerOneJoined;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString PlayerOnePlatformId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool PlayerTwoJoined;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString PlayerTwoPlatformId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool MatchKeyValid;

	AMyGameMode();

	void SubmitMatchMakerResultsRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);

	void PostSeamlessTravel();
	
};

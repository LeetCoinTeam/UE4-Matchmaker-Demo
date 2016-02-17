// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "Http.h"
#include "Json.h"
#include "Base64.h"
#include <string>
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MMDEMO1_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/**
	* For Matchmaker all we are doing is storing the platformID.
	*/
	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool AuthorizePlayer(FString PlatformID, FString MatchKey, int32 playerID);

	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool GetWinnerInfo( int32 playerID);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString MatchKeyFromPlayerOne;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool PlayerOneJoined;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString PlayerOnePlatformId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		int32 PlayerOnePlayerID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool PlayerTwoJoined;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		FString PlayerTwoPlatformId;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		int32 PlayerTwoPlayerID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LEET")
		bool MatchKeyValid;

	UMyGameInstance();

	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool SubmitMatchMakerResults();
	/**
	* Delegate called when the request completes
	*
	* @param HttpRequest - object that started/processed the request
	* @param HttpResponse - optional response object if request completed
	* @param bSucceeded - true if Url connection was made and response was received
	*/
	void SubmitMatchMakerResultsRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
	
	
};


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MMDEMO1_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
	// playerTitle
	UPROPERTY(Replicated)
		FString title;
	// platformKey
	UPROPERTY(Replicated)
		FString platformKey;
	
	UFUNCTION(BlueprintCallable, Category = "LEET")
		bool AuthorizePlayer(FString PlatformID, FString MatchKey);
};


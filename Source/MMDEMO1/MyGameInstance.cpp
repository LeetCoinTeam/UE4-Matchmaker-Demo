// Fill out your copyright notice in the Description page of Project Settings.

#include "MMDEMO1.h"
#include "MyGameInstance.h"
#include "MyPlayerController.h"

UMyGameInstance::UMyGameInstance()
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] GAME INSTANCE INIT"));
	PlayerOneJoined = false;
}

bool UMyGameInstance::AuthorizePlayer(FString PlatformID, FString MatchKey, int32 playerID)
{
	
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] AuthorizePlayer"));
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlatformID: %s"), *PlatformID);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] MatchKey: %s"), *MatchKey);
	if (PlayerOneJoined)
	{
		UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerOneJoined"));
		if (MatchKeyFromPlayerOne == MatchKey)
		{
			UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] MatchKeyValid"));
			MatchKeyValid = true;
			PlayerTwoJoined = true;
			PlayerTwoPlatformId = PlatformID;
			PlayerTwoPlayerID = playerID;

			//FName LevelName = "/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap";
			//UGameplayStatics::OpenLevel(GWorld, LevelName, false);

			FString UrlString = TEXT("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
			GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
			GetWorld()->ServerTravel(UrlString);
			

			for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
			{
				UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerController Found"));
				APlayerController* PlayerController = *Iterator;
				AMyPlayerController* MyController = Cast<AMyPlayerController>(PlayerController);
			}
			

			//UGameplayStatics::OpenLevel(this, TEXT("ThirdPersonExampleMap"), false);
		}
		else {
			return false;
		}
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] NOT PlayerOneJoined"));
		MatchKeyFromPlayerOne = MatchKey;
		PlayerOneJoined = true;
		PlayerOnePlatformId = PlatformID;
		PlayerOnePlayerID = playerID;
	}

	return true;


}

bool UMyGameInstance::GetWinnerInfo(const int32 playerID)
{
	UE_LOG(LogTemp, Log, TEXT("[LEET] UMyGameInstance GetWinnerInfo"));

	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerOnePlatformId: %s"), *PlayerOnePlatformId);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerOnePlayerID: %i"), PlayerOnePlayerID);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerTwoPlatformId: %s"), *PlayerTwoPlatformId);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] PlayerTwoPlayerID: %i"), PlayerTwoPlayerID);
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] MatchKeyFromPlayerOne: %s"), *MatchKeyFromPlayerOne);

	// Build the player dict list as json
	//TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());


	//TArray<FString> playerlist;

	//JsonObject->SetArrayField(TEXT("player_dict_list"), )
	//JsonObject->SetStringField(TEXT("nonce"), *FString::Printf(TEXT("%s"), *nonceString));
	//JsonObject->SetStringField(TEXT("encryption"), *FString::Printf(TEXT("%s"), *encryption));
	
	FString player_dict_list;

	if (playerID == PlayerOnePlayerID)
	{
		UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] Winner is Player One"));
		player_dict_list = "%5B%7B%22platformID%22%3A+%22" + PlayerOnePlatformId + "%22%2C+%22kills%22%3A+1%2C+%22deaths%22%3A+0%7D%2C+%7B%22platformID%22%3A+%22" + PlayerTwoPlatformId + "%22%2C+%22kills%22%3A+0%2C+%22deaths%22%3A+1%7D%5D";
	}
	else if (playerID == PlayerTwoPlayerID)
	{
		UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] Winner is Player One"));
		player_dict_list = "%5B%7B%22platformID%22%3A+%22" + PlayerTwoPlatformId + "%22%2C+%22kills%22%3A+1%2C+%22deaths%22%3A+0%7D%2C+%7B%22platformID%22%3A+%22" + PlayerOnePlatformId + "%22%2C+%22kills%22%3A+0%2C+%22deaths%22%3A+1%7D%5D";
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] ERROR Winner could not be found"));
		player_dict_list = "";
	}

	FHttpModule* Http = &FHttpModule::Get();
	
	if (!Http) { return false; }
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] http is available"));
	if (!Http->IsHttpEnabled()) { return false; }
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] http is enabled"));

	
	FString DeveloperAPIKey = "XXXX"; // Get this from leet sandbox
	
	FString DeveloperAPISecret = "XXXX"; // Get this from leet sandbox
	FString nonceString = "10951350917635";
	FString encryption = "off";

	

	FString OutputString;
	// TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	// FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	// Build Params as text string
	OutputString = "nonce=" + nonceString + "&encryption=" + encryption + "&match_key=" + MatchKeyFromPlayerOne + "&player_dict_list=" + player_dict_list;
	// urlencode the params

	//Waiting for 4.11 for cypto++ for proper hmac sha512 signs

	FString HashStr = "411willGetCryptoPPWhichCanDoProperHMACSigning";
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] hash"));
	UE_LOG(LogTemp, Log, TEXT("[LEET] [UMyGameInstance] HashStr: %s"), *HashStr);

	FString TargetHost = "http://apitest-dot-leetsandbox.appspot.com/api/v2/matchmaker/results";
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	Request->SetVerb("POST");
	Request->SetURL(TargetHost);
	Request->SetHeader("User-Agent", "LEETUnrealEngineClient/1.0");
	Request->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	Request->SetHeader("Key", MatchKeyFromPlayerOne);
	Request->SetHeader("Sign", HashStr);
	Request->SetContentAsString(OutputString);

	Request->OnProcessRequestComplete().BindUObject(this, &UMyGameInstance::SubmitMatchMakerResultsRequestComplete);
	if (!Request->ProcessRequest()) { return false; }

	// TODO KICK PLAYERS

	// Reset game instance variables
	PlayerOneJoined = false;

	// For now, just travel back to login level.
	FString UrlString = TEXT("/Game/ThirdPersonCPP/Maps/MyLoginLevel?listen");
	GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;
	GetWorld()->ServerTravel(UrlString);

	return true;
}

bool UMyGameInstance::SubmitMatchMakerResults()
{
	return true;


}

void UMyGameInstance::SubmitMatchMakerResultsRequestComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
{

}


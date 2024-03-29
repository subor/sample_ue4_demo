// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RuyiSDKManager.h"
//#include "RuyiSDKDemoCharacter.h"
#include "RuyiSDKDemoGameMode.h"

#include "AllowWindowsPlatformTypes.h"
#include "Windows/WindowsPlatformProcess.h"
#include "HideWindowsPlatformTypes.h"
#include "HAL/ThreadingBase.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

USTRUCT(Blueprintable)
struct FRuyiSummaryFriendData
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString gender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString dob;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString location;
};

USTRUCT(Blueprintable)
struct FRuyiNetProfile 
{
	GENERATED_USTRUCT_BODY();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString profileName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString profileId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString pictureUrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString email;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isFriend;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRuyiSummaryFriendData summaryFriendData;
};

USTRUCT(Blueprintable)
struct FRuyiSystemSettingData 
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AudioVolumn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SpeakerVolumn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Mute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Language;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DevModeOn;
};

#define JSON_RESPONSE_OK 200

/**
 * 
 */
UCLASS()
class RUYISDKDEMO_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void InitSDK();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Authentication")
	void Ruyi_StartRegister(FString username, FString password);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Authentication")
	void Ruyi_StartLogin(FString username, FString password);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Authentication")
	void Ruyi_StartLoginOut();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Friend")
	void Ruyi_StartFriendList();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Friend")
	void Ruyi_StartAddFriends(TArray<FString> profileIds);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|Friend")
	void Ruyi_StartRemoveFriends(TArray<FString> profileIds);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|AsyncMatch")
	void Ruyi_StartMatchMakingFindPlayers(int rangeDelta, int numMatches);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|AsyncMatch")
	void Ruyi_StartSave(int score);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|AsyncMatch")
	void Ruyi_StartLoad();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|SystemSetting")
	void Ruyi_StartSystemSetting1(FRuyiSystemSettingData settingData);

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|StorageLayer")
	void Ruyi_StartUploadFileToStorageLayer();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|RuyiNet")
	void Ruyi_StartGetLeaderboard();

	UFUNCTION(BlueprintCallable, Category = "RuyiSDK|Request|RuyiNet")
	void Ruyi_StartGetPlayerProfile();

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void OpenFileDialog(FString& filePath);

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	UTexture2D* LoadTexture2D_FromFile(const FString& filePath, bool& isValid, int& width, int& height);

	UFUNCTION(BlueprintCallable, Category = "MainWidget")
	void ReadSaveFile(FString localPath);
public:

	//RuyiSDK event
	//UFUNCTION(BlueprintImplementableEvent, Category = "RuyiSDK|Event|Authentication")
	//void Ruyi_CallbackSDKLogin();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	RuyiSDKRequestType SDKRequestType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	FRuyiNetProfile PlayerProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	TArray<FRuyiNetProfile> Friends;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	TArray<FRuyiNetProfile> Matches;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	int Score1P;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	int Score2P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	bool IsLogin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	bool IsSaveSucceed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	bool IsLoadCloudSucceed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	bool IsLoadLocalSucceed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	FString SavePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	bool IsRequestFinish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RuyiSDK|Data")
	FRuyiSystemSettingData SettingData;
};

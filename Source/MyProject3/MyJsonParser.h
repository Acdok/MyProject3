#pragma once

#include "CoreMinimal.h"
#include "JsonUtilities.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "MyJsonParser.generated.h"

// Forward declaration
class IHttpRequest;
class IHttpResponse;

// FConversation ����ü ����
USTRUCT(BlueprintType)
struct FConversation : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(BlueprintReadWrite)
    FString Name;

    UPROPERTY(BlueprintReadWrite)
    FString Emotion;

    UPROPERTY(BlueprintReadWrite)
    FString Message;
};

// UMyJsonParser Ŭ���� ����
UCLASS(Blueprintable)
class MYPROJECT3_API UMyJsonParser : public UObject
{
    GENERATED_BODY()

public:
    // JSON ������ �Ľ��ϴ� ���� �Լ� ����
    UFUNCTION(BlueprintCallable, Category = "JSON")
    void ParseJson(FString JsonString);

    // �Ľ̵� ��ȭ ������ ������ �迭 ���� (�������Ʈ���� �б� ����)
    UPROPERTY(BlueprintReadOnly, Category = "JSON")
    TArray<FConversation> Conversations;

    UFUNCTION(BlueprintCallable, Category = "HTTP")
    FString SendRequestAndGetResponse(FString Characters, FString Description, bool bIsNewStory, FString LastConversation,FString NewCharacters, FString NewCharacterDescriptions, FString VoiceActors);

    // Variable to store the last response
    UPROPERTY(BlueprintReadWrite, Category = "HTTP")
    FString LastResponse;



private:
    // Function to handle the actual sending of the request
 
    void SendPostRequest(FString RequestContent);

    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

    // Function to parse the characters string into a JSON array
    TArray<TSharedPtr<FJsonValue>> ParseCharactersArray(FString Characters);


};
#pragma once

#include "CoreMinimal.h"
#include "JsonUtilities.h"
#include "MyJsonParser.generated.h"

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
    void ParseJson();

    // �Ľ̵� ��ȭ ������ ������ �迭 ���� (�������Ʈ���� �б� ����)
    UPROPERTY(BlueprintReadOnly, Category = "JSON")
    TArray<FConversation> Conversations;
};

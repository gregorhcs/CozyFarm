// Copyright 2024 Thieves of the Night. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SnAbilitySystemFunctionLibrary.generated.h"

class USnAbility;
/**
 * 
 */
UCLASS()
class GASEASIERINPUTEXTENSION_API USnAbilitySystemFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="SnAbility")
	static int32 GetInputID(TSubclassOf<USnAbility> AbilityClass);
	
};

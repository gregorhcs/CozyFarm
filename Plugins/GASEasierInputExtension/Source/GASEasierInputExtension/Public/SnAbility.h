// Copyright 2024 Thieves of the Night. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SnAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GASEASIERINPUTEXTENSION_API USnAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	USnAbility();
	
	UPROPERTY(BlueprintReadOnly)
	int32 InputId = -1;

private:
	inline static int32 InputIdCounter = 0;

};

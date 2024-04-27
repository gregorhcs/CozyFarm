// Copyright 2024 Thieves of the Night. All Rights Reserved.

#include "SnAbilitySystemFunctionLibrary.h"

#include "SnAbility.h"

int32 USnAbilitySystemFunctionLibrary::GetInputID(TSubclassOf<USnAbility> AbilityClass)
{
	return AbilityClass.GetDefaultObject()->InputId;
}

// Copyright 2024 Thieves of the Night. All Rights Reserved.

#include "SnAbilitySystemComponent.h"

#include "Misc/DataValidation.h"


void USnAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	GrantBeginPlayAbilities();
}

#if WITH_EDITOR
EDataValidationResult USnAbilitySystemComponent::IsDataValid(FDataValidationContext& Context) const
{
	if (!AreBeginPlayAbilitiesValid(Context))
		return EDataValidationResult::Invalid;
	
	return Super::IsDataValid(Context);
}
#endif // WITH_EDITOR

void USnAbilitySystemComponent::ReleaseInputForAbility(TSubclassOf<USnAbility> AbilityClass)
{
	if (!ensure(IsValid(AbilityClass)))
		return;
		
	ReleaseInputID(AbilityClass.GetDefaultObject()->InputId);
}

void USnAbilitySystemComponent::GrantBeginPlayAbilities()
{
	for (const TSubclassOf<USnAbility> AbilityClass : BeginPlayAbilities)
	{
		GiveAbility(FGameplayAbilitySpec(
			AbilityClass,
			1,
			AbilityClass.GetDefaultObject()->InputId
		));
	}
}

#if WITH_EDITOR
bool USnAbilitySystemComponent::AreBeginPlayAbilitiesValid(FDataValidationContext& Context) const
{
 	for (TSubclassOf<USnAbility> AbilityClass : BeginPlayAbilities)
 	{
 		if (!IsValid(AbilityClass))
 		{
 			Context.AddError(FText::FromString("SnAbilitySystemComponent::BeginPlayAbilities contains invalid entries!"));
 			return false;
 		}
 	}

 	return true;
}
#endif // WITH_EDITOR

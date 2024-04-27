// Copyright 2024 Thieves of the Night. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SnAbility.h"
#include "SnAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASEASIERINPUTEXTENSION_API USnAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<USnAbility>> BeginPlayAbilities;

	// - UActorComponent
	virtual void BeginPlay() override;
	// --
	
	UFUNCTION(BlueprintCallable)
	void ReleaseInputForAbility(TSubclassOf<USnAbility> AbilityClass);
	
	#if WITH_EDITOR
	// - UObject
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
	// --
	#endif

private:
	void GrantBeginPlayAbilities();
	
	#if WITH_EDITOR
	bool AreBeginPlayAbilitiesValid(FDataValidationContext& Context) const;
	#endif
};

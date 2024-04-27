// Copyright 2024 Thieves of the Night. All Rights Reserved.


#include "SnAbility.h"

USnAbility::USnAbility()
{
	if (InputId == -1)
	{
		InputId = InputIdCounter++;
	}
}

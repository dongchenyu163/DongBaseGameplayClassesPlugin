// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_MouseDragable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UI_MouseDraggable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DONGBASEGAMEPLAYCLASSES_API II_MouseDraggable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="", meta=(DisplayName="", Tooltip=""))
	void OnGlobalMouseUp();
	virtual void OnGlobalMouseUp_CPP() = 0;

};

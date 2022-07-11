// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CTRL_DragReleaseCPP.generated.h"

UCLASS()
class DONGBASEGAMEPLAYCLASSES_API ACTRL_DragReleaseCPP : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACTRL_DragReleaseCPP();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	virtual void Handle_MouseDown();
	void Handle_MouseUp();
	virtual void Handle_TouchDown(ETouchIndex::Type InFingerIndex, FVector InLocation);
	void Handle_TouchUp(ETouchIndex::Type InFingerIndex, FVector InLocation);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// UPROPERTY()
	// FKey aaa;
};

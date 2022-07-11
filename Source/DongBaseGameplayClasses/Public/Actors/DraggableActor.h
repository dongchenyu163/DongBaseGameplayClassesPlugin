// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DraggableActor.generated.h"

UCLASS()
class DONGBASEGAMEPLAYCLASSES_API ADraggableActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADraggableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

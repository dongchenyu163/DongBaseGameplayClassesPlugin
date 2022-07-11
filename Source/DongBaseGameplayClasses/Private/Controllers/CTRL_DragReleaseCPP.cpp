// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/CTRL_DragReleaseCPP.h"


// Sets default values
ACTRL_DragReleaseCPP::ACTRL_DragReleaseCPP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACTRL_DragReleaseCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACTRL_DragReleaseCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


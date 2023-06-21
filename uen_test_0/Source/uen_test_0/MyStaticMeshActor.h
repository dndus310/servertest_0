// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyStaticMeshActor.generated.h"

/**
 * 
 */
UCLASS()
class UEN_TEST_0_API AMyStaticMeshActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMyStaticMeshActor();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaTime ) override;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:
	FVector Gl_StartLocation;
	FVector Gl_TargetLocation;
};

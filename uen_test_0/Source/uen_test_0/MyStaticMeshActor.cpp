// Fill out your copyright notice in the Description page of Project Settings.

#include "MyStaticMeshActor.h"
#include "Kismet/KismetMathLibrary.h"



AMyStaticMeshActor::AMyStaticMeshActor()
{
    PrimaryActorTick.bCanEverTick = true;

    Speed = 100.f;

    SetMobility(EComponentMobility::Type::Movable);
}

void AMyStaticMeshActor::BeginPlay()
{
    Super::BeginPlay();

    if(HasAuthority())
    {
        SetReplicates(true);
        SetReplicateMovement(true);
        
        Gl_StartLocation = GetActorLocation();
        Gl_TargetLocation = UKismetMathLibrary::TransformLocation(GetActorTransform(), TargetLocation);
    }

}

void AMyStaticMeshActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(HasAuthority())
    {
        FVector Location = GetActorLocation();
        FVector Direction = (Gl_TargetLocation - Location).GetSafeNormal();

        float FinalDistance = (Gl_TargetLocation - Gl_StartLocation).Size();
        float CurrentDistance = (Location - Gl_StartLocation).Size();

        if(CurrentDistance >= FinalDistance)
        {
            //change Gl_StartLocation
            FVector temp = Gl_StartLocation;
            Gl_StartLocation = Gl_TargetLocation;
            Gl_TargetLocation = temp;
        }
        SetActorLocation(Location + Direction * Speed * DeltaTime);
    }

}

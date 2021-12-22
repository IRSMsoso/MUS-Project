// Fill out your copyright notice in the Description page of Project Settings.


#include "Rock.h"
#include "KismetProceduralMeshLibrary.h"
#include "ProceduralMeshComponent.h"

// Sets default values
ARock::ARock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Procedural Mesh"));
	GridX = 10;
	GridY = 10;
	GridSpacing = 20;


	RecreateProceduralMesh();
}


void ARock::RecreateProceduralMesh() {
	TArray<int32> Triangles;
	TArray<FVector2D> UVs;
	UKismetProceduralMeshLibrary::CreateGridMeshWelded(GridX, GridY, Triangles, Vertices, UVs, GridSpacing);
	ProcMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UVs, TArray<FVector2D>(), TArray<FVector2D>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);


}

// Called when the game starts or when spawned
void ARock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);




}

void ARock::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ARock, GridX)) {
		RecreateProceduralMesh();
	}
	else if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ARock, GridY)) {
		RecreateProceduralMesh();
	}

}


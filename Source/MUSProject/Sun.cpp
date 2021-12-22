// Fill out your copyright notice in the Description page of Project Settings.


#include "Sun.h"
#include "ProceduralMeshComponent.h"
#include "KismetProceduralMeshLibrary.h"

// Sets default values
ASun::ASun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Procedural Mesh"));
	

	RecreateProceduralMesh();
}

void ASun::RecreateProceduralMesh()
{
	if (!(IsValid(BaseMesh) && BaseMesh->HasValidRenderData())) {
		return;
	}
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> Tangents;
	UKismetProceduralMeshLibrary::GetSectionFromStaticMesh(BaseMesh, 0, 0, SunVertices, Triangles, Normals, UVs, Tangents);
	
	ProcMesh->CreateMeshSection(0, SunVertices, Triangles, Normals, UVs, TArray<FColor>(), Tangents, false);

	// ProcMesh->CreateMeshSection(0, Vertices, Triangles, TArray<FVector>(), UVs, TArray<FVector2D>(), TArray<FVector2D>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);

}

// Called when the game starts or when spawned
void ASun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASun::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ASun, BaseMesh)) {
		RecreateProceduralMesh();
	}
	else if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(ASun, RecreateProceduralMeshButton) && RecreateProceduralMeshButton) {
		RecreateProceduralMesh();
		RecreateProceduralMeshButton = false;
	}
}




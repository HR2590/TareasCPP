// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter.h"
#include "Components/BoxComponent.h"




// Sets default values
ATeleporter::ATeleporter():TeleportToGo(this),bHasActivated(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TeleporterMesh"));
	BoxCollision=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	Body->SetupAttachment(RootComponent);
	BoxCollision->SetupAttachment(Body);
	
}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this,&ATeleporter::OnBoxBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this,&ATeleporter::OnBoxEndOverlap);

}

// Called every frame
void ATeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




void ATeleporter::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		if (TeleportToGo!=this && TeleportToGo!=nullptr)
		{
			TeleportToGo->bHasActivated=true;
			if (!bHasActivated)
				OtherActor->SetActorLocation(TeleportToGo->GetActorLocation());
		}
}

void ATeleporter::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bHasActivated=false;
}

void ATeleporter::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName=PropertyChangedEvent.Property->GetFName();
	if (PropertyName=="TeleportToGo" && TeleportToGo!=this)
	{
		TeleportToGo->TeleportToGo=this;
		
	}
}































// Fill out your copyright notice in the Description page of Project Settings.

#include "SpringWheel.h"


// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	Wheel = CreateDefaultSubobject<USphereComponent>(FName("Wheel"));
	PhysicsConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Physics Constraint"));

	Axle = CreateDefaultSubobject<USphereComponent>(FName("Axel"));
	AxelConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("Axel Constraint"));

	SetRootComponent(PhysicsConstraint);
	Wheel->SetupAttachment(Axle);
	Axle->SetupAttachment(PhysicsConstraint);
	AxelConstraint->SetupAttachment(Axle);

}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	
	SetupConstraint();
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpringWheel::SetupConstraint()
{
	if (!GetAttachParentActor())
		return;

	UPrimitiveComponent* BodyRoot = Cast<UPrimitiveComponent>(GetAttachParentActor()->GetRootComponent());
	if (!BodyRoot)
		return;
	PhysicsConstraint->SetConstrainedComponents(BodyRoot, NAME_None, Axle, NAME_None);
	AxelConstraint->SetConstrainedComponents(Axle, NAME_None, Wheel, NAME_None);
}

void ASpringWheel::AddDrivingForce(float ForceMagnitude)
{
	Wheel->AddForce(Axle->GetForwardVector()*ForceMagnitude);
}

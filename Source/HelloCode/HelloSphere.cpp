// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloSphere.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
AHelloSphere::AHelloSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 루트 컴포넌트는 겹침과 충돌을 알려주는 구체 컴포넌트가 될 것이다.
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(220.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	// 구체 메시를 생성하고 연결한다
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereVisual->AttachTo(RootComponent);


	// 구체 컴포넌트에 속성을 적용한다
	SphereComponent->InitSphereRadius(220.0f);
	SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	// 구체 메시를 생성하고 연결한다
	SphereVisual->AttachTo(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> SphereAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (SphereAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f -50.0f));
	}

	// 파이어 파티클 시스템 생성하기 
	UParticleSystemComponent* FireParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireParticles"));

	FireParticles->AttachTo(SphereVisual);
	FireParticles->bAutoActivate = true;

	// 컴포넌트에 파이어 파티클 시스템 적용하기
	ConstructorHelpers::FObjectFinder<UParticleSystem>FireVisual(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));

	if (FireVisual.Succeeded())
	{
		FireParticles->SetTemplate(FireVisual.Object);
	}

	// 텍스트 랜더 컴포넌트 초기화
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
	
	TextRenderComponent->AttachTo(SphereVisual);

	TextRenderComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 110.0f));

	TextRenderComponent->SetHorizontalAlignment(EHTA_Center);
	TextRenderComponent->SetYScale(2.0f);
	TextRenderComponent->SetXScale(2.0f);
	TextRenderComponent->SetVisibility(true);
	TextRenderComponent->SetText(NSLOCTEXT("AnyNs", "Any", "HelloWorld"));

}

// Called when the game starts or when spawned
void AHelloSphere::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHelloSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


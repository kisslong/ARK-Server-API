#pragma once

#include "API/Enums.h"

struct FDamageEvent
{
	FieldValue<float> ImpulseField() { return { this, "FDamageEvent.Impulse" }; }
	FieldValue<float> OriginalDamageField() { return { this, "FDamageEvent.OriginalDamage" }; }
	FieldValue<int> InstanceBodyIndexField() { return { this, "FDamageEvent.InstanceBodyIndex" }; }
	FieldValue<TSubclassOf<UDamageType>> DamageTypeClassField() { return { this, "FDamageEvent.DamageTypeClass" }; }

	// Functions

	void GetBestHitInfo(AActor * HitActor, AActor * HitInstigator, FHitResult * OutHitInfo, FVector * OutImpulseDir) { NativeCall<void, AActor *, AActor *, FHitResult *, FVector *>(this, "FDamageEvent.GetBestHitInfo", HitActor, HitInstigator, OutHitInfo, OutImpulseDir); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FDamageEvent.StaticStruct"); }
};

struct UPhysicalMaterial
{
};
struct FBodyInstance
{
};

struct __declspec(align(8)) FHitResult
{
	unsigned __int32 bBlockingHit : 1;
	unsigned __int32 bStartPenetrating : 1;
	unsigned __int32 bVolatileCollision : 1;
	float Time;
	FVector_NetQuantize Location;
	FVector_NetQuantizeNormal Normal;
	FVector_NetQuantize ImpactPoint;
	FVector_NetQuantizeNormal ImpactNormal;
	FVector_NetQuantize TraceStart;
	FVector_NetQuantize TraceEnd;
	float PenetrationDepth;
	int Item;
	TWeakObjectPtr<UPhysicalMaterial> PhysMaterial;
	TWeakObjectPtr<AActor> Actor;
	TWeakObjectPtr<UPrimitiveComponent> Component;
	FBodyInstance *BodyInstance;
	FName BoneName;
	int FaceIndex;

	// Functions

	void operator=(FHitResult * __that) { NativeCall<void, FHitResult *>(this, "FHitResult.operator=", __that); }
	AActor * GetActor() { return NativeCall<AActor *>(this, "FHitResult.GetActor"); }
	UPrimitiveComponent * GetComponent() { return NativeCall<UPrimitiveComponent *>(this, "FHitResult.GetComponent"); }
	static UScriptStruct * StaticStruct() { return NativeCall<UScriptStruct *>(nullptr, "FHitResult.StaticStruct"); }
};

struct FOverlapInfo
{
	bool bFromSweep;
	FHitResult OverlapInfo;
	void *CachedCompPtr;
};

struct FInternetAddr
{
};

struct FSocket
{
	FieldValue<ESocketType> SocketTypeField() { return { this, "FSocket.SocketType" }; }
	FieldValue<FString> SocketDescriptionField() { return { this, "FSocket.SocketDescription" }; }
};

struct FSocketBSD : FSocket
{
	FieldValue<unsigned __int64> SocketField() { return { this, "FSocketBSD.Socket" }; }
	FieldValue<FDateTime> LastActivityTimeField() { return { this, "FSocketBSD.LastActivityTime" }; }
	//FieldValue<ISocketSubsystem *> SocketSubsystemField() { return { this, "FSocketBSD.SocketSubsystem" }; }

	// Functions

	bool Close() { return NativeCall<bool>(this, "FSocketBSD.Close"); }
	bool Bind(FInternetAddr * Addr) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.Bind", Addr); }
	bool Connect(FInternetAddr * Addr) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.Connect", Addr); }
	bool Listen(int MaxBacklog) { return NativeCall<bool, int>(this, "FSocketBSD.Listen", MaxBacklog); }
	//ESocketInternalState::Return HasState(ESocketInternalState::Param State, FTimespan WaitTime) { return NativeCall<ESocketInternalState::Return, ESocketInternalState::Param, FTimespan>(this, "FSocketBSD.HasState", State, WaitTime); }
	bool HasPendingConnection(bool * bHasPendingConnection) { return NativeCall<bool, bool *>(this, "FSocketBSD.HasPendingConnection", bHasPendingConnection); }
	bool HasPendingData(unsigned int * PendingDataSize) { return NativeCall<bool, unsigned int *>(this, "FSocketBSD.HasPendingData", PendingDataSize); }
	FSocket * Accept(FString * SocketDescription) { return NativeCall<FSocket *, FString *>(this, "FSocketBSD.Accept", SocketDescription); }
	FSocket * Accept(FInternetAddr * OutAddr, FString * SocketDescription) { return NativeCall<FSocket *, FInternetAddr *, FString *>(this, "FSocketBSD.Accept", OutAddr, SocketDescription); }
	bool SendTo(const char * Data, int Count, int * BytesSent, FInternetAddr * Destination) { return NativeCall<bool, const char *, int, int *, FInternetAddr *>(this, "FSocketBSD.SendTo", Data, Count, BytesSent, Destination); }
	bool Send(const char * Data, int Count, int * BytesSent) { return NativeCall<bool, const char *, int, int *>(this, "FSocketBSD.Send", Data, Count, BytesSent); }
	bool RecvFrom(char * Data, int BufferSize, int * BytesRead, FInternetAddr * Source, ESocketReceiveFlags::Type Flags) { return NativeCall<bool, char *, int, int *, FInternetAddr *, ESocketReceiveFlags::Type>(this, "FSocketBSD.RecvFrom", Data, BufferSize, BytesRead, Source, Flags); }
	bool Recv(char * Data, int BufferSize, int * BytesRead, ESocketReceiveFlags::Type Flags) { return NativeCall<bool, char *, int, int *, ESocketReceiveFlags::Type>(this, "FSocketBSD.Recv", Data, BufferSize, BytesRead, Flags); }
	//bool Wait(ESocketWaitConditions::Type Condition, FTimespan WaitTime) { return NativeCall<bool, ESocketWaitConditions::Type, FTimespan>(this, "FSocketBSD.Wait", Condition, WaitTime); }
	ESocketConnectionState GetConnectionState() { return NativeCall<ESocketConnectionState>(this, "FSocketBSD.GetConnectionState"); }
	void GetAddress(FInternetAddr * OutAddr) { NativeCall<void, FInternetAddr *>(this, "FSocketBSD.GetAddress", OutAddr); }
	bool SetNonBlocking(bool bIsNonBlocking) { return NativeCall<bool, bool>(this, "FSocketBSD.SetNonBlocking", bIsNonBlocking); }
	bool SetBroadcast(bool bAllowBroadcast) { return NativeCall<bool, bool>(this, "FSocketBSD.SetBroadcast", bAllowBroadcast); }
	bool JoinMulticastGroup(FInternetAddr * GroupAddress) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.JoinMulticastGroup", GroupAddress); }
	bool LeaveMulticastGroup(FInternetAddr * GroupAddress) { return NativeCall<bool, FInternetAddr *>(this, "FSocketBSD.LeaveMulticastGroup", GroupAddress); }
	bool SetMulticastLoopback(bool bLoopback) { return NativeCall<bool, bool>(this, "FSocketBSD.SetMulticastLoopback", bLoopback); }
	bool SetMulticastTtl(char TimeToLive) { return NativeCall<bool, char>(this, "FSocketBSD.SetMulticastTtl", TimeToLive); }
	bool SetReuseAddr(bool bAllowReuse) { return NativeCall<bool, bool>(this, "FSocketBSD.SetReuseAddr", bAllowReuse); }
	bool SetLinger(bool bShouldLinger, int Timeout) { return NativeCall<bool, bool, int>(this, "FSocketBSD.SetLinger", bShouldLinger, Timeout); }
	bool SetSendBufferSize(int Size, int * NewSize) { return NativeCall<bool, int, int *>(this, "FSocketBSD.SetSendBufferSize", Size, NewSize); }
	bool SetReceiveBufferSize(int Size, int * NewSize) { return NativeCall<bool, int, int *>(this, "FSocketBSD.SetReceiveBufferSize", Size, NewSize); }
	int GetPortNo() { return NativeCall<int>(this, "FSocketBSD.GetPortNo"); }
	//void FThreadedFSocketBSD(unsigned __int64 InSocket, ESocketType InSocketType, FString * InSocketDescription, ISocketSubsystem * InSubsystem) { NativeCall<void, unsigned __int64, ESocketType, FString *, ISocketSubsystem *>(this, "FSocketBSD.FThreadedFSocketBSD", InSocket, InSocketType, InSocketDescription, InSubsystem); }
};

struct RCONClientConnection
{
	FieldValue<FSocket *> SocketField() { return { this, "RCONClientConnection.Socket" }; }
	FieldValue<UShooterCheatManager *> CheatManagerField() { return { this, "RCONClientConnection.CheatManager" }; }
	FieldValue<bool> IsAuthenticatedField() { return { this, "RCONClientConnection.IsAuthenticated" }; }
	FieldValue<bool> IsClosedField() { return { this, "RCONClientConnection.IsClosed" }; }
	FieldValue<TArray<signed char>> DataBufferField() { return { this, "RCONClientConnection.DataBuffer" }; }
	FieldValue<unsigned int> CurrentPacketSizeField() { return { this, "RCONClientConnection.CurrentPacketSize" }; }
	FieldValue<long double> LastReceiveTimeField() { return { this, "RCONClientConnection.LastReceiveTime" }; }
	FieldValue<long double> LastSendKeepAliveTimeField() { return { this, "RCONClientConnection.LastSendKeepAliveTime" }; }
	FieldValue<FString> ServerPasswordField() { return { this, "RCONClientConnection.ServerPassword" }; }

	// Functions

	void Tick(long double WorldTime, UWorld * InWorld) { NativeCall<void, long double, UWorld *>(this, "RCONClientConnection.Tick", WorldTime, InWorld); }
	void ProcessRCONPacket(RCONPacket * Packet, UWorld * InWorld) { NativeCall<void, RCONPacket *, UWorld *>(this, "RCONClientConnection.ProcessRCONPacket", Packet, InWorld); }
	void SendMessageW(int Id, int Type, FString * OutGoingMessage) { NativeCall<void, int, int, FString *>(this, "RCONClientConnection.SendMessageW", Id, Type, OutGoingMessage); }
	void Close() { NativeCall<void>(this, "RCONClientConnection.Close"); }
};

struct RCONPacket
{
	int Length;
	int Id;
	int Type;
	FString Body;
};

struct UGameplayStatics
{
	static APlayerController * GetPlayerController(UObject * WorldContextObject, int PlayerIndex) { return NativeCall<APlayerController *, UObject *, int>(nullptr, "UGameplayStatics.GetPlayerController", WorldContextObject, PlayerIndex); }
	static APlayerController * CreatePlayer(UObject * WorldContextObject, int ControllerId, bool bSpawnPawn) { return NativeCall<APlayerController *, UObject *, int, bool>(nullptr, "UGameplayStatics.CreatePlayer", WorldContextObject, ControllerId, bSpawnPawn); }
	static void SetGlobalTimeDilation(UObject * WorldContextObject, float TimeDilation) { NativeCall<void, UObject *, float>(nullptr, "UGameplayStatics.SetGlobalTimeDilation", WorldContextObject, TimeDilation); }
	static bool SetGamePaused(UObject * WorldContextObject, bool bPaused) { return NativeCall<bool, UObject *, bool>(nullptr, "UGameplayStatics.SetGamePaused", WorldContextObject, bPaused); }
	static bool ApplyRadialDamage(UObject * WorldContextObject, float BaseDamage, FVector * Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, AActor * DamageCauser, AController * InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { return NativeCall<bool, UObject *, float, FVector *, float, TSubclassOf<UDamageType>, TArray<AActor *> *, AActor *, AController *, bool, ECollisionChannel, float>(nullptr, "UGameplayStatics.ApplyRadialDamage", WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageIgnoreDamageActors(UObject * WorldContextObject, float BaseDamage, FVector * Origin, float DamageRadius, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, TArray<AActor *> * IgnoreDamageActors, AActor * DamageCauser, AController * InstigatedByController, bool bDoFullDamage, ECollisionChannel DamagePreventionChannel, float Impulse) { return NativeCall<bool, UObject *, float, FVector *, float, TSubclassOf<UDamageType>, TArray<AActor *> *, TArray<AActor *> *, AActor *, AController *, bool, ECollisionChannel, float>(nullptr, "UGameplayStatics.ApplyRadialDamageIgnoreDamageActors", WorldContextObject, BaseDamage, Origin, DamageRadius, DamageTypeClass, IgnoreActors, IgnoreDamageActors, DamageCauser, InstigatedByController, bDoFullDamage, DamagePreventionChannel, Impulse); }
	static bool ApplyRadialDamageWithFalloff(UObject * WorldContextObject, float BaseDamage, float MinimumDamage, FVector * Origin, float DamageInnerRadius, float DamageOuterRadius, float DamageFalloff, TSubclassOf<UDamageType> DamageTypeClass, TArray<AActor *> * IgnoreActors, AActor * DamageCauser, AController * InstigatedByController, ECollisionChannel DamagePreventionChannel, float Impulse, TArray<AActor *> * IgnoreDamageActors, int NumAdditionalAttempts) { return NativeCall<bool, UObject *, float, float, FVector *, float, float, float, TSubclassOf<UDamageType>, TArray<AActor *> *, AActor *, AController *, ECollisionChannel, float, TArray<AActor *> *, int>(nullptr, "UGameplayStatics.ApplyRadialDamageWithFalloff", WorldContextObject, BaseDamage, MinimumDamage, Origin, DamageInnerRadius, DamageOuterRadius, DamageFalloff, DamageTypeClass, IgnoreActors, DamageCauser, InstigatedByController, DamagePreventionChannel, Impulse, IgnoreDamageActors, NumAdditionalAttempts); }
	static void ApplyPointDamage(AActor * DamagedActor, float BaseDamage, FVector * HitFromDirection, FHitResult * HitInfo, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> DamageTypeClass, float Impulse, bool bForceCollisionCheck, ECollisionChannel ForceCollisionCheckTraceChannel) { NativeCall<void, AActor *, float, FVector *, FHitResult *, AController *, AActor *, TSubclassOf<UDamageType>, float, bool, ECollisionChannel>(nullptr, "UGameplayStatics.ApplyPointDamage", DamagedActor, BaseDamage, HitFromDirection, HitInfo, EventInstigator, DamageCauser, DamageTypeClass, Impulse, bForceCollisionCheck, ForceCollisionCheckTraceChannel); }
	static void ApplyDamage(AActor * DamagedActor, float BaseDamage, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> DamageTypeClass, float Impulse) { NativeCall<void, AActor *, float, AController *, AActor *, TSubclassOf<UDamageType>, float>(nullptr, "UGameplayStatics.ApplyDamage", DamagedActor, BaseDamage, EventInstigator, DamageCauser, DamageTypeClass, Impulse); }
	static AActor * BeginSpawningActorFromBlueprint(UObject * WorldContextObject, UBlueprint * Blueprint, FTransform * SpawnTransform, bool bNoCollisionFail) { return NativeCall<AActor *, UObject *, UBlueprint *, FTransform *, bool>(nullptr, "UGameplayStatics.BeginSpawningActorFromBlueprint", WorldContextObject, Blueprint, SpawnTransform, bNoCollisionFail); }
	static AActor * BeginSpawningActorFromClass(UObject * WorldContextObject, TSubclassOf<AActor> ActorClass, FTransform * SpawnTransform, bool bNoCollisionFail) { return NativeCall<AActor *, UObject *, TSubclassOf<AActor>, FTransform *, bool>(nullptr, "UGameplayStatics.BeginSpawningActorFromClass", WorldContextObject, ActorClass, SpawnTransform, bNoCollisionFail); }
	static void OpenLevel(UObject * WorldContextObject, FName LevelName, bool bAbsolute, FString Options) { NativeCall<void, UObject *, FName, bool, FString>(nullptr, "UGameplayStatics.OpenLevel", WorldContextObject, LevelName, bAbsolute, Options); }
	static FVector * GetActorArrayAverageLocation(FVector * result, TArray<AActor *> * Actors) { return NativeCall<FVector *, FVector *, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetActorArrayAverageLocation", result, Actors); }
	static void GetActorArrayBounds(TArray<AActor *> * Actors, bool bOnlyCollidingComponents, FVector * Center, FVector * BoxExtent) { NativeCall<void, TArray<AActor *> *, bool, FVector *, FVector *>(nullptr, "UGameplayStatics.GetActorArrayBounds", Actors, bOnlyCollidingComponents, Center, BoxExtent); }
	static void GetAllActorsOfClass(UObject * WorldContextObject, TSubclassOf<AActor> ActorClass, TArray<AActor *> * OutActors) { NativeCall<void, UObject *, TSubclassOf<AActor>, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetAllActorsOfClass", WorldContextObject, ActorClass, OutActors); }
	//static void GetAllActorsWithInterface(UObject * WorldContextObject, TSubclassOf<UInterface> Interface, TArray<AActor *> * OutActors) { NativeCall<void, UObject *, TSubclassOf<UInterface>, TArray<AActor *> *>(nullptr, "UGameplayStatics.GetAllActorsWithInterface", WorldContextObject, Interface, OutActors); }
	static EPhysicalSurface GetSurfaceType(FHitResult * Hit) { return NativeCall<EPhysicalSurface, FHitResult *>(nullptr, "UGameplayStatics.GetSurfaceType", Hit); }
	static bool AreAnyListenersWithinRange(FVector Location, float MaximumRange) { return NativeCall<bool, FVector, float>(nullptr, "UGameplayStatics.AreAnyListenersWithinRange", Location, MaximumRange); }
	static void PlaySound(UObject * WorldContextObject, USoundCue * InSoundCue, USceneComponent * AttachComponent, FName AttachName, bool bFollow, float VolumeMultiplier, float PitchMultiplier) { NativeCall<void, UObject *, USoundCue *, USceneComponent *, FName, bool, float, float>(nullptr, "UGameplayStatics.PlaySound", WorldContextObject, InSoundCue, AttachComponent, AttachName, bFollow, VolumeMultiplier, PitchMultiplier); }
	static void GetAccurateRealTime(UObject * WorldContextObject, int * Seconds, float * PartialSeconds) { NativeCall<void, UObject *, int *, float *>(nullptr, "UGameplayStatics.GetAccurateRealTime", WorldContextObject, Seconds, PartialSeconds); }
};

struct FItemMultiplier
{
	TSubclassOf<UPrimalItem> ItemClass;
	float ItemMultiplier;
};

struct APrimalBuff
{
	FieldValue<float> DeactivationLifespanField() { return { this, "APrimalBuff.DeactivationLifespan" }; }
	FieldValue<FName> InstigatorAttachmentSocketField() { return { this, "APrimalBuff.InstigatorAttachmentSocket" }; }
	FieldValue<FVector> AoETraceToTargetsStartOffsetField() { return { this, "APrimalBuff.AoETraceToTargetsStartOffset" }; }
	FieldValue<TWeakObjectPtr<AActor>> TargetField() { return { this, "APrimalBuff.Target" }; }
	FieldValue<TWeakObjectPtr<UPrimalItem>> InstigatorItemField() { return { this, "APrimalBuff.InstigatorItem" }; }
	FieldValue<float> SlowInstigatorFallingAddZVelocityField() { return { this, "APrimalBuff.SlowInstigatorFallingAddZVelocity" }; }
	FieldValue<float> SlowInstigatorFallingDampenZVelocityField() { return { this, "APrimalBuff.SlowInstigatorFallingDampenZVelocity" }; }
	FieldValue<float> DeactivateAfterTimeField() { return { this, "APrimalBuff.DeactivateAfterTime" }; }
	FieldValue<float> WeaponRecoilMultiplierField() { return { this, "APrimalBuff.WeaponRecoilMultiplier" }; }
	FieldValue<float> ReceiveDamageMultiplierField() { return { this, "APrimalBuff.ReceiveDamageMultiplier" }; }
	FieldValue<float> MeleeDamageMultiplierField() { return { this, "APrimalBuff.MeleeDamageMultiplier" }; }
	FieldValue<float> DepleteInstigatorItemDurabilityPerSecondField() { return { this, "APrimalBuff.DepleteInstigatorItemDurabilityPerSecond" }; }
	FieldArray<float, 12> ValuesToAddPerSecondField() { return { this, "APrimalBuff.ValuesToAddPerSecond" }; }
	//FieldValue<FStatusValueModifierDescription> BuffDescriptionField() { return { this, "APrimalBuff.BuffDescription" }; }
	FieldValue<float> CharacterAdd_DefaultHyperthermicInsulationField() { return { this, "APrimalBuff.CharacterAdd_DefaultHyperthermicInsulation" }; }
	FieldValue<float> CharacterAdd_DefaultHypothermicInsulationField() { return { this, "APrimalBuff.CharacterAdd_DefaultHypothermicInsulation" }; }
	FieldValue<float> CharacterMultiplier_ExtraWaterConsumptionMultiplierField() { return { this, "APrimalBuff.CharacterMultiplier_ExtraWaterConsumptionMultiplier" }; }
	FieldValue<float> CharacterMultiplier_ExtraFoodConsumptionMultiplierField() { return { this, "APrimalBuff.CharacterMultiplier_ExtraFoodConsumptionMultiplier" }; }
	FieldValue<float> CharacterMultiplier_SubmergedOxygenDecreaseSpeedField() { return { this, "APrimalBuff.CharacterMultiplier_SubmergedOxygenDecreaseSpeed" }; }
	FieldValue<float> ViewMinExposureMultiplierField() { return { this, "APrimalBuff.ViewMinExposureMultiplier" }; }
	FieldValue<float> ViewMaxExposureMultiplierField() { return { this, "APrimalBuff.ViewMaxExposureMultiplier" }; }
	FieldValue<float> XPtoAddField() { return { this, "APrimalBuff.XPtoAdd" }; }
	FieldValue<float> XPtoAddRateField() { return { this, "APrimalBuff.XPtoAddRate" }; }
	FieldValue<bool> bDeactivateAfterAddingXPField() { return { this, "APrimalBuff.bDeactivateAfterAddingXP" }; }
	FieldValue<float> SubmergedMaxSpeedModifierField() { return { this, "APrimalBuff.SubmergedMaxSpeedModifier" }; }
	FieldValue<float> UnsubmergedMaxSpeedModifierField() { return { this, "APrimalBuff.UnsubmergedMaxSpeedModifier" }; }
	//FieldValue<TArray<FDamagePrimalCharacterStatusValueModifier>> CharacterStatusValueModifiersField() { return { this, "APrimalBuff.CharacterStatusValueModifiers" }; }
	FieldValue<long double> BuffStartTimeField() { return { this, "APrimalBuff.BuffStartTime" }; }
	FieldValue<UMaterialInterface *> BuffPostProcessEffectField() { return { this, "APrimalBuff.BuffPostProcessEffect" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> PreventActorClassesTargetingField() { return { this, "APrimalBuff.PreventActorClassesTargeting" }; }
	FieldValue<TArray<float>> PreventActorClassesTargetingRangesField() { return { this, "APrimalBuff.PreventActorClassesTargetingRanges" }; }
	FieldValue<TSubclassOf<APrimalBuff>> AOEOtherBuffToApplyField() { return { this, "APrimalBuff.AOEOtherBuffToApply" }; }
	FieldValue<float> AOEBuffRangeField() { return { this, "APrimalBuff.AOEBuffRange" }; }
	FieldValue<float> CharacterAOEBuffDamageField() { return { this, "APrimalBuff.CharacterAOEBuffDamage" }; }
	FieldValue<float> CharacterAOEBuffResistanceField() { return { this, "APrimalBuff.CharacterAOEBuffResistance" }; }
	FieldValue<float> Maximum2DVelocityForStaminaRecoveryField() { return { this, "APrimalBuff.Maximum2DVelocityForStaminaRecovery" }; }
	FieldValue<TArray<UMaterialInterface *>> PostprocessBlendablesToExcludeField() { return { this, "APrimalBuff.PostprocessBlendablesToExclude" }; }
	FieldValue<TArray<TWeakObjectPtr<APrimalCharacter>>> BuffedCharactersField() { return { this, "APrimalBuff.BuffedCharacters" }; }
	FieldValue<long double> LastItemDurabilityDepletionTimeField() { return { this, "APrimalBuff.LastItemDurabilityDepletionTime" }; }
	FieldValue<TSubclassOf<APrimalBuff>> BuffToGiveOnDeactivationField() { return { this, "APrimalBuff.BuffToGiveOnDeactivation" }; }
	FieldValue<TArray<TSubclassOf<APrimalBuff>>> BuffClassesToCancelOnActivationField() { return { this, "APrimalBuff.BuffClassesToCancelOnActivation" }; }
	FieldValue<TArray<TSubclassOf<APrimalBuff>>> ActivePreventsBuffClassesField() { return { this, "APrimalBuff.ActivePreventsBuffClasses" }; }
	FieldValue<TArray<TSubclassOf<APrimalCharacter>>> BuffRequiresOwnerClassField() { return { this, "APrimalBuff.BuffRequiresOwnerClass" }; }
	FieldValue<TArray<TSubclassOf<APrimalCharacter>>> BuffPreventsOwnerClassField() { return { this, "APrimalBuff.BuffPreventsOwnerClass" }; }
	FieldValue<float> XPEarningMultiplierField() { return { this, "APrimalBuff.XPEarningMultiplier" }; }
	FieldValue<bool> bUseBPSetupForInstigatorField() { return { this, "APrimalBuff.bUseBPSetupForInstigator" }; }
	FieldValue<bool> bUseBPDeactivatedField() { return { this, "APrimalBuff.bUseBPDeactivated" }; }
	FieldValue<bool> bUseBPCustomAllowAddBuffField() { return { this, "APrimalBuff.bUseBPCustomAllowAddBuff" }; }
	FieldValue<FVector> staticPathingDestinationField() { return { this, "APrimalBuff.staticPathingDestination" }; }
	FieldValue<long double> TickingDeactivationTimeField() { return { this, "APrimalBuff.TickingDeactivationTime" }; }
	//FieldValue<UPrimalBuffPersistentData *> MyBuffPersistentDataField() { return { this, "APrimalBuff.MyBuffPersistentData" }; }
	//FieldValue<TSubclassOf<UPrimalBuffPersistentData>> BuffPersistentDataClassField() { return { this, "APrimalBuff.BuffPersistentDataClass" }; }
	//FieldValue<TArray<FMaxStatScaler>> MaxStatScalersField() { return { this, "APrimalBuff.MaxStatScalers" }; }
	FieldValue<TWeakObjectPtr<AActor>> DamageCauserField() { return { this, "APrimalBuff.DamageCauser" }; }
	FieldValue<USoundBase *> ExtraActivationSoundToPlayField() { return { this, "APrimalBuff.ExtraActivationSoundToPlay" }; }
	FieldValue<bool> bPersistentBuffSurvivesLevelUpField() { return { this, "APrimalBuff.bPersistentBuffSurvivesLevelUp" }; }
	FieldValue<float> AoEApplyDamageField() { return { this, "APrimalBuff.AoEApplyDamage" }; }
	FieldValue<float> AoEApplyDamageIntervalField() { return { this, "APrimalBuff.AoEApplyDamageInterval" }; }
	FieldValue<TSubclassOf<UDamageType>> AoEApplyDamageTypeField() { return { this, "APrimalBuff.AoEApplyDamageType" }; }
	FieldValue<TSubclassOf<APrimalBuff>> ForceNetworkSpatializationMaxLimitBuffTypeField() { return { this, "APrimalBuff.ForceNetworkSpatializationMaxLimitBuffType" }; }
	FieldValue<int> ForceNetworkSpatializationBuffMaxLimitNumField() { return { this, "APrimalBuff.ForceNetworkSpatializationBuffMaxLimitNum" }; }
	FieldValue<float> ForceNetworkSpatializationBuffMaxLimitRangeField() { return { this, "APrimalBuff.ForceNetworkSpatializationBuffMaxLimitRange" }; }
	FieldValue<float> InsulationRangeField() { return { this, "APrimalBuff.InsulationRange" }; }
	FieldValue<float> HyperThermiaInsulationField() { return { this, "APrimalBuff.HyperThermiaInsulation" }; }
	FieldValue<float> HypoThermiaInsulationField() { return { this, "APrimalBuff.HypoThermiaInsulation" }; }
	FieldValue<FVector> AoEBuffLocOffsetField() { return { this, "APrimalBuff.AoEBuffLocOffset" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> AoEClassesToIncludeField() { return { this, "APrimalBuff.AoEClassesToInclude" }; }
	FieldValue<TArray<TSubclassOf<AActor>>> AoEClassesToExcludeField() { return { this, "APrimalBuff.AoEClassesToExclude" }; }
	FieldValue<bool> bUseBPExcludeAoEActorField() { return { this, "APrimalBuff.bUseBPExcludeAoEActor" }; }
	FieldValue<bool> bOverrideBuffDescriptionField() { return { this, "APrimalBuff.bOverrideBuffDescription" }; }
	FieldValue<bool> bOnlyTickWhenPossessedField() { return { this, "APrimalBuff.bOnlyTickWhenPossessed" }; }
	FieldValue<bool> bDestroyWhenUnpossessedField() { return { this, "APrimalBuff.bDestroyWhenUnpossessed" }; }
	FieldValue<long double> LastAoEApplyDamageTimeField() { return { this, "APrimalBuff.LastAoEApplyDamageTime" }; }
	FieldValue<float> OnlyForInstigatorSoundFadeInTimeField() { return { this, "APrimalBuff.OnlyForInstigatorSoundFadeInTime" }; }
	FieldValue<bool> bUseBuffTickServerField() { return { this, "APrimalBuff.bUseBuffTickServer" }; }
	FieldValue<bool> bUseBuffTickClientField() { return { this, "APrimalBuff.bUseBuffTickClient" }; }
	FieldValue<float> BuffTickServerMaxTimeField() { return { this, "APrimalBuff.BuffTickServerMaxTime" }; }
	FieldValue<float> BuffTickServerMinTimeField() { return { this, "APrimalBuff.BuffTickServerMinTime" }; }
	FieldValue<float> BuffTickClientMaxTimeField() { return { this, "APrimalBuff.BuffTickClientMaxTime" }; }
	FieldValue<float> BuffTickClientMinTimeField() { return { this, "APrimalBuff.BuffTickClientMinTime" }; }
	FieldValue<long double> LastBuffTickTimeServerField() { return { this, "APrimalBuff.LastBuffTickTimeServer" }; }
	FieldValue<long double> LastBuffTickTimeClientField() { return { this, "APrimalBuff.LastBuffTickTimeClient" }; }
	FieldValue<long double> NextBuffTickTimeServerField() { return { this, "APrimalBuff.NextBuffTickTimeServer" }; }
	FieldValue<long double> NextBuffTickTimeClientField() { return { this, "APrimalBuff.NextBuffTickTimeClient" }; }
	FieldValue<bool> bTickFunctionDisabledField() { return { this, "APrimalBuff.bTickFunctionDisabled" }; }
	FieldValue<bool> bWasStasisedField() { return { this, "APrimalBuff.bWasStasised" }; }
	FieldValue<int> AddBuffMaxNumStacksField() { return { this, "APrimalBuff.AddBuffMaxNumStacks" }; }
	FieldValue<USoundBase *> DeactivatedSoundField() { return { this, "APrimalBuff.DeactivatedSound" }; }
	FieldValue<bool> bDeactivatedSoundOnlyLocalField() { return { this, "APrimalBuff.bDeactivatedSoundOnlyLocal" }; }
	FieldValue<bool> bDisableBloomField() { return { this, "APrimalBuff.bDisableBloom" }; }
	FieldValue<bool> bBPOverrideCharacterNewFallVelocityField() { return { this, "APrimalBuff.bBPOverrideCharacterNewFallVelocity" }; }
	FieldValue<bool> bBPModifyCharacterFOVField() { return { this, "APrimalBuff.bBPModifyCharacterFOV" }; }
	FieldValue<bool> bDisableLightShaftsField() { return { this, "APrimalBuff.bDisableLightShafts" }; }
	FieldValue<float> PostProcessInterpSpeedDownField() { return { this, "APrimalBuff.PostProcessInterpSpeedDown" }; }
	FieldValue<float> PostProcessInterpSpeedUpField() { return { this, "APrimalBuff.PostProcessInterpSpeedUp" }; }
	FieldValue<float> TPVCameraSpeedInterpolationMultiplierField() { return { this, "APrimalBuff.TPVCameraSpeedInterpolationMultiplier" }; }
	FieldValue<bool> bIsCarryBuffField() { return { this, "APrimalBuff.bIsCarryBuff" }; }
	FieldValue<long double> TimeForNextAOECheckField() { return { this, "APrimalBuff.TimeForNextAOECheck" }; }
	FieldValue<float> AOEBuffIntervalMinField() { return { this, "APrimalBuff.AOEBuffIntervalMin" }; }
	FieldValue<float> AOEBuffIntervalMaxField() { return { this, "APrimalBuff.AOEBuffIntervalMax" }; }
	FieldValue<float> MaximumVelocityZForSlowingFallField() { return { this, "APrimalBuff.MaximumVelocityZForSlowingFall" }; }
	FieldValue<int> FNameIntField() { return { this, "APrimalBuff.FNameInt" }; }

	// Functions

	bool TemplateAllowActorSpawn(UWorld * World, FVector * AtLocation, FRotator * AtRotation, FActorSpawnParameters * SpawnParameters) { return NativeCall<bool, UWorld *, FVector *, FRotator *, FActorSpawnParameters *>(this, "APrimalBuff.TemplateAllowActorSpawn", World, AtLocation, AtRotation, SpawnParameters); }
	void Deactivate() { NativeCall<void>(this, "APrimalBuff.Deactivate"); }
	void NetDeactivate_Implementation() { NativeCall<void>(this, "APrimalBuff.NetDeactivate_Implementation"); }
	void BeginPlay() { NativeCall<void>(this, "APrimalBuff.BeginPlay"); }
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> * OutLifetimeProps) { NativeCall<void, TArray<FLifetimeProperty> *>(this, "APrimalBuff.GetLifetimeReplicatedProps", OutLifetimeProps); }
	void AddDamageStatusValueModifier(APrimalCharacter * addToCharacter, EPrimalCharacterStatusValue::Type ValueType, bool bSpeedToAddInSeconds, bool bContinueOnUnchangedValue, bool bResetExistingModifierDescriptionIndex, bool bSetValue, bool bSetAdditionalValue, float LimitExistingModifierDescriptionToMaxAmount, float damageMultiplierAmountToAdd, float speedToAdd, int StatusValueModifierDescriptionIndex, bool bUsePercentualDamage, bool bMakeUntameable, float percentualDamage, TSubclassOf<UDamageType> ScaleValueByCharacterDamageType) { NativeCall<void, APrimalCharacter *, EPrimalCharacterStatusValue::Type, bool, bool, bool, bool, bool, float, float, float, int, bool, bool, float, TSubclassOf<UDamageType>>(this, "APrimalBuff.AddDamageStatusValueModifier", addToCharacter, ValueType, bSpeedToAddInSeconds, bContinueOnUnchangedValue, bResetExistingModifierDescriptionIndex, bSetValue, bSetAdditionalValue, LimitExistingModifierDescriptionToMaxAmount, damageMultiplierAmountToAdd, speedToAdd, StatusValueModifierDescriptionIndex, bUsePercentualDamage, bMakeUntameable, percentualDamage, ScaleValueByCharacterDamageType); }
	void SetupForInstigator() { NativeCall<void>(this, "APrimalBuff.SetupForInstigator"); }
	void Tick(float DeltaSeconds) { NativeCall<void, float>(this, "APrimalBuff.Tick", DeltaSeconds); }
	void ProcessStaticPathing(bool triggerRunning) { NativeCall<void, bool>(this, "APrimalBuff.ProcessStaticPathing", triggerRunning); }
	FVector * UpdateStaticPathingDestination(FVector * result, FVector locOverride, float randomOffsetMultiplier, bool useRandomNegativeXDir, bool orientRandOffsetByRotation, FRotator randOffsetByRotation, float GroundCheckSpreadOverride) { return NativeCall<FVector *, FVector *, FVector, float, bool, bool, FRotator, float>(this, "APrimalBuff.UpdateStaticPathingDestination", result, locOverride, randomOffsetMultiplier, useRandomNegativeXDir, orientRandOffsetByRotation, randOffsetByRotation, GroundCheckSpreadOverride); }
	void EnableTickFunction() { NativeCall<void>(this, "APrimalBuff.EnableTickFunction"); }
	bool AOEBuffCanAffect(APrimalCharacter * forChar) { return NativeCall<bool, APrimalCharacter *>(this, "APrimalBuff.AOEBuffCanAffect", forChar); }
	void InstigatorJumped() { NativeCall<void>(this, "APrimalBuff.InstigatorJumped"); }
	void Destroyed() { NativeCall<void>(this, "APrimalBuff.Destroyed"); }
	void NetResetBuffStart_Implementation() { NativeCall<void>(this, "APrimalBuff.NetResetBuffStart_Implementation"); }
	bool ResetBuffStart() { return NativeCall<bool>(this, "APrimalBuff.ResetBuffStart"); }
	APrimalBuff * AddBuff(APrimalCharacter * ForCharacter, AActor * DamageCauser) { return NativeCall<APrimalBuff *, APrimalCharacter *, AActor *>(this, "APrimalBuff.AddBuff", ForCharacter, DamageCauser); }
	static APrimalBuff * StaticAddBuff(TSubclassOf<APrimalBuff> BuffClass, APrimalCharacter * ForCharacter, UPrimalItem * AssociatedItem, AActor * DamageCauser, bool bForceOnClient) { return NativeCall<APrimalBuff *, TSubclassOf<APrimalBuff>, APrimalCharacter *, UPrimalItem *, AActor *, bool>(nullptr, "APrimalBuff.StaticAddBuff", BuffClass, ForCharacter, AssociatedItem, DamageCauser, bForceOnClient); }
	bool ExcludePostProcessBlendableMaterial(UMaterialInterface * BlendableMaterialInterface) { return NativeCall<bool, UMaterialInterface *>(this, "APrimalBuff.ExcludePostProcessBlendableMaterial", BlendableMaterialInterface); }
	bool PreventActorTargeting_Implementation(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalBuff.PreventActorTargeting_Implementation", ByActor); }
	bool PreventRunning() { return NativeCall<bool>(this, "APrimalBuff.PreventRunning"); }
	bool ExcludeAoEActor(AActor * ActorToConsider) { return NativeCall<bool, AActor *>(this, "APrimalBuff.ExcludeAoEActor", ActorToConsider); }
	bool HideBuffFromHUD_Implementation() { return NativeCall<bool>(this, "APrimalBuff.HideBuffFromHUD_Implementation"); }
	void Stasis() { NativeCall<void>(this, "APrimalBuff.Stasis"); }
	void Unstasis() { NativeCall<void>(this, "APrimalBuff.Unstasis"); }
	bool ExtendBuffTime(float AmountOfAdditionalTime) { return NativeCall<bool, float>(this, "APrimalBuff.ExtendBuffTime", AmountOfAdditionalTime); }
	int GetBuffType_Implementation() { return NativeCall<int>(this, "APrimalBuff.GetBuffType_Implementation"); }
	bool ReduceBuffTime(float AmountOfTimeToReduce) { return NativeCall<bool, float>(this, "APrimalBuff.ReduceBuffTime", AmountOfTimeToReduce); }
	static UClass * StaticClass() { return NativeCall<UClass *>(nullptr, "APrimalBuff.StaticClass"); }
	static void StaticRegisterNativesAPrimalBuff() { NativeCall<void>(nullptr, "APrimalBuff.StaticRegisterNativesAPrimalBuff"); }
	void BPDrawBuffStatusHUD(AShooterHUD * HUD, float XPos, float YPos, float ScaleMult) { NativeCall<void, AShooterHUD *, float, float, float>(this, "APrimalBuff.BPDrawBuffStatusHUD", HUD, XPos, YPos, ScaleMult); }
	float BuffAdjustDamage(float Damage, FHitResult * HitInfo, AController * EventInstigator, AActor * DamageCauser, TSubclassOf<UDamageType> TheDamgeType) { return NativeCall<float, float, FHitResult *, AController *, AActor *, TSubclassOf<UDamageType>>(this, "APrimalBuff.BuffAdjustDamage", Damage, HitInfo, EventInstigator, DamageCauser, TheDamgeType); }
	void BuffTickClient(float DeltaTime) { NativeCall<void, float>(this, "APrimalBuff.BuffTickClient", DeltaTime); }
	void BuffTickServer(float DeltaTime) { NativeCall<void, float>(this, "APrimalBuff.BuffTickServer", DeltaTime); }
	void DrawBuffFloatingHUD(int BuffIndex, AShooterHUD * HUD, float CenterX, float CenterY, float DrawScale) { NativeCall<void, int, AShooterHUD *, float, float, float>(this, "APrimalBuff.DrawBuffFloatingHUD", BuffIndex, HUD, CenterX, CenterY, DrawScale); }
	void NotifyDamage(float DamageAmount, TSubclassOf<UDamageType> DamageClass, AController * EventInstigator, AActor * TheDamageCauser) { NativeCall<void, float, TSubclassOf<UDamageType>, AController *, AActor *>(this, "APrimalBuff.NotifyDamage", DamageAmount, DamageClass, EventInstigator, TheDamageCauser); }
	bool PreventActorTargeting(AActor * ByActor) { return NativeCall<bool, AActor *>(this, "APrimalBuff.PreventActorTargeting", ByActor); }
	void SetBuffCauser(AActor * CausedBy) { NativeCall<void, AActor *>(this, "APrimalBuff.SetBuffCauser", CausedBy); }
};

struct UPrimalEngramEntry
{
	FieldValue<int> RequiredCharacterLevelField() { return { this, "UPrimalEngramEntry.RequiredCharacterLevel" }; }
	FieldValue<int> RequiredEngramPointsField() { return { this, "UPrimalEngramEntry.RequiredEngramPoints" }; }
	FieldValue<TSubclassOf<UPrimalItem>> BluePrintEntryField() { return { this, "UPrimalEngramEntry.BluePrintEntry" }; }
	FieldValue<FString> ExtraEngramDescriptionField() { return { this, "UPrimalEngramEntry.ExtraEngramDescription" }; }
	//FieldValue<TArray<FEngramEntries>> EngramRequirementSetsField() { return { this, "UPrimalEngramEntry.EngramRequirementSets" }; }
	FieldValue<int> MyEngramIndexField() { return { this, "UPrimalEngramEntry.MyEngramIndex" }; }
	FieldValue<TEnumAsByte<enum EEngramGroup::Type>> EngramGroupField() { return { this, "UPrimalEngramEntry.EngramGroup" }; }

	// Functions

	UObject * GetObjectW() { return NativeCall<UObject *>(this, "UPrimalEngramEntry.GetObjectW"); }
	FString * GetEntryString(FString * result) { return NativeCall<FString *, FString *>(this, "UPrimalEngramEntry.GetEntryString", result); }
	UTexture2D * GetEntryIcon(UObject * AssociatedDataObject, bool bIsEnabled) { return NativeCall<UTexture2D *, UObject *, bool>(this, "UPrimalEngramEntry.GetEntryIcon", AssociatedDataObject, bIsEnabled); }
	bool MeetsEngramRequirements(AShooterPlayerState * aPlayerState, bool bOnlyCheckLevel, bool bDontCheckEngramPreRequirements) { return NativeCall<bool, AShooterPlayerState *, bool, bool>(this, "UPrimalEngramEntry.MeetsEngramRequirements", aPlayerState, bOnlyCheckLevel, bDontCheckEngramPreRequirements); }
	bool MeetsEngramChainRequirements(AShooterPlayerState * aPlayerState) { return NativeCall<bool, AShooterPlayerState *>(this, "UPrimalEngramEntry.MeetsEngramChainRequirements", aPlayerState); }
	FString * GetEngramDescription(FString * result, AShooterPlayerState * aPlayerState) { return NativeCall<FString *, FString *, AShooterPlayerState *>(this, "UPrimalEngramEntry.GetEngramDescription", result, aPlayerState); }
	FString * GetEngramName(FString * result) { return NativeCall<FString *, FString *>(this, "UPrimalEngramEntry.GetEngramName", result); }
	int GetRequiredEngramPoints() { return NativeCall<int>(this, "UPrimalEngramEntry.GetRequiredEngramPoints"); }
	int GetRequiredLevel() { return NativeCall<int>(this, "UPrimalEngramEntry.GetRequiredLevel"); }
	bool UseEngramRequirementSets() { return NativeCall<bool>(this, "UPrimalEngramEntry.UseEngramRequirementSets"); }
	bool IsEngramClassHidden(TSubclassOf<UPrimalItem> ForItemClass) { return NativeCall<bool, TSubclassOf<UPrimalItem>>(this, "UPrimalEngramEntry.IsEngramClassHidden", ForItemClass); }
	void GetAllChainedPreReqs(AShooterPlayerState * aPlayerState, TArray<TSubclassOf<UPrimalEngramEntry>> * TestedEntries) { NativeCall<void, AShooterPlayerState *, TArray<TSubclassOf<UPrimalEngramEntry>> *>(this, "UPrimalEngramEntry.GetAllChainedPreReqs", aPlayerState, TestedEntries); }
	int GetChainRequiredEngramPoints(TArray<TSubclassOf<UPrimalEngramEntry>> * TestedEntries) { return NativeCall<int, TArray<TSubclassOf<UPrimalEngramEntry>> *>(this, "UPrimalEngramEntry.GetChainRequiredEngramPoints", TestedEntries); }
	void ClearHiddenEngramRequirements() { NativeCall<void>(this, "UPrimalEngramEntry.ClearHiddenEngramRequirements"); }
};

struct FDinoAncestorsEntry
{
	FString MaleName;
	unsigned int MaleDinoID1;
	unsigned int MaleDinoID2;
	FString FemaleName;
	unsigned int FemaleDinoID1;
	unsigned int FemaleDinoID2;
};

struct FCraftingResourceRequirement
{
	float BaseResourceRequirement;
	TSubclassOf<UPrimalItem> ResourceItemType;
	bool bCraftingRequireExactResourceType;
};

struct UKismetSystemLibrary
{
	static FString * GetDisplayName(FString * result, UObject * Object) { return NativeCall<FString *, FString *, UObject *>(nullptr, "UKismetSystemLibrary.GetDisplayName", result, Object); }
	static bool IsDedicatedServer(UObject * WorldContextObject) { return NativeCall<bool, UObject *>(nullptr, "UKismetSystemLibrary.IsDedicatedServer", WorldContextObject); }
	static void K2_SetTimer(UObject * Object, FString FunctionName, float Time, bool bLooping) { NativeCall<void, UObject *, FString, float, bool>(nullptr, "UKismetSystemLibrary.K2_SetTimer", Object, FunctionName, Time, bLooping); }
	static void K2_SetTimerForNextTick(UObject * Object, FString FunctionName, bool bLooping) { NativeCall<void, UObject *, FString, bool>(nullptr, "UKismetSystemLibrary.K2_SetTimerForNextTick", Object, FunctionName, bLooping); }
	static void K2_ClearTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_ClearTimer", Object, FunctionName); }
	static void K2_PauseTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_PauseTimer", Object, FunctionName); }
	static void K2_UnPauseTimer(UObject * Object, FString FunctionName) { NativeCall<void, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_UnPauseTimer", Object, FunctionName); }
	static bool K2_IsTimerActive(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_IsTimerActive", Object, FunctionName); }
	static bool K2_IsTimerPaused(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_IsTimerPaused", Object, FunctionName); }
	static bool K2_TimerExists(UObject * Object, FString FunctionName) { return NativeCall<bool, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_TimerExists", Object, FunctionName); }
	static float K2_GetTimerElapsedTime(UObject * Object, FString FunctionName) { return NativeCall<float, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_GetTimerElapsedTime", Object, FunctionName); }
	static float K2_GetTimerRemainingTime(UObject * Object, FString FunctionName) { return NativeCall<float, UObject *, FString>(nullptr, "UKismetSystemLibrary.K2_GetTimerRemainingTime", Object, FunctionName); }
	static void SetClassPropertyByName(UObject * Object, FName PropertyName, TSubclassOf<UObject> Value) { NativeCall<void, UObject *, FName, TSubclassOf<UObject>>(nullptr, "UKismetSystemLibrary.SetClassPropertyByName", Object, PropertyName, Value); }
	static void SetVectorPropertyByName(UObject * Object, FName PropertyName, FVector * Value) { NativeCall<void, UObject *, FName, FVector *>(nullptr, "UKismetSystemLibrary.SetVectorPropertyByName", Object, PropertyName, Value); }
	static void SetRotatorPropertyByName(UObject * Object, FName PropertyName, FRotator * Value) { NativeCall<void, UObject *, FName, FRotator *>(nullptr, "UKismetSystemLibrary.SetRotatorPropertyByName", Object, PropertyName, Value); }
	static void SetLinearColorPropertyByName(UObject * Object, FName PropertyName, FLinearColor * Value) { NativeCall<void, UObject *, FName, FLinearColor *>(nullptr, "UKismetSystemLibrary.SetLinearColorPropertyByName", Object, PropertyName, Value); }
	static void SetTransformPropertyByName(UObject * Object, FName PropertyName, FTransform * Value) { NativeCall<void, UObject *, FName, FTransform *>(nullptr, "UKismetSystemLibrary.SetTransformPropertyByName", Object, PropertyName, Value); }
	static void GetActorListFromComponentList(TArray<UPrimitiveComponent *> * ComponentList, UClass * ActorClassFilter, TArray<AActor *> * OutActorList) { NativeCall<void, TArray<UPrimitiveComponent *> *, UClass *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.GetActorListFromComponentList", ComponentList, ActorClassFilter, OutActorList); }
	static bool SphereOverlapActors_NEW(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapActors_NEW", WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapActorsSimple(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TEnumAsByte<enum EObjectTypeQuery> ObjectType, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, TEnumAsByte<enum EObjectTypeQuery>, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapActorsSimple", WorldContextObject, SpherePos, SphereRadius, ObjectType, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool SphereOverlapComponents_NEW(UObject * WorldContextObject, FVector SpherePos, float SphereRadius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.SphereOverlapComponents_NEW", WorldContextObject, SpherePos, SphereRadius, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxOverlapActors_NEW(UObject * WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.BoxOverlapActors_NEW", WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool BoxOverlapComponents_NEW(UObject * WorldContextObject, FVector BoxPos, FVector BoxExtent, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.BoxOverlapComponents_NEW", WorldContextObject, BoxPos, BoxExtent, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool CapsuleOverlapActors_NEW(UObject * WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UObject *, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.CapsuleOverlapActors_NEW", WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool CapsuleOverlapComponents_NEW(UObject * WorldContextObject, FVector CapsulePos, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UObject *, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.CapsuleOverlapComponents_NEW", WorldContextObject, CapsulePos, Radius, HalfHeight, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool ComponentOverlapActors_NEW(UPrimitiveComponent * Component, FTransform * ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ActorClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<AActor *> * OutActors) { return NativeCall<bool, UPrimitiveComponent *, FTransform *, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<AActor *> *>(nullptr, "UKismetSystemLibrary.ComponentOverlapActors_NEW", Component, ComponentTransform, ObjectTypes, ActorClassFilter, ActorsToIgnore, OutActors); }
	static bool ComponentOverlapComponents_NEW(UPrimitiveComponent * Component, FTransform * ComponentTransform, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, UClass * ComponentClassFilter, TArray<AActor *> * ActorsToIgnore, TArray<UPrimitiveComponent *> * OutComponents) { return NativeCall<bool, UPrimitiveComponent *, FTransform *, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, UClass *, TArray<AActor *> *, TArray<UPrimitiveComponent *> *>(nullptr, "UKismetSystemLibrary.ComponentOverlapComponents_NEW", Component, ComponentTransform, ObjectTypes, ComponentClassFilter, ActorsToIgnore, OutComponents); }
	static bool BoxTraceSingle(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceSingle", WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMulti(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, ETraceTypeQuery TraceChannel, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, ETraceTypeQuery, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceMulti", WorldContextObject, Start, End, HalfSize, Orientation, TraceChannel, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool LineTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.LineTraceSingleForObjects", WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool LineTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.LineTraceMultiForObjects", WorldContextObject, Start, End, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool SphereTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.SphereTraceSingleForObjects", WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool SphereTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.SphereTraceMultiForObjects", WorldContextObject, Start, End, Radius, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool BoxTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceSingleForObjects", WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool BoxTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, FVector HalfSize, FRotator Orientation, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, FVector, FRotator, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.BoxTraceMultiForObjects", WorldContextObject, Start, End, HalfSize, Orientation, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static bool CapsuleTraceSingleForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult * OutHit, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, FHitResult *, bool>(nullptr, "UKismetSystemLibrary.CapsuleTraceSingleForObjects", WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf); }
	static bool CapsuleTraceMultiForObjects(UObject * WorldContextObject, FVector Start, FVector End, float Radius, float HalfHeight, TArray<TEnumAsByte<enum EObjectTypeQuery>> * ObjectTypes, bool bTraceComplex, TArray<AActor *> * ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, TArray<FHitResult> * OutHits, bool bIgnoreSelf) { return NativeCall<bool, UObject *, FVector, FVector, float, float, TArray<TEnumAsByte<enum EObjectTypeQuery>> *, bool, TArray<AActor *> *, EDrawDebugTrace::Type, TArray<FHitResult> *, bool>(nullptr, "UKismetSystemLibrary.CapsuleTraceMultiForObjects", WorldContextObject, Start, End, Radius, HalfHeight, ObjectTypes, bTraceComplex, ActorsToIgnore, DrawDebugType, OutHits, bIgnoreSelf); }
	static void DrawDebugFrustum(UObject * WorldContextObject, FTransform * FrustumTransform, FLinearColor FrustumColor, float Duration) { NativeCall<void, UObject *, FTransform *, FLinearColor, float>(nullptr, "UKismetSystemLibrary.DrawDebugFrustum", WorldContextObject, FrustumTransform, FrustumColor, Duration); }
	static void GetActorBounds(AActor * Actor, FVector * Origin, FVector * BoxExtent) { NativeCall<void, AActor *, FVector *, FVector *>(nullptr, "UKismetSystemLibrary.GetActorBounds", Actor, Origin, BoxExtent); }
	static int GetRenderingDetailMode() { return NativeCall<int>(nullptr, "UKismetSystemLibrary.GetRenderingDetailMode"); }
	static int GetRenderingMaterialQualityLevel() { return NativeCall<int>(nullptr, "UKismetSystemLibrary.GetRenderingMaterialQualityLevel"); }
	static void ShowPlatformSpecificAchievementsScreen(APlayerController * SpecificPlayer) { NativeCall<void, APlayerController *>(nullptr, "UKismetSystemLibrary.ShowPlatformSpecificAchievementsScreen", SpecificPlayer); }
};

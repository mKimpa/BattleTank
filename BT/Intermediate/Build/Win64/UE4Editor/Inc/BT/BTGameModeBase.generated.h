// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BT_BTGameModeBase_generated_h
#error "BTGameModeBase.generated.h already included, missing '#pragma once' in BTGameModeBase.h"
#endif
#define BT_BTGameModeBase_generated_h

#define BT_Source_BT_BTGameModeBase_h_15_SPARSE_DATA
#define BT_Source_BT_BTGameModeBase_h_15_RPC_WRAPPERS
#define BT_Source_BT_BTGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define BT_Source_BT_BTGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABTGameModeBase(); \
	friend struct Z_Construct_UClass_ABTGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ABTGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/BT"), NO_API) \
	DECLARE_SERIALIZER(ABTGameModeBase)


#define BT_Source_BT_BTGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesABTGameModeBase(); \
	friend struct Z_Construct_UClass_ABTGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ABTGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/BT"), NO_API) \
	DECLARE_SERIALIZER(ABTGameModeBase)


#define BT_Source_BT_BTGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABTGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABTGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABTGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABTGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABTGameModeBase(ABTGameModeBase&&); \
	NO_API ABTGameModeBase(const ABTGameModeBase&); \
public:


#define BT_Source_BT_BTGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABTGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABTGameModeBase(ABTGameModeBase&&); \
	NO_API ABTGameModeBase(const ABTGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABTGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABTGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABTGameModeBase)


#define BT_Source_BT_BTGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define BT_Source_BT_BTGameModeBase_h_12_PROLOG
#define BT_Source_BT_BTGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BT_Source_BT_BTGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	BT_Source_BT_BTGameModeBase_h_15_SPARSE_DATA \
	BT_Source_BT_BTGameModeBase_h_15_RPC_WRAPPERS \
	BT_Source_BT_BTGameModeBase_h_15_INCLASS \
	BT_Source_BT_BTGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BT_Source_BT_BTGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BT_Source_BT_BTGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	BT_Source_BT_BTGameModeBase_h_15_SPARSE_DATA \
	BT_Source_BT_BTGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	BT_Source_BT_BTGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	BT_Source_BT_BTGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BT_API UClass* StaticClass<class ABTGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BT_Source_BT_BTGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

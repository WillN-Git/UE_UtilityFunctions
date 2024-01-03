/**
*   @author WN
*   @license MIT License
*   
*   Copyright (c) 2024 WN
*/


#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BasicHelper.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogWNBasicHelper, Log, All);


///////////////////////////////////////////////////////////////////////
//
// This class groups together various utility functions
// that can be reused in several projects.
//
///////////////////////////////////////////////////////////////////////
UCLASS()
class /* YOURPROJECT_API */ UWNBasicHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	///================ BINARY

	/*
	* NUMBER PARSING
	* ~~~~~~~~~~~~~~
	* 
	* With these functions, you can convert numerical values into bytes and vice versa.
	*/

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToFloat(TArray<uint8> InBytes, float& OutValue);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToInteger(TArray<uint8> InBytes, int32& OutValue);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToInteger64(TArray<uint8> InBytes, int64& OutValue);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseFloatToBytes(float InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseIntegerToBytes(int32 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseInterger64ToBytes(int64 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToFloatPure(TArray<uint8> InBytes, float& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToIntegerPure(TArray<uint8> InBytes, int32& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToInteger64Pure(TArray<uint8> InBytes, int64& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseFloatToBytesPure(float InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseIntegerToBytesPure(int32 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseInterger64ToBytesPure(int64 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder = false);

	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToFloatArrayPure(TArray<uint8> InBytes, TArray<float>& OutValues);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToDoubleArrayPure(TArray<uint8> InBytes, TArray<double>& OutValues);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToIntegerArrayPure(TArray<uint8> InBytes, TArray<int32>& OutValues);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseBytesToInteger64ArrayPure(TArray<uint8> InBytes, TArray<int64>& OutValues);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseFloatArrayToBytesPure(TArray<float> InValues, TArray<uint8>& OutBytes);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseIntegerArrayToBytesPure(TArray<int32> InValues, TArray<uint8>& OutBytes);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "WNBasicHelper|Binary|Number Parsing")
	static void ParseInteger64ArrayToBytesPure(TArray<int64> InValues, TArray<uint8>& OutBytes);


	///================ MISCELLANEOUS

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Miscellaneous|Format")
	static FString FormatToScientificFloat(float Value);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Miscellaneous|Format")
	static FString FormatToScientificDouble(double Value);

	UFUNCTION(BlueprintCallable, Category = "WNBasicHelper|Miscellaneous|Format")
	static FString FormatToScientificVector(FVector Vector);
};

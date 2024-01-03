#include "BasicHelper.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include <iostream>

#include UE_INLINE_GENERATED_CPP_BY_NAME(BasicHelper)

DEFINE_LOG_CATEGORY(LogWNBasicHelper);

// Bytes sizes
#define FLOAT_SIZE 4
#define INT_SIZE 4
#define INT64_SIZE 8
#define DBL_SIZE 8


///================ BINARY

/*
* NUMBER PARSING
* ~~~~~~~~~~~~~~
*
* With these functions, you can convert numerical values into bytes and vice versa.
*/


void UWNBasicHelper::ParseBytesToFloat(TArray<uint8> InBytes, float& OutValue)
{
	if (InBytes.Num() != FLOAT_SIZE)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToFloat : Cannot convert bytes to float. Array must contain %d bytes but has %d bytes."), FLOAT_SIZE, InBytes.Num());
		return;
	}

	FMemory::Memmove(&OutValue, InBytes.GetData(), FLOAT_SIZE);
}

void UWNBasicHelper::ParseBytesToInteger(TArray<uint8> InBytes, int32& OutValue)
{
	if (InBytes.Num() != INT_SIZE)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToInteger : Cannot convert bytes to integer. Array must contain %d bytes but has %d bytes."), INT_SIZE, InBytes.Num());
		return;
	}

	FMemory::Memmove(&OutValue, InBytes.GetData(), INT_SIZE);
}

void UWNBasicHelper::ParseBytesToInteger64(TArray<uint8> InBytes, int64& OutValue)
{
	if (InBytes.Num() != INT64_SIZE)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToInteger64 : Cannot convert bytes to integer64. Array must contain %d bytes but has %d bytes."), INT64_SIZE, InBytes.Num());
		return;
	}

	FMemory::Memmove(&OutValue, InBytes.GetData(), INT64_SIZE);
}

void UWNBasicHelper::ParseFloatToBytes(float InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	OutBytes.Empty();

	union
	{
		float tmpVal;
		uint8 tmpArray[FLOAT_SIZE];
	} u;

	u.tmpVal = InValue;
	OutBytes.AddUninitialized(FLOAT_SIZE);

	FMemory::Memmove(OutBytes.GetData(), u.tmpArray, FLOAT_SIZE);

	if (SwitchByteOrder)
	{
		OutBytes.SwapMemory(3, 1);
		OutBytes.SwapMemory(2, 1);
	}
}

void UWNBasicHelper::ParseIntegerToBytes(int32 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	OutBytes.Empty();

	union 
	{
		int32 tmpVal;
		uint8 tmpArray[INT_SIZE];
	} u;

	u.tmpVal = InValue;
	OutBytes.AddUninitialized(INT_SIZE);

	FMemory::Memmove(OutBytes.GetData(), u.tmpArray, INT_SIZE);

	if (SwitchByteOrder)
	{
		OutBytes.SwapMemory(3, 0);
		OutBytes.SwapMemory(2, 1);
	}
}

void UWNBasicHelper::ParseInterger64ToBytes(int64 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	OutBytes.Empty();

	union
	{
		int64 tmpVal;
		uint8 tmpArray[INT64_SIZE];
	} u;

	u.tmpVal = InValue;
	OutBytes.AddUninitialized(INT_SIZE);

	FMemory::Memmove(OutBytes.GetData(), u.tmpArray, INT64_SIZE);

	if (SwitchByteOrder)
	{
		OutBytes.SwapMemory(7, 0);
		OutBytes.SwapMemory(6, 1);
		OutBytes.SwapMemory(5, 2);
		OutBytes.SwapMemory(4, 3);
	}
}

void UWNBasicHelper::ParseBytesToFloatPure(TArray<uint8> InBytes, float& OutValue)
{
	ParseBytesToFloat(InBytes, OutValue);
}

void UWNBasicHelper::ParseBytesToIntegerPure(TArray<uint8> InBytes, int32& OutValue)
{
	ParseBytesToInteger(InBytes, OutValue);
}

void UWNBasicHelper::ParseBytesToInteger64Pure(TArray<uint8> InBytes, int64& OutValue)
{
	ParseBytesToInteger64(InBytes, OutValue);
}

void UWNBasicHelper::ParseFloatToBytesPure(float InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	ParseFloatToBytes(InValue, OutBytes, SwitchByteOrder);
}

void UWNBasicHelper::ParseIntegerToBytesPure(int32 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	ParseIntegerToBytes(InValue, OutBytes, SwitchByteOrder);
}

void UWNBasicHelper::ParseInterger64ToBytesPure(int64 InValue, TArray<uint8>& OutBytes, bool SwitchByteOrder)
{
	ParseIntegerToBytes(InValue, OutBytes, SwitchByteOrder);
}

void UWNBasicHelper::ParseBytesToFloatArrayPure(TArray<uint8> InBytes, TArray<float>& OutValues)
{
	if (InBytes.Num() == 0 && InBytes.Num() % FLOAT_SIZE != 0)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToFloatArray : Cannot convert bytes to float array. Array must be a multiple of %d"), FLOAT_SIZE);
		return;
	}

	OutValues.Empty();
	OutValues.AddUninitialized(InBytes.Num() / FLOAT_SIZE);
	
	FMemory::Memmove(OutValues.GetData(), InBytes.GetData(), InBytes.Num());
}

void UWNBasicHelper::ParseBytesToDoubleArrayPure(TArray<uint8> InBytes, TArray<double>& OutValues)
{
	if (InBytes.Num() == 0 && InBytes.Num() % DBL_SIZE != 0)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToDoubleArray : Cannot convert bytes to double array. Array must be a multiple of %d"), DBL_SIZE);
		return;
	}

	OutValues.Empty();
	OutValues.AddUninitialized(InBytes.Num() / DBL_SIZE);

	FMemory::Memmove(OutValues.GetData(), InBytes.GetData(), InBytes.Num());
}

void UWNBasicHelper::ParseBytesToIntegerArrayPure(TArray<uint8> InBytes, TArray<int32>& OutValues)
{
	if (InBytes.Num() == 0 && InBytes.Num() % INT_SIZE != 0)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToFloatArray : Cannot convert bytes to integer array. Array must be a multiple of %d"), INT_SIZE);
		return;
	}

	OutValues.Empty();
	OutValues.AddUninitialized(InBytes.Num() / INT_SIZE);

	FMemory::Memmove(OutValues.GetData(), InBytes.GetData(), InBytes.Num());
}

void UWNBasicHelper::ParseBytesToInteger64ArrayPure(TArray<uint8> InBytes, TArray<int64>& OutValues)
{
	if (InBytes.Num() == 0 && InBytes.Num() % INT64_SIZE != 0)
	{
		UE_LOG(LogWNBasicHelper, Error, TEXT("ParseBytesToFloatArray : Cannot convert bytes to integer64 array. Array must be a multiple of %d"), INT64_SIZE);
		return;
	}

	OutValues.Empty();
	OutValues.AddUninitialized(InBytes.Num() / INT64_SIZE);

	FMemory::Memmove(OutValues.GetData(), InBytes.GetData(), InBytes.Num());
}

void UWNBasicHelper::ParseFloatArrayToBytesPure(TArray<float> InValues, TArray<uint8>& OutBytes)
{
	OutBytes.Empty();
	OutBytes.AddUninitialized(InValues.Num() * FLOAT_SIZE);

	FMemory::Memmove(OutBytes.GetData(), InValues.GetData(), InValues.Num() * FLOAT_SIZE);
}

void UWNBasicHelper::ParseIntegerArrayToBytesPure(TArray<int32> InValues, TArray<uint8>& OutBytes)
{
	OutBytes.Empty();
	OutBytes.AddUninitialized(InValues.Num() * INT_SIZE);

	FMemory::Memmove(OutBytes.GetData(), InValues.GetData(), InValues.Num() * INT_SIZE);
}

void UWNBasicHelper::ParseInteger64ArrayToBytesPure(TArray<int64> InValues, TArray<uint8>& OutBytes)
{
	OutBytes.Empty();
	OutBytes.AddUninitialized(InValues.Num() * INT64_SIZE);

	FMemory::Memmove(OutBytes.GetData(), InValues.GetData(), InValues.Num() * INT64_SIZE);
}


///================ MISCELLANEOUS

FString UWNBasicHelper::FormatToScientificFloat(float Value)
{
	std::stringstream stream;

	// Rewrite value in scientific notation
	stream << std::scientific << Value;

	// Get string in the streaming pool
	std::string dest = stream.str();

	size_t pos = dest.find('e');

	if (pos != std::string::npos)
		return FString(dest.c_str());

	// If we have an exponent starting with 0, drop it
	if (pos != std::string::npos && dest[pos + 2] == '0')
		dest.erase(pos + 1, 1);

	return FString(dest.c_str());
}

FString UWNBasicHelper::FormatToScientificDouble(double Value)
{
	std::stringstream stream;

	// Rewrite value in scientific notation
	stream << std::scientific << Value;

	// Get string in the streaming pool
	std::string dest = stream.str();

	size_t pos = dest.find('e');

	if (pos != std::string::npos)
		return FString(dest.c_str());

	// If we have an exponent starting with 0, drop it
	if (pos != std::string::npos && dest[pos + 2] == '0')
		dest.erase(pos + 1, 1);

	return FString(dest.c_str());
}

FString UWNBasicHelper::FormatToScientificVector(FVector Vector)
{
	FString x = FormatToScientificDouble(Vector.X),
		y = FormatToScientificDouble(Vector.Y),
		z = FormatToScientificDouble(Vector.Z);

	return FString("{ x : " + x + ", y: " + y + ", z: " + z + " }");
}


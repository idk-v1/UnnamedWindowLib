#pragma once

#include "idk_util.h"
#include "idk_memory.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

static idk_uint idk_str_len(const char* str)
{
	if (str)
		return (idk_uint)strlen(str);
	return 0;
}

static bool idk_str_eq(const char* left, const char* right)
{
	return (strcmp(left, right) == 0);
}

static void idk_str_delete(char* str)
{
	if (str)
		free(str);
}

static char* idk_str_add(const char* left, const char* right)
{
	idk_uint leftSize = idk_str_len(left);
	idk_uint rightSize = idk_str_len(right);

	char* ret = idk_mem_alloc(leftSize + rightSize + 1);
	if (ret)
	{
		memcpy(ret, left, leftSize);
		memcpy(ret + leftSize, right, rightSize);
		ret[leftSize + rightSize] = 0;
	}

	return ret;
}
static char* idk_str_addDL(char* left, const char* right)
{
	char* ret = idk_str_add(left, right);
	idk_str_delete(left);
	return ret;
}
static char* idk_str_addDR(const char* left, char* right)
{
	char* ret = idk_str_add(left, right);
	idk_str_delete(right);
	return ret;
}
static char* idk_str_addDB(char* left, char* right)
{
	char* ret = idk_str_add(left, right);
	idk_str_delete(left);
	idk_str_delete(right);
	return ret;
}

static bool idk_str_addTo(char** left, const char* right)
{
	if (left)
	{
		idk_uint leftSize = idk_str_len(*left);
		idk_uint rightSize = idk_str_len(right);

		if (idk_mem_realloc(left, leftSize + rightSize + 1))
		{
			memcpy(*left + leftSize, right, rightSize);
			(*left)[leftSize + rightSize] = 0;
			return true;
		}
	}
	return false;
}
static bool idk_str_addToD(char** left, char* right)
{
	bool ret = idk_str_addTo(left, right);
	idk_str_delete(right);
	return ret;
}

static char* idk_str_sub(const char* str, idk_uint pos, idk_uint size)
{
	char* ret = NULL;
	idk_uint length = idk_str_len(str);
	if (pos < length)
	{
		length = idk_min(length - pos, size);
		ret = idk_mem_alloc(length + 1);
		if (ret)
		{
			memcpy(ret, str + pos, length);
			ret[length] = 0;
		}
	}
	return ret;
}
static char* idk_str_subD(char* str, idk_uint pos, idk_uint size)
{
	char* ret = idk_str_sub(str, pos, size);
	idk_str_delete(str);
	return ret;
}

static char* idk_sprintf(const char* format, ...)
{
	va_list args, argCopy;
	va_start(args, format);

	va_copy(argCopy, args);
	idk_uint length = vsnprintf(NULL, 0, format, argCopy);
	va_end(argCopy);

	char* ret = idk_mem_alloc(length + 1);
	if (ret)
		vsnprintf(ret, length + 1, format, args);

	va_end(args);

	return ret;
}

static idk_uint idk_str_findC(const char* str, char find)
{
	idk_uint length = idk_str_len(str);
	for (idk_uint i = 0; i < length; i++)
		if (str[i] == find)
			return i;
	return -1;
}
static idk_uint idk_str_findOC(const char* str, char find, idk_uint offset)
{
	idk_uint length = idk_str_len(str);
	for (idk_uint i = offset; i < length; i++)
		if (str[i] == find)
			return i;
	return -1;
}
static idk_uint idk_str_findS(const char* str, const char* find)
{
	idk_uint length = idk_str_len(str);
	idk_uint findLength = idk_str_len(find);

	for (idk_uint i = 0; i < length; i++)
		for (idk_uint f = 0; f < findLength; f++)
		{
			if (f == findLength - 1)
				return i;
			if (str[i + f] != find[f])
				break;
		}
	return -1;
}
static idk_uint idk_str_findOS(const char* str, const char* find, idk_uint offset)
{
	idk_uint length = idk_str_len(str);
	idk_uint findLength = idk_str_len(find);

	for (idk_uint i = offset; i < length; i++)
		for (idk_uint f = 0; f < findLength; f++)
		{
			if (f == findLength - 1)
				return i;
			if (str[i + f] != find[f])
				break;
		}
	return -1;
}

static char* idk_str_fromInt(int64_t num)
{
	return idk_sprintf("%lld", num);
}
static char* idk_str_fromUint(uint64_t num)
{
	return idk_sprintf("%llu", num);
}
static char* idk_str_fromFloat(double num)
{
	return idk_sprintf("%f", num);
}

static int64_t idk_str_toInt(const char* str)
{
	return strtoll(str, NULL, 10);
}
static uint64_t idk_str_toUint(const char* str)
{
	return strtoull(str, NULL, 10);
}
static double idk_str_toFloat(const char* str)
{
	return strtod(str, NULL);
}

static int64_t idk_str_toIntD(char* str)
{
	int64_t ret = idk_str_toInt(str);
	idk_str_delete(str);
	return ret;
}
static uint64_t idk_str_toUintD(char* str)
{
	uint64_t ret = idk_str_toUint(str);
	idk_str_delete(str);
	return ret;
}
static double idk_str_toFloatD(char* str)
{
	double ret = idk_str_toFloat(str);
	idk_str_delete(str);
	return ret;
}
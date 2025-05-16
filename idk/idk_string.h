#pragma once

#include "idk_util.h"
#include "idk_memory.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

static idk_uint idk_str_len(const char* str)
{
	if (str)
		return strlen(str);
	return 0;
}

static bool     idk_str_eq(const char* left, const char* right)
{
	return (strcmp(left, right) == 0);
}

static void     idk_str_delete(char* str)
{
	if (str)
		free(str);
}

static char* idk_str_addKK(const char* left, const char* right)
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
static char* idk_str_addDK(char* left, const char* right)
{
	char* ret = idk_str_addKK(left, right);
	idk_str_delete(left);
	return ret;
}
static char* idk_str_addKD(const char* left, char* right)
{
	char* ret = idk_str_addKK(left, right);
	idk_str_delete(right);
	return ret;
}
static char* idk_str_addDD(char* left, char* right)
{
	char* ret = idk_str_addKK(left, right);
	idk_str_delete(left);
	idk_str_delete(right);
	return ret;
}

static bool     idk_str_addToK(char** left, const char* right)
{
	if (left)
	{
		idk_uint leftSize = idk_str_len(*left);
		idk_uint rightSize = idk_str_len(right);

		if (idk_mem_realloc(left, leftSize + rightSize + 1))
		{
			memcpy(*left + leftSize, right, rightSize);
			*left[leftSize + rightSize] = 0;
			return true;
		}
	}
	return false;
}
static bool     idk_str_addToD(char** left, char* right)
{
	bool ret = idk_str_addToK(left, right);
	idk_str_delete(right);
	return ret;
}

static char* idk_str_subK(const char* str, idk_uint pos, idk_uint size)
{
	char* ret = NULL;
	idk_uint length = idk_min(idk_str_len(str), size);
	if (pos <= length)
	{
		length -= pos;
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
	char* ret = idk_str_subK(str, pos, size);
	idk_str_delete(str);
	return ret;
}

static idk_uint idk_str_findC(const char* str, char find);
static idk_uint idk_str_findOC(const char* str, char find, idk_uint offset);
static idk_uint idk_str_findS(const char* str, const char* find);
static idk_uint idk_str_findOS(const char* str, const char* find, idk_uint offset);

static char*    idk_str_fromInt(int64_t num);
static char*    idk_str_fromUint(uint64_t num);
static char*    idk_str_fromFloat(double num);

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
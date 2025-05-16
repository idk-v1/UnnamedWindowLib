#pragma once

#include "idk_util.h"
#include "idk_array.h"

#include <stdio.h>
#include <stdarg.h>

char*    idk_str_addKK(const char* left, const char* right);
char*    idk_str_addDK(char* left, const char* right);
char*    idk_str_addKD(const char* left, char* right);
char*    idk_str_addDD(char* left, char* right);

bool     idk_str_addToK(char** left, const char* right);
bool     idk_str_addToD(char** left, char* right);

char*    idk_str_subK(const char* str, idk_uint pos, idk_uint size);
char*    idk_str_subD(char* str, idk_uint pos, idk_uint size);

idk_uint idk_string_length(const char* str);

idk_uint idk_string_findC(const char* str, char find);
idk_uint idk_string_findS(const char* str, const char* find);

char*    idk_string_fromInt(int64_t num);
char*    idk_string_fromUint(uint64_t num);
char*    idk_string_fromFloat(double num);

char*    idk_sprintf(const char* format, ...);

void     idk_string_delete(char* str);
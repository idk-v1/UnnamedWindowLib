#pragma once

#include "idk_util.h"
#include "idk_memory.h"

#define IDK_ARRAY_TEMPLATE(type, name) \
typedef struct name \
{ \
	type* data; \
	idk_uint length; \
	idk_uint capacity; \
} name; \
\
static name name##_create(idk_uint size) \
{ \
	name array; \
	array.data = idk_mem_allocNT(size, type); \
	array.capacity = size; \
	array.length = 0; \
	return array; \
} \
\
static bool name##_push(name* array, type data) \
{ \
	if (array->length + 1 > array->capacity) \
	{ \
		if (idk_mem_reallocNT(&array->data, array->capacity * 2, type)) \
			array->capacity *= 2; \
		else \
			return false; \
	} \
	array->data[array->length++] = data; \
	return true; \
} \
\
static type name##_pop(name* array) \
{ \
	type ret = { 0 }; \
	if (array->length > 0) \
		ret = array->data[--array->length]; \
	return ret; \
} \
\
static bool name##_insert(name* array, type data, idk_uint pos) \
{ \
	if (pos > array->length) \
		return false; \
	if (array->length + 1 > array->capacity) \
	{ \
		if (idk_mem_reallocNT(&array->data, array->capacity * 2, type)) \
			array->capacity *= 2; \
		else \
			return false; \
	} \
	for (idk_int i = array->length; i >= (idk_int)pos; i--) \
		array->data[i + 1] = array->data[i]; \
	array->data[pos] = data; \
	array->length++; \
	return true; \
} \
\
static type name##_remove(name* array, idk_uint pos) \
{ \
	type ret = { 0 }; \
	if (pos < array->length) \
	{ \
		ret = array->data[pos]; \
		for (idk_uint i = pos; i < array->length - 1; i++) \
			array->data[i] = array->data[i + 1]; \
		array->length--; \
	} \
	return ret; \
} \
\
static bool name##_resize(name* array, idk_uint length) \
{ \
	if (idk_mem_reallocNT(&array->data, length, type)) \
	{ \
		array->capacity = length; \
		return true; \
	} \
	return false; \
} \
\
static void name##_clear(name* array) \
{ \
	array->length = 0; \
} \
\
static void name##_delete(name* array) \
{ \
	idk_mem_free(array->data); \
    idk_mem_zero(array, sizeof(name)); \
}
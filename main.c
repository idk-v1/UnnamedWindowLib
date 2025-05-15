#include "idk/idk_array.h"

typedef struct intArray
{
    int* data; 
    idk_uint length; 
    idk_uint capacity;
} intArray; 

static intArray intArray_create(idk_uint size)
{
    intArray array; 
    array.data = idk_mem_alloc(size * sizeof(int)); 
    array.capacity = size; 
    array.length = 0; 
    return array;
} 

static _Bool intArray_push(intArray* array, int data)
{
    if (array->length + 1 > array->capacity)
    {
        if (idk_mem_realloc(&array->data, array->capacity * 2 * sizeof(int))) 
            array->capacity *= 2; 
        else 
            return 0;
    } 
    array->data[array->length++] = data; 
    return 1;
} 

static int intArray_pop(intArray* array)
{
    int ret = { 0 };
    if (array->length > 0) 
        ret = array->data[--array->length]; 
    return ret;
} 

static _Bool intArray_insert(intArray* array, int data, idk_uint pos)
{
    if (pos > array->length) 
        return 0; 
    if (array->length + 1 > array->capacity)
    {
        if (idk_mem_realloc(&array->data, array->capacity * 2 * sizeof(int))) 
            array->capacity *= 2; 
        else 
            return 0;
    } 
    for (idk_uint i = array->length; i >= pos; i--) 
        array->data[i] = array->data[pos]; 
    array->data[pos] = data; 
    return 1;
} 

static int intArray_remove(intArray* array, idk_uint pos)
{
    int ret = { 0 }; 
    if (pos < array->length)
    {
        ret = array->data[pos]; 
        for (idk_uint i = pos; i < array->length - 1; i++) 
            array->data[i] = array->data[i + 1];
    } return ret;
} 

static void intArray_clear(intArray* array)
{
    array->length = 0;
} 

static void intArray_delete(intArray* array)
{
    idk_mem_free(array->data); 
    array->data = ((void*)0); 
    array->length = 0; 
    array->capacity = 0;
}

int main(int argc, char* argv[])
{


	return 0;
}
#pragma once

static void idk_mem_free(void* ptr)
{
	if (ptr)
		free(ptr);
}

static void* idk_mem_alloc(idk_uint size)
{
	if (size > 0)
		return malloc(size);
	return NULL;
}
#define idk_mem_allocN(count, elemSize) idk_mem_alloc(count * elemSize)
#define idk_mem_allocNT(count, type) idk_mem_alloc(count * sizeof(type))
#define idk_mem_allocT(type) idk_mem_alloc(sizeof(type))


static bool idk_mem_realloc(void** ptr, idk_uint size)
{
	if (ptr)
		if (size > 0)
		{
			void* temp = realloc(*ptr, size);
			if (temp)
			{
				*ptr = temp;
				return true;
			}
	return false;
}
#define idk_mem_reallocN(ptr, count, elemSize) idk_mem_realloc(ptr, count * elemSize)
#define idk_mem_reallocNT(ptr, count, type) idk_mem_realloc(ptr, count * sizeof(type))
#define idk_mem_reallocT(ptr, type) idk_mem_realloc(ptr, sizeof(type))
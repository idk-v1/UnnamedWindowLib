#include "idk/idk_array.h"

IDK_ARRAY_TEMPLATE(int, intArray)

int main(int argc, char* argv[])
{
	intArray array = intArray_create(10);

	intArray_insert(&array, 5, 0);
	intArray_push(&array, 2);
	intArray_push(&array, 3);
	intArray_insert(&array, 8, 1);
	intArray_remove(&array, 0);
	intArray_remove(&array, 2);

	intArray_delete(&array);

	return 0;
}
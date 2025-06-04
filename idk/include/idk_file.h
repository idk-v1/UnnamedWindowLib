#pragma once

#include "utility/"
#include "utility/idk_array.h"
#include "idk_time.h"

typedef struct idk_File
{
	char* name;
	idk_uint size;
	idk_DateTime create;
	idk_DateTime modify;
	bool isDir;
} idk_File;

IDK_ARRAY_TEMPLATE(idk_File, idk_Directory)

IDK_ARRAY_TEMPLATE(idk_byte, idk_RawFile)

char*         idk_dir_getCurrent();
void          idk_dir_setCurrent(const char* path);

idk_Directory idk_dir_getFiles(const char* path);

bool          idk_dir_create(const char* path, const char* name);
bool          idk_dir_exists(const char* path, const char* name);
bool          idk_dir_delete(const char* path, const char* name);


bool          idk_file_create(const char* path, const char* name);
bool          idk_file_exists(const char* path, const char* name);
bool          idk_file_delete(const char* path, const char* name);

idk_RawFile   idk_file_read(const char* path, const char* name);
bool          idk_file_write(const char* path, const char* name, idk_byte* data, idk_uint size);
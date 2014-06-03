#ifndef _INDRA__L__HPP_
#define _INDRA__L__HPP_

#include "stdtypes.h"

BOOL lscript_compile(const char* src_filename, const char* dst_filename,
					 const char* err_filename, BOOL compile_to_mono, const char* class_name, BOOL is_god_like);

BOOL lscript_compile(char *filename, BOOL compile_to_mono, BOOL is_god_like = FALSE);

#endif

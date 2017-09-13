#include <stdio.h>
#include <string.h>
#include "indra.l.hpp"

// http_request string constants
const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED = "URL_REQUEST_DENIED";
#define MAX_STRING 255

int main(int argc, char *argv[])
{
    char base_filename[MAX_STRING];
    int i, len;
    char *dot;
    if (argc < 2)
    {
        fputs("Requires a filename without extension.\n", stderr);
        return 1;
    }
//    lscript_compile(argv[1], true);
    len = strlen(argv[1]);
    // leave room for ".lsl.pp\0" (length 8)
    if (len > MAX_STRING - 8)
    {
        fputs("Input filename too long.\n", stderr);
        return 1;
    }
    dot = strrchr(argv[1], '.');
    if (dot == NULL)
        dot = argv[1] + len;

    strncpy(base_filename, argv[1], dot - argv[1]);
    base_filename[dot - argv[1]] = '\0';

    char src_filename[MAX_STRING];
    if (*dot == '.')
        sprintf(src_filename, "%s", argv[1]); // use the arg verbatim
    else
        sprintf(src_filename, "%s.lsl", base_filename); // append .lsl
    char err_filename[MAX_STRING];
    sprintf(err_filename, "%s.out", base_filename);
    //char class_name[MAX_STRING];
    //sprintf(class_name, "%s", argv[1]);
    char bin_name[MAX_STRING];
    sprintf(bin_name, "%s.cil", base_filename);

    lscript_compile(src_filename, bin_name, err_filename, true, "1f1f1f1f-1f1f-1f1f-1f1f-1f1f1f1f1f1f", false);

// Don't generate LSO bytecode as we've removed LSO output code.
//    sprintf(bin_name, "%s.lso", base_filename);
//    lscript_compile(src_filename, bin_name, err_filename, false, class_name, false);
    return 0;
}

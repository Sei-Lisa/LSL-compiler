#include <stdio.h>
#include "indra.l.hpp"

// http_request string constants
const char* URL_REQUEST_GRANTED = "URL_REQUEST_GRANTED";
const char* URL_REQUEST_DENIED = "URL_REQUEST_DENIED";
#define MAX_STRING 255

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fputs("Requires a filename without extension.", stderr);
        return 1;
    }
//    lscript_compile(argv[1], true);

    char src_filename[MAX_STRING];
    sprintf(src_filename, "%s.lsl", argv[1]);
    char err_filename[MAX_STRING];
    sprintf(err_filename, "%s.out", argv[1]);
    char class_name[MAX_STRING];
    sprintf(class_name, "%s", argv[1]);
    char bin_name[MAX_STRING];
    sprintf(bin_name, "%s.cil", argv[1]);

    lscript_compile(src_filename, bin_name, err_filename, true, class_name, false);

// Don't generate LSO bytecode as we've removed LSO output code.
//    sprintf(bin_name, "%s.lso", argv[1]);
//    lscript_compile(src_filename, bin_name, err_filename, false, class_name, false);
    return 0;
}

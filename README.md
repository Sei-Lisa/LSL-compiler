# LSL-compiler

This is a standalone LSL compiler, extracted from the viewer sources. Its main purpose is to allow the analysis of the generated code, providing an insight into the internals of Mono and LSO, but it can also be used as an external syntax checking tool.

This version includes some fixes and code changes that are believed to exist in the server (like the output of ldloc/stloc), or that do not affect compilation or generated code (like fixes to the pretty printer).

## Building

Building requires installation of [**kwdb**](https://bitbucket.org/Sei_Lisa/kwdb). The file `indralex.py` present in the source should be copied to **kwdb**'s `lsl2dfg/lsloutputs/` directory. Edit `Makefile` to point to the installation directory of **kwdb** and to modify the compiler options if required.

**kwdb** in turn requires **python 2**. **flex** and **bison** are also required. And of course, a C++ compiler (tested with **g++** only).

## Running

Run by entering:

```
./lslcomp <filename>
```

The input script's extension defaults to `.lsl` if not specified. In case of successful compilation, it generates the following files:

- An `.out` file with the LSO assembler output.
- A `.cil` file with the Mono assembler output.
- An `.lsl.pp` (or whatever the original extension was, with `.pp` appended) file with the pretty-printed script output.

In case of error, the error message is displayed in standard error, and the `.out` file and possibly the `.lsl.pp` file are still generated.

The generated `.cil` file is suitable as input to the Mono assembler, which can generate a `.dll` with this command:

```
ilasm /dll <filename>.cil
```

(assuming you have the **mono-devel** package).

## License

This program, like the viewer sources it is based on, is licensed under the GNU LGPL v2.1.

Copyright © 2010 Linden Research, Inc.  
Copyright © 2017 Sei Lisa.

Sei Lisa is the author's user name in the Second Life® virtual world.

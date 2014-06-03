CXX=g++
CPPFLAGS=-DLINUX=1 -Illcommon -Ilscript -DEMERGENCY_DEBUG_PRINTOUTS
CFLAGS=-g -O0
LDFLAGS=

LSLK=~/apps/secondlife/scripts/lslkeywords/

all : lslcomp

indra.l : indra.l.in
	$(LSLK)lsl2dfg/LSL2dfg.py -y -d $(LSLK)database/kwdb.xml -g sl -f indralex -i $< -o $@

lscript_library/lscript_library.cpp : lscript_library/lscript_library.cpp.in
	\
   $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -g sl -f viewersrc -i $<\
 | $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -f viewersrc -g os,-sl -t OSSL\
 | $(LSLK)lsl2dfg/LSL2dfg.py -d $(LSLK)database/kwdb.xml -f viewersrc -g aa,-os,-sl -t AA -o $@


indra.l.cpp : indra.l
	flex -P indra_ -o indra.l.cpp indra.l

indra.y.cpp indra.y.hpp : indra.y
	bison -p indra_ -d -o indra.y.cpp indra.y


%.o : %.cpp
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) "$<" -o "$@"

lslcomp.o : lslcomp.cpp
# lscript_bytecode.o : lscript_bytecode.cpp
lscript_error.o : lscript_error.cpp
lscript_resource.o : lscript_resource.cpp
lscript_scope.o : lscript_scope.cpp
lscript_tree.o : lscript_tree.cpp llcommon/llstring.h
lscript_typecheck.o : lscript_typecheck.cpp
indra.l.o : indra.l.cpp indra.y.hpp
indra.y.o : indra.y.cpp indra.y.hpp
llcommon/llfile.o : llcommon/llfile.cpp
llcommon/llstringtable.o : llcommon/llstringtable.cpp
# lscript_library/lscript_alloc.o : lscript_library/lscript_alloc.cpp
lscript_library/lscript_library.o : lscript_library/lscript_library.cpp

lslcomp : lslcomp.o indra.l.o indra.y.o\
 lscript_error.o lscript_resource.o\
 lscript_scope.o lscript_tree.o\
 lscript_typecheck.o\
 llcommon/llfile.o llcommon/llstringtable.o\
 lscript_library/lscript_library.o
	g++ $(CFLAGS) $(LDFLAGS) lslcomp.o indra.l.o indra.y.o\
 lscript_error.o lscript_resource.o\
 lscript_scope.o lscript_tree.o\
 lscript_typecheck.o\
 llcommon/llfile.o llcommon/llstringtable.o\
 lscript_library/lscript_library.o\
 -o lslcomp


clean :
	rm -f lslcomp *.o lscript_library/*.o llcommon/*.o\
 indra.l.cpp indra.l indra.y.cpp indra.y.hpp\
 lscript_library/lscript_library.cpp

.PHONY : all clean

#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1445274692/FrameWork.o \
	${OBJECTDIR}/_ext/1445274692/generic.o \
	${OBJECTDIR}/_ext/1445274692/graph.o \
	${OBJECTDIR}/_ext/1445274692/hashmap.o \
	${OBJECTDIR}/_ext/1445274692/heap.o \
	${OBJECTDIR}/_ext/1445274692/list.o \
	${OBJECTDIR}/_ext/1445274692/nodelist.o \
	${OBJECTDIR}/_ext/1445274692/nodetree.o \
	${OBJECTDIR}/_ext/1445274692/quebrado.o \
	${OBJECTDIR}/_ext/1445274692/queue.o \
	${OBJECTDIR}/_ext/1445274692/stack.o \
	${OBJECTDIR}/_ext/1445274692/tree.o \
	${OBJECTDIR}/_ext/1479848513/DataTypes.o \
	${OBJECTDIR}/_ext/1479848513/Database.o \
	${OBJECTDIR}/_ext/1479848513/ErrorHandler.o \
	${OBJECTDIR}/_ext/1479848513/GenObject.o \
	${OBJECTDIR}/_ext/1479848513/MemManagement.o \
	${OBJECTDIR}/_ext/1479848513/character.o \
	${OBJECTDIR}/_ext/1479848513/debugSys.o \
	${OBJECTDIR}/_ext/1479848513/double.o \
	${OBJECTDIR}/_ext/1479848513/exceptions.o \
	${OBJECTDIR}/_ext/1479848513/float.o \
	${OBJECTDIR}/_ext/1479848513/integer.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=-m64

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a

${OBJECTDIR}/_ext/1445274692/FrameWork.o: ../../src/FrameWork.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/FrameWork.o ../../src/FrameWork.c

${OBJECTDIR}/_ext/1445274692/generic.o: ../../src/generic.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/generic.o ../../src/generic.c

${OBJECTDIR}/_ext/1445274692/graph.o: ../../src/graph.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/graph.o ../../src/graph.c

${OBJECTDIR}/_ext/1445274692/hashmap.o: ../../src/hashmap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/hashmap.o ../../src/hashmap.c

${OBJECTDIR}/_ext/1445274692/heap.o: ../../src/heap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/heap.o ../../src/heap.c

${OBJECTDIR}/_ext/1445274692/list.o: ../../src/list.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/list.o ../../src/list.c

${OBJECTDIR}/_ext/1445274692/nodelist.o: ../../src/nodelist.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodelist.o ../../src/nodelist.c

${OBJECTDIR}/_ext/1445274692/nodetree.o: ../../src/nodetree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodetree.o ../../src/nodetree.c

${OBJECTDIR}/_ext/1445274692/quebrado.o: ../../src/quebrado.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/quebrado.o ../../src/quebrado.c

${OBJECTDIR}/_ext/1445274692/queue.o: ../../src/queue.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/queue.o ../../src/queue.c

${OBJECTDIR}/_ext/1445274692/stack.o: ../../src/stack.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/stack.o ../../src/stack.c

${OBJECTDIR}/_ext/1445274692/tree.o: ../../src/tree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/tree.o ../../src/tree.c

${OBJECTDIR}/_ext/1479848513/DataTypes.o: /home/kevin/libDEA/src/DataTypes.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/DataTypes.o /home/kevin/libDEA/src/DataTypes.c

${OBJECTDIR}/_ext/1479848513/Database.o: /home/kevin/libDEA/src/Database.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/Database.o /home/kevin/libDEA/src/Database.c

${OBJECTDIR}/_ext/1479848513/ErrorHandler.o: /home/kevin/libDEA/src/ErrorHandler.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/ErrorHandler.o /home/kevin/libDEA/src/ErrorHandler.c

${OBJECTDIR}/_ext/1479848513/GenObject.o: /home/kevin/libDEA/src/GenObject.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/GenObject.o /home/kevin/libDEA/src/GenObject.c

${OBJECTDIR}/_ext/1479848513/MemManagement.o: /home/kevin/libDEA/src/MemManagement.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/MemManagement.o /home/kevin/libDEA/src/MemManagement.c

${OBJECTDIR}/_ext/1479848513/character.o: /home/kevin/libDEA/src/character.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/character.o /home/kevin/libDEA/src/character.c

${OBJECTDIR}/_ext/1479848513/debugSys.o: /home/kevin/libDEA/src/debugSys.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/debugSys.o /home/kevin/libDEA/src/debugSys.c

${OBJECTDIR}/_ext/1479848513/double.o: /home/kevin/libDEA/src/double.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/double.o /home/kevin/libDEA/src/double.c

${OBJECTDIR}/_ext/1479848513/exceptions.o: /home/kevin/libDEA/src/exceptions.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/exceptions.o /home/kevin/libDEA/src/exceptions.c

${OBJECTDIR}/_ext/1479848513/float.o: /home/kevin/libDEA/src/float.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/float.o /home/kevin/libDEA/src/float.c

${OBJECTDIR}/_ext/1479848513/integer.o: /home/kevin/libDEA/src/integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/integer.o /home/kevin/libDEA/src/integer.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1577270788/Mem_managment_test.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	gcc   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/_ext/1577270788/Mem_managment_test.o: /Users/kevincando/Documents/libDEA/include/tests/Mem_managment_test.c 
	${MKDIR} -p ${TESTDIR}/_ext/1577270788
	${RM} "$@.d"
	$(COMPILE.c) -O2 -w -I../../include -I. -std=c99 -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1577270788/Mem_managment_test.o /Users/kevincando/Documents/libDEA/include/tests/Mem_managment_test.c


${OBJECTDIR}/_ext/1445274692/FrameWork_nomain.o: ${OBJECTDIR}/_ext/1445274692/FrameWork.o ../../src/FrameWork.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/FrameWork.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/FrameWork_nomain.o ../../src/FrameWork.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/FrameWork.o ${OBJECTDIR}/_ext/1445274692/FrameWork_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/generic_nomain.o: ${OBJECTDIR}/_ext/1445274692/generic.o ../../src/generic.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/generic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/generic_nomain.o ../../src/generic.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/generic.o ${OBJECTDIR}/_ext/1445274692/generic_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/graph_nomain.o: ${OBJECTDIR}/_ext/1445274692/graph.o ../../src/graph.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/graph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/graph_nomain.o ../../src/graph.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/graph.o ${OBJECTDIR}/_ext/1445274692/graph_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/hashmap_nomain.o: ${OBJECTDIR}/_ext/1445274692/hashmap.o ../../src/hashmap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/hashmap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/hashmap_nomain.o ../../src/hashmap.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/hashmap.o ${OBJECTDIR}/_ext/1445274692/hashmap_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/heap_nomain.o: ${OBJECTDIR}/_ext/1445274692/heap.o ../../src/heap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/heap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/heap_nomain.o ../../src/heap.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/heap.o ${OBJECTDIR}/_ext/1445274692/heap_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/list_nomain.o: ${OBJECTDIR}/_ext/1445274692/list.o ../../src/list.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/list_nomain.o ../../src/list.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/list.o ${OBJECTDIR}/_ext/1445274692/list_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/nodelist_nomain.o: ${OBJECTDIR}/_ext/1445274692/nodelist.o ../../src/nodelist.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/nodelist.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodelist_nomain.o ../../src/nodelist.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/nodelist.o ${OBJECTDIR}/_ext/1445274692/nodelist_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/nodetree_nomain.o: ${OBJECTDIR}/_ext/1445274692/nodetree.o ../../src/nodetree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/nodetree.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodetree_nomain.o ../../src/nodetree.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/nodetree.o ${OBJECTDIR}/_ext/1445274692/nodetree_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/quebrado_nomain.o: ${OBJECTDIR}/_ext/1445274692/quebrado.o ../../src/quebrado.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/quebrado.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/quebrado_nomain.o ../../src/quebrado.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/quebrado.o ${OBJECTDIR}/_ext/1445274692/quebrado_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/queue_nomain.o: ${OBJECTDIR}/_ext/1445274692/queue.o ../../src/queue.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/queue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/queue_nomain.o ../../src/queue.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/queue.o ${OBJECTDIR}/_ext/1445274692/queue_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/stack_nomain.o: ${OBJECTDIR}/_ext/1445274692/stack.o ../../src/stack.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/stack.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/stack_nomain.o ../../src/stack.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/stack.o ${OBJECTDIR}/_ext/1445274692/stack_nomain.o;\
	fi

${OBJECTDIR}/_ext/1445274692/tree_nomain.o: ${OBJECTDIR}/_ext/1445274692/tree.o ../../src/tree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1445274692/tree.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/tree_nomain.o ../../src/tree.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1445274692/tree.o ${OBJECTDIR}/_ext/1445274692/tree_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/DataTypes_nomain.o: ${OBJECTDIR}/_ext/1479848513/DataTypes.o /home/kevin/libDEA/src/DataTypes.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/DataTypes.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/DataTypes_nomain.o /home/kevin/libDEA/src/DataTypes.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/DataTypes.o ${OBJECTDIR}/_ext/1479848513/DataTypes_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/Database_nomain.o: ${OBJECTDIR}/_ext/1479848513/Database.o /home/kevin/libDEA/src/Database.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/Database.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/Database_nomain.o /home/kevin/libDEA/src/Database.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/Database.o ${OBJECTDIR}/_ext/1479848513/Database_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/ErrorHandler_nomain.o: ${OBJECTDIR}/_ext/1479848513/ErrorHandler.o /home/kevin/libDEA/src/ErrorHandler.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/ErrorHandler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/ErrorHandler_nomain.o /home/kevin/libDEA/src/ErrorHandler.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/ErrorHandler.o ${OBJECTDIR}/_ext/1479848513/ErrorHandler_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/GenObject_nomain.o: ${OBJECTDIR}/_ext/1479848513/GenObject.o /home/kevin/libDEA/src/GenObject.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/GenObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/GenObject_nomain.o /home/kevin/libDEA/src/GenObject.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/GenObject.o ${OBJECTDIR}/_ext/1479848513/GenObject_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/MemManagement_nomain.o: ${OBJECTDIR}/_ext/1479848513/MemManagement.o /home/kevin/libDEA/src/MemManagement.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/MemManagement.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/MemManagement_nomain.o /home/kevin/libDEA/src/MemManagement.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/MemManagement.o ${OBJECTDIR}/_ext/1479848513/MemManagement_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/character_nomain.o: ${OBJECTDIR}/_ext/1479848513/character.o /home/kevin/libDEA/src/character.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/character.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/character_nomain.o /home/kevin/libDEA/src/character.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/character.o ${OBJECTDIR}/_ext/1479848513/character_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/debugSys_nomain.o: ${OBJECTDIR}/_ext/1479848513/debugSys.o /home/kevin/libDEA/src/debugSys.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/debugSys.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/debugSys_nomain.o /home/kevin/libDEA/src/debugSys.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/debugSys.o ${OBJECTDIR}/_ext/1479848513/debugSys_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/double_nomain.o: ${OBJECTDIR}/_ext/1479848513/double.o /home/kevin/libDEA/src/double.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/double.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/double_nomain.o /home/kevin/libDEA/src/double.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/double.o ${OBJECTDIR}/_ext/1479848513/double_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/exceptions_nomain.o: ${OBJECTDIR}/_ext/1479848513/exceptions.o /home/kevin/libDEA/src/exceptions.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/exceptions.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/exceptions_nomain.o /home/kevin/libDEA/src/exceptions.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/exceptions.o ${OBJECTDIR}/_ext/1479848513/exceptions_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/float_nomain.o: ${OBJECTDIR}/_ext/1479848513/float.o /home/kevin/libDEA/src/float.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/float.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/float_nomain.o /home/kevin/libDEA/src/float.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/float.o ${OBJECTDIR}/_ext/1479848513/float_nomain.o;\
	fi

${OBJECTDIR}/_ext/1479848513/integer_nomain.o: ${OBJECTDIR}/_ext/1479848513/integer.o /home/kevin/libDEA/src/integer.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1479848513
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1479848513/integer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -w -I../../include -std=c99 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1479848513/integer_nomain.o /home/kevin/libDEA/src/integer.c;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1479848513/integer.o ${OBJECTDIR}/_ext/1479848513/integer_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1559065848/estudiante.o \
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
	${OBJECTDIR}/_ext/1445274692/tree.o


# C Compiler Flags
CFLAGS=

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

${OBJECTDIR}/_ext/1559065848/estudiante.o: ../../include/estudiante.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1559065848
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1559065848/estudiante.o ../../include/estudiante.c

${OBJECTDIR}/_ext/1445274692/generic.o: ../../src/generic.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/generic.o ../../src/generic.c

${OBJECTDIR}/_ext/1445274692/graph.o: ../../src/graph.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/graph.o ../../src/graph.c

${OBJECTDIR}/_ext/1445274692/hashmap.o: ../../src/hashmap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/hashmap.o ../../src/hashmap.c

${OBJECTDIR}/_ext/1445274692/heap.o: ../../src/heap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/heap.o ../../src/heap.c

${OBJECTDIR}/_ext/1445274692/list.o: ../../src/list.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/list.o ../../src/list.c

${OBJECTDIR}/_ext/1445274692/nodelist.o: ../../src/nodelist.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodelist.o ../../src/nodelist.c

${OBJECTDIR}/_ext/1445274692/nodetree.o: ../../src/nodetree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/nodetree.o ../../src/nodetree.c

${OBJECTDIR}/_ext/1445274692/quebrado.o: ../../src/quebrado.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/quebrado.o ../../src/quebrado.c

${OBJECTDIR}/_ext/1445274692/queue.o: ../../src/queue.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/queue.o ../../src/queue.c

${OBJECTDIR}/_ext/1445274692/stack.o: ../../src/stack.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/stack.o ../../src/stack.c

${OBJECTDIR}/_ext/1445274692/tree.o: ../../src/tree.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/1445274692
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1445274692/tree.o ../../src/tree.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibdeanetbeans.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

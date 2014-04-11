# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMLINUXdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := /users/elo/jnokaya/ENSSAT2A/TPS\ REEL/WINDRIVER/TpsReel
WS_ROOT_DIR := /users/elo/jnokaya/ENSSAT2A/TPS\ REEL/WINDRIVER



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simlinux
CPU = SIMLINUX
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks66
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = TpsReel/$(MODE_DIR)/TpsReel.out \
	 TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage.o


#Rules

# TpsReel
ifeq ($(DEBUG_MODE),1)
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TpsReel/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TpsReel/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TpsReel/$(MODE_DIR)/% : IDE_LIBRARIES = 
TpsReel/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TpsReel/$(MODE_DIR)/% : DEFINES = 
TpsReel/$(MODE_DIR)/% : EXPAND_DBG = 0
TpsReel/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
TpsReel/$(MODE_DIR)/% : CPU = SIMLINUX
TpsReel/$(MODE_DIR)/% : TOOL_FAMILY = diab
TpsReel/$(MODE_DIR)/% : TOOL = diab
TpsReel/$(MODE_DIR)/% : TOOL_PATH = 
TpsReel/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TpsReel/$(MODE_DIR)/% : LIBPATH = 
TpsReel/$(MODE_DIR)/% : LIBS = 
TpsReel/$(MODE_DIR)/% : OBJ_DIR := TpsReel/$(MODE_DIR)

OBJECTS_TpsReel = TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage.o

TpsReel/$(MODE_DIR)/TpsReel.out : $(OBJECTS_TpsReel)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_TpsReel) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_TpsReel) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TpsReel/$(MODE_DIR)/TpsReel_compile_file : $(FILE) ;

_clean :: TpsReel/$(MODE_DIR)/TpsReel_clean

TpsReel/$(MODE_DIR)/TpsReel_clean : 
	$(TRACE_FLAG)if [ -d "TpsReel" ]; then cd "TpsReel"; rm -rf $(MODE_DIR); fi


# TpsReel_partialImage
ifeq ($(DEBUG_MODE),1)
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TpsReel_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TpsReel_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TpsReel_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
TpsReel_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TpsReel_partialImage/$(MODE_DIR)/% : DEFINES = 
TpsReel_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
TpsReel_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simlinux
TpsReel_partialImage/$(MODE_DIR)/% : CPU = SIMLINUX
TpsReel_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
TpsReel_partialImage/$(MODE_DIR)/% : TOOL = diab
TpsReel_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
TpsReel_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks66
TpsReel_partialImage/$(MODE_DIR)/% : LIBPATH = 
TpsReel_partialImage/$(MODE_DIR)/% : LIBS = 
TpsReel_partialImage/$(MODE_DIR)/% : OBJ_DIR := TpsReel_partialImage/$(MODE_DIR)

OBJECTS_TpsReel_partialImage =

TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage.o : $(OBJECTS_TpsReel_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks66 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_TpsReel_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage_compile_file : $(FILE) ;

_clean :: TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage_clean

TpsReel_partialImage/$(MODE_DIR)/TpsReel_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "TpsReel_partialImage" ]; then cd "TpsReel_partialImage"; rm -rf $(MODE_DIR); fi


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""

###########################################################################
## Makefile generated for component 'Robot_Control'. 
## 
## Makefile     : Robot_Control_rtw.mk
## Generated on : Wed Mar 17 14:21:43 2021
## Final product: ./Robot_Control.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = Robot_Control
MAKEFILE                  = Robot_Control_rtw.mk
MATLAB_ROOT               = D:/Program Files/MATLAB/R2020b
MATLAB_BIN                = D:/Program Files/MATLAB/R2020b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/codegen/lib/Robot_Control
TGT_FCN_LIB               = GNU
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = Robot_Control_rtw_comp.rsp
CMD_FILE                  = Robot_Control_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = Robot_Control.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU Tools for ARM Embedded Processors
# Supported Version(s):    
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# TARGET_LOAD_CMD_ARGS
# TARGET_LOAD_CMD
# MW_GNU_ARM_TOOLS_PATH
# FDATASECTIONS_FLG

#-----------
# MACROS
#-----------

LIBGCC                = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-libgcc-file-name}
LIBC                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libc.a}
LIBM                  = ${shell $(MW_GNU_ARM_TOOLS_PATH)/arm-none-eabi-gcc ${CFLAGS} -print-file-name=libm.a}
PRODUCT_BIN           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).bin
PRODUCT_HEX           = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
CPFLAGS               = -O binary
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: GNU ARM Assembler
AS_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AS = "$(AS_PATH)/arm-none-eabi-gcc"

# C Compiler: GNU ARM C Compiler
CC_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CC = "$(CC_PATH)/arm-none-eabi-gcc"

# Linker: GNU ARM Linker
LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
LD = "$(LD_PATH)/arm-none-eabi-g++"

# C++ Compiler: GNU ARM C++ Compiler
CPP_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP = "$(CPP_PATH)/arm-none-eabi-g++"

# C++ Linker: GNU ARM C++ Linker
CPP_LD_PATH = $(MW_GNU_ARM_TOOLS_PATH)
CPP_LD = "$(CPP_LD_PATH)/arm-none-eabi-g++"

# Archiver: GNU ARM Archiver
AR_PATH = $(MW_GNU_ARM_TOOLS_PATH)
AR = "$(AR_PATH)/arm-none-eabi-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Hex Converter: Hex Converter
OBJCOPYPATH = $(MW_GNU_ARM_TOOLS_PATH)
OBJCOPY = "$(OBJCOPYPATH)/arm-none-eabi-objcopy"

# Executable Size: Executable Size
EXESIZEPATH = $(MW_GNU_ARM_TOOLS_PATH)
EXESIZE = "$(EXESIZEPATH)/arm-none-eabi-size"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del /f/q
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = -O binary $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O3
CPPFLAGS             = -std=gnu++14 \
                       -fno-rtti \
                       -fno-exceptions \
                       $(FDATASECTIONS_FLG) \
                       -Wall \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -c \
                       -O3
CPP_LDFLAGS          = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       =
EXESIZE_FLAGS        = $(PRODUCT)
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              = -Wl,--gc-sections \
                       -Wl,-Map="$(PRODUCT_NAME).map"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./Robot_Control.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
DEFINES_CUSTOM = 
DEFINES_SKIPFORSIL = -D__linux__ -DARM_PROJECT -D_USE_TARGET_UDP_ -D_RUNONTARGETHARDWARE_BUILD_ -DSTACK_SIZE=200000
DEFINES_STANDARD = -DMODEL=Robot_Control

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/Robot_Control_data.cpp $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/Robot_Control_initialize.cpp $(START_DIR)/Robot_Control.cpp $(START_DIR)/eye.cpp $(START_DIR)/isinf.cpp $(START_DIR)/rotz.cpp $(START_DIR)/roty.cpp $(START_DIR)/rotx.cpp $(START_DIR)/CPos_wrt_I.cpp $(START_DIR)/inpolygon.cpp $(START_DIR)/isnan.cpp $(START_DIR)/abs.cpp $(START_DIR)/abs1.cpp $(START_DIR)/manipulability.cpp $(START_DIR)/contactJacobians.cpp $(START_DIR)/recursiveKin.cpp $(START_DIR)/skew.cpp $(START_DIR)/svd.cpp $(START_DIR)/anyNonFinite.cpp $(START_DIR)/vAllOrAny.cpp $(START_DIR)/isfinite.cpp $(START_DIR)/svd1.cpp $(START_DIR)/xzsvdc.cpp $(START_DIR)/xnrm2.cpp $(START_DIR)/xdotc.cpp $(START_DIR)/xdot.cpp $(START_DIR)/prod.cpp $(START_DIR)/combineVectorElements.cpp $(START_DIR)/isequal.cpp $(START_DIR)/find_pgon_goal.cpp $(START_DIR)/norm.cpp $(START_DIR)/cross.cpp $(START_DIR)/Leg_Controller_B.cpp $(START_DIR)/atan2.cpp $(START_DIR)/atan21.cpp $(START_DIR)/angle.cpp $(START_DIR)/angle1.cpp $(START_DIR)/mldivide.cpp $(START_DIR)/lusolve.cpp $(START_DIR)/ifWhileCond.cpp $(START_DIR)/step_planner_intelligent.cpp $(START_DIR)/centroid_codeGen.cpp $(START_DIR)/sum.cpp $(START_DIR)/all.cpp $(START_DIR)/allOrAny.cpp $(START_DIR)/cos.cpp $(START_DIR)/cos1.cpp $(START_DIR)/sin.cpp $(START_DIR)/sin1.cpp $(START_DIR)/sqrt.cpp $(START_DIR)/sqrt1.cpp $(START_DIR)/xscal.cpp $(START_DIR)/xaxpy.cpp $(START_DIR)/xrotg.cpp $(START_DIR)/xrot.cpp $(START_DIR)/xswap.cpp $(START_DIR)/sort.cpp $(START_DIR)/sortIdx.cpp $(START_DIR)/sign.cpp $(START_DIR)/sign1.cpp $(START_DIR)/exp.cpp $(START_DIR)/exp1.cpp $(START_DIR)/Body_Pose_Controller.cpp $(START_DIR)/circshift.cpp $(START_DIR)/Leg_Controller.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Robot_Control_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o Robot_Control_initialize.o Robot_Control.o eye.o isinf.o rotz.o roty.o rotx.o CPos_wrt_I.o inpolygon.o isnan.o abs.o abs1.o manipulability.o contactJacobians.o recursiveKin.o skew.o svd.o anyNonFinite.o vAllOrAny.o isfinite.o svd1.o xzsvdc.o xnrm2.o xdotc.o xdot.o prod.o combineVectorElements.o isequal.o find_pgon_goal.o norm.o cross.o Leg_Controller_B.o atan2.o atan21.o angle.o angle1.o mldivide.o lusolve.o ifWhileCond.o step_planner_intelligent.o centroid_codeGen.o sum.o all.o allOrAny.o cos.o cos1.o sin.o sin1.o sqrt.o sqrt1.o xscal.o xaxpy.o xrotg.o xrot.o xswap.o sort.o sortIdx.o sign.o sign1.o exp.o exp1.o Body_Pose_Controller.o circshift.o Leg_Controller.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


ALL_DEPS:=$(patsubst %.o,%.dep,$(ALL_OBJS))
all:

ifndef DISABLE_GCC_FUNCTION_DATA_SECTIONS
FDATASECTIONS_FLG := -ffunction-sections -fdata-sections
endif



-include codertarget_assembly_flags.mk
-include ../codertarget_assembly_flags.mk
-include ../../codertarget_assembly_flags.mk
-include $(ALL_DEPS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild postbuild download execute


all : build postbuild
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


postbuild : $(PRODUCT)


download : postbuild


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.s
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.S
	$(AS) $(ASFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : D:/Desktop/Capstone/kinematics-MATLAB/SpringProject/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Robot_Control_data.o : $(START_DIR)/Robot_Control_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Robot_Control_initialize.o : $(START_DIR)/Robot_Control_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Robot_Control.o : $(START_DIR)/Robot_Control.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


eye.o : $(START_DIR)/eye.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isinf.o : $(START_DIR)/isinf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotz.o : $(START_DIR)/rotz.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


roty.o : $(START_DIR)/roty.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rotx.o : $(START_DIR)/rotx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CPos_wrt_I.o : $(START_DIR)/CPos_wrt_I.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inpolygon.o : $(START_DIR)/inpolygon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isnan.o : $(START_DIR)/isnan.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abs.o : $(START_DIR)/abs.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


abs1.o : $(START_DIR)/abs1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


manipulability.o : $(START_DIR)/manipulability.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


contactJacobians.o : $(START_DIR)/contactJacobians.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


recursiveKin.o : $(START_DIR)/recursiveKin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


skew.o : $(START_DIR)/skew.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.o : $(START_DIR)/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


anyNonFinite.o : $(START_DIR)/anyNonFinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


vAllOrAny.o : $(START_DIR)/vAllOrAny.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isfinite.o : $(START_DIR)/isfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd1.o : $(START_DIR)/svd1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzsvdc.o : $(START_DIR)/xzsvdc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.o : $(START_DIR)/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdot.o : $(START_DIR)/xdot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


prod.o : $(START_DIR)/prod.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


combineVectorElements.o : $(START_DIR)/combineVectorElements.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


isequal.o : $(START_DIR)/isequal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


find_pgon_goal.o : $(START_DIR)/find_pgon_goal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


norm.o : $(START_DIR)/norm.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cross.o : $(START_DIR)/cross.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Leg_Controller_B.o : $(START_DIR)/Leg_Controller_B.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


atan2.o : $(START_DIR)/atan2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


atan21.o : $(START_DIR)/atan21.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


angle.o : $(START_DIR)/angle.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


angle1.o : $(START_DIR)/angle1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


mldivide.o : $(START_DIR)/mldivide.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


lusolve.o : $(START_DIR)/lusolve.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ifWhileCond.o : $(START_DIR)/ifWhileCond.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


step_planner_intelligent.o : $(START_DIR)/step_planner_intelligent.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


centroid_codeGen.o : $(START_DIR)/centroid_codeGen.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/sum.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


all.o : $(START_DIR)/all.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


allOrAny.o : $(START_DIR)/allOrAny.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cos.o : $(START_DIR)/cos.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cos1.o : $(START_DIR)/cos1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sin.o : $(START_DIR)/sin.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sin1.o : $(START_DIR)/sin1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt.o : $(START_DIR)/sqrt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sqrt1.o : $(START_DIR)/sqrt1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xscal.o : $(START_DIR)/xscal.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.o : $(START_DIR)/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.o : $(START_DIR)/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.o : $(START_DIR)/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.o : $(START_DIR)/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sign.o : $(START_DIR)/sign.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sign1.o : $(START_DIR)/sign1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


exp.o : $(START_DIR)/exp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


exp1.o : $(START_DIR)/exp1.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Body_Pose_Controller.o : $(START_DIR)/Body_Pose_Controller.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


circshift.o : $(START_DIR)/circshift.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Leg_Controller.o : $(START_DIR)/Leg_Controller.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### ASFLAGS = $(ASFLAGS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	@echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	@echo "### EXESIZE_FLAGS = $(EXESIZE_FLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."



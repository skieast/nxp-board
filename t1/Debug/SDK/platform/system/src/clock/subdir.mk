################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/system/src/clock/fsl_clock_manager.c \
../SDK/platform/system/src/clock/fsl_clock_manager_common.c 

OBJS += \
./SDK/platform/system/src/clock/fsl_clock_manager.o \
./SDK/platform/system/src/clock/fsl_clock_manager_common.o 

C_DEPS += \
./SDK/platform/system/src/clock/fsl_clock_manager.d \
./SDK/platform/system/src/clock/fsl_clock_manager_common.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/system/src/clock/%.o: ../SDK/platform/system/src/clock/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL43Z256VLH4" -I"/home/fellipe/workspace.kds/t1/SDK/platform/hal/inc" -I"/home/fellipe/workspace.kds/t1/SDK/platform/hal/src/sim/MKL43Z4" -I"/home/fellipe/workspace.kds/t1/SDK/platform/system/src/clock/MKL43Z4" -I"/home/fellipe/workspace.kds/t1/SDK/platform/system/inc" -I"/home/fellipe/workspace.kds/t1/SDK/platform/osa/inc" -I"/home/fellipe/workspace.kds/t1/SDK/platform/CMSIS/Include" -I"/home/fellipe/workspace.kds/t1/SDK/platform/devices" -I"/home/fellipe/workspace.kds/t1/SDK/platform/devices/MKL43Z4/include" -I"/home/fellipe/workspace.kds/t1/SDK/platform/utilities/src" -I"/home/fellipe/workspace.kds/t1/SDK/platform/utilities/inc" -I"/home/fellipe/workspace.kds/t1/SDK/platform/devices/MKL43Z4/startup" -I"/home/fellipe/workspace.kds/t1/Generated_Code/SDK/platform/devices/MKL43Z4/startup" -I"/home/fellipe/workspace.kds/t1/Sources" -I"/home/fellipe/workspace.kds/t1/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



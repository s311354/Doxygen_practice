################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../process/bitwise.c \
../process/linked_list.c \
../process/recurse.c \
../process/struct_process.c 

OBJS += \
./process/bitwise.o \
./process/linked_list.o \
./process/recurse.o \
./process/struct_process.o 

C_DEPS += \
./process/bitwise.d \
./process/linked_list.d \
./process/recurse.d \
./process/struct_process.d 


# Each subdirectory must supply rules for building sources it contributes
process/%.o: ../process/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/Users/shi-rongliu/eclipse-workspace/C_Practice/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LinkedList.c \
../controller.c \
../funciones.c \
../main.c \
../parser.c \
../piloto.c \
../vuelo.c 

OBJS += \
./LinkedList.o \
./controller.o \
./funciones.o \
./main.o \
./parser.o \
./piloto.o \
./vuelo.o 

C_DEPS += \
./LinkedList.d \
./controller.d \
./funciones.d \
./main.d \
./parser.d \
./piloto.d \
./vuelo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



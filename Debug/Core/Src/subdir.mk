################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/can.c \
../Core/Src/main.c \
../Core/Src/param_process_data.c \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/stm32f3xx_it.c \
../Core/Src/tim.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/can.o \
./Core/Src/main.o \
./Core/Src/param_process_data.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/tim.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/can.d \
./Core/Src/main.d \
./Core/Src/param_process_data.d \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/stm32f3xx_it.d \
./Core/Src/tim.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/BSP/STM32F3xx_Nucleo_32 -I../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/can.d ./Core/Src/can.o ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/param_process_data.d ./Core/Src/param_process_data.o ./Core/Src/stm32f3xx_hal_msp.d ./Core/Src/stm32f3xx_hal_msp.o ./Core/Src/stm32f3xx_it.d ./Core/Src/stm32f3xx_it.o ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/usart.d ./Core/Src/usart.o

.PHONY: clean-Core-2f-Src


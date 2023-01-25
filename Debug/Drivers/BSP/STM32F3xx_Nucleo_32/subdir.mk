################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.c 

OBJS += \
./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.o 

C_DEPS += \
./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32F3xx_Nucleo_32/%.o: ../Drivers/BSP/STM32F3xx_Nucleo_32/%.c Drivers/BSP/STM32F3xx_Nucleo_32/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/BSP/STM32F3xx_Nucleo_32 -I../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32F3xx_Nucleo_32

clean-Drivers-2f-BSP-2f-STM32F3xx_Nucleo_32:
	-$(RM) ./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.d ./Drivers/BSP/STM32F3xx_Nucleo_32/stm32f3xx_nucleo_32.o

.PHONY: clean-Drivers-2f-BSP-2f-STM32F3xx_Nucleo_32


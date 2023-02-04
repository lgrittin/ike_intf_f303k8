################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/system_stm32f3xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f3xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/%.o Drivers/CMSIS/%.su: ../Drivers/CMSIS/%.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/BSP/STM32F3xx_Nucleo_32 -I../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32f3xx.d ./Drivers/CMSIS/system_stm32f3xx.o ./Drivers/CMSIS/system_stm32f3xx.su

.PHONY: clean-Drivers-2f-CMSIS


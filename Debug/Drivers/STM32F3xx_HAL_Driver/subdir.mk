################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_can.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cec.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_comp.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_exti.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_hrtim.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_irda.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_iwdg.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nand.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nor.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pccard.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sdadc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smbus.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sram.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tsc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart_ex.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_wwdg.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_adc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_comp.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_crc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dac.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dma.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_exti.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_fmc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_gpio.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_hrtim.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_i2c.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_opamp.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_pwr.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rcc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rtc.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_spi.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_tim.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usart.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usb.c \
../Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_utils.c 

OBJS += \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_can.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cec.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_comp.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_exti.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_hrtim.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_irda.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_iwdg.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nand.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nor.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pccard.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sdadc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smbus.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sram.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tsc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart_ex.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_wwdg.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_adc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_comp.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_crc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dac.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dma.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_exti.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_fmc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_gpio.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_hrtim.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_i2c.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_opamp.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_pwr.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rcc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rtc.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_spi.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_tim.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usart.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usb.o \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_utils.o 

C_DEPS += \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_can.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cec.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_comp.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_exti.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_hrtim.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_irda.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_iwdg.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nand.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nor.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pccard.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sdadc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smbus.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sram.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tsc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart_ex.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_wwdg.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_adc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_comp.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_crc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dac.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dma.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_exti.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_fmc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_gpio.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_hrtim.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_i2c.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_opamp.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_pwr.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rcc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rtc.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_spi.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_tim.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usart.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usb.d \
./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F3xx_HAL_Driver/%.o: ../Drivers/STM32F3xx_HAL_Driver/%.c Drivers/STM32F3xx_HAL_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F303x8 -DUSE_STM32F3XX_NUCLEO_32 -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/BSP/STM32F3xx_Nucleo_32 -I../Drivers/CMSIS/Include -Os -ffunction-sections -Wall -Wno-missing-braces -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F3xx_HAL_Driver

clean-Drivers-2f-STM32F3xx_HAL_Driver:
	-$(RM) ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_adc_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_can.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_can.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cec.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cec.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_comp.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_comp.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_cortex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_crc_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dac_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_dma.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_exti.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_exti.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_flash_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_gpio.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_hrtim.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_hrtim.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2c_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_i2s_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_irda.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_irda.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_iwdg.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_iwdg.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nand.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nand.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nor.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_nor.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_opamp_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pccard.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pccard.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pcd_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_pwr_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rcc_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_rtc_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sdadc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sdadc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smartcard_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smbus.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_smbus.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_spi_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sram.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_sram.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tim_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tsc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_tsc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_uart_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart_ex.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_usart_ex.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_wwdg.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_hal_wwdg.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_adc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_adc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_comp.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_comp.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_crc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_crc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dac.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dac.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dma.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_dma.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_exti.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_exti.o
	-$(RM) ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_fmc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_fmc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_gpio.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_gpio.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_hrtim.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_hrtim.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_i2c.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_i2c.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_opamp.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_opamp.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_pwr.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_pwr.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rcc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rcc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rtc.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_rtc.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_spi.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_spi.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_tim.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_tim.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usart.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usart.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usb.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_usb.o ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_utils.d ./Drivers/STM32F3xx_HAL_Driver/stm32f3xx_ll_utils.o

.PHONY: clean-Drivers-2f-STM32F3xx_HAL_Driver


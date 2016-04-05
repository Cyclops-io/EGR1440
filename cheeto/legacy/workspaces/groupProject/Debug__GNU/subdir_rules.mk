################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Compiler'
	"/home/cheeto/programs/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/bin/arm-none-eabi-gcc" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__MSP432P401R__ -DTARGET_IS_FALCON -Dgcc -I"/home/cheeto/programs/ti/ccsv6/ccs_base/arm/include" -I"/home/cheeto/programs/ti/ccsv6/ccs_base/arm/include/CMSIS" -I"/home/cheeto/programs/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-4_8-2014q3/arm-none-eabi/include" -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '



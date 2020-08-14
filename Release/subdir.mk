################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SMD5050LEDStrip.cpp \
../led_strip_scheduler.cpp \
../scheduler.cpp 

LINK_OBJ += \
./SMD5050LEDStrip.cpp.o \
./led_strip_scheduler.cpp.o \
./scheduler.cpp.o 

CPP_DEPS += \
./SMD5050LEDStrip.cpp.d \
./led_strip_scheduler.cpp.d \
./scheduler.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
SMD5050LEDStrip.cpp.o: ../SMD5050LEDStrip.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/ledstates" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/generators" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/android_messages" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

led_strip_scheduler.cpp.o: ../led_strip_scheduler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/ledstates" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/generators" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/android_messages" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

scheduler.cpp.o: ../scheduler.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/Applications/Eclipse.app/Contents/Eclipse//arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino5/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/ledstates" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/cores/arduino" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/generators" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler" -I"/Users/karthikdharmarajan/Documents/Arduino/led-light-strip-scheduler/android_messages" -I"/Applications/Eclipse.app/Contents/Eclipse/arduinoPlugin/packages/arduino/hardware/avr/1.8.2/variants/standard" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


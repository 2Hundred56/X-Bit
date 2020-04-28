################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BlankTexture.cpp \
../src/CentralManager.cpp \
../src/CollisionManager.cpp \
../src/CollisionTerms.cpp \
../src/GraphicsManager.cpp \
../src/IntVector.cpp \
../src/PaletteTexture.cpp \
../src/Pixel.cpp \
../src/Player.cpp \
../src/Rect.cpp \
../src/RenderTarget.cpp \
../src/ResourceManager.cpp \
../src/SDLTarget.cpp \
../src/TestHandle.cpp \
../src/TestObject.cpp \
../src/Tileset.cpp \
../src/Time.cpp \
../src/Vector.cpp \
../src/main.cpp 

OBJS += \
./src/BlankTexture.o \
./src/CentralManager.o \
./src/CollisionManager.o \
./src/CollisionTerms.o \
./src/GraphicsManager.o \
./src/IntVector.o \
./src/PaletteTexture.o \
./src/Pixel.o \
./src/Player.o \
./src/Rect.o \
./src/RenderTarget.o \
./src/ResourceManager.o \
./src/SDLTarget.o \
./src/TestHandle.o \
./src/TestObject.o \
./src/Tileset.o \
./src/Time.o \
./src/Vector.o \
./src/main.o 

CPP_DEPS += \
./src/BlankTexture.d \
./src/CentralManager.d \
./src/CollisionManager.d \
./src/CollisionTerms.d \
./src/GraphicsManager.d \
./src/IntVector.d \
./src/PaletteTexture.d \
./src/Pixel.d \
./src/Player.d \
./src/Rect.d \
./src/RenderTarget.d \
./src/ResourceManager.d \
./src/SDLTarget.d \
./src/TestHandle.d \
./src/TestObject.d \
./src/Tileset.d \
./src/Time.d \
./src/Vector.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



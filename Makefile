# g++ main.cpp -o build/main.o
# g++ engine.hpp -o build/engine.d

# Compile the C++ files in the current directory and when done, link the executable into build/build.exe
CFLAGS = -std=c++17 -I. -I'/e/programs/VulkanSDK/1.3.261.1/include'
LDFLAGS = -L'/e/programs/VulkanSDK/1.3.261.1/lib' `pkg-config --static --libs glfw3` -l:vulkan-1.lib # /e/programs/VulkanSDK/1.3.261.1/Lib/vulkan-1.lib' #'bin/vulkan-1.dll'
# 'pkg-config --static --libs glfw3' -L'/e/programs/VulkanSDK/1.3.261.1/Lib/vulkan-1.lib'

build.exe: *.cpp *.hpp
	@echo -e "\033[34;34mCompiling \033[32;32m$< \033[0m"
	@g++ $(CFLAGS) -o build/build.exe *.cpp $(LDFLAGS)

.PHONY: test clean

test: build.exe
	./build/build.exe

clean:
	rm -f build/build.exe
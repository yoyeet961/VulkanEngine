# g++ main.cpp -o build/main.o
# g++ engine.hpp -o build/engine.d

# Compile the C++ files in the current directory into build/fileName.o, and when done, link the executable into build/build.exe
CFLAGS = -std=c++17 -I. -I usr/include
LDFLAGS = -L'include/lib' `pkg-config --static --libs glfw3` -L'bin/vulkan-1.dll'
# 'pkg-config --static --libs glfw3'

build.exe: *.cpp *.hpp
	@echo -e "\033[34;34mCompiling... \033[0m"
	g++ $(CFLAGS) -o build/build.exe *.cpp $(LDFLAGS)

.PHONY: test clean

test: build.exe
	./build/build.exe

clean:
	rm -f build/build.exe
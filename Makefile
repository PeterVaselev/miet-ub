

GCC = g++
CLANG = clang++
CPP_FLAGS = -std=c++23 -O3
BUILD_DIRECTORY = build

all: vector_test limit_int bench array_access
	@echo "All examples are builded"

build: 
	@mkdir -p $(BUILD_DIRECTORY)

vector_test: example_function_calling
	@echo "$< are builded"

limit_int: example_limit_int
	@echo "$< are builded"

bench: example_bit_sdvig
	@echo "$< are builded"

array_access: example_array_access
	@echo "$< are builded"


example_%: src/%.cpp build
	@echo "Build with $(GCC)"
	@$(GCC) $< $(CPP_FLAGS) -o $(BUILD_DIRECTORY)/$@_gcc
	@echo "Build done."
	@echo "Build with $(CLANG)"
	@$(CLANG) $< $(CPP_FLAGS) -o $(BUILD_DIRECTORY)/$@_clang
	@echo "Build done."


clean:
	@rm -fr $(BUILD_DIRECTORY)/*
	@echo "Successfully clean"




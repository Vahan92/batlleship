HEADER := $(wildcard ./src/*.h)
SOURCE := $(wildcard ./src/*.cpp)
OBJECTS := $(patsubst ./src/%.cpp, ./obj/%.o, $(SOURCE))
CC := g++
TARGET := battleships.exe

$(TARGET) : $(OBJECTS) $(HEADER)	
	@mkdir -p bin		
	@$(CC) $^ -o bin/$@

obj/%.o : src/%.cpp 
	@mkdir -p obj
	@echo $@
	@echo "OBJ = $(OBJECTS)"
	$(CC) -c $< -o $@
	
.PHONY: clean doxygen tests
clean:
	@rm -rf bin obj docs/html docs/latex test_results tests/bin tests/obj

doxygen:
	@doxygen ./docs/Doxyfile

tests: 
	cd tests && $(MAKE)
	./tests/bin/test1.exe
	./tests/bin/test2.exe

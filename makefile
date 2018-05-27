HEADER := $(widcard ./src/*.h)
SOURCE := $(wildcard ./src/*.cpp)
OBJECTS := $(patsubst ./src/%.cpp, ./obj/%.o, $(SOURCE))
CC := g++
TARGET := battleships.exe

$(TARGET) : $(OBJECTS)	
	@mkdir -p bin		
	@$(CC) $^ -o bin/$@

obj/%.o : src/%.cpp 
	@mkdir -p obj
	@echo $@
	@echo "OBJ = $(OBJECTS)"
	$(CC) -c $< -o $@
	
clean:
	@rm -f *.o *.exe
	@rm -rf bin
	@rm -rf obj 
	@rm -rf docs/html
	@rm -rf docs/latex

.PHONY: doxygen
doxygen:
	@doxygen ./docs/Doxyfile


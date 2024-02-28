CXX=c++ 
SOURCES=main.cpp 

CXXFLAGS=-fsanitize=address -g
LDFLAGS=-fsanitize=address -g
DEPFLAGS=-MMD -MP

OBJECTS:=$(SOURCES:.cpp=.o)
TARGET=vector

DEPS=.deps
-include $(DEPS)/$*.d

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@
	@mkdir -p $(DEPS)
	@mv $*.d $(DEPS) 

run: $(TARGET) 
	./$(TARGET)

clean: 
	$(RM) $(OBJECTS) $(TARGET)



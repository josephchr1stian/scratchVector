CXX=c++ 
SOURCES=main.cpp 

CXXFLAGS= -g -fsanitize=address
LDFLAGS=-g -fsanitize=address
DEPFLAGS=-MMD -MP

OBJECTS:=$(SOURCES:.cpp=.o)
TARGET=vector

DEPS=.deps
-include $(DEPS)/$(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

%.o : %.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@
	@mkdir -p $(DEPS)
	@mv $*.d $(DEPS) 

run: $(TARGET) 
	./$(TARGET)

clean: 
	$(RM) -r $(OBJECTS) $(TARGET) $(DEPS)

.DEFAULT_GOAL=$(TARGET)

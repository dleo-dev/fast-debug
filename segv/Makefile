CSRCS=$(wildcard *.c)
CXXSRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(CXXSRCS)) $(patsubst %.c,%.o,$(CSRCS))
EXECUTABLE=test

CFLAGS=-g
CXXFLAGS=-g
LDFLAGS=-rdynamic 
LIBS=

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@echo "Link $@"
	@$(CXX) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	@echo "Compile $@"
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

%.o: %.c
	@echo "Compile $@"
	@$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	@echo "Remove all objects and binaries"
	@rm -f *.o
	@rm -f $(EXECUTABLE)

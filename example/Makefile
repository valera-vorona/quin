BIN = test
BINPP = testpp

# Flags
CFLAGS += -I..
CXXFLAGS += -I..

SRC = test.c
OBJ = $(SRC:.c=.o)

SRCPP = testpp.cpp
OBJPP = $(SRCPP:.cpp=.o)

ifeq ($(OS),Windows_NT)
BIN := $(BIN).exe
BINPP := $(BINPP).exe
endif

all: $(BIN) $(BINPP)

$(BIN): clean
	$(CC) $(SRC) $(CFLAGS) -o $(BIN)

$(BINPP): clean
	$(CXX) $(SRCPP) $(CXXFLAGS) -o $(BINPP)

clean:
	rm -f $(OBJ) $(OBJPP)

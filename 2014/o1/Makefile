VPATH			=	./src
CXXFLAGS		=	-I	"./include"
CXXLIBDIR		=	-L	"./lib"
CPPFILES		=	$(wildcard	./src/*.cpp)
OBJFILES		=	$(notdir	$(CPPFILES:.cpp=.o))
OBJFILES1		=	$(addprefix	./lib/,$(filter-out	b%_1.o,$(OBJFILES)))

all:test calistir

test:$(OBJFILES1)
	g++	$(OBJFILES1)	-o	./bin/test	$(CXXLIBDIR)	

lib/%.o:%.cpp
	g++		-c $(CXXFLAGS)	$<	-o	$@

calistir:
	./bin/test
	
clean:
	del	lib\*.o
	del	*.exe
CXX = g++-13
CXXFLAGS = -std=c++20 -Werror=vla -g -O0 -Wall -MMD
EXEC = GameofLife
OBJECTS = main.o board.o action.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

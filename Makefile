CXX = g++
# CXX = clang++

CXXFLAGS= -Wall -Wno-uninitialized

BINARIES=distanceBetweenTest initPointTest pointsApproxEqualTest boxesApproxEqualTest \
	initBoxTest areaOfBoxTest pointToStringTest boxToStringTest

COMMON_OBJECTS=tddFuncs.o utility.o shapeFuncs.o

all: ${BINARIES}

tests: ${BINARIES}
	./distanceBetweenTest
	./initPointTest
	./pointsApproxEqualTest
	./boxesApproxEqualTest
	./initBoxTest
	./areaOfBoxTest
	./pointToStringTest
	./boxToStringTest


distanceBetweenTest: distanceBetweenTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

initPointTest: initPointTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

pointsApproxEqualTest: pointsApproxEqualTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@


boxesApproxEqualTest: boxesApproxEqualTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

areaOfBoxTest: areaOfBoxTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

initBoxTest: initBoxTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

pointToStringTest: pointToStringTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

boxToStringTest: boxToStringTest.o $(COMMON_OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

boxToStringTest.o: boxToStringTest.cpp
	$(CXX) $(CXXFLAGS) -c boxToStringTest.cpp -o boxToStringTest.o

clean:
	/bin/rm -f ${BINARIES} *.o

CXX = g++

OBJECTS = main.o detectToken.o bruteForce.o kmp.o sunday.o
CXXFLAGS += $(INCLUDES) -g -O3

detectToken : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o detectToken

#%.o : %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@
	
main.o : main.cpp detectToken.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
detectToken.o : detectToken.cpp detectToken.h stringMatching.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
bruteForce.o : bruteForce.cpp stringMatching.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
kmp.o : kmp.cpp stringMatching.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
sunday.o : sunday.cpp stringMatching.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
bm.o : bm.cpp stringMatching.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:	
	rm -f detectToken *.o *.out
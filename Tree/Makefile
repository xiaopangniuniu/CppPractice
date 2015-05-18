CXX = g++

OBJECTS = tree.o binaryTree.o
CXXFLAGS += $(INCLUDES) -g -O3

tree : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o tree

#%.o : %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@
	
tree.o : CallTree.cpp BinaryTree.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
binaryTree.o : BinaryTree.cpp BinaryTree.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:	
	rm -f tree *.o *.out
CXX = g++

OBJECTS = main.o insertSort.o exchangeSort.o selectSort.o mergeSort.o
CXXFLAGS += $(INCLUDES) -g -O3

sorting : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o sorting

#%.o : %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@
	
main.o : main.cpp SortingHeader.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
insertSort.o : InsertSorting.cpp SortingHeader.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
exchangeSort.o : ExchangeSort.cpp SortingHeader.h 
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
selectSort.o : SelectSort.cpp SortingHeader.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
mergeSort.o : MergeSorting.cpp SortingHeader.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:	
	rm -f sorting *.o *.out
CXX := g++
OMP = -fopenmp
OPTLEVEL = -O2
# CXX := icpc
# OMP = -qopenmp
# ICPC_OPT_REPORT := -qopt-report -qopt-report-phase=vec 
CXX_WARNING_OPTIONS := -Wall -Wextra -Wno-unused-variable -Wno-unused-function $(ICPC_OPT_REPORT) 

# CXX_STANDATD = c++11
# CXX_STANDATD = c++14
CXX_STANDATD = c++17

CXXFLAGS := -std=$(CXX_STANDATD) $(OPTLEVEL)  $(OMP) $(CXX_WARNING_OPTIONS) 
LDFALGS := -pthread $(OMP) -lpthread -lm -ldl

DEBUGGING = -g
# DEBUGGING =
CXXFLAGS := $(CXXFLAGS) -I$(LIB_DIR) -I./ $(DEBUGGING) -fPIC

.PHONY: clean 

# APP 

OpenTask_HelloWorld: OpenTask_HelloWorld.o 
	$(CXX) -std=$(CXX_STANDATD) OpenTask_HelloWorld.o -L. $(LDFLAGS) $(DEBUGGING) -o OpenTask_HelloWorld.exe $(LDFALGS) 

DataSharing: DataSharing.o 
	$(CXX) -std=$(CXX_STANDATD) DataSharing.o -L. $(LDFLAGS) $(DEBUGGING) -o DataSharing.exe $(LDFALGS) 

OpenTask_HelloWorld.o: 00-OpenTask_HelloWorld.cpp 
	$(CXX) $(CXXFLAGS)  -c -o OpenTask_HelloWorld.o 00-OpenTask_HelloWorld.cpp 

DataSharing.o: 01-DataSharing.cpp 
	$(CXX) $(CXXFLAGS)  -c -o DataSharing.o 01-DataSharing.cpp 

clean:
	rm *.o
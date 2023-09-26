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

Single_Barrier_Construct: Single_Barrier_Construct.o 
	$(CXX) -std=$(CXX_STANDATD) Single_Barrier_Construct.o -L. $(LDFLAGS) $(DEBUGGING) -o Single_Barrier_Construct.exe $(LDFALGS) 

Child_Task_Taskwait : Child_Task_Taskwait.o
	$(CXX) -std=$(CXX_STANDATD) Child_Task_Taskwait.o -L. $(LDFLAGS) $(DEBUGGING) -o Child_Task_Taskwait.exe $(LDFALGS) 

fib : fib.o
	$(CXX) -std=$(CXX_STANDATD) fib.o -L. $(LDFLAGS) $(DEBUGGING) -o fib.exe $(LDFALGS) 

TaskLoop_TaskGroup: TaskLoop_TaskGroup.o 
	$(CXX) -std=$(CXX_STANDATD) TaskLoop_TaskGroup.o -L. $(LDFLAGS) $(DEBUGGING) -o TaskLoop_TaskGroup.exe $(LDFALGS)

OpenTask_HelloWorld.o: 00-OpenTask_HelloWorld.cpp 
	$(CXX) $(CXXFLAGS)  -c -o OpenTask_HelloWorld.o 00-OpenTask_HelloWorld.cpp 

DataSharing.o: 01-DataSharing.cpp 
	$(CXX) $(CXXFLAGS)  -c -o DataSharing.o 01-DataSharing.cpp 

Single_Barrier_Construct.o: 02-Single_Barrier_Construct.cpp 
	$(CXX) $(CXXFLAGS)  -c -o Single_Barrier_Construct.o 02-Single_Barrier_Construct.cpp 

Child_Task_Taskwait.o : 03-Child_Task_Taskwait.cpp
	$(CXX) $(CXXFLAGS)  -c -o Child_Task_Taskwait.o 03-Child_Task_Taskwait.cpp

fib.o : 04-fib.cpp
	$(CXX) $(CXXFLAGS)  -c -o fib.o 04-fib.cpp

TaskLoop_TaskGroup.o: 05-TaskLoop_TaskGroup.cpp 
	$(CXX) $(CXXFLAGS)  -c -o TaskLoop_TaskGroup.o 05-TaskLoop_TaskGroup.cpp

clean:
	rm *.o
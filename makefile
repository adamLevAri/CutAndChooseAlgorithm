#!make -f

CFLAGS=-stdlib=libc++ -std=c++11

cutDemo:  Agent.o CutAndChoose.o Allocation.o PiecewiseConstantAgent.o PiecewiseUniformAgent.o CutAndChooseDemo.o
	g++ $(CFLAGS) $^ -o cutDemo

lastDemo:  Agent.o CutAndChoose.o Allocation.o PiecewiseConstantAgent.o PiecewiseUniformAgent.o LastDiminisherDemo.o
	g++ $(CFLAGS) $^ -o lastDemo

test:  Agent.o CutAndChoose.o Allocation.o PiecewiseConstantAgent.o PiecewiseUniformAgent.o badkan.o
	g++ $(CFLAGS) $^ -o test

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@
	
Agent.o: Agent.cpp Agent.hpp

CutAndChooseDemo.o: CutAndChooseDemo.cpp 

LastDiminisherDemo.o: LastDiminisherDemo.cpp

badkan.o: badkan.cpp badkan.hpp

CutAndChoose.o: CutAndChoose.cpp CutAndChoose.hpp

Allocation.o: Allocation.cpp Allocation.hpp

PiecewiseConstantAgent.o: PiecewiseConstantAgent.cpp PiecewiseConstantAgent.hpp

PiecewiseUniformAgent.o: PiecewiseUniformAgent.cpp PiecewiseUniformAgent.hpp

clean:
	rm -f *.o cutDemo lastDemo test

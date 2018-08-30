CC = g++
CFLAGS = -std=c++11
SRCS = annotation.cpp functions.cpp help.cpp main.cpp
PROG = ground_truth.out

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

all:
	$(CC) $(CFLAGS) -o $(PROG) $(SRCS) $(LIBS)

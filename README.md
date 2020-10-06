# ML_With_Cpp
This repo contains what most people fear - "ML with C++"

Each folder contains the project files related to a Machine Learning Algorithm in C++. These are a combination of .cpp, .h and Makefiles.

## Instructions to compile:

You can compile and produce the executable by running the command 'make' on your Linux terminal. It is assumed that you store all the files in the same folder including the Makefile.

**OR**

Use the command ```g++ -c -Wall filename.cpp``` to compile each .cpp file and them link the resulting object files (.o files) using the command ```g++ filename.o filename1.o -o myprog.exe```

## Data Visualization

For data visualization purposes we have used ```Python``` as the goal of this project is to implement ML algorithms in C++ and not learn data visualization with C++ which is an entirely different and undoubtedly interesting domain to discover

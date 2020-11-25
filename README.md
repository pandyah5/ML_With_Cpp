# ML_With_Cpp
This repo contains what most people fear - "ML with C++"

Each folder contains the project files related to a Machine Learning Algorithm in C++. These are a combination of .cpp, .h and Makefiles.

## Instructions to compile:

You can compile and produce the executable by running the command 'make' on your Linux terminal. It is assumed that you store all the files in the same folder including the Makefile.

**OR**

Use the command ```g++ -c -Wall filename.cpp``` to compile each .cpp file and them link the resulting object files (.o files) using the command ```g++ filename.o filename1.o -o myprog.exe```

## Contents:

- **Linear Regression**

  In statistics, linear regression is a linear approach to modelling the relationship between a scalar response and one or more explanatory variables (also known as dependent     and independent variables). In linear regression, the relationships are modeled using linear predictor functions whose unknown model parameters are estimated from the data.

- **Perceptron**

  In machine learning, the perceptron is an algorithm for supervised learning of binary classifiers. A binary classifier is a function which can decide whether or not an input,   represented by a vector of numbers, belongs to some specific class. It is a type of linear classifier, i.e. a classification algorithm that makes its predictions based on a     linear predictor function combining a set of weights with the feature vector.
  
- **K-Means**

  k-means clustering is a method of vector quantization, originally from signal processing, that aims to partition n observations into k clusters in which each observation         belongs to the cluster with the nearest mean (cluster centers or cluster centroid), serving as a prototype of the cluster. This results in a partitioning of the data space       into Voronoi cells.


## Data Visualization

For data visualization purposes we have used ```Python``` as the goal of this project is to implement ML algorithms in C++ and not learn data visualization with C++ which is an entirely different and undoubtedly interesting domain to discover

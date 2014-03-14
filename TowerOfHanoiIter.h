#ifndef __play__TowerOfHanoiIter__
#define __play__TowerOfHanoiIter__

#include <iostream>
using namespace std;

//To Test the algorithm
void runIt();

//This function prints the three pegs
void printMove(int [], int [] , int [], int, bool);

//This function move the disks from one peg to the other
void moveDisk(int, int *, int *, int *, int *);

//This calculates the minimum number of steps required to solve the problem
int formulaSteps(int);

//Just to be on the safe side because I am testing integer arrays ;)
bool inBound(int, int);

#endif /* defined(__play__TowerOfHanoiIter__) */
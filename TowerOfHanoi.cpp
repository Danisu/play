#include "TowerOfHanoi.h"

/*
**Question Reference: http://en.wikipedia.org/wiki/Tower_of_Hanoi
**Tower of Hanoi recursive function
**Takes disWeight as a first argument: Max weight is diskWeight and Min weight is 0
**Three character 
*/
void moveDisks (int diskWeight, char source, char dest, char spare){
    if (diskWeight == 0){
        cout << "Move disk " << diskWeight << " from peg " << source << " to peg " << dest << endl;
    }else{
        moveDisks(diskWeight - 1, source, spare, dest);
        cout << "Move disk "  << diskWeight << " from peg " << source << " to peg " << dest << endl;
        moveDisks(diskWeight - 1, spare, dest, source);
    }
    
}
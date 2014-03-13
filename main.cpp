#include "TowerOfHanoi.h"

int main(int argc, const char * argv[])
{
    //moveDisks(weight of disks (0 smallest), Source Peg,
    //                         Spare Peg, Destination Peg);
    moveDisks(3, 'A','B','C');
    return 0;
}

/** Output
 Move disk 0 from peg A to peg C
 Move disk 1 from peg A to peg B
 Move disk 0 from peg C to peg B
 Move disk 2 from peg A to peg C
 Move disk 0 from peg B to peg A
 Move disk 1 from peg B to peg C
 Move disk 0 from peg A to peg C
 Move disk 3 from peg A to peg B
 Move disk 0 from peg C to peg B
 Move disk 1 from peg C to peg A
 Move disk 0 from peg B to peg A
 Move disk 2 from peg C to peg B
 Move disk 0 from peg A to peg C
 Move disk 1 from peg A to peg B
 Move disk 0 from peg C to peg B
 Program ended with exit code: 0
**/
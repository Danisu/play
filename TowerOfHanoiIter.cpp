#include "TowerOfHanoiIter.h"
/*
 ** For even number of disks it moves all the disks to spare peg
 ** For odd number of disks it moves all the disks to destination peg
 
 ** Quick fix in the printMove function
 ** change the reference from spare to destination when number of disks are even
 */

void runIt(){
    //declare the number of disks for tower of Hanoi
    int numDisks;
    printf("Enter the number of Disks: ");
    
    scanf("%d",&numDisks);
    
    int source[numDisks], spare[numDisks], dest[numDisks];
    
    //initialize pegs
    for (int i = 0; i < numDisks; i++)
    {
        source[i] = i+1;        //Smallest element is 1 and largest is N
        dest[i] = spare[i] = 0; //Empty
    }
    
    //This formulaSteps counts the minimum number of steps
    //needed for tower of hanoi problem
    int steps = formulaSteps(numDisks);
    
    //This variable is used to check
    //the move needed from one peg to other
    int mvPegs = -1;
    
    //used for printMove function
    bool isEven;
    if (numDisks%2 == 0)
        isEven = true;
    else
        isEven = false;
    //These variable will keep track of the head of the peg
    int head1 = 0, head2 = numDisks-1, head3 = numDisks - 1;
    
    for (int step = 1; step <= steps; step++)
    {
        mvPegs = step%3; // Result = 1, 2, 0; 1, 2, 0 ...
        
        //I am using simple array; Just a small check
        if (inBound(head1, numDisks) && inBound(head2, numDisks) && inBound(head3, numDisks)){
            
            if (mvPegs == 1) //Peg 1 -> Peg 3 or Peg 3 -> Peg 1
            {
                moveDisk(numDisks, & head1, & head3, source, dest);
                printMove(source, spare, dest, numDisks, isEven);
            }
            else if (mvPegs == 2) // Peg 1 -> Peg 2 or Peg 2 -> Peg 1
            {
                moveDisk(numDisks, & head1, & head2, source, spare);
                printMove(source, spare, dest, numDisks, isEven);
            }
            else if (mvPegs == 0) // Peg 2 -> Peg 3 or Peg 3 -> Peg 2
            {
                moveDisk(numDisks, & head2, & head3, spare, dest);
                printMove(source, spare, dest, numDisks, isEven);
            }else
            {
                cout << "CODE 1111" << endl;
            }
        }
        else
        {
            break;
        }
    }
}

void printMove(int * source, int * spare, int * dest, int size, bool isEven){
    static int step = 0;
    if (!isEven) {
        cout << " SOURC: ";
        for (int i = 0; i < size; i++) {
            cout << source[i] << " ";
        }
        cout << endl;
        cout << " SPARE: ";
        for (int i = 0; i < size; i++) {
            cout << spare[i] << " ";
        }
        cout << endl;
        
        cout << " DESTI: ";
        for (int i = 0; i < size; i++) {
            cout << dest[i] << " ";
        }
        cout << endl;
        step++;
        cout << "--------------------- END OF STEP: " << step << endl;
    }
    else
    {
        cout << " SOURC: ";
        for (int i = 0; i < size; i++) {
            cout << source[i] << " ";
        }
        cout << endl;
        cout << " SPARE: ";
        for (int i = 0; i < size; i++) {
            cout << dest[i] << " ";     //QUICK FIX
        }
        cout << endl;
        
        cout << " DESTI: ";
        for (int i = 0; i < size; i++) {
            cout << spare[i] << " ";    //QUICK FIX
        }
        cout << endl;
        step++;
        cout << "--------------------- END OF STEP: " << step << endl;
    }
}

void moveDisk(int numDisks, int * head1, int * head2, int * peg1, int * peg2){
    int disk1, disk2, temp = 0;
    
    disk1 = peg1[*head1];
    disk2 = peg2[*head2];
    
    if (disk1 == 0)
    {
        if (disk2 != 0) {
            peg1[*head1] = disk2;   //Move disk from Disk C to A
            peg2[*head2] = 0;       //Empty the position of the moved disk
            temp = *head2 + 1;      //Move the header of the C
            if (temp >= numDisks){} //Last disk on the peg
            else
                *head2 = temp;
        }
    }
    else if (disk2 == 0)
    {
        if (disk1 != 0) {
            peg2[*head2] = disk1;   //Move disk from Disk A to C
            peg1[*head1] = 0;       //Empty the position of the moved disk
            temp = *head1 + 1;      //Move the header of the C
            if (temp >= numDisks){} //Last disk on the peg
            else
                *head1 = temp;
        }
    }
    else if (disk1 > disk2)
    {
        temp = *head1 - 1;      //Move header of A for the added disk
        *head1 = temp;
        peg1[*head1] = disk2;   //Move disk from Disk C to A
        
        peg2[*head2] = 0;       //Empty the position of the moved disk
        temp = *head2 + 1;
        if (temp >= numDisks){} //Last disk on the peg
        else
            *head2 = temp;
        
    }
    else
    {
        temp = *head2 - 1;      //Move header of C for the added disk
        *head2 = temp;
        peg2[*head2] = disk1;   //Move disk from Disk A to C
        
        peg1[*head1] = 0;       //Empty the position of the moved disk
        temp = *head1 + 1;
        if (temp >= numDisks){} //Last disk on the peg
        else
            *head1 = temp;
    }
}
// 2^n - 1
int formulaSteps(int numDisks){
    int steps = 1;
    for (int i = 0; i < numDisks; i++) {
        steps *=2;
    }
    return steps-1;
}
//Bound is {0, Number of disks -1}
bool inBound(int value, int highRange){
    if (value >= 0 && value < highRange) {
        return true;
    }else{
        cout << "Out of bound " << value << " " << highRange<< endl;
        return false;
    }
}
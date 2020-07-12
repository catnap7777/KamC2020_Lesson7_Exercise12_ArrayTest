#include <stdio.h>

#define MAX 100

int array1[MAX];
//int count = -1, maximum, minimum, num_entered, temp;
int count = -1, maximum, minimum, num_entered, temp;

int main(void)
{
    puts("Enter integer values one per line");
    puts("Enter 0 when finished.");

    do
    {
        scanf("%d", &temp);
        //for whatever reason WHEN USING DEBUGGER AND SETTING UP SOME BREAKPOINTS,
        //the following two statements with count being incremented
        // in the array assignment statements does not seem to work properly in that the values
        // entered are not assigned in sequence in the array ie.([0],[1],[3],[n])...
        // some might be in [0] then [6] then [22], etc.... weird and bad if you go past MAX = 100
        // that way. Not sure why this is happening. Compiler? C++? C99? C11?
        // Anyway, it works if you increment count separately count = count + 1 OR count++ at end of loop
        //
        //**** Additional note => the gdb may be having an issue bc array1[count++] = temp seems to work
        //****  if I just execute the program - Also, if I test/debug pgm with only setting breakpoint
        //****  at end on return, it seems to work. Maybe breakpoints and stepping into, etc.
        //****  mess up the counter???? - weird!  Need to research
        //
        //**** WARNING - Seems to only be an issue when certain breakpoint are set when debugging..
        //**** messes up counter somehow; be careful when testing
        //

        //printf("\n\tcount before = %d",count);
        array1[++count]=temp;
        //array1[count++]=temp;
        //array1[count]=temp;
        //count = count + 1;
        //count++;
        //printf("\tcount after = %d\n",count);
    } while (count < (MAX-1) && temp != 0);

    num_entered =count;

    //print the contents of the array
    for(count=0;count<=MAX && array1[count] != 0;count++)
    {
        printf("\n\t\tArray at [%d] = %d",count,array1[count]);
    }

    //Find the largest and smallest.
    //First set maximum to a very small value
    //and minimum to a very large value

    maximum = -32000;
    minimum = 32000;

    for (count=0; count<= num_entered && array1[count]!= 0; count++)
    {
        if (array1[count] > maximum)
            maximum = array1[count];
        if (array1[count] < minimum)
            minimum = array1[count];
    }

    printf("\n\n\tThe maximum value is %d", maximum);
    printf("\n\tThe minimum value is %d\n\n", minimum);

    return 0;

}


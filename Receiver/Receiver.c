#include <stdio.h>

void SimpleMovingAverage(int n, int array[])
{
    int size = 5;
    int i, sum;
    float average;
    for (i = n-5; i < n; i++) {
            sum += array[i];
        }
    average = sum / size;
    printf("The Average is: %f", average);
}


int MaxValue(int n, int array[])
{
    int Max = array[0],i;
    
    for(i = 0 ; i < n; i++)
    {
        if( array[i] > Max )
        {
            MaxB = array[i];
        }
    }
    
    return Max;
}

int MinValue(int n, int array[])
{
    int Min = array[0],i;
    
    for(i = 0 ; i < n; i++)
    {
        if( array[i] < Min )
        {
            Min = array[i];
        }
    }
    
    return Min;
}


void printMaxMinBattery(int n, int Battery[])
{
    printf("[Maximum Battery Value, Minumim Battery Value] : [%d, %d]", MaxValue(n,Battery),MinValue(n, Battery));
}

void printMaxMinCurrent(int n, int Current[])
{
    printf("[Maximum [Current] Value, Minumim Current Value] : [%d, %d]", MaxValue(n,Current),MinValue(n, Current));
}



int main()
{
    char str[60];
    int num1, num2, num3,lastnum1 = 0, index = 1;
    int Battery[50];
    int Current[50];

    while(index < 50)
    {
        fgets(str, 60, stdin);
        sscanf(str, "[Measurenment Number: Battery Charge, Current] : [%d: %d,%d]", &num1, &num2, &num3);
        fflush(stdin);
        if(num1 != lastnum1)
        {
            lastnum1 = num1;
            Battery[index] = num2;
            Current[index] = num3;
            index++;
            printf("%d\n", index);
        }
        
    }
    
    printMaxMinBattery(index,Battery);
    printMaxMinCurrent(index,Current);
    SimpleMovingAverage(index, Battery);
    SimpleMovingAverage(index, Current);
    return 0;
}

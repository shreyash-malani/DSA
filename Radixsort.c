// this uses 2 data structure

// 639  921  420  385 589  937   804  253  184  572

#include <stdio.h>
#include <stdlib.h>
#define N 10

// Function to input array elements
void input(int *a) 
{
    int i = 0;
    while (i < N) 
    {
        printf("\nEnter a 3-digit number: ");
        scanf("%d", (a + i));
        if (a[i] < 100 || a[i] > 999) 
        {
            printf("Please enter a valid 3-digit number!...\n");
            continue;
        }
        i++;
    }
}

// Function to display array elements
void display(int *a, int flg) 
{
    int i = 0;
    if (flg == 0)
        printf("\nBefore Sorting: ");
    else
        printf("\nAfter Sorting: ");

    while (i < N) 
    {
        printf("%4d", a[i]);
        i++;
    }
    printf("\n");
}

// Function to extract digit from a given position
int getDigit(int val, int pos) 
{
    int index;
    switch (pos) 
    {
        case 3: // rightmost digit
            index = val % 10;
            break;
        case 2: // middle digit
            index = (val / 10) % 10;
            break;
        case 1: // leftmost digit
            index = val / 100;
            break;
        default:
            index = 0;
            break;
    }
    return index;
}

// Queue structure to hold digits during sorting
struct queue 
{
    int arr[10];
    int fr, rr;
} q[10];  // array of 10 queues for digits 0 to 9 Global array

// Function to initialize the queue
void init() 
{
    for (int i = 0; i < 10; i++) 
    {
        q[i].fr = q[i].rr = -1;
    }
}

// Function to insert elements into the correct queue based on the digit
void insert(int *a, int pos) 
{
    int i = 0, index;
    while (i < N) 
    {
        index = getDigit(a[i], pos);
        q[index].rr++;
        q[index].arr[q[index].rr] = a[i];
        i++;
    }
}

// Function to remove elements from queues and put them back into the array
void remque(int *a) 
{
    int i = 0, j = 0, k = 0;
    while (i < 10) 
    {
        j = 0;
        while (j <= q[i].rr) 
        {
            a[k] = q[i].arr[j];
            k++;
            j++;
        }
        i++;
    }
}

// Radix sort function
void radix(int *a) 
{
    int pos = 3;
    while (pos > 0) 
    {
        init();
        insert(a, pos);
        remque(a);
        pos--;
        
    }
}

// Main function
int main() 
{
    int x[N];
    input(x);
    display(x, 0);
    radix(x);
    display(x, 1);
    return 0;
}
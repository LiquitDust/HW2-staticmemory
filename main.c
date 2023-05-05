//***************************************
//** DO NOT SUBMIT THIS FILE
//***************************************
#include <stdio.h>
#include <math.h>

void print();
void push(float,float);
void pop();
void print_polar();
void sort();
void sort_polar();

int main()
{
    int r;
    push(1,1);
    push(0,1);
    push(2,2);
    push(0,2);
    push(3,5);
    print();
    sort();
    print();
    
    
    printf(".............................................................................................");
    scanf("%d",&r);
    
    return 0;
}

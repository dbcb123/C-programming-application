/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int recivingGoods[100];
    int salingGoods[100];
    int remainGoods[100];
    int category;
    int count;
    int id;
    scanf("%d", &category);
    
    for(int i = 0; i < category; i++) {
        scanf("%d", &count);
        recivingGoods[i] = count; 
    }
    for(int i = 0; i < category; i++) {
        scanf("%d", &count);
        salingGoods[i] = count; 
    }
    for(int i = 0; i < category; i++) {
        remainGoods[i] = recivingGoods[i] - salingGoods[i]; 
    }
    
    scanf("%d", &id);
    
    printf("출력=========================\n");
    printf("%d\n", remainGoods[id-1]);
    
    for(int i = 0; i < category; i++) {
        printf("%d ", remainGoods[i]);
        if(i == category - 1) printf("\n");
    }
}
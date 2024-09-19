/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void insertGroupGoods(int size, int* array) {
    int count;
    for(int i = 0; i < size; i++) {
        scanf("%d", &count);
        *(array + i) = count;
    }    
}

void insertSingleGoods(int id, int count, int* array) {
    *(array + (id - 1)) = count;
}

void setRemainGoods(int size, int* receiveGoods, int* soldGoods, int* array) {
    for(int i = 0; i < size; i++) {
        *(array + i) = *(receiveGoods + i) - *(soldGoods + i);
    }
}

void getRemainGoods(int size, int* receiveGoods, int* soldGoods, int* remainGoods) {
    printf("재고 수량:");
    int allReciveCount = 0;
    int allSoldCount = 0;
    for(int i = 0; i < size; i++) {
        printf("%d ", *(remainGoods + i));
        allReciveCount += *(receiveGoods + i);
        allSoldCount += *(soldGoods + i);
        if(i == size - 1) {
            printf("\n");
        }
    }
    printf("총 판매량: %d (판매율 %f)\n", allSoldCount, allSoldCount / (float)allReciveCount * 100 );
    for(int i = 0; i < size; i++) {
        if(*(remainGoods + i) <= 2) {
            printf("상품ID %d : 재고부족(%d)\n", i + 1, *(remainGoods + i));
        }
    }
}

int main()
{
    int select = 0;
    int menuSelect, id, count;
    int receiveGoods[5] = { 0, 0, 0, 0, 0};
    int soldGoods[5]= { 0, 0, 0, 0, 0};
    int remainGoods[5] = { 0, 0, 0, 0, 0};
    while(1) {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료\n");
        scanf("%d", &select);
        
        if(select == 4) break;
        
        switch (select) {
            case 1:
                printf("입고수량 입력 : 전체 상품 입고 수량 입력1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &menuSelect);
                if(menuSelect == 1) {
                    insertGroupGoods(5, receiveGoods);
                } else {
                    printf("상품ID:");
                    scanf("%d", &id);
                    printf("입고수량:");
                    scanf("%d", &count);
                    insertSingleGoods(id, count, receiveGoods);
                }
                printf("\n");
                break;
            case 2:
                printf("판매수량 입력 : 전체 상품 판매 수량 입력1, 개별 상품 입력 2를 선택\n");
                scanf("%d", &menuSelect);
                if(menuSelect == 1) {
                    insertGroupGoods(5, soldGoods);
                } else {
                    printf("상품ID:");
                    scanf("%d", &id);
                    printf("판매수량:");
                    scanf("%d", &count);
                    insertSingleGoods(id, count, soldGoods);
                }
                printf("\n");
                break;
            case 3:
                setRemainGoods(5, receiveGoods, soldGoods, remainGoods);
                getRemainGoods(5, receiveGoods, soldGoods, remainGoods);
                printf("\n");
                break;
                
        }
    }
 

    return 0;
}
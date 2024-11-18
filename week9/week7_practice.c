#include <stdio.h>
#include <string.h>
typedef struct Goods {
    int id;
    char name[100];
    int receivedCount;
    int soldCount;
    int price;
} GOODS;

void setReceivedList (GOODS *goods) {
    int id;
    char name[100];
    int count;
    int price;
    int i = 0;
    
    printf("상품ID:");
    scanf("%d", &id);
    printf("상품명:");
    scanf("%s", name);
    printf("입고량:");
    scanf("%d", &count);
    printf("판매가격:");
    scanf("%d", &price);
    
    printf("%d", (goods + i)->id);
    
    
    while((goods + i)->id != id && (goods + i) -> id) {
        i++;
    }

    if(i >= 4) {
        printf("허용 갯수 초과\n");
    }
    (goods + i) -> id = id;
    strcpy((goods + i) -> name, name);
    (goods + i) -> receivedCount = count;
    (goods + i) -> soldCount = 0;
    (goods + i) -> price = price;
}

void setSoldList (GOODS *goods) {
    int id;
    int check = 0;
    int count, soldCount;
    
    printf("상품 ID:");
    scanf("%d", &id);
    for(int i = 0; i < 5; i++) {
        if((goods + i) -> id == id){
            check = 1;
            count = i;
        }
    }
    if(!check) {
        printf("존재하지 않는 ID입니다\n");
        return;
    } else {
        printf("판매 수량 입력:");
        scanf("%d", &soldCount);
        (goods + count) -> soldCount = soldCount;
    }
}

void goodsData (GOODS *goods) {
    int id;
    int check = 0;
    int count;
    printf("상품 ID:");
    scanf("%d", &id);
    for(int i = 0; i < 5; i++) {
        if((goods + i) -> id == id){
            check = 1;
            count = i;
        }
    }
    if(!check) {
        printf("존재하지 않는 ID입니다\n");
        return;
    } else {
        printf("상품ID: %d\n", (goods + count) -> id);
        printf("상품명: %s\n", (goods + count) -> name);
        printf("가격: %d\n", (goods + count) -> price);
        printf("입고량: %d\n", (goods + count) -> receivedCount);
        printf("판매량: %d\n", (goods + count) -> soldCount);
    }
}
void goodsState (GOODS *goods, int size) {
    int totalReceivedGoods = 0, totalSoldGoods = 0;
    int maxId = 0, minId = 0;
    printf("재고 수량:");
    for(int i = 0; i < size; i++) {
        printf("%d ", (goods + i) -> receivedCount - (goods + i) -> soldCount);
        totalReceivedGoods += (goods + i) -> receivedCount;
        totalSoldGoods += (goods + i) -> soldCount;
        
        if((goods + i) -> soldCount > (goods + maxId) -> soldCount) {
            maxId = i;
        }
        if((goods + i) -> soldCount < (goods + minId) -> soldCount) {
            minId = i;
        }
        
        
    }
    printf("\n");
    printf("총 판매량: %d (판매율: %.2lf%%)\n", totalSoldGoods, (double)totalSoldGoods/totalReceivedGoods * 100);
    printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxId, (goods + maxId) -> soldCount);
    printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minId, (goods + minId) -> soldCount);
    
     for(int i = 0; i < size; i++) {
        if((goods + i) -> receivedCount - (goods + i) -> soldCount <= 2){
            printf("상품 ID %d : 재고 부족(%d)\n", (goods + i) -> id, (goods + i) -> receivedCount - (goods + i) ->soldCount);
        }
    }
}

int main()
{
    GOODS receivedGoods[5];
    int menu;
    while(1) {
        printf("원하는 메뉴를 입력하세요.(1.입고, 2.판매, 3.개별현황, 4.전체현황, 5.종료)");
        scanf("%d", &menu);
        
        if(menu == 5) {
            break;
        }
        
        switch(menu) {
            case 1:
                setReceivedList(receivedGoods);
                break;
            case 2:
                setSoldList(receivedGoods);
                break;
            case 3:
                goodsData(receivedGoods);
                break;
            case 4:
                goodsState(receivedGoods, 5);
                break;
        }
    }
    return 0;
}

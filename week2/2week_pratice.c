#include <stdio.h>

int main() {
  int receiveGoods[100];
  int soldGoods[100];
  int remainGoods[100];
  int category;
  int count;
  int id;
  int receiveCount = 0;
  int soldCount = 0;
  int maxIndex = 0, minIndex = 0;
  scanf("%d", &category);

  for (int i = 0; i < category; i++) {
    scanf("%d", &count);
    receiveGoods[i] = count;
    receiveCount += receiveGoods[i];
  }
  for (int i = 0; i < category; i++) {
    scanf("%d", &count);
    soldGoods[i] = count;
    soldCount += soldGoods[i];
  }

  for (int i = 1; i < category; i++) {
    if (soldGoods[maxIndex] < soldGoods[i]) {
      maxIndex = i;
    }
    if (soldGoods[minIndex] > soldGoods[i]) {
      minIndex = i;
    }
  }
  
  for (int i = 0; i < category; i++) {
    remainGoods[i] = receiveGoods[i] - soldGoods[i];
  }

  printf("재고수량: ");
  for (int i = 0; i < category; i++) {
    printf("%d ", remainGoods[i]);
    if (i == category - 1)
      printf("\n");
  }
  printf("총 판매량: %d (판매율 %.2f%%)\n", soldCount,
         soldCount / (float)receiveCount * 100);
  printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxIndex + 1,
         soldGoods[maxIndex]);
  printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minIndex + 1,
         soldGoods[minIndex]);

  for (int i = 0; i < category; i++) {
    if (remainGoods[i] <= 2) {
      printf("상품 ID %d : 재고부족(%d)\n", i + 1, remainGoods[i]);
    }
  }
}
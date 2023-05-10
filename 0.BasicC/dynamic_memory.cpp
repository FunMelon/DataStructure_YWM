// 动态数组的用法和静态数组基本类似
// 重点记忆其的内存分配和回收方式
#include "macro.h"
#include <stdio.h>
#include <stdlib.h> // malloc函数所需要的库

int main(int argc, char *argv[]) {
  int *a = (int *)malloc(sizeof(int) * MAXSIZE);  // 为动态数组分配内存空间
  int A[MAXSIZE];

  for (int i = 0; i < MAXSIZE; i++) {
    a[i] = A[i] = i * 2;
  }

  for (int i = 0; i < MAXSIZE; i++) {
    printf("%d %d\n", a[i], A[i]);
  }

  free(a);  // 将动态数组的内存回收

  printf("\n回收内存后\n");
  for (int i = 0; i < MAXSIZE; i++) {
    printf("%d %d\n", a[i], A[i]);
  }

  return 0;
}

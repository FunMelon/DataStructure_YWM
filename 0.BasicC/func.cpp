// 这是一个辅助函数集合，使用了更多的C++知识，主要用于验证
#include "macro.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

// 打印静态数组
void PrintArray(ElemType a[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", a[i]);
  printf("\n");
}

// 随机生成一个长度为len, 指定上界和下界的数组
ElemType *RandomArray(int min, int max, int len) {
  ElemType *a = (ElemType *)malloc(sizeof(ElemType) * len);
  srand(time(NULL));
  for (int i = 0; i < len; i++) {
    a[i] = rand() % max + min;
  }
  return a;
}

// 设置当前时间种子
void setSeed() {
  srand(time(NULL));
}

// 生成随机一个数
ElemType Random(int min, int max) {
  return rand() % max + min;
}

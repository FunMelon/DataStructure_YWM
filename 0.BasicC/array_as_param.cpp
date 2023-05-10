// 数组作为参数传递进去，是把对应的指针传递进去了
// 访问数组相当于访问位于栈帧底部静态数组
// 因此内部对数组的修改会导致外部数组的值的变化
#include <stdio.h>
#include "macro.h"
#include "func.cpp"

void func (int a[], int len) {
  for (int i = 0; i < len; i++)
    a[i] = 0;
}

int main (int argc, char *argv[])
{
  int a[MAXSIZE] = {1, 2, 3, 4, 5};
  printf("初始数组为: \n");
  PrintArray(a, MAXSIZE);  // 使用辅助函数
  func(a, MAXSIZE);
  printf("调用函数后：\n");
  PrintArray(a, MAXSIZE);
  return 0;
}

#include <stdio.h>

void Swap(int a, int b) {  // 使用直接参数传递，这是一个错误的函数，不能实现交换
  int c = a;
  a = b;
  b = c;
}

void SwapByPointer(int *a, int *b) { // 使用指针传递参数，在内部访问需要对指针寻址
  int c = *a;
  *a = *b;
  *b = c;
}

void SwapByReference(int &a, int &b) {  // 使用引用传递参数，C++特性
  int c = a;
  a = b;
  b = c;
}

int main(int argc, char *argv[]) {
  int a = 1, b = 2;
  printf("初始下：a = %d, b = %d\n", a, b);
  Swap(a, b);
  printf("尝试直接参数传递交换后：a = %d, b = %d\n", a, b);
  SwapByPointer(&a, &b);
  printf("尝试指针传参的交换后：a = %d, b = %d\n", a, b);
  SwapByReference(a, b);
  printf("尝试引用传参的交换后：a = %d, b = %d\n", a, b);
  return 0;
}

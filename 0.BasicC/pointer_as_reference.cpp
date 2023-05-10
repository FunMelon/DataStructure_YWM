// 这个主要是辨析指针引用的作用，以及什么时候需要使用指针引用
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int data;
} st;

void func1(st *s) { s->data = 10; }

void func2(st *s) {
  st *s1 = (st *)malloc(sizeof(st));
  s1->data = 20;
  s = s1;
}

void func3(st *&s) {
  st *s1 = (st *)malloc(sizeof(st));
  s1->data = 30;
  s = s1;
}

int main(int argc, char *argv[]) {
  st *s = (st *)malloc(sizeof(st));
  s->data = 0;
  printf("经过func1后：\n");
  func1(s);
  printf("%d\n", s->data);
  std::cout << s << std::endl;

  printf("经过func2后：\n");
  func2(s);
  printf("%d\n", s->data);
  std::cout << s << std::endl;

  printf("经过func3后：\n");
  func3(s);
  printf("%d\n", s->data);
  std::cout << s << std::endl;
  return 0;
}

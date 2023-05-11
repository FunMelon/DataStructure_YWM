// 动态分配内存的顺序表
#include "../../0.BasicC/macro.h"
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // 线性表的初始大小
typedef struct {
  ElemType *data; // 指示动态分配数组的指针
  int length;     // 当前个数
} SeqList;

Status InitList(SeqList &L); // 初始化表，构造一个空的线性表L
int Length(SeqList L);  // 获取线性表L的长度
int LocateElem(SeqList L, ElemType e);  // 按值查找，返回e在线性表L第一次出现的位置
Status GetElem(SeqList L, int i, ElemType &e);  // 按位查找，返回线性表L中第i个元素
Status ListInsert(SeqList &L, int i, ElemType e);  // 插入操作，在线性表第i个位置插入e
Status ListDelete(SeqList &L, int i, ElemType &e);  // 删除操作，删除线性表第i个位置的元素，并用e返回删除元素的值
void PrintList(SeqList L);  // 按先后顺序输出线性表所有元素值
Bool Empty(SeqList L);  // 判空操作
Status DestroyList(SeqList &L);  // 销毁线性表，并释放线性表L所占用的内存空间

Status InitList(SeqList &L) {  // 分配内存和指定表长，两项工作
  L.data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
  // L.data = new ElemType[InitSize];  // C++的写法，比C语言的分配更短

  if (!L.data) exit(OVERFLOW);  // 内存分配失败，异常退出
  L.length = 0;
  return OK;
}

int Length(SeqList L) {  // 老实说这个函数应该用不到
  return L.length;
}

int LocateElem(SeqList L, ElemType e) {  // 注意看看是要求返回第几个元素还是元素的下标
  for (int i = 0; i < L.length; i++) 
    if (L.data[i] == e) return i + 1;
  return 0;  // 未找到
}

Status GetElem(SeqList L, int i, ElemType &e) {  // 不直接返回是为了区分异常情况下的返回值
  if (i < 1 || i > L.length) return ERROR;  // 检查是否越界
  e = L.data[i - 1];
  return OK;
}

Status ListInsert(SeqList &L, int i, ElemType e) {
  if (i < 1 || i > L.length + 1) return ERROR;  // 检查是否越界
  if (L.length == MaxSize) return ERROR;  // 检查是否表满
  for (int j = L.length - 1; j >= i - 1; j--)  // 从后往前顺序移动元素
    L.data[j + 1] = L.data[j];  // !!!:记住最后是L.data[i] = L.data[i - 1]，带入看看是否满足循环条件
  L.data[i - 1] = e;
  ++L.length;  // 修改表长
  return OK;
}

Status ListDelete(SeqList &L, int i, ElemType &e) {
  if (i < 1 || i > L.length) return ERROR;  // 注意和插入相区分
  for (int j = i; j <= L.length - 1; j++)
    L.data[j - 1] = L.data[j];  // !!!:记住最后被移动的元素是L.data[L.length - 1]，移动到L.data[L.length - 2] 
  --L.length;
  return OK;
}

void PrintList(SeqList L) {
  for (int i = 0; i < L.length; i++)
    printf("%d ", L.data[i]);
  printf("\n");
}

Bool Empty(SeqList L) {
  return L.length == 0;
}

Status DestroyList(SeqList &L) {
  free(L.data);
  L.length = 0;
  return OK;
}

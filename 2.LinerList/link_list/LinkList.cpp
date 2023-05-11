// 链表，在该实现中为带头节点的链表
#include "../../0.BasicC/macro.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct LNode {
  ElemType data;      // 节点的数据源
  struct LNode *next; // 节点的指针域
} LNode, *LinkList;   // LinkList为指向LNode结构体的指针类型``

Status InitList(LinkList &L); // 初始化表，构造一个空的线性表L
int Length(LinkList L);  // 获取线性表L的长度
LNode *LocateElem(LinkList L, ElemType e);  // 按值查找，返回e在线性表L第一次出现的位置
Status GetElem(LinkList L, int i, ElemType &e);  // 按位查找，返回线性表L中第i个元素
Status ListInsert(LinkList &L, int i, ElemType e);  // 插入操作，在线性表第i个位置插入e
Status ListDelete(LinkList &L, int i, ElemType &e);  // 删除操作，删除线性表第i个位置的元素，并用e返回删除元素的值
void PrintList(LinkList L);  // 按先后顺序输出线性表所有元素值
Bool Empty(LinkList L);  // 判空操作
Status DestroyList(LinkList &L);  // 销毁线性表，并释放线性表L所占用的内存空间

Status InitList(LinkList &L) {
  L = (LinkList)malloc(sizeof(LNode));  // 分配头节点
  L->next = NULL;
  return OK;
}

int Length(LinkList L) {
  int i = 0;
  while(L->next != NULL) {  // 注意带头节点的表永不为空
    L = L->next;
    i++;
  }

  // LNode *p = L;  // 使用一个临时指针代替L进行遍历，但是此处L并不是指针，因此修改L并不会影响外部
  // while(p->next != NULL) {
  //   p = p->next;
  //   i++;
  // }

  // LNode *p = L->next;  // 这里首先取得第一个信息节点，判断条件也要相应的更改
  // while(p != NULL) {
  //   p = p->next;
  //   i++;
  // }

  return i;
}

LNode *LocateElem(LinkList L, ElemType e) {
  LNode *p = L->next;  // 首先取得第一个信息节点
  while(p && p->data != e)  // 第一个为边界条件，第二个为符合条件
    p = p->next;
  return p;
}

Status GetElem(LinkList L, int i, ElemType &e) {  // !!!:注意对边界条件的判断
  LNode *p = L->next;
  int j = 1;
  while(p && j < i) {
    p = p->next;
    j++;
  }
  if (!p || j > i) return ERROR;  // 遍历得到空节点（i超过了表长）或初始的i就不合法（i < 1）
  e = p->data;
  return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e) {
  LNode *p = L;
  int j = 0;
  while(p && j < i - 1) {  // 跳出循环时，如果查找成功的话，j应该停在第i-1个位置
    p = p->next;
    j++;
  }
  if (!p || j > i - 1) return ERROR;  // 通过这个条件不难总结异常检查的一般规律
  LNode *s = (LNode *)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e) {
  LNode *p = L;
  int j = 0;
  while(p->next && j < i - 1) {  // 删除时，对于p的判断更改了
                                 // 因为p这里指是待删除节点的前一个节点
                                 // 所以p->不能为空，否则无法删除
    p = p->next;
    j++;
  }
  if (!p->next || j > i - 1) return ERROR;
  LNode *q = p->next;  // 这里保证p->next不能为空
  p->next = q->next;
  free(q);
  return OK;
}

void PrintList(LinkList L) {
  while(L->next)  // 采用了与严书截然不同的方式：1.没有预声明工作指针；2.使用next进行判断
    printf("%d ", L->next->data);

  // LNode *p = L->next;
  // while(p)
  //   printf("%d ", p->data);

  printf("\n");
}

Bool Empty(LinkList L) {
  return L->next == NULL;
}

Status DestroyList(LinkList &L) {
  LNode *p = L->next;
  L->next = NULL;
  LNode *q;
  while(p) {
    q = p->next;
    free(p);
    p = q;
  }
  return OK;
}

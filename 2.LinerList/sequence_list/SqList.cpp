// 顺序表的静态定义
#include "../../0.BasicC/macro.h"

#define MaxSize 50
typedef struct {
  ElemType data[MaxSize]; // 顺序表的元素
  int length;             // 顺序表的当前长度
} SqList;                 // 顺序表的类型定义

#include "../../0.BasicC/func.cpp"
#include "SeqList.cpp"
#include <cstdio>

int main(int argc, char *argv[]) {
  SeqList L;
  int o;
  Bool ListExist = FALSE; // 表是否存在的变量
  Bool isLoop = TRUE;

  while (isLoop) {
    printf("\n\n0:建表，1:求表长，2：按值查找\n");
    printf("3:按位查找，4：插入，5：删除\n");
    printf("6：输出表，7：判断表是否为空，8:销毁表\n");
    printf("9：随机生成数据，10：退出\n");
    printf("请输入操作：");
    scanf("%d", &o);
    switch (o) {
    case 0:
      if (ListExist)
        printf("错误！该表存在，无法建表\n");
      else if (InitList(L)) {
        printf("建表成功\n");
        ListExist = TRUE;
      } else
        printf("建表失败\n");
      break;
    case 1:
      if (!ListExist)
        printf("错误！还未建表\n");
      else
        printf("表长为：%d\n", Length(L));
      break;
    case 2:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        ElemType e;
        printf("请输入待查找的元素: ");
        scanf("%d", &e);
        int i = LocateElem(L, e);
        if (i == 0)
          printf("未找到该元素！\n");
        else
          printf("该元素是第%d个元素", i);
      }
      break;
    case 3:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        int i;
        printf("请输入待查找的位置: ");
        scanf("%d", &i);
        ElemType e;
        if (GetElem(L, i, e))
          printf("找到元素%d\n", e);
        else
          printf("未找到该元素！\n");
      }
      break;
    case 4:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        int i;
        ElemType e;
        printf("请输入带插入的位置: ");
        scanf("%d", &i);
        printf("请输入带插入的元素: ");
        scanf("%d", &e);
        if (ListInsert(L, i, e))
          printf("插入成功！\n");
        else
          printf("插入失败！\n");
      }
      break;
    case 5:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        int i;
        ElemType e;
        printf("请输入带删除的位置: ");
        scanf("%d", &i);
        if (ListDelete(L, i, e)) {
          printf("删除成功，获取元素%d\n", e);
        } else {
          printf("删除失败\n");
        }
      }
      break;
    case 6:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        for (int i = 0; i < L.length; i++)
          printf("%d ", L.data[i]);
        printf("\n");
      }
      break;
    case 7:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        if (Empty(L))
          printf("表为空\n");
        else
          printf("表不空\n");
      }
      break;
    case 8:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        DestroyList(L);
        printf("已成功销毁线性表\n");
        ListExist = FALSE;
      }
      break;
    case 9:
      if (!ListExist)
        printf("错误！还未建表\n");
      else {
        int i;
        printf("请输入要产生的数目：");
        scanf("%d", &i);
        for (int j = 1; j <= i; j++)
          ListInsert(L, j, Random(0, 10));
        printf("已产生线性表");
      }
      break;
    case 10:
      isLoop = false;
      break;
    default:
      break;
    }
  };
  return 0;
}

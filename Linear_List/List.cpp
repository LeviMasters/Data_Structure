#include <iostream>
using namespace std;

#define MAXSIZE 100   // 线性表最大长度
typedef int ElemType; // 抽象类型
typedef struct {}List; // 构造线性表结构体

bool InitList(List &L);                                  // 构造一个空的线性表L
bool DestroyList(List &L);                               // 删除线性表L
bool ClearList(List &L);                                 // 清空线性表L
bool ListEmpty(List L);                                  // 判断线性表L是否为空表
int ListLength(List &L);                                 // 返回线性表元素个数
bool GetElem(List L, int idx, ElemType &e);              // 用e返回第idx位置的元素
int LocateElem(List L, ElemType e);                      // 返回查找元素e在线性表中的位置
bool PriorElem(List L, ElemType cur_e, ElemType &pre_e); // 返回cur_e在线性表L中的前驱pre_e
bool NextElem(List L, ElemType cur_e, ElemType &next_e); // 返回cur_e在线性表L中的后继next_e
bool ListInsert(List &L, int idx, ElemType e);           // 在i第dx位置前插入新元素e，L的长度加1
int ListDelete(List &L, int idx);                        // 删除L中第idx位置的元素，L的长度减1
bool TraverseList(List L);                               // 对线性表L每个结点进行遍历

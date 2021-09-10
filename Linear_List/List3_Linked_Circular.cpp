#include <iostream>
using namespace std;

// 循环链表

typedef int ElemType; // 抽象类型
typedef struct LNode
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;     // 构造单链表结构体

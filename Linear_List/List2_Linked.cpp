#include <iostream>
using namespace std;

// 单链式线性表

typedef int ElemType; // 抽象类型
typedef struct LNode
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;     // 构造单链表结构体

// 构造一个空的单链表L
bool InitList(LinkList &L)
{
    L = new LNode;  // 创建头结点
    L->next = NULL; // 设置头结点的指针域为空
}

// 删除单链表L
bool DestroyList(LinkList &L);
bool ClearList(LinkList &L); // 清空单链表L
bool ListEmpty(LinkList L);  // 判断单链表L是否为空表
int ListLength(LinkList &L); // 返回单链表元素个数

// 用e返回第idx位置的元素
bool GetElem(LinkList L, int idx, ElemType &e)
{
    LNode *p = L->next;
    int i = 1;
    while (p && i < idx)
    {
        p = p->next; // 沿着链表查找idx位置的e
        i++;
    }
    if (!p || i > idx)
        return false;
    e = p->data;
    return true;
}
// 返回查找元素e在单链表中的结点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

bool PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e); // 返回cur_e在单链表L中的前驱pre_e
bool NextElem(LinkList L, ElemType cur_e, ElemType &next_e); // 返回cur_e在单链表L中的后继next_e

// 在i第dx位置前插入新元素e
bool ListInsert(LinkList &L, int idx, ElemType e)
{
    LNode *p = L;
    int i = 0;
    while (p && i < idx - 1)
    {
        p = p->next;
        i++;
    }
    if (!p || i > idx - 1)
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除L中第idx位置的元素
int ListDelete(LinkList &L, int idx)
{
    LNode *p = L;
    int i = 0;
    while (p->next && (i < idx - 1))
    {
        p = p->next;
        i++;
    }
    if (!p || i > idx - 1)
        return false;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
    return true;
}
bool TraverseList(LinkList L); // 对单链表L每个结点进行遍历

// 头插法创建单链表
bool CreateList_H(LinkList &L, int n)
{
    LNode *p;
    L = new LNode;
    L->next = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        p = new LNode;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

// 尾插法创建单链表
bool CreateList_R(LinkList &L, int n)
{
    LNode *p;
    L = new LNode;
    L->next = NULL;

    LNode *r = L;
    int i;
    for (i = 0; i < n; i++)
    {
        p = new LNode;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

// *有序链表和并*
void MergeList_Sq(LinkList &LA, LinkList &LB, LinkList &LC)
{
    LNode *pa = LA->next;
    LNode *pb = LB->next;

    LC = LA;
    LNode *pc = LC;

    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete LB;
}

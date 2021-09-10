#include <iostream>
using namespace std;

// 双向链表

typedef int ElemType; // 抽象类型
typedef struct DuLnode
{
    ElemType data;         // 数据域
    struct DuLnode *prior; // 前驱指针域
    struct DuLnode *next;  // 后继指针域
} DuLnode, *DuLinkList;    // 构造双向链表

// 用e返回第idx位置的元素
DuLnode *GetElem_DuL(DuLinkList L, int idx)
{
    DuLnode *p = L->next;
    int i = 1;
    while (p && i < idx)
    {
        p = p->next; // 沿着链表查找idx位置的e
        i++;
    }
    if (!p || i > idx)
        return NULL;
    DuLnode *e = new DuLnode;
    e = p;

    return e;
}

// 双向链表插入
bool ListInsert_DuL(DuLinkList &L, int idx, ElemType e)
{
    DuLnode *p;
    if (!(p = GetElem_DuL(L, idx)))
        return false;

    DuLnode* s=new DuLnode;
    s->data=e;
    s->prior=p->prior;
    p->prior->next=s;

    s->next=p;
    p->prior=s;

    delete p;

    return true;
}

// 双向链表删除
bool ListDelete_DuL(DuLinkList &L, int idx)
{
    DuLnode *p;
    if (!(p = GetElem_DuL(L, idx)))
        return false;

    p->prior->next=p->next;
    p->next->prior=p->prior;

    delete p;

    return true;
}
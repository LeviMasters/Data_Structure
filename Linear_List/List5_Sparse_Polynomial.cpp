#include <iostream>
using namespace std;

// 稀疏二项式

typedef struct PNode
{
    float coef;         // 系数
    int expn;           // 指数
    struct PNode *next; // 指针域
} PNode, *Polynomial;   // 构造单链表结构体

void CreatePolyn(Polynomial &P, int n)
{
    P = new PNode;
    P->next = NULL;
    int i;
    PNode *s;
    PNode *pre;
    PNode *q;
    for (i = 1; i <= n; i++)
    {
        s = new PNode;
        cout << "input s coef and expn:" << endl;
        cin >> s->coef >> s->expn;
        pre = P;
        q = P->next;
        while (q && q->expn < s->expn)
        {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

void AddPolyn(Polynomial &Pa, Polynomial &Pb)
{
    PNode *p1 = Pa->next;
    PNode *p2 = Pb->next;
    PNode *p3 = Pa;
    PNode *r;
    float sum;
    while (p1 && p2)
    {
        if (p1->expn == p2->expn)
        {
            sum = p1->coef + p2->coef;
            if (sum != 0)
            {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2;
                p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1;
                p1 = p1->next;
                delete r;
                r = p2;
                p2 = p2->next;
                delete r;
            }
        }
        else if (p1->expn < p2->expn)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1 ? p1 : p2;
    delete Pb;
}
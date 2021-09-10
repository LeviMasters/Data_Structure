#include <iostream>
using namespace std;

// 顺序线性表

#define MAXSIZE 100   // 最大长度
typedef int ElemType; // 抽象类型

typedef struct
{
    ElemType *elem; // 莻空间的基地址
    int length;     // 顺序表长度
} SqList;           // 结构体

// 初始化线性表
bool InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE]; // 分配空间
    if (!L.elem)
        return false; // 存储分配失败退出
    L.length = 0;     // 初始化长度为0
    return true;
}

// 获取第idx位置的元素用e返回
bool GetElem(SqList L, int idx, ElemType &e)
{
    if (idx < 1 || idx > L.length)
        return false;    // idx位置不合理
    e = L.elem[idx - 1]; // 返回idx-1下标的元素
    return true;
}

// 查找e在L中的位置
int LocateElem(SqList L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; i++)
        if (L.elem[i] == e)
            return i + 1; // 查找成功返回序号i+1
    return 0;             // 查找失败 返回0
}

// 在L表第idx位置插入e
bool ListInsert(SqList &L, int idx, ElemType e)
{
    if (idx < 1 || idx > L.length)
        return false; // 插入位置不合法
    if (L.length == MAXSIZE)
        return false; // 存储空间已满
    int i;
    for (i = L.length - 1; i >= idx - 1; i--)
        L.elem[i + 1] = L.elem[i]; // 插入位置及之后的元素往后移
    L.elem[i - 1] = e;             // 将e元素放入第i个位置
    L.length++;                    // 表长加1
    return true;
}

// 删除顺序表L中的第idx位置的元素
bool ListDelete(SqList &L, int idx)
{
    if (idx < 1 || idx > L.length)
        return false; // 删除位置不合法
    int i;
    for (i = idx; i <= L.length - 1; i++)
        L.elem[i - 1] = L.elem[i]; // 将删除位置后的元素往前移
    L.length--;                    // 表长减1
    return true;
}

// 删除线性表L
bool DestroyList(SqList &L)
{
    if (!L.elem)
        return false;
    delete L.elem; // 释放内存
    return true;
}

// 清空线性表L
bool ClearList(SqList &L)
{
    L.length = 0; // 将线性表长度设为0
    return true;
}

// 判断线性表L是否为空表
bool ListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}

// 返回线性表元素个数
int ListLength(SqList &L)
{
    return L.length; // 直接返回长度
}

// 对线性表L每个结点进行遍历
bool TraverseList(SqList L)
{
    if (!L.elem)
        return false; // 空表
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " "; // 遍历打印顺序表
    cout << endl;
    return true;
}

// *无序线性表和并*
void MergeList(SqList &LA, SqList LB)
{
    int m, n;
    m = ListLength(LA);
    n = ListLength(LB);
    int i;
    ElemType e;
    for (i = 1; i <= n; i++)
    {
        GetElem(LB, i, e);
        if (!LocateElem(LA, e))
            ListInsert(LA, ++m, e); // 将LB中的元素插入到LA后面
    }
}

// *有序线性表和并*
void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
{
    LC.length = LA.length + LB.length;
    LC.elem = new ElemType[LC.length];
    ElemType *pc = LC.elem;
    ElemType *pa = LA.elem;
    ElemType *pb = LB.elem;
    ElemType *pa_last = LA.elem + LA.length - 1;
    ElemType *pb_last = LB.elem + LB.length - 1;

    while ((pa <= pa_last) && (pb <= pb_last))
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while (pa <= pa_last)
        *pc++ = *pa++;
    while (pb <= pb_last)
        *pc++ = *pb++;
}

void PrintInfo()
{
    // 打印提示信息
    cout << "0.InitList\t"
         << "1.DestroyList\t"
         << "2.ClearList\t" << endl;
    cout << "3.ListEmpty\t"
         << "4.ListLength\t"
         << "5.GetElem\t" << endl;
    cout << "6.LocateElem\t"
         << "7.ListInsert\t"
         << "8.ListDelete\t" << endl;
    cout << "9.TraverseList\t"
         << "another key out" << endl;
}

// 主函数
int main()
{
    SqList L;
    int idx;
    ElemType e;
    bool result;
    int len;
    while (true)
    {
        int t;
        PrintInfo();

        cout << "switch:";
        cin >> t;

        if (t < 1 || t > 9)
            break;

        cout << "ouput: \t";
        switch (t)
        {
        case 0:
            result = InitList(L);
            cout << result << endl;
            break;
        case 1:
            result = DestroyList(L);
            cout << result << endl;
            break;
        case 2:
            result = ClearList(L);
            cout << result << endl;
            break;
        case 3:
            result = ListEmpty(L);
            cout << result << endl;
            break;
        case 4:
            len = ListLength(L);
            cout << len << endl;
            break;
        case 5:
            cout << "input getelem idx:";
            cin >> idx;
            result = GetElem(L, idx, e);
            cout << e << endl;
            break;
        case 6:
            cout << "input elem e:";
            cin >> e;
            idx = LocateElem(L, e);
            cout << idx << endl;
            break;
        case 7:
            cout << "input getelem idx:";
            cin >> idx;
            cout << "input elem e:";
            cin >> e;
            result = ListInsert(L, idx, e);
            cout << result << endl;
            break;
        case 8:
            cout << "input delete idx:";
            cin >> idx;
            result = ListDelete(L, idx);
            cout << result << endl;
            break;
        case 9:
            result = TraverseList(L);
            cout << result << endl;
            break;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
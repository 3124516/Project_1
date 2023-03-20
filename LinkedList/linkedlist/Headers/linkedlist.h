#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;
typedef enum Status {
    error,
    success
} Status;


Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);
Status InsertList(LNode* p, ElemType data);
Status DeleteList(LNode* p, ElemType e);
void TraverseList(LinkedList L);
Status SearchList(LinkedList L, ElemType e);
Status ReverseList(LinkedList* L);
Status IsLoopList(LinkedList L);
void SwapPairs(LinkedList L);
LNode* FindMidNode(LinkedList L);
void show(void);
int judge_int(void);

Status InitList(LinkedList *L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if(list == NULL)
    {
    	printf("内存分配失败\n");
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList* L) {
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertList(LNode* p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));

    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode* p, ElemType e) {
    LinkedList posNode = p->next;
    LinkedList posNodeFront = p;
    if (posNode == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while (posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if (posNode == NULL)
            {
                printf("没有该数据\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);
        return success;
    }
}

void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) {
    while (L != NULL)
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}

Status ReverseList(LinkedList* L) {
    LNode* newHead;
    LNode* p1;
    LNode* p2;
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    newHead = p1;
    while (p2 != NULL) {
        p1 = p2;
        p2 = p1->next;
        p1->next = newHead;
        newHead = p1;
    }
    (*L)->next = newHead;
    return success;
}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
            return error;
        if (fast == slow)
            return success;
    }
    return error;
}

void SwapPairs(LinkedList L) {
                    LinkedList root=L;
                    LinkedList p1 = root;
                    LinkedList p2 = root->next;
                    while (p2 != NULL && p2->next != NULL) {
                        p1->next = p2->next;
                        p2->next = p1->next->next;
                        p1->next->next = p2;
                        p1 = p2;
                        p2 = p2->next;
                    }
                    return;
                }

void show(void)
{
    printf("\n\n\n\n单链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.插入结点\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.查找数据\n");
    printf("7.反转链表\n");
    printf("8.判断链表是否成环\n");
    printf("9.调转链表中的奇数项和偶数项\n");
    printf("10.查找中间结点\n");
    printf("11.退出\n");
    printf("\n请输入对应的数字(1-11)：");
}

int judge_int(void)
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m]>'9')
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}


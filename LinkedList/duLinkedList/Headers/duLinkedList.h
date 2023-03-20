#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;
typedef enum Status {
	error,
	success,
} Status;


Status InitList_DuL(DuLinkedList *L);
void DestroyList_DuL(DuLinkedList *L);
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q);
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q);
Status DeleteList_DuL(DuLNode *p, ElemType *e);
void TraverseList_DuL(DuLinkedList L);
void show(void);
int judge_int(void);

Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList List;
    List = (DuLinkedList)malloc(sizeof(DuLNode));
    if(List == NULL)
    {
	    printf("内存分配失败\n");
        return error;
    }
    List->next = NULL;
    List->prior = NULL;
    *L = List;
    return success;
}

void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList temp;

    while(*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(p->next == NULL)
    {
        p->next = q;
        q->prior = p;
    }
    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;
        return success;
    }
}

Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    q->prior = p;
    return success;
}

Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p->next == NULL)
    {
        printf("链表为空，无法删除\n");
        return error;
    }
    else
    {
        DuLinkedList posNode = p->next, posNodeFront = p;

        while(posNode->data != *e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            if(posNode == NULL)
            {
                printf("找不到该数据\n");
                return error;
            }
        }
        if(posNode->next != NULL)
        {
            posNodeFront->next = posNode->next;
            posNode->next->prior = posNodeFront;
        }
        else
        {
            posNodeFront->next = NULL;
        }
        free(posNode);
        return success;
    }
}

void TraverseList_DuL(DuLinkedList L) {
    if(L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }
	else if(L->next == NULL)
	{
		printf("当前链表为空\n");
	}
    else
    {
        DuLinkedList temp = L->next;
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void show(void)
{
    printf("\n\n\n\n双链表ADT\n\n");
    printf("1.创建空链表\n");
    printf("2.销毁链表\n");
    printf("3.头插法插入数据\n");
    printf("4.尾插法插入数据\n");
    printf("5.删除数据\n");
    printf("6.遍历链表\n");
    printf("7.退出\n");
    printf("\n请输入对应的数字(1-7)：");
}

int judge_int(void)
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j= 1, k;
    while(j)
    {
        scanf("%s", word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')
            {
                printf("请输入整数：");
                break;
            }
            else
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
}
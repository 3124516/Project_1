#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"duLinkedList.h"

int main(void)
{
    int choice, num = 0;
    DuLinkedList head;
    head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch(choice)
        {
            case 1:
            {
                if(InitList_DuL(&head))
                {
                    printf("空链表创建成功\n");
                }
                else
                {
                    printf("空链表创建失败\n");
                }
                break;
            }
            case 2:
            {
                DestroyList_DuL(&head);
                printf("链表销毁成功\n");
                break;
            }
            case 3:
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertBeforeList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 4:
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    DuLinkedList newNode;
                    if(InitList_DuL(&newNode))
                    {
                        printf("请输入数据：");
                        scanf("%d", &newNode->data);
                        if(InsertAfterList_DuL(head, newNode))
                        {
                            printf("数据插入成功\n");
                        }
                        else
                        {
                            printf("数据插入失败\n");
                        }
                    }
                    else
                    {
                        printf("数据插入失败\n");
                    }
                }
                break;
            }
            case 5:
            {
                if(head == NULL)
                {
                    printf("链表未创建，请先创建链表\n");
                }
                else
                {
                    printf("你想删除哪个数据：");
                    scanf("%d", &num);
                    if(DeleteList_DuL(head, &num))
                    {
                        printf("数据删除成功\n");
                    }
                    else
                    {
                        printf("数据删除失败\n");
                    }
                }
                break;
            }
            case 6:
            {
                TraverseList_DuL(head);
                break;
            }
            case 7:
            {
                DestroyList_DuL(&head);
                break;
            }
            default:
            {
                printf("请重新输入数字!(1-7)\n");
                break;
            }
        }
    } while (choice != 7);

    return 0;
}
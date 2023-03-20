#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"linkedlist.h"

int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1:
        {
            if (InitList(&head))
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
            DestroyList(&head);
            printf("链表销毁完成\n");
            break;
        }
        case 3:
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
                printf("请输入数据：");
                scanf("%d", &num);
                if (InsertList(head, num))
                {
                    printf("数据插入成功\n");
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
            printf("你想删除哪个数据：");
            scanf("%d", &num);
            if (DeleteList(head, num))
            {
                printf("数据删除成功\n");
            }
            else
            {
                printf("数据删除失败\n");
            }
            break;
        }
        case 5:
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表不存在或者只存在一个空的头结点\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        }
        case 6:
        {
            printf("请输入你要查找的数据：");
            scanf("%d", &num);
            if (SearchList(head, num))
            {
                printf("该数存在\n");
            }
            else
            {
                printf("该数不存在\n");
            }
            break;
        }
        case 7:
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }

            }
            break;
        }
        case 8:
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        }
        case 9:
        {
			if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表奇偶调转失败\n");
            }
            else
            {
				SwapPairs(head);
			}
            break;
        }
        case 10:
        {
            if (head == NULL || head->next == NULL)
            {
                printf("这是空链表\n");
            }
            else
            {
                printf("链表中间储存的值为%d\n", (FindMidNode(head))->data);
            }
            break;
        }
        case 11:
        {
            DestroyList(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-11)\n");
            break;
        }
        }
    } while (choice != 11);

    return 0;
}
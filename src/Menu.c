/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

#include "..\inc\Add.h"
#include "..\inc\Cover.h"
#include "..\inc\Delete.h"
#include "..\inc\Search.h"
#include "..\inc\Show.h"
#include "..\inc\Save.h"
#include "..\inc\Update.h"

void Menu(char *FILE_NAME, Telinf tel[], int length)
{
    char choice = {0}; // 选择变量
    int exit = 1;      // 退出变量

    do
    {
        system("cls");
        cover(length - 1); // 输入菜单

        printf("请输入你的选择: ");
        scanf("%c", &choice);

        while (getchar() != '\n') // 清空缓冲区
            continue;
        // 选择菜单
        switch (choice)
        {
        case '1':
            length = add(tel, length); // 添加一行数据
            break;
        case '2':
            length = delete (tel, length); // 删除指定数据
            break;
        case '3':
            update(tel, length); // 修改指定数据
            break;
        case '4':
            search(tel, length); // 查找数据
            break;
        case '5':
            show(tel, length); // 显示所有数据
            break;
        case '0':
            save(FILE_NAME, tel, length); // 退出并保存数据在文件中
            exit = 0;
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
        system("pause");
    } while (exit);
}
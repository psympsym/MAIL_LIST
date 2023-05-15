/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include ".\inc\Tel.h"

#include ".\inc\StructInit.h"
#include ".\inc\Auth.h"
#include ".\inc\ReadIn.h"
#include ".\inc\Menu.h"

int main(int argc, char *argv[])
{
    Telinf tel[MAXROW]; // 定义数组变量
    // 登录成功的用户名
    char username[MAXUN];
    // 以用户名创建的文件名
    char FILE_NAME[MAXUN + 40] = {0};

    int length = 0; // 定义数组实际长度
    while (1)
    {
        Auth(username); // 用户登录

        // 定义文件名，由[用户名+Data]组成
        sprintf(FILE_NAME, "%s%s", username, "_Data.txt");

        length = ReadIn(FILE_NAME, tel, length); // 从文件中读取数据
        if (length == 0)                         // 若读入空数据
        {
            StructInit(tel); // 初始化结构体
            length++;
        }

        Menu(FILE_NAME, tel, length);

    }
    return 0;
}

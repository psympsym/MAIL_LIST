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
    Telinf tel[MAXROW];  // 定义数组变量

    Auth();
    
    int length = 0; // 定义数组实际长度

	length = ReadIn(tel, length); // 从文件中读取数据
    if (length == 0) // 若读入空数据
    {
        StructInit(tel); // 初始化结构体
        length++;
    }
    
    Menu(tel, length);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Bool.h"

/**
 * @brief 删除一条记录
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录结构体数组实际长度
 * @return 处理后通讯录结构体数组实际长度
 */
int delete(Telinf tel[], int length)
{
    system("cls"); // 清空屏幕

    int Del[MAXROW] = {0}; // 记录要删除的记录的下标

    /* ---------------------------------- 查询部分 ---------------------------------- */

    char keyword[MAX_QQ] = {0}; // 关键字
    int count = 0;              // 查找到的数据数量

    printf("请输入你要删除的数据: ");
    s_scanf(keyword, MAX_QQ); // 调用函数获取用户输入的关键字

    // 打印表格的表头
    printf("   \t%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[0].name, tel[0].sex, tel[0].tel_phone, tel[0].mobile, tel[0].QQ, tel[0].age);

    // 遍历通讯录数组，查找包含关键字的记录，并打印对应行
    for (int i = 1; i <= length; i++)
    {
        if (strstr(tel[i].name, keyword) != NULL || // 在姓名字段中查找
            strstr(tel[i].sex, keyword) != NULL || // 在性别字段中查找
            strstr(tel[i].tel_phone, keyword) != NULL || // 在固定电话号码字段中查找
            strstr(tel[i].mobile, keyword) != NULL || // 在移动电话号码字段中查找
            strstr(tel[i].QQ, keyword) != NULL || // 在QQ号码字段中查找
            strstr(tel[i].age, keyword) != NULL) // 在年龄字段中查找
        {
            printf("%-3d\t", count + 1);
            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].QQ, tel[i].age);

            Del[count] = i; // 记录要删除的记录的下标
            count++;
        }
    }

    /* ---------------------------------- 删除部分 ---------------------------------- */

    char inputchar = 0; // 用于接收输入的临时字符
    int num = 0; // 用于接收输入的数字

    if (count == 0)
    {
        system("cls");
        printf("没有找到相关信息\n");
    }
    else
    {
        printf("请输入你要删除的记录的序号: ");

        // 接收用户输入，并处理输入的数字
        while (inputchar = getchar())
        {
            // 当输入是数字时，将其转为数字
            if (isdigit(inputchar))
            {
                num = num * 10 + inputchar - '0'; 
            }
            // 当输入到空格、逗号、或者回车时，处理输入的数字
            else if (num != 0 && (inputchar == ' ' || inputchar == ',' || inputchar == '\n'))
            {
                // 判断输入的数字是否超出范围
                if (num < 1 || num > count)
                {
                    printf("%d超出范围已略过\n", num);
                    num = 0;
                    continue;
                }

                // 删除记录并更新要删除的记录的下标
                for (int i = Del[num - 1]; i < length; i++)
                {
                    memcpy(&tel[i], &tel[i + 1], sizeof(Telinf));
                }

                for (int i = Del[num - 1]; i <= count; i++)
                {
                    if (Del[i] > Del[num - 1])
                    {
                        Del[i]--;
                    }
                }

                // 更新通讯录记录数
                length--;
                printf("第%d条信息删除成功\n", num);
                num = 0;
            }

            // 如果输入到行尾，退出循环
            if (inputchar == '\n')
            {
                break;
            }
        }
    }

    return length;
}

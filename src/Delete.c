/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Bool.h"

/**
 * @brief 删除一条记录
 * @param tel[] 通讯录结构体数组
 * @param length 通讯录结构体数组实际长度
 * @return int 处理后通讯录结构体数组实际长度
*/
int delete(Telinf tel[], int length)
{
    system("cls");

    char mdy_name[MAX_NAME] = { 0 }; // 要删除的姓名
    
    int flag = 0;

    printf("请输入你要删除的姓名\n");
    s_scanf(mdy_name, MAX_NAME);
    for (int i = 0; i <= length; i++)
    {
        if (strstr(tel[i].name, mdy_name) != NULL)
        {
			flag = 1;
            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].tel_office, tel[i].age);
            printf("你真的要删除吗？(Y/N)\n");
            if (bool())
            {
				for (int j = i; j <= length; j++)
				{
					strcpy(tel[j].age, tel[j + 1].age);
					strcpy(tel[j].mobile, tel[j + 1].mobile);
					strcpy(tel[j].name, tel[j + 1].name);
					strcpy(tel[j].sex, tel[j + 1].sex);
					strcpy(tel[j].tel_office, tel[j + 1].tel_office);
					strcpy(tel[j].tel_phone, tel[j + 1].tel_phone);
				}
				printf("删除成功, 按下任意键返回菜单\n");
				length--;
				break;
            }
            else
            {
                ;
            }
        }
    }

    if (flag == 0)
    {
        printf("没有找到该联系人\n");
    }

    return length;
}
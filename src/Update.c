/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Add.h"
#include "..\inc\Bool.h"

/**
 * @brief �޸�һ����¼
 * @param tel[] ͨѶ¼�ṹ������
 * @param length ͨѶ¼�ṹ������ʵ�ʳ���
 * @return void
 */
void update(Telinf tel[], int length)
{
    system("cls");

    char name[MAX_NAME] = {0};

    printf("��������Ҫ�޸ĵ�����\n");
    s_scanf(name, MAX_NAME);
    int flag = 0;

    for (int i = 0; i <= length; i++)
    {
        if (strstr(tel[i].name, name) != NULL)
        {
            flag = 1;

            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].tel_office, tel[i].age); // ��ʾ��Ϣ

            printf("������Ҫ�޸ĵ�������");
            s_scanf(tel[i].name, MAX_NAME);
            printf("������Ҫ�޸ĵ��Ա�");
            s_scanf(tel[i].sex, MAX_SEX);
            printf("������Ҫ�޸ĵļ�ͥ�绰��");
            s_scanf(tel[i].tel_phone, MAX_TEL_PHONE);
            printf("������Ҫ�޸ĵ��ƶ��绰��");
            s_scanf(tel[i].mobile, MAX_MOBILE);
            printf("������Ҫ�޸ĵİ칫�绰��");
            s_scanf(tel[i].tel_office, MAX_TEL_OFFICE);
            printf("������Ҫ�޸ĵ����䣺");
            s_scanf(tel[i].age, MAX_AGE);

            break;
        }
    }
    
    if (flag == 0)
    {
        printf("û���ҵ�����ϵ��\n");
        printf("�Ƿ���Ӹ���ϵ��(Y/N)��\n");
        if (bool())
        {
            add(tel, length);
        }
        else
        {
            ;
        }
    }
    else
    {
        printf("��ӳɹ�, ������������ز˵�\n");
    }
}

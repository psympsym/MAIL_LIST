/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"

/**
 * @brief ���һ����¼
 * @param tel[] ͨѶ¼�ṹ������
 * @param length ͨѶ¼�ṹ������ʵ�ʳ���
 * @return int �����ͨѶ¼�ṹ������ʵ�ʳ���
 */
int add(Telinf tel[], int length)
{
    system("cls");
    
    if (length >= MAXROW)
    {
        printf("ͨѶ¼�������޷�����µļ�¼\n");
    }
    else
    {
        printf("������������");
        s_scanf(tel[length].name, MAX_NAME);
        printf("�������Ա�");
        s_scanf(tel[length].sex, MAX_SEX);
        printf("�������ͥ�绰��");
        s_scanf(tel[length].tel_phone, MAX_TEL_PHONE);
        printf("�������ƶ��绰��");
        s_scanf(tel[length].mobile, MAX_MOBILE);
        printf("������칫�绰��");
        s_scanf(tel[length].tel_office, MAX_TEL_OFFICE);
        printf("���������䣺");
        s_scanf(tel[length].age, MAX_AGE);

        length++;
        printf("��ӳɹ�, ������������ز˵�\n");
    }

    return length;
}

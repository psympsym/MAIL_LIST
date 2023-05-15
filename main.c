/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include ".\inc\Tel.h"

#include ".\inc\StructInit.h"
#include ".\inc\ReadIn.h"
#include ".\inc\Add.h"
#include ".\inc\Delete.h"
#include ".\inc\Update.h"
#include ".\inc\Search.h"
#include ".\inc\Show.h"
#include ".\inc\Cover.h"
#include ".\inc\Save.h"

int main(int argc, char *argv[])
{
    Telinf tel[MAXROW];  // �����������

    int length = 0; // ��������ʵ�ʳ���
    char choice = { 0 }; // ѡ�����

	length = ReadIn(tel, length); // ���ļ��ж�ȡ����
    if (length == 0) // �����������
    {
        StructInit(tel); // ��ʼ���ṹ��
        length++;
    }

    do
    {
        system("cls");
        cover(length - 1); // ����˵�

        printf("���������ѡ��: ");
        scanf("%c", &choice);

        while (getchar() != '\n') // ��ջ�����
            continue;
        
        switch (choice)
        {
        case '1':
            length = add(tel, length); // ���һ������
            break;
        case '2':
            length = delete(tel, length); // ɾ��ָ������
            break;
        case '3':
            update(tel, length); // �޸�ָ������
            break;
        case '4':
            search(tel, length); // ��������
            break;
        case '5':
            show(tel, length); // ��ʾ��������
            break;
        case '0':
            save(tel, length); // �˳��������������ļ���
            break;
        default:
            printf("�����������������\n");
            break;
        }
        system("pause");
    } while (1);

    return 0;
}

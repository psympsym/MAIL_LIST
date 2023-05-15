/* ����ͷ�ļ� */
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
    char choice = {0}; // ѡ�����
    int exit = 1;      // �˳�����

    do
    {
        system("cls");
        cover(length - 1); // ����˵�

        printf("���������ѡ��: ");
        scanf("%c", &choice);

        while (getchar() != '\n') // ��ջ�����
            continue;
        // ѡ��˵�
        switch (choice)
        {
        case '1':
            length = add(tel, length); // ���һ������
            break;
        case '2':
            length = delete (tel, length); // ɾ��ָ������
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
            save(FILE_NAME, tel, length); // �˳��������������ļ���
            exit = 0;
            break;
        default:
            printf("�����������������\n");
            break;
        }
        system("pause");
    } while (exit);
}
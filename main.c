/* ����ͷ�ļ� */
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
    Telinf tel[MAXROW]; // �����������
    // ��¼�ɹ����û���
    char username[MAXUN];
    // ���û����������ļ���
    char FILE_NAME[MAXUN + 40] = {0};

    int length = 0; // ��������ʵ�ʳ���
    while (1)
    {
        Auth(username); // �û���¼

        // �����ļ�������[�û���+Data]���
        sprintf(FILE_NAME, "%s%s", username, "_Data.txt");

        length = ReadIn(FILE_NAME, tel, length); // ���ļ��ж�ȡ����
        if (length == 0)                         // �����������
        {
            StructInit(tel); // ��ʼ���ṹ��
            length++;
        }

        Menu(FILE_NAME, tel, length);

    }
    return 0;
}

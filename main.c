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
    Telinf tel[MAXROW];  // �����������

    Auth();
    
    int length = 0; // ��������ʵ�ʳ���

	length = ReadIn(tel, length); // ���ļ��ж�ȡ����
    if (length == 0) // �����������
    {
        StructInit(tel); // ��ʼ���ṹ��
        length++;
    }
    
    Menu(tel, length);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "..\inc\Tel.h"
#include "..\inc\Input.h"
#include "..\inc\Bool.h"

/**
 * @brief ɾ��һ����¼
 * @param tel[] ͨѶ¼�ṹ������
 * @param length ͨѶ¼�ṹ������ʵ�ʳ���
 * @return �����ͨѶ¼�ṹ������ʵ�ʳ���
 */
int delete(Telinf tel[], int length)
{
    system("cls"); // �����Ļ

    int Del[MAXROW] = {0}; // ��¼Ҫɾ���ļ�¼���±�

    /* ---------------------------------- ��ѯ���� ---------------------------------- */

    char keyword[MAX_QQ] = {0}; // �ؼ���
    int count = 0;              // ���ҵ�����������

    printf("��������Ҫɾ��������: ");
    s_scanf(keyword, MAX_QQ); // ���ú�����ȡ�û�����Ĺؼ���

    // ��ӡ���ı�ͷ
    printf("   \t%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[0].name, tel[0].sex, tel[0].tel_phone, tel[0].mobile, tel[0].QQ, tel[0].age);

    // ����ͨѶ¼���飬���Ұ����ؼ��ֵļ�¼������ӡ��Ӧ��
    for (int i = 1; i <= length; i++)
    {
        if (strstr(tel[i].name, keyword) != NULL || // �������ֶ��в���
            strstr(tel[i].sex, keyword) != NULL || // ���Ա��ֶ��в���
            strstr(tel[i].tel_phone, keyword) != NULL || // �ڹ̶��绰�����ֶ��в���
            strstr(tel[i].mobile, keyword) != NULL || // ���ƶ��绰�����ֶ��в���
            strstr(tel[i].QQ, keyword) != NULL || // ��QQ�����ֶ��в���
            strstr(tel[i].age, keyword) != NULL) // �������ֶ��в���
        {
            printf("%-3d\t", count + 1);
            printf("%-10s %-4s %-16s %-16s %-16s %-4s\n", tel[i].name, tel[i].sex, tel[i].tel_phone, tel[i].mobile, tel[i].QQ, tel[i].age);

            Del[count] = i; // ��¼Ҫɾ���ļ�¼���±�
            count++;
        }
    }

    /* ---------------------------------- ɾ������ ---------------------------------- */

    char inputchar = 0; // ���ڽ����������ʱ�ַ�
    int num = 0; // ���ڽ������������

    if (count == 0)
    {
        system("cls");
        printf("û���ҵ������Ϣ\n");
    }
    else
    {
        printf("��������Ҫɾ���ļ�¼�����: ");

        // �����û����룬���������������
        while (inputchar = getchar())
        {
            // ������������ʱ������תΪ����
            if (isdigit(inputchar))
            {
                num = num * 10 + inputchar - '0'; 
            }
            // �����뵽�ո񡢶��š����߻س�ʱ���������������
            else if (num != 0 && (inputchar == ' ' || inputchar == ',' || inputchar == '\n'))
            {
                // �ж�����������Ƿ񳬳���Χ
                if (num < 1 || num > count)
                {
                    printf("%d������Χ���Թ�\n", num);
                    num = 0;
                    continue;
                }

                // ɾ����¼������Ҫɾ���ļ�¼���±�
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

                // ����ͨѶ¼��¼��
                length--;
                printf("��%d����Ϣɾ���ɹ�\n", num);
                num = 0;
            }

            // ������뵽��β���˳�ѭ��
            if (inputchar == '\n')
            {
                break;
            }
        }
    }

    return length;
}

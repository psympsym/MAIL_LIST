/* ����ͷ�ļ� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "..\inc\Tel.h"

/**
 * @brief ��ʼ���ṹ��
 * @param tel[] ͨѶ¼�ṹ������
 * @return none
 * @note ���ṹ���һ���ʼ��Ϊ��ǩ
*/
void StructInit(Telinf tel[]) // ��ʼ���ṹ��
{
    strcpy(tel[0].name, "����");
    strcpy(tel[0].sex, "�Ա�");
    strcpy(tel[0].tel_phone, "��ͥ�绰");
    strcpy(tel[0].mobile, "�ƶ��绰");
    strcpy(tel[0].tel_office, "�����绰");
    strcpy(tel[0].age, "����");
}
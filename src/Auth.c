/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#include "..\inc\Tel.h"

#include "..\inc\Input.h" // �ṩ s_scanf() ����

/* ---------------------------------- �������� ---------------------------------- */
int login(char *username, char *password);
int register_account(char *username, char *password);
char *inPass(char *str, int length);

/**
 * @brief �û���¼����
 * @param username �û���
 * @return none
*/
void Auth(char *username)
{
    // ����ѡ��
    char option = 0;
    // �ж������Ƿ����
    int inerror = 0;

    // ������������
    char password[MAXPSW];

    do
    {
        system("cls");
        printf("********************************************\n");
        printf("**********  ��ӭ����ͨѶ¼����ϵͳ  **********\n");
        printf("**********    ��ѡ��Ҫ���еĲ���:   **********\n");
        printf("**********      1.��¼�����˺�     **********\n");
        printf("**********       2.ע�����˺�      **********\n");
        printf("**********         0.�˳�          **********\n");
        printf("********************************************\n");
        if (inerror)
        {
            printf("��������ȷ��ѡ��!\n");
            inerror = 0;
        }
        scanf("%c", &option);

        while (getchar() != '\n')
            continue;

        switch (option)
        {
        case '1':
            if (login(username, password) == 1)
                option = '0';
            break;
        case '2':
            if (register_account(username, password) == 1)
                option = '0';
            break;
        case '0':
            exit(0);
            break;
        default:
            inerror = 1;
            continue;
        }

    } while (option != '0');
}

/**
 * @brief �û���¼����
 * @param username �û���
 * @param password ����
 * @return ��¼�Ƿ�ɹ�
*/
int login(char *username, char *password)
{
    FILE *file;
    User user;

    // ���˻���Ϣ�ļ�
    file = fopen(USER_FILE, "rb"); // �Զ����Ƹ�ʽ���ļ�
    if (!file)                     // ����ļ������ڣ��򴴽�һ���µ� User.dat �ļ�
    {
        file = fopen(USER_FILE, "wb+");
        fclose(file);
        file = fopen(USER_FILE, "rb");

        if (!file)
        {
            printf("�޷������˻���Ϣ�ļ�\n");
            system("pause");
            exit(0);
        }
    }

    // ��ȡ�û���������
    printf("�������˻����ƣ�");
    s_scanf(username, MAXUN);

    // ����û���ȡ�ļ����ȶ��û���������
    while (fread(&user, sizeof(User), 1, file) == 1)
    {
        if (!strcmp(username, user.username)) // �û���ƥ��
        {
            printf("���������룺");
            inPass(password, MAXPSW);
            printf("\n");

            if (!strcmp(password, user.password)) // ����ƥ��
            {
                fclose(file);
                system("cls");
                printf("��¼�ɹ�\n");
                return 1;
            }
            else // ���벻ƥ��
            {
                fclose(file);
                printf("������˻����������, ����������\n");
                system("pause");
                return 0;
            }
        }
    }
    // û���ҵ�ƥ����û���
    fclose(file);
    printf("δ�ҵ����˻�������ע����˻�\n");
    system("pause");
    return -1;
}

/**
 * @brief �û�ע�ắ��
 * @param username �û���
 * @param password ����
 * @return ����ע���Ƿ�ɹ�
*/
int register_account(char *username, char *password)
{
    char repassword[MAXPSW];

    FILE *file;
    User user;

    // ���˻���Ϣ�ļ�
    file = fopen(USER_FILE, "rb"); // �Զ����Ƹ�ʽ���ļ�
    if (!file)                     // ����ļ������ڣ��򴴽�һ���µ� User.dat �ļ�
    {
        file = fopen(USER_FILE, "wb+");
        fclose(file);
        file = fopen(USER_FILE, "rb");
        if (!file)
        {
            printf("�޷������˻���Ϣ�ļ�\n");
            system("pause");
            return -1;
        }
    }
    else
    {
        fclose(file);
        file = fopen(USER_FILE, "ab+"); // �Զ����Ƹ�ʽ׷�ӷ�ʽ���ļ�
    }

    // ��ȡ�û����������Ƿ��Ѵ��ڸ��˺���
    while (1)
    {
        printf("������Ҫע����˺�����: ");
        s_scanf(username, MAXUN);

        rewind(file);
        int found = 0;
        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            if (!strcmp(username, user.username))
            {
                found = 1;
                printf("�˺� %s �Ѿ�����!\n", username);
                break;
            }
        }

        if (!found)
            break;
    }

    // ��ȡ���룬ȷ���������������һ��
    while (1)
    {
        printf("������Ҫע���˺ŵ�����(8-16λ):");
        inPass(password, MAXPSW);
        printf("\n");
        if (strlen(password) < 8 || strlen(password) > 16)
        {
            printf("���볤�Ȳ�����Ҫ��, ����������!\n");
            continue;
        }
        printf("��ȷ���������: ");
        inPass(repassword, MAXPSW);
        printf("\n");
        if (strcmp(password, repassword))
        {
            printf("������������벻һ��, ����������!\n");
        }
        else
        {
            break;
        }
    }

    // д���û���������
    strcpy(user.username, username);
    strcpy(user.password, password);
    fwrite(&user, sizeof(User), 1, file);

    // �ر��ļ�����ʾע��ɹ�
    fclose(file);
    system("cls");
    printf("�˺�ע��ɹ�!\n");
    return 1;
}

/**
 * @brief ���������Զ��滻Ϊ*
 * @param str ������ַ���
 * @param length �ַ�������
 * @return ����������ַ���
 */
char *inPass(char *str, int length)
{
    char temp;
    int count = 0;

    while ((temp = getch()) != 13 && count < length - 1)
    {
        // ����û��˸���ɾ��һ���ַ�
        if (temp == 8)
        {
            if (count > 0)
            {
                count--;
                printf("\b \b");
            }
            continue;
        }

        str[count++] = temp;
        putchar('*');
    }
    str[count] = '\0';
    return str;
}

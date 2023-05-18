/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <ctype.h> // ���� ctype.h ��ʹ�� isalpha �� isdigit ����
#include <conio.h> // ���� conio.h ��ʹ�� getch ����

#include "..\inc\Tel.h"

#include "..\inc\Input.h" // �ṩ s_scanf() ����

/* ---------------------------------- �������� ---------------------------------- */

int login(char *username, int *key);
int register_account(char *username, int *key);
char *inPass(char *str, int length);
int check_password_strength(const char *password);
char *encryption(char *str, int *key);
char *decrypt(char *str, int *key);

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
    // ��Կ
    int key[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5};

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
        // ��������������ʾ��������
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
            if (login(username, key) == 1)
                option = '0';
            break;
        case '2':
            if (register_account(username, key) == 1)
                option = '0';
            break;
        case '0':
            system("cls");
            printf("===============================================\n");
            printf("=========     ��л����ʹ�ú�֧�֣�    =========\n");
            printf("=========   ���Ĺ��������Ǹ���׿Խ    =========\n");
            printf("========= �ڴ��ٴ�����������ף�����! =========\n");
            printf("===============================================\n");
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
int login(char *username, int *key)
{
    FILE *file;
    User user;

    // ������������
    char password[MAXPSW];

    // ���˻���Ϣ�ļ�
    file = fopen(USER_FILE, "rb"); // �Զ����Ƹ�ʽ���ļ�

    // ����ļ������ڣ��򴴽�һ���µ� User.dat �ļ�
    if (!file)
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
        // if (!strcmp(username, user.username)) // �û���ƥ��
        if (!strcmp(username, decrypt(user.username, key)))
        {
            printf("���������룺");
            inPass(password, MAXPSW);
            printf("\n");

            // if (!strcmp(password, user.password)) //
            if (!strcmp(password, decrypt(user.password, key)))
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
int register_account(char *username, int *key)
{
    // ������������
    char password[MAXPSW];
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

        // �����ļ���ͷ
        rewind(file);

        // �ж��Ƿ��Ѵ��ڸ��˺�
        int found = 0;

        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            // if (!strcmp(username, user.username))
            if (!strcmp(username, decrypt(user.username, key)))
            {
                found = 1;
                printf("�˺� %s �Ѿ�����!\n", username);
                system("pause");
                return 0;
            }
        }

        if (!found)
        {
            break;
        }
    }

    // ����ע��ʧ�ܴ���
    int failedAttempts = 0;

    // ��ȡ���룬ȷ���������������һ���ҷ���Ҫ��
    while (1)
    {
        printf("������Ҫע���˺ŵ�����(8-16λ, ���ٰ�����ĸ������):");
        inPass(password, MAXPSW);
        printf("\n");

        if (strlen(password) < 8 || strlen(password) > 16 || !check_password_strength(password))
        {
            printf("���볤�Ȳ�����Ҫ���ǿ�Ȳ���, ����������!\n");
            failedAttempts++;
            if (failedAttempts > 2)
            {
                printf("������������������, ������ע��!\n");
                system("pause");
                return 0;
            }
            continue;
        }

        printf("��ȷ���������: ");
        inPass(repassword, MAXPSW);
        printf("\n");

        if (strcmp(password, repassword))
        {
            printf("������������벻һ��, ����������!\n");
            failedAttempts++;
            if (failedAttempts > 2)
            {
                printf("������������������, ������ע��!\n");
                system("pause");
                return 0;
            }
        }
        else
        {
            break;
        }
    }

    // д���û���������
    strcpy(user.username, encryption(username, key));
    strcpy(user.password, encryption(password, key));
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

/**
 * @brief ��������Ƿ��������һ����ĸ��һ������
 * @param password ����
 * @return �������Ҫ�󷵻� 1�����򷵻� 0
 */
int check_password_strength(const char *password)
{
    int has_alpha = 0, has_digit = 0;

    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isalpha(password[i])) // ������ĸ
            has_alpha = 1;
        if (isdigit(password[i])) // ��������
            has_digit = 1;
        if (has_alpha && has_digit)
            return 1;
    }
    return 0;
}

/**
 * @brief ���ܺ���
 * @param str Ҫ���ܵ��ַ���
 * @param key ��Կ
 * @return ���ؼ��ܺ���ַ���
 */
char *encryption(char *str, int *key)
{
    char *ciphertext;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        ciphertext[i] = str[i] + key[i % sizeof(key)];
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

/**
 * @brief ���ܺ���
 * @param str Ҫ���ܵ��ַ���
 * @param key ��Կ
 * @return ���ؽ��ܺ���ַ���
 */
char *decrypt(char *str, int *key)
{
    char *plaintext;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        plaintext[i] = str[i] - key[i % sizeof(key)];
    }
    plaintext[i] = '\0';
    return plaintext;
}

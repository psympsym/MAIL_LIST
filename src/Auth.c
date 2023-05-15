/* ---------------------------------- ����ͷ�ļ� --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

#include "..\inc\Input.h" // �ṩ s_scanf() ����

/* ---------------------------------- �������� ---------------------------------- */
int login();
int register_account();

void Auth()
{
    char option;
	int inerror = 0;
    do 
    {
	    system("cls");
        printf("********************************************\n");
        printf("************��ӭ����ͨѶ¼����ϵͳ************\n");
        printf("************  ��ѡ��Ҫ���еĲ���: ************\n");
        printf("************    1.��¼�����˺�   ************\n");
        printf("************     2.ע�����˺�    ************\n");
        printf("************       0.�˳�        ************\n");
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
				if (login() == 1)
					option = '0';
                break;
            case '2':
                if (register_account() == 1)
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

// ��¼����
int login() 
{
    char username[MAXUN], password[MAXPSW];
    FILE *file;
    User user;

    // ���˻���Ϣ�ļ�
    file = fopen(USER_FILE, "r");
    if (!file) // ����ļ������ڣ��򴴽�һ���µ� User.txt �ļ�
    {  
        file = fopen(USER_FILE, "w+");
        fclose(file);
        file = fopen(USER_FILE, "r");

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
    
    // ���ж�ȡ�˻���Ϣ���ȶ��û���������
    while (fscanf(file, "%s\t%s\n", user.username, user.password) != EOF) 
    {
        if (!strcmp(username, user.username)) // �û���ƥ��
        { 
            printf("���������룺");
            s_scanf(password, MAXPSW);
            
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

// ע�ắ��
int register_account() 
{
    char username[MAXUN], password[MAXPSW], repassword[MAXPSW];

    FILE *file;
    User user;

       // ���˻���Ϣ�ļ�
    file = fopen(USER_FILE, "r");
    if (!file) // ����ļ������ڣ��򴴽�һ���µ� User.txt �ļ�
    {  
        file = fopen(USER_FILE, "w+");
        fclose(file);
        file = fopen(USER_FILE, "r");
		fclose(file);
        if (!file) 
        {
            printf("�޷������˻���Ϣ�ļ�\n");
            system("pause");
            return -1;
        }
        else
        {
        	file = fopen(USER_FILE, "a+");
		}
    }
	else
	{
		fclose(file);
		file = fopen(USER_FILE, "a+");
	}
	
    // ��ȡ�û����������Ƿ��Ѵ��ڸ��˺���
    while (1) 
    {
        printf("������Ҫע����˺�����: ");
        s_scanf(username, MAXUN);
        
        rewind(file);
        while (fscanf(file, "%s\t%s\n", user.username, user.password) != EOF)
        {
            if (!strcmp(username, user.username))
            {
                printf("�˺� %s �Ѿ�����!\n", username);
                break;
            }
        }
        
        if (feof(file))
            break;
    }

    // ��ȡ���룬ȷ���������������һ��
    while (1) 
    {
        printf("������Ҫע���˺ŵ�����(8-16λ):");
        s_scanf(password, MAXPSW);
        if (strlen(password) < 8 || strlen(password) > 16) 
        {
            printf("���볤�Ȳ�����Ҫ��, ����������!\n");
            continue;
        }
        printf("������ȷ���������: ");
        s_scanf(repassword, MAXPSW);
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
    fprintf(file, "%s\t%s\n", username, password);

    // �ر��ļ�����ʾע��ɹ�
    fclose(file);
    system("cls");
    printf("�˺�ע��ɹ�!\n");
    return 1;
}

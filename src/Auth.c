/* ---------------------------------- 包含头文件 --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#include "..\inc\Tel.h"

#include "..\inc\Input.h" // 提供 s_scanf() 函数

/* ---------------------------------- 函数声明 ---------------------------------- */
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
        printf("************欢迎来到通讯录管理系统************\n");
        printf("************  请选择要进行的操作: ************\n");
        printf("************    1.登录已有账号   ************\n");
        printf("************     2.注册新账号    ************\n");
        printf("************       0.退出        ************\n");
        printf("********************************************\n");
		if (inerror)
		{
			printf("请输入正确的选项!\n");
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

// 登录函数
int login() 
{
    char username[MAXUN], password[MAXPSW];
    FILE *file;
    User user;

    // 打开账户信息文件
    file = fopen(USER_FILE, "r");
    if (!file) // 如果文件不存在，则创建一个新的 User.txt 文件
    {  
        file = fopen(USER_FILE, "w+");
        fclose(file);
        file = fopen(USER_FILE, "r");

        if (!file) 
        {
            printf("无法创建账户信息文件\n");
            system("pause");
            exit(0);
        }
    }

    // 获取用户名和密码
    printf("请输入账户名称：");
    s_scanf(username, MAXUN);
    
    // 逐行读取账户信息并比对用户名和密码
    while (fscanf(file, "%s\t%s\n", user.username, user.password) != EOF) 
    {
        if (!strcmp(username, user.username)) // 用户名匹配
        { 
            printf("请输入密码：");
            s_scanf(password, MAXPSW);
            
            if (!strcmp(password, user.password)) // 密码匹配
            {
                fclose(file);
                system("cls");
                printf("登录成功\n");
                return 1;
            }
            else // 密码不匹配
            {
                fclose(file);
                printf("输入的账户或密码错误, 请重新输入\n");
                system("pause");
                return 0;
            }
        }
    }
    // 没有找到匹配的用户名
    fclose(file);
    printf("未找到该账户，请先注册该账户\n");
    system("pause"); 
    return -1;
}

// 注册函数
int register_account() 
{
    char username[MAXUN], password[MAXPSW], repassword[MAXPSW];

    FILE *file;
    User user;

       // 打开账户信息文件
    file = fopen(USER_FILE, "r");
    if (!file) // 如果文件不存在，则创建一个新的 User.txt 文件
    {  
        file = fopen(USER_FILE, "w+");
        fclose(file);
        file = fopen(USER_FILE, "r");
		fclose(file);
        if (!file) 
        {
            printf("无法创建账户信息文件\n");
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
	
    // 获取用户名，查找是否已存在该账号名
    while (1) 
    {
        printf("请输入要注册的账号名称: ");
        s_scanf(username, MAXUN);
        
        rewind(file);
        while (fscanf(file, "%s\t%s\n", user.username, user.password) != EOF)
        {
            if (!strcmp(username, user.username))
            {
                printf("账号 %s 已经存在!\n", username);
                break;
            }
        }
        
        if (feof(file))
            break;
    }

    // 获取密码，确保两次输入的密码一致
    while (1) 
    {
        printf("请输入要注册账号的密码(8-16位):");
        s_scanf(password, MAXPSW);
        if (strlen(password) < 8 || strlen(password) > 16) 
        {
            printf("密码长度不符合要求, 请重新输入!\n");
            continue;
        }
        printf("请密码确认你的密码: ");
        s_scanf(repassword, MAXPSW);
        if (strcmp(password, repassword)) 
        {
            printf("两次输入的密码不一致, 请重新输入!\n");
        } 
        else 
        {
            break;
        }
    }

    // 写入用户名和密码
    fprintf(file, "%s\t%s\n", username, password);

    // 关闭文件并提示注册成功
    fclose(file);
    system("cls");
    printf("账号注册成功!\n");
    return 1;
}

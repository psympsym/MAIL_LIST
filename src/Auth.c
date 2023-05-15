/* ---------------------------------- 包含头文件 --------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

#include "..\inc\Tel.h"

#include "..\inc\Input.h" // 提供 s_scanf() 函数

/* ---------------------------------- 函数声明 ---------------------------------- */
int login(char *username, char *password);
int register_account(char *username, char *password);
char *inPass(char *str, int length);

/**
 * @brief 用户登录函数
 * @param username 用户名
 * @return none
*/
void Auth(char *username)
{
    // 输入选择
    char option = 0;
    // 判断输入是否错误
    int inerror = 0;

    // 保存读入的密码
    char password[MAXPSW];

    do
    {
        system("cls");
        printf("********************************************\n");
        printf("**********  欢迎来到通讯录管理系统  **********\n");
        printf("**********    请选择要进行的操作:   **********\n");
        printf("**********      1.登录已有账号     **********\n");
        printf("**********       2.注册新账号      **********\n");
        printf("**********         0.退出          **********\n");
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
 * @brief 用户登录函数
 * @param username 用户名
 * @param password 密码
 * @return 登录是否成功
*/
int login(char *username, char *password)
{
    FILE *file;
    User user;

    // 打开账户信息文件
    file = fopen(USER_FILE, "rb"); // 以二进制格式打开文件
    if (!file)                     // 如果文件不存在，则创建一个新的 User.dat 文件
    {
        file = fopen(USER_FILE, "wb+");
        fclose(file);
        file = fopen(USER_FILE, "rb");

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

    // 逐个用户读取文件并比对用户名和密码
    while (fread(&user, sizeof(User), 1, file) == 1)
    {
        if (!strcmp(username, user.username)) // 用户名匹配
        {
            printf("请输入密码：");
            inPass(password, MAXPSW);
            printf("\n");

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

/**
 * @brief 用户注册函数
 * @param username 用户名
 * @param password 密码
 * @return 返回注册是否成功
*/
int register_account(char *username, char *password)
{
    char repassword[MAXPSW];

    FILE *file;
    User user;

    // 打开账户信息文件
    file = fopen(USER_FILE, "rb"); // 以二进制格式打开文件
    if (!file)                     // 如果文件不存在，则创建一个新的 User.dat 文件
    {
        file = fopen(USER_FILE, "wb+");
        fclose(file);
        file = fopen(USER_FILE, "rb");
        if (!file)
        {
            printf("无法创建账户信息文件\n");
            system("pause");
            return -1;
        }
    }
    else
    {
        fclose(file);
        file = fopen(USER_FILE, "ab+"); // 以二进制格式追加方式打开文件
    }

    // 获取用户名，查找是否已存在该账号名
    while (1)
    {
        printf("请输入要注册的账号名称: ");
        s_scanf(username, MAXUN);

        rewind(file);
        int found = 0;
        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            if (!strcmp(username, user.username))
            {
                found = 1;
                printf("账号 %s 已经存在!\n", username);
                break;
            }
        }

        if (!found)
            break;
    }

    // 获取密码，确保两次输入的密码一致
    while (1)
    {
        printf("请输入要注册账号的密码(8-16位):");
        inPass(password, MAXPSW);
        printf("\n");
        if (strlen(password) < 8 || strlen(password) > 16)
        {
            printf("密码长度不符合要求, 请重新输入!\n");
            continue;
        }
        printf("请确认你的密码: ");
        inPass(repassword, MAXPSW);
        printf("\n");
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
    strcpy(user.username, username);
    strcpy(user.password, password);
    fwrite(&user, sizeof(User), 1, file);

    // 关闭文件并提示注册成功
    fclose(file);
    system("cls");
    printf("账号注册成功!\n");
    return 1;
}

/**
 * @brief 输入密码自动替换为*
 * @param str 输入的字符串
 * @param length 字符串长度
 * @return 返回输入的字符串
 */
char *inPass(char *str, int length)
{
    char temp;
    int count = 0;

    while ((temp = getch()) != 13 && count < length - 1)
    {
        // 如果用户退格则删除一个字符
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

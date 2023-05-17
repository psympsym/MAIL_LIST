#ifndef _Tel_h_
#define _Tel_h_

/* 宏定义 */
// #define FILE_NAME "Data.txt"
// #define DESKFILE_NAME "C:\\Users\\WHR\\Desktop\\Data.txt"
// 宏定义账户信息文件名
#define USER_FILE "User.dat"

#define MAXROW 200
#define MAX_NAME 11
#define MAX_SEX 5
#define MAX_TEL_PHONE 17
#define MAX_MOBILE 17
#define MAX_QQ 17
#define MAX_AGE 5

#define MAXUN  17
#define MAXPSW 17

/* 结构体定义 */
typedef struct tel
{
    char name[MAX_NAME];             /*姓名*/
    char sex[MAX_SEX];               /*性别*/
    char tel_phone[MAX_TEL_PHONE];   /*家庭电话*/
    char mobile[MAX_MOBILE];         /*移动电话*/
    char QQ[MAX_QQ];         /*QQ*/
    char age[MAX_AGE];               /*年龄*/
} Telinf;

// 定义用户结构体
typedef struct user 
{
    char username[MAXUN];
    char password[MAXPSW];
} User;


#endif

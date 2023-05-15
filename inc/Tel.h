#ifndef _Tel_h_
#define _Tel_h_

/* 宏定义 */
#define FILE_NAME "Data.txt"
#define DESKFILE_NAME "C:\\Users\\WHR\\Desktop\\Data.txt"

#define MAXROW 200
#define MAX_NAME 11
#define MAX_SEX 5
#define MAX_TEL_PHONE 17
#define MAX_MOBILE 17
#define MAX_TEL_OFFICE 17
#define MAX_AGE 5

/* 结构体定义 */
typedef struct tel
{
    char name[MAX_NAME];             /*姓名*/
    char sex[MAX_SEX];               /*性别*/
    char tel_phone[MAX_TEL_PHONE];   /*家庭电话*/
    char mobile[MAX_MOBILE];         /*移动电话*/
    char tel_office[MAX_TEL_OFFICE]; /*办公电话*/
    char age[MAX_AGE];                         // 年龄
} Telinf;

#endif

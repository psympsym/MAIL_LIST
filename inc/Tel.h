#ifndef _Tel_h_
#define _Tel_h_

/* �궨�� */
// #define FILE_NAME "Data.txt"
// #define DESKFILE_NAME "C:\\Users\\WHR\\Desktop\\Data.txt"
// �궨���˻���Ϣ�ļ���
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

/* �ṹ�嶨�� */
typedef struct tel
{
    char name[MAX_NAME];             /*����*/
    char sex[MAX_SEX];               /*�Ա�*/
    char tel_phone[MAX_TEL_PHONE];   /*��ͥ�绰*/
    char mobile[MAX_MOBILE];         /*�ƶ��绰*/
    char QQ[MAX_QQ];         /*QQ*/
    char age[MAX_AGE];               /*����*/
} Telinf;

// �����û��ṹ��
typedef struct user 
{
    char username[MAXUN];
    char password[MAXPSW];
} User;


#endif

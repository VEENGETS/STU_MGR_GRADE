#ifndef _STU_GRADE_MGR_H_
#define _STU_GRADE_MGR_H_






//  考试信息结构体
typedef struct
{
	char g1_n[50];
	char g2_n[50];
	char g3_n[50];
} text_name;  //  考试科目结构体

typedef struct
{
	char g1_t[50];
	char g2_t[50];
	char g3_t[50];
} text_time;  //  考试时间结构体

typedef struct
{
	unsigned short g1_g;
	unsigned short g2_g;
	unsigned short g3_g;
} text_grade;  //  每个考试科目结构体

typedef struct
{
	text_name t_name;
	text_time t_time;
	text_grade t_grade;
} student_text;  //  总考试信息！

//  学生信息结构体
typedef struct
{
        char sno[20];
        char name[31];
        char sex;
        char phonenum[12];
        char ID_num[20];
        char class[20];
	student_text st;
} stu;



//  学生信息链表节点结构体
typedef struct node_t
{
        stu data;
        struct node_t* next;
} node;





extern node* stu_list;

#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"




void main_menu(void)
{
	system("clear");
	printf("\n欢迎使用学生成绩管理系统！\n");
	
		
	time_t t;
	time(&t);
	localtime(&t);
	struct tm* now_time = localtime(&t);
	const char* weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
	printf("\n现在是北京时间时间：%d年%d月%d日 %d:%02d:%02d 星期%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);
}



void mgr_menu(void)
{
	printf("\n\n尊敬的管理员，您好！\n");
	printf("请按照提示输入您要操作的对应编号！\n");
	printf("1. 修改自己用户名和密码\n");
	printf("2. 添加学生用户\n");
	printf("3. 删除学生用户\n");
	printf("4. 修改学生用户信息\n");
	printf("5. 查询学生用户信息\n");
	printf("6. 查询学生成绩信息\n");
	printf("7. 录入考试成绩\n");
	printf("8. 修改考试成绩\n");
	printf("9. 删除考试成绩\n");
	printf("0. 退出系统\n");
}


void user_menu(void)
{
	printf("\n\n尊敬的用户，您好！\n");
	printf("请按照提示输入您要操作的对应编号！\n");
	printf("1. 修改登录密码\n");
	printf("2. 查询个人信息\n");
	printf("3. 查询成绩\n");
	printf("0. 退出系统\n");
}

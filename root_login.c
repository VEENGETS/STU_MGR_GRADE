#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "md5.h"
#include "root_login.h"
#include "func.h"

int root_login_check(const char* login_name, const char* root_passwd);
int is_first_login(void);


typedef struct
{
	char root_name[51];
	char root_passwd[51];	
}rd;

rd rd1;

void root_login(void)
{

	char login_name[51], root_passwd[51], root_passwd_again[51];
	
	printf("\n用户名：");
	scanf("%s", login_name);
	strcpy(root_passwd, getpass("密  码："));
	
	if(is_first_login())  //  首次登录
	{
		if((strcmp(login_name, "root")) != 0 || (strcmp(root_passwd, "666666")) != 0)
		{
			printf("\n用户名或密码错误！登录失败！\n");
			exit(1);
		}
		//  首次登录成功
		printf("\n登陆成功！欢迎您%s！", login_name);
		printf("\n为了保障您账号的安全，请重新设置您的用户名和密码！");

		printf("\n管理员用户名：");
		scanf("%s", login_name);
		while(1)
		{
			strcpy(root_passwd, getpass("密码："));

			strcpy(root_passwd_again, getpass("再次输入密码："));
			if(strcmp(root_passwd, root_passwd_again) == 0) break;

			printf("\n两次密码不一致 ，请重新输入!\n");
		}

		strcpy(rd1.root_name, login_name);
		md5_encode(root_passwd_again, strlen(root_passwd_again), rd1.root_passwd);

		FILE* fp = fopen("data_login", "wb");

		if(NULL == fp)
		{
			perror("Open file fail");
		}

		fwrite(&rd1, sizeof(rd1), 1, fp);

		fclose(fp);
		printf("\n管理员密码修改成功！\n");
	}
	else
	{
		//  非首次登录
		if(!root_login_check(login_name, root_passwd))
		{
			printf("用户名或密码错误，登录失败！\n");
			exit(1);
		}


	}
	printf("欢迎使用本系统！\n");
	
}



int is_first_login(void)
{
	FILE* fp1 = fopen("/root/root_data/data_login", "rb");
	if(NULL == fp1)
		return 1;

	fclose(fp1);

	return 0;
}



int root_login_check(const char* login_name, const char* root_passwd)
{
	FILE* fp = NULL;
	rd st;
	char root_pass_md5[33];
	int check_success = 0;

	fp = fopen("data_login", "rb");

	if(NULL == fp)
	{
		perror("Open file fail!");
		return 0;
	}

	md5_encode(root_passwd, strlen(root_passwd), root_pass_md5);

	while(fread(&st, sizeof(st), 1, fp) == 1)
	{
		if(strcmp(login_name, st.root_name) == 0 && strcmp(root_pass_md5, st.root_passwd) == 0)
		{
			//  登录验证成功
			check_success = 1;
			rd1 = st;
			break;
		}
	}


	fclose(fp);
	return check_success;
}

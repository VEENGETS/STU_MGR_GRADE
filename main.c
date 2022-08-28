#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "stu_grade_mgr.h"
#include "menu.h"
#include "root_login.h"




int main()
{
	main_menu();

	int op, r_u;

	//stu_list = create();

	while(1)
	{
		printf("\n------------------------------------------------------------------------------");
		printf("\n请选择您的身份：");
		printf("\n1. root用户");
		printf("\n2. 普通用户");
		printf("\n0. 退出系统");
		printf("\n------------------------------------------------------------------------------");

		printf("\n您的选择是：");
		if(1 != scanf("%d", &r_u))
		{
			//  如果输入失败
			while(getchar() != '\n');
			r_u = -1;
		}
		printf("\n------------------------------------------------------------------------------");

		system("clear");

		switch(r_u)
		{
			case 1:
				{

					root_login();

					//  管理员登录
					while(1)
					{
		printf("\n------------------------------------------------------------------------------");
						mgr_menu();
		printf("\n------------------------------------------------------------------------------");

						printf("\n您要进行的操作是：");
						if(1 != scanf("%d", &op))
						{
							//  如果输入失败
							while(getchar() != '\n');
							op = -1;
						}

						system("clear");

						switch(op)
						{
							case 1:
								{

								}
								break;
							case 2:
								{
									//  添加学生用户
									//push_back_stu(stu_list, stu);
									//write_file(stu_list);

								}
								break;
							case 3:
								{

								}
								break;
							case 4:
								{

								}
								break;
							case 5:
								{

								}
								break;
							case 6:
								{

								}
								break;
							case 7:
								{

								}
								break;
							case 8:
								{

								}
								break;
							case 9:
								{

								}
								break;
							case 0:
								{
									//  退出系统
								}
								break;
							default:
								{
									printf("输入错误，请您重新输入正确的编号！");
								}

						}


					}

				}
				break;

			case 2:
				{
					//  普通用户界面

				}
				break;

			case 0:
				{
					//  退出

				}
				break;

			default:
				{
					printf("\n输入错误！请您重新输入正确的编号！");
				}
		}
		}

	return 0;
}

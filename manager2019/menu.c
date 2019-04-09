#include <string.h>
#include "menu.h"
int ask_menu(int is_login)
{
							// 파라미터 : 로그인여부 (0 No, 1Yes)
							// 리턴값 : 선택한 메뉴번호
							// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
	int menu=10;
	char command[20];
  	if(is_login==0)
	{
				
    			printf(">");
			scanf("%s", command);
			if(strcmp(command, "join")==0)
			{
				 menu=1;
				 
			}
							
			else if(strcmp(command, "login")==0)
			{
				 menu=2;
				 
			}
			else if(strcmp(command, "exit")==0)
			{
				menu = 0;
			}
			else if(strcmp(command, "list")==0)
			{
				menu = 4;
			}
			else
			printf("No such command!\n");
		
	}
  	else
	{
		
		
    			printf("#");
  			scanf("%s", command);
			if(strcmp(command, "logout")==0)
			{
				menu = 3;
				
			}
			else
				printf("%s\n", command);
		
	}
  	return menu;
}

#include "user.h"
#include "menu.h"

int main(int argc, char* argv[])
{							//커맨드 라인에서 입력받기//You will set filename
	LOGIN* userlist[100]; 				// 사용자목록 포인터 배열 (최대 100)
  	int is_login=0; 				// 로그인 여부 (0 NO, 1 Yes)
  	int menu_id;
 
	if (argc != 2)
	{						//커맨드 라인에서 뭔가가 입력되지 않으면
		printf("Usage : manager <datafile>\n");	//이 메세지 출력 후 
		return 0;				//종료
  	}
							//그게 아니면
  	int count = load_file(userlist, argv[1]);	//load_file함수에 사용자와 커맨드 라인 값을
	if(count<0) return 0;							// 넣어서 나온 결과를 카운트에 저장
							//데이터파일에서 몇명의 정보를 읽어왔는지 카운트에 save
  	while(1)
	{
    		//if(is_login==0) is_login = login(userlist, count);//로그인이 안돼있으면 로그인 함수에 사용자와
								//카운트 넣어서 그 결과를 is_login에 저장
    			menu_id = ask_menu(is_login); 	// 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    		
		if(menu_id==1) 
		{
			join(userlist, count);
			count++;
		}	//sign up to userlist
    		else if (menu_id==2) is_login = login(userlist, count);//Log in
    		else if (menu_id==3) logout(&is_login);	//Log out
    		else if (menu_id==0) break;
		else if (menu_id==4) list(userlist, count);
		else continue; 
  	}

  	save_file(userlist, count, argv[1]);//file save
  return 0;
}

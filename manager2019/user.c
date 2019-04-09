#include "user.h"

int load_file(LOGIN* list[], char* filename)
{							//사용자와 커맨드라인 입력값을 파라미터로 받음
	#ifdef DEBUG_MODE
		printf("DEBUG: load_file()\n");
	#endif	
  	int count=0;					//변수 카운트 0 초기화
  	FILE *datafile = fopen(filename, "r");		//읽기모드로 데이터 파일 오픈
	int newFile = 0;
	if(datafile == NULL)
	{
		
		printf("There is no such file. Want to make new?\n");
		printf("Yes >> 1\tNo >> 2 :  ");
		scanf("%d", &newFile);
		if(newFile == 1)
		{
			datafile = fopen(filename,"w+");
			printf(">Welcome!");
			fclose(datafile);
			datafile = fopen(filename, "r");		
		}
		else return -1;
	}	
  	while(!feof(datafile))
	{						//파일의 끝을 만나기 전까지
    		
		list[count]=(LOGIN*)malloc(sizeof(LOGIN));//카운트인덱스 배열에 사용자목록 배열 크기 메모리 할당
    		fscanf(datafile,"%s %s",list[count]->id,list[count]->password);//데이터파일에서
		if(strcmp(list[count]->id, ""))									// 아이디 패스워드 읽기
    		count++;				//한 명 읽어오면 +1
  	}						//와일문 종료

  	printf("%d records read!\n",count);		//if while loop is done 출력되어야 할 문장 카운트 확인
  	fclose(datafile);				//파일 오픈해서 다썼으니 닫기
  	return count;					//몇명인지 리턴해줌
}

void join(LOGIN* list[], int count)
{							//파라미터에 사용자 목록이랑 현재까지 등록된 사람 전달
	
	#ifdef DEBUG_MODE
		printf("DEBUG: join()\n");
	#endif	
  	char id[20], pass[20];				//아이디랑 패스워드 변수 선언
  	while(1)
	{
    		printf("Enter new user id >> ");
    		scanf("%s", id);			//사용하고싶은 아이디 입력
    		int dup=0;
    		for(int i=0;i<count;i++)
		{					//입력된 사용자 목록 크기만큼 반복
      			if(strcmp(id, list[i]->id)==0)
			{				//If id is already exist,
        			dup=1;
				break;		//for checking duplicate, set dup as 1
      			}
    		}
		
    		if(dup==1)
		{					//기존 목록에 아이디가 이미 존재할 경우
      			printf("Already exist!!\n");
    		}	
    		else
		{					// if id isn't exist in the list,
							// it's been successfully saved in the list
      			printf("Enter password >> ");//아이디 입력을 마치고 비밀번호 입력
      			scanf("%s", pass);// pass에 비밀번호 입력
      			list[count] = (LOGIN*)malloc(sizeof(LOGIN));//i가 마지막 사용자 다음 번호로 이동했으니
								//그대로 카운트 부터 인덱스 시작하면 됨.
							//여기에 또 아이디랑 비밀번호 넣어야 하니 메모리할당.
      			strcpy(list[count]->id, id);	//내가 입력한 아이디를 해당 번호 목록 구조체에 복사
			strcpy(list[count]->password, pass);//내가 입력한 비밀번호를 해당 번호목록 구조체에 복사
			printf("New user added!\n");//회원가입을 마치고 출력
      			break;
    		}
  	}
}


int login(LOGIN* list[], int count)
{				
	#ifdef DEBUG_MODE
		printf("DEBUG: login()\n");
	#endif			//사용자목록과 현재 등록된 사람수를 파라미터로 전달
  	char id[20], pass[20];				//아이디와 패스워드 변수 생성 최대 20자
  	printf("Enter user id >> ");
  	scanf("%s", id);				//내 아이디 입력
  	int dup=0, found;				//듀플리케이트 생성, 몇번째 목록인지 구분하는 변수 하나
  	
	for(int i=0;i<count;i++)
	{						//목록에 있는 목록 번호 전체 서치
    		if(strcmp(id, list[i]->id)==0)
		{					//if id is same with id in the list,
      			dup=1;				//set duplicate 1
      			found = i;			//we've got id so set  found as id's number
      			break;
    		}
		else dup=2;
  	}

 	if(dup!=1)
	{						//if there is no same id in the list,
    		printf("No such user!!\n");		//print this message
    		return 0;
  	}
  	else
	{						//if we found id in the list
    		printf("Enter password >> ");
    		scanf("%s", pass);			//input password
    		if(strcmp(list[found]->password, pass)==0)
		{					//if pass is same with found's password in the list
      			printf(">Welcome %s!!\n", id);	// print this message with id that you just put 
      			return 1;
    		}		
    		else
		{					//if password is incorrect
      			printf("Password incorrect!!\n");
      			return 0;			//exit login and start from main again
    		}
  	}
}

void logout(int* is_login)
{	
	#ifdef DEBUG_MODE
		printf("DEBUG: logout()\n");
	#endif
						//to logout, 
  	*is_login = 0;					//set is_login 0
  	printf("Logout!!\n");
}							//it will give 0 to main.c so while loop will be stop.

void save_file(LOGIN* list[], int count, char* filename)
{
	#ifdef DEBUG_MODE
		printf("DEBUG: save_file()\n");
	#endif

  	FILE *datafile = fopen(filename, "w");		//make or open datafile
  	for(int i=0; i<count; i++)
	{						//from 0 to count
    		fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  	}
							//save id and pass
  	printf("%s Saved!\n", filename);		// if successfully saved, print this
  	fclose(datafile);//after finishing using file pointer, close it
}


void list(LOGIN* list[], int count)
{
	#ifdef DEBUG_MODE
		printf("DEBUG: list()\n");
	#endif

	printf("(id / password)\n"); 
	int i=0;
	for(i=0; i<count; i++)
	{
		printf("[%d] %s / %s\n", i+1, list[i]->id, list[i]->password);
	}
}










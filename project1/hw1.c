#include <time.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>

int main()
{
	char a[5]; // 가위, 바위, 보 중 하나를 받을 문자형배열을 선언
	bool t = true; // 반복에 이용할 부울형 변수를 선언하고 true로 초기화
	char b; // 게임의 지속 또는 종료의 여부를 묻는 문자형 변수 선언
	int x,y; // 랜덤변수를 받을 정수와 사용자 정의 정수를 받을 정수형변수를 선언
	int win = 0, lose = 0, draw = 0,cnt=0;// 이긴 회수,진 회수,비긴 회수,게임 회수를 카운트하기전에 0으로 모두 초기화
	while (t)// 반복 0이면 반복문종료, 1이면 무한반복을 이용
	{
		printf("가위 바위 보 중 하나를 입력해주십시오\n"); // 사용자에게 가위, 바위, 보 중 하나를 내라고 명시
		scanf_s("%s", a, sizeof(a)); // 입력받음
		srand((unsigned int)time(NULL)); // 시드를 현재시간으로 설정
		if (strcmp(a, "가위") == 0) x = 1; // 입력받은것과 가위을 비교해서 맞으면 x=1을 대입하는데 왜 1을 대입하냐하면, switch-case문을 이용할 것이기 때문입니다.
		if (strcmp(a, "바위") == 0) x = 2; // 위와 동일
		if (strcmp(a, "보") == 0) x = 3; // 위와 동일
		switch (x) // 가위, 바위, 보로 분류 1이면 가위, 2면 바위, 3이면 보 
		{
		case 1: // 사용자가 가위을 낸 경우
			y = rand() % 3 + 1; // 1부터 3까지 생성되는 랜덤변수를 생성하고 저장
			x = 2;// 가위을 2라고 설정하고, 보는 1로 바위는 3으로 설정함으로써 이김과 짐을 표현할 수 있기때문에 이런 아이디어를 생각해보았습니다.
			if (x > y) { printf("이겼습니다. 컴퓨터는 보를 냈습니다.\n"); win++; break; } // 컴퓨터가 랜덤변수로 1을 내놓았을 때, 사용자가 이기고 이긴회수를 그 때 마다 1회추가
			else if (x < y) { printf("졌습니다. 컴퓨터는 바위를 냈습니다.\n"); lose++; break; }//컴퓨터가 랜덤 변수로 3을 내놓았을 때, 사용자가 지고 진 회수를 그 때 마다 1회추가
			else if (x == y) { printf("비겼습니다. 컴퓨터는 가위을 냈습니다.\n"); draw++; break;}// 컴퓨터가 랜덤 변수로 2를 내놓았을 때, 사용자와 비기고 비기는 회수를 1회추가
		case 2: // 사용자가 바위를 낸 경우 원리는 위와 동일하므로 주석생략하겠습니다.
			y = rand() % 3 + 1;
			x = 2;
			if (x > y) { printf("이겼습니다. 컴퓨터는 가위를 냈습니다.\n"); win++; break; }
			else if (x < y) { printf("졌습니다. 컴퓨터는 보를 냈습니다.\n"); lose++; break; }
			else if (x == y) { printf("비겼습니다. 컴퓨터는 바위를 냈습니다.\n"); draw++; break; }
		case 3: // 사용자가 빠를 낸 경우 마찬가지로 위와 동일하므로 주석 생략 
			y = rand() % 3 + 1;
			x = 2;
			if (x > y) { printf("이겼습니다. 컴퓨터는 바위를 냈습니다.\n"); win++; break; }
			else if (x < y) { printf("졌습니다. 컴퓨터는 가위를 냈습니다.\n"); lose++; break; }
			else if (x == y) { printf("비겼습니다. 컴퓨터는 보를 냈습니다.\n"); draw++; break; }
		default: // 묵 찌 빠를 입력하지않은경우 잘못입력했다고 명시해주고 다시시작할 것.
			printf("가위 바위 보 중 하나를 입력하세요\n"); break;
		}
		if (draw == 10) // 10번 비겼을 때 컴퓨터의 패배이므로 게임의 결과를 사용자에게 알려주고 반복문을 종료시킨다.
		{
			printf("10번 비겼으므로 컴퓨터의 패배입니다 \n");
			break;
		}
		printf("계속하실거면 c를, 종료하시려면 q를 눌러주세요\n"); // 계속할 건지 여부를 묻는다.
		scanf_s(" %c", &b, sizeof(b));
		if (b == 'c') t = true; // c입력시, while(1) 되므로 게속반복
		else if (b == 'q') t = false; // q입력시, while(0) 이므로 반복문 종료
		else // c 또는 q를 입력하지 않은 경우 c나q중 하나를 입력하라고 명시하고 다시한번 입력하게 만든다. 두 번이상 틀린경우 반복문을 탈출하고 횟수들을 출력후 프로그램을 종료한다.
		{
			printf("c나 q중 하나를 입력하세요 한번 더 c 또는 q를 입력하지 않으시면 프로그램이 종료됩니다.\n");
			scanf_s(" %c", &b, sizeof(b));
			if (b == 'c') continue;
			else if (b == 'q') break;
			else break;
		}
		cnt++; // 게임회수 1회씩 추가
	}
	printf("총 %d번의 게임 중 이긴횟수 : %d, 진 회수 : %d, 비긴회수:%d 입니다.\n",cnt,win,lose,draw); // 게임종료시 이긴 회수와 진 회수 비긴 회수 를 가르쳐준다.
	return 0;
}
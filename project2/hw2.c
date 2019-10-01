/*
프로그래머 성명 : 유성민
학번 : 201520908
프로그램의 기능 : 입력된 문자열을 시저가 사용한 방식으로 암호화 또는 복호화 시키는 프로그램 입니다.
*/

#include <stdio.h>
#include <string.h>

#define str_length 51 // 문자열은 최대 50자 가능하므로 최대 문자열 길이 설정 널문자포함, 51로 설정

int main()
{
	bool flag = true; // 반복에 필요한 부울형 변수 선언하고 ture로 초기화
	char c; // 반복에 필요한 문자형 변수
	int n,length; // 선택메뉴, 문자열 길이
	char str[str_length]; // 문자열을 입력받을 배열
	while (flag)
	{
		printf("문자열을 입력하세요\n");
		scanf_s("%s", str, sizeof(str));
		printf("1.암호화\t2.복호화\n");
		printf("선택메뉴 입력 : "); scanf_s("%d", &n);
		if (n != 1 || n != 2) printf("선택메뉴를 잘못 입력했습니다\n");
		length = strlen(str); // 문자열의 길이를 저장
		if (n == 1) // 암호화를 선택시
		{
			for (int i = 0; i < length; i++) // 입력받은 문자열의 끝까지 반복
			{
				if (str[i] >= 'a' && str[i] <= 'z') // 알파벳 소문자를 입력 받았을 때
				{
					str[i] += ('e' - 'a'); // 암호화는 배열요소 + 4를 가야하므로, 4를 더하고 요소에 저장 (평행크기는 => 4)
					if (str[i] > 'z') str[i] -= ('z' - 'a'); // 알파벳 소문자를 벗어나면 overflow처럼 범위내에서 돌고 돌아야 하므로 초과한만큼에서 알파벳의 개수를 빼준다.
					printf("%c", str[i]); // 암호화된 문자열을 출력
				}
				else if (str[i] >= 'A' && str[i] <= 'Z') // 알파벳 대문자를 입력 받았을 때
					if (str[i] >= 'a' && str[i] <= 'z') // 원리는 위와 동일 하므로 주석 생략하겠습니다.
					{
						str[i] += ('E' - 'A');
						if (str[i] > 'Z') str[i] -= ('Z' - 'A');
						printf("%c", str[i]);
					}
			}
			printf("\n");
		}
		else if (n == 2) // 복호화 선택시
		{
			for (int i = 0; i < length; i++) // 입력받은 문자열의 끝까지 반복
			{
				if (str[i] >= 'a' && str[i] <= 'z') // 알파벳 소문자를 입력 받았을 때
				{
					str[i] -= ('e' - 'a'); // 암호화와 반대로 배열요소에서 4를 빼고 요소에 저장
					if (str[i] < 'a') str[i] += ('z' - 'a'); // // 알파벳 소문자를 벗어나면  초과한만큼에서 알파벳의 개수를 더한다.
					printf("%c", str[i]); // 복호화된 문자열을 출력
				}
				else if (str[i] >= 'A' && str[i] <= 'Z') // 알파벳 대문자를 입력 받았을 때
					if (str[i] >= 'a' && str[i] <= 'z')
					{
						str[i] -= ('E' - 'A');
						if (str[i] < 'A') str[i] += ('Z' - 'A');
						printf("%c", str[i]);
					}
			}
			printf("\n");
		}
		printf("계속하고 싶으시면 c를 종료하고 싶으시면 q를 눌러주세요\n"); // 반복이 되야하므로 계속할 지 멈출 지 사용자에게 선택시킴
		scanf_s(" %c", &c, sizeof(c)); // 반복에 관한 문자를 입력받음
		if (c == 'c') flag = true; // 계속할거면 while(flag==1) 으로 반복시킴
		else if (c == 'q')
		{
			flag = false; // 끝낼거면 while(flag==0) 으로 종료시킴
			printf("프로그램을 종료합니다\n");
		}
		else
		{
			printf("잘못 입력했습니다. c나 q중 하나만 입력하세요\n"); // 문자를 잘못 입력한 경우
			continue; // 다시 반복문의 처음으로 돌아감
		}
	}
    return 0;
}
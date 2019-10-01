#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#define NAMELENGTH 50
#define STU_NUM 3

struct student
{
	char name[NAMELENGTH];
	int korean;
	int english;
	int sum;
	double avg;
};

int main()
{
	int menu;
	bool flag = true;
	int t;
	struct student s[STU_NUM] = { 0, };
	char namecmp1[NAMELENGTH];
	char namecmp2[NAMELENGTH];
	int cnt = 0;
	printf("**************************\n");
	printf("[성적 관리 프로그램v1.0]\n");
	printf("**************************\n");
	printf("1. 전체 학생 성적 보기\n2. 새로운 학생 등록\n3. 개인 성적 조회\n4. 학생 정보 삭제\n5. 프로그램종료\n");
	printf("사용자입력: ");
	while (scanf(" %d", &menu) == 1)
	{
		switch (menu)
		{
		case 1:
			if (*(s[0]).name == 0 && *(s[1]).name == 0 && *(s[2]).name == 0) printf("입력된 학생 정보가 없습니다\n");
			else
			{
				printf("[이름]\t\t[국어]\t[영어]\t[총점]\t[평균]\n");
				for (int i = 0; i < STU_NUM; i++)
				{
					s[i].sum = s[i].korean + s[i].english;
					s[i].avg = (double)s[i].sum / STU_NUM;
				}
				for (int i = 0; i < STU_NUM; i++)
				{
					if (*(s[i]).name != 0)
					{
						printf("[%s]\t\t%d\t%d\t%d\t%lf\n", s[i].name, s[i].korean, s[i].english, s[i].sum, s[i].avg);
					}
				}
			}
			break;
		case 2:
			if (*(s[STU_NUM - 1]).name != NULL) printf("메모리가 가득차서 입력이 불가능합니다\n");
			else
			{
				if (*(s[0]).name == 0 || *(s[1]).name == 0 || *(s[2]).name == 0)
				{
					printf("[2. 새로운 학생 등록]\n");
					for (int i = 0; i < STU_NUM; i++)
					{
						printf("이름 : "); scanf(" %s", s[i].name);
						printf("국어 : "); scanf(" %d", &s[i].korean);
						printf("영어 : "); scanf(" %d", &s[i].english);
						printf("\n");
					}
				}
			}
			break;
		case 3:
			if (*(s[0]).name == 0 && *(s[1]).name == 0 && *(s[2]).name == 0)
			{
				printf("입력된 학생 정보가 없습니다\n");
				break;
			}
			printf("찾을 학생 이름 : "); scanf(" %s", namecmp1);
			if (strcmp(s[0].name, namecmp1) != 0 && strcmp(s[1].name, namecmp1) != 0 && strcmp(s[2].name, namecmp1) != 0)
			{
				printf("찾는 학생이 없습니다.\n");
			}
			else
			{
				for (int k = 0; k < STU_NUM; k++)
				{
					if (strcmp((s[k]).name, namecmp1) == 0) t = k;
				}
				printf("[이름]\t\t[국어]\t[영어]\t[총점]\t[평균]\n");
				for (int i = 0; i < STU_NUM; i++)
				{
					s[i].sum = s[i].korean + s[i].english;
					s[i].avg = (double)s[i].sum / STU_NUM;
				}
				printf("[%s]\t\t%d\t%d\t%d\t%lf\n", s[t].name, s[t].korean, s[t].english, s[t].sum, s[t].avg);
				if (strcmp(s[0].name, namecmp1) != 0 && strcmp(s[1].name, namecmp1) != 0 && strcmp(s[2].name, namecmp1) != 0)
				{
					printf("찾는 학생이 없습니다.\n");
				}
			}
			break;
		case 4:
			if (*(s[0]).name == 0 && *(s[1]).name == 0 && *(s[2]).name == 0)
			{
				printf("입력된 학생 정보가 없습니다\n");
				break;
			}
			printf("삭제할 학생 이름 : "); scanf(" %s", namecmp2);
			if (strcmp(s[0].name, namecmp2) != 0 && strcmp(s[1].name, namecmp2) != 0 && strcmp(s[2].name, namecmp2) != 0)
			{
				printf("찾는 학생이 없습니다.\n");
			}
			else
			{
				for (int k = 0; k < STU_NUM; k++)
				{
					if (strcmp(s[k].name, namecmp2) == 0)
					{
						cnt++;
					}
				}
				if (cnt == 1)
				{
					for (int k = 0; k < STU_NUM; k++)
					{
						if (strcmp(s[k].name, namecmp2) == 0)
						{
							*(s[k]).name = *(s[k + 1]).name;
							s[k].korean = s[k + 1].korean;
							s[k].english = s[k + 1].english;
							*(s[k + 1]).name = 0;
							s[k + 1].korean = 0;
							s[k + 1].english = 0;
							if (k == 2)
							{
								*(s[2]).name = 0;
								s[2].korean = 0;
								s[2].english = 0;
							}
						}
					}
				}
				else if (cnt == 2)
				{
					for (int k = 0; k < STU_NUM; k++)
					{
						if (strcmp(s[k].name, namecmp2) == 0)
						{
							*(s[k]).name = *(s[k + 1]).name;
							s[k].korean = s[k + 1].korean;
							s[k].english = s[k + 1].english;
							*(s[k + 1]).name = 0;
							s[k + 1].korean = 0;
							s[k + 1].english = 0;
							if (k == 1)
							{
								*(s[1]).name = 0;
								s[1].korean = 0;
								s[1].english = 0;
							}
							if (k == 2)
							{
								*(s[2]).name = 0;
								s[2].korean = 0;
								s[2].english = 0;
							}
						}
					}
				}
				else if (cnt == 3)
				{
					for (int k = 0; k < STU_NUM; k++)
					{
						if (strcmp(s[k].name, namecmp2) == 0)
						{
							*(s[k]).name = 0;
							s[k].korean = 0;
							s[k].english = 0;
						}
					}
				}
			}
			cnt = 0;
			break;
		case 5:
			printf("성적  관리 프로그램을 종료합니다\n");
			break;
		default:
			printf("잘못 입력하셨습니다\n");
			break;
		}
		if (menu == 5) break;
		printf("**************************\n");
		printf("[성적 관리 프로그램v1.0]\n");
		printf("**************************\n");
		printf("1. 전체 학생 성적 보기\n2. 새로운 학생 등록\n3. 개인 성적 조회\n4. 학생 정보 삭제\n5. 프로그램종료\n");
		printf("사용자입력: ");
	}
	return 0;
}
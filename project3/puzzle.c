/************************************************************************************
** 이름 : 유성민
** 학번 : 201520908
** 프로그램의 기능 : 퍼즐을 파일에다가 출력 후, 그것을 이용하여 퍼즐찾기 문제를 해결하는 프로그램
*************************************************************************************/

// 이번 프로그램은 희안하게 공백만 뜨길래 문제 원인을 찾다가 도저히 모르겠어서 워드, 퍼즐배열에 간단한 테스트케이스를 집어넣어 팔방향 다 잘되는지 실험해봤는데 잘됩니다. 
// 문제는 파일에서 입력받고 (프린트되는것까지 확인했습니다) 파일에서 입력도 잘받아오는데 파일입출력 공부도 열심히 했는데 원인을 못찾았습니다.
// 노력했다는 것만 알아주신다면 감사하겠습니다 (꾸벅)

#include <stdio.h>
#include <string.h>
#define NBWORD 38
#define PUZZLESIZE 17
#define WORDLEN PUZZLESIZE

void CheckEastDiretion(int row, int col, char word[NBWORD]); // 좌 우 요소 비교함수
void CheckNorthDiretion(int row, int col, char word[NBWORD]); //  상 하 요소 비교함수
void CheckNorthEastDiretion(int row, char word[NBWORD]); // 대각선  ＼ 방향 요소 비교함수
void CheckNorthWestDiretion(int row, int col, char word[NBWORD]); // 대각선 / 방향 요소 비교함수
void CheckWord(char word[NBWORD]); // 위의 네 가지 함수를 반복하며 단어를 찾는 함수
void printmark(); // 찾은 결과를 프린트 하는 함수
char puzzle[PUZZLESIZE][PUZZLESIZE] = { 0,};// 퍼즐을 입력받을 배열
char word[NBWORD][WORDLEN + 1] = {0,}; // 단어리스트를 입력받을 배열
int mark[PUZZLESIZE - 1][PUZZLESIZE - 1] = { 0, }; // 찾은 단어를 체크할 배열

int main()
{
	int i = 0, m;
	FILE* fin1 = NULL;
	FILE* fin2 = NULL;
	fin1 = fopen("wordlist.txt", "r"); // 단어리스트를 파일에서 꺼내온다
	fin2 = fopen("puzzle.txt", "r"); // 퍼즐을 파일에서 꺼내온다
	while(1)
	{
		if (feof(fin1)) break; // 파일의 끝에서 멈춤
		fscanf(fin1, "%s", word[i]); // 파일에 저장된 단어리스트를 워드 배열에 입력받는다
		//printf("%s",word[i]);
		i++;
	}
	while (1)
	{
		if (feof(fin1)) break;
			fscanf(fin2, "%s", puzzle[i]); // 파일에 저장된 퍼즐을 퍼즐 배열에 입력받는다
			//printf("%s",puzzle[i]);
	}
	for (m = 0; m < NBWORD; m++)
	{
		if (word[m] != NULL) // 단어갯수까지 체크함수를 반복한다
		{
			CheckWord(word[m]);
		}
	}
	printmark(); // 찾은것을 표시한다
	fclose(fin1); // 파일 닫는다
	fclose(fin2);
	return 0;
}

void CheckEastDiretion(int row, int col, char word[NBWORD]) // 좌 우 요소 검사 함수
{
	int j, k, len;
	bool flag = true;
	len = strlen(word);
	if (col + len >= PUZZLESIZE) return; // 열 + 단어 길이가 퍼즐크기를 초과한다 탐색범위 벗어남
	for (j = 0, k = col; j < len; j++, k++) // 열을 늘려가면서 ->-> 방향으로 검사 하겠다
	{
		if (puzzle[row][k] != word[j]) // 요소가 같지 않으면
		{
			flag = false; // 거짓을 저장
			break; // 멈춤
		}
	}
	if (flag == false) // 위에서 거짓일 때
	{
		for (j = 0, k = col + len - 1; j < len; j++, k--) // 열의 끝에서 시작하겠다 <- <- 방향으로 검사
		{
			if (puzzle[row][k] != word[j]) // 찾지못하면
			{
				flag = false; // 거짓을 저장
				return; // 검사가 끝났으므로 종료
			}
		}
	}
	for (j = 0, k = col; j < len; j++, k++) mark[row][k] = 1; // 위의 경우를 제외하고 찾은경우는 마크배열에 1을 마크해서 체크함
}
void CheckNorthDiretion(int row, int col, char word[NBWORD]) // 상 하  요소 검사 함수
{
	int j, k, len;
	bool flag = true;
	len = strlen(word);
	if (row + len >= PUZZLESIZE) return; // 위에서 설명했으므로 밑에서부터 생략
	for (j = 0, k = row; j < len; j++, k++) 
	{
		if (puzzle[k][col] != word[j]) // 행을 증가시켜가며  v v v 하방향 검사 
		{
			flag = false;
			break;
		}
	}
	if (flag == false)
	{
		for (j = 0, k = row + len - 1; j < len; j++, k--)
		{
			if (puzzle[k][col] != word[j]) // 행의 초기값을 마지막행에 위치시키고 행을 감소시키며 ^ ^ ^ 상방향 검사
			{
				flag = false;
				return;
			}
		}
	}
	for (j = 0, k = row; j < len; j++, k++) mark[k][col] = 1;
}
void CheckNorthEastDiretion(int row,char word[NBWORD]) // 대각선  ＼ 방향 요소 비교함수 (행과 열의 요소가 같다는 사실을 이용함)
{
	int j, i, len;
	bool flag = true;
	len = strlen(word);
		if (row+ len >= PUZZLESIZE) return;
		for (j = 0, i = row; j < len; j++, i++)
		{                                                                                                                           
			if (puzzle[i][i] != word[j]) // 행을 늘려가며(열을늘려가며) 검사함 위에서 아래로  대각선
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
		{
			for (j = 0, i = row + len - 1; j < len; j++, i--)
			{
				if (puzzle[i][i] != word[j]) // 행의 초기값을 마지막행에 위치시키고 행을 감소시키며  아래에서 위로 검사  대각선 역순
				{
					flag = false;
					return;
				}
			}
		}
		for (j = 0, i = row; j < len; j++,i++) mark[i][i] = 1;
}
void CheckNorthWestDiretion(int row, int col,char word[NBWORD]) // 대각선  / 방향 요소 비교함수(행과 열의 요소의 합이 퍼즐배열크기-2 임을 이용) 
{
	int j, i,  len;
	bool flag = true;
	len = strlen(word);
	if (col + len >= PUZZLESIZE) return;
	for (j = 0, i = row+ len - 1; j < len; j++, i--)
	{
		if (puzzle[PUZZLESIZE - 2 - i][row] != word[j]) // 행의 초기값을  마지막행에 위치시키고 행을 감소해가면서 요소 검사 대각선 역순 아래서 위로
		{
			flag = false;
			break;
		}
	}
		if (flag == false)
		{
			for (j = 0, i = row; j < len; j++, i++)
			{
				if (puzzle[i][PUZZLESIZE - 2 - i] != word[j]) // 행을 0행에다 놓고 늘려가며 요소비교 대각선 방향 위에서 아래로
				{
					flag = false;
					return;
				}
			}
		}
		for (j = 0, i = row; j < len; j++, i++) mark[i][PUZZLESIZE-2-i] = 1;
}
void CheckWord(char word[NBWORD]) // 최종적으로 팔방향 검사를 할 할수
{
	int row, col;
	for (row = 0; row < PUZZLESIZE; row++) // 행을 늘려가며 퍼즐배열크기 전까지
	{
		for (col = 0; col < PUZZLESIZE; col++) // 열을 늘려가며 퍼즐배열크기 전까지
		{
			CheckEastDiretion(row, col, word);
			CheckNorthDiretion(row, col, word);
			CheckNorthEastDiretion(row, word);
			CheckNorthWestDiretion(row, col, word);
		}
	}
}

void printmark() // 찾은 것을 표시할 함수
{
	printf("전하고자 하는 메세지는 : \n");
	for (int i = 0; i < PUZZLESIZE - 1; i++)
	{
		for (int j = 0; j < PUZZLESIZE - 1; j++)
		{
			if (mark[i][j] == 0) // 매칭되는 것에 1이 저장되있고 문제에서 요구하는 것은 동그라미 치지않은 것이 전하는 메시지를 찾는 것이므로 
				printf("%c", puzzle[i][j]); // 퍼즐배열에서 그에 해당하는 요소를 출력시킨다.
		}
	}
}
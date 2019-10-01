/**************************************************************
** 이름 : 유성민
** 학번 : 201520908
** 프로그램의 기능 : 8퀸 문제의 해답을 보여주고 총 갯수를 찾는 프로그램
**************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX 10 // 배열의 크기

int nQueen[MAX + 1]; // 일차원배열로 체스판 행 하나하나 구성하여 총 8행을 구성할 것임
int size = 8; // 체스판의 크기이자, 퀸의 수
int cnt = 0; // 해를 찾을 때마다 증가시킬 변수 즉, 해의 갯수를 나타내는 변수

bool issafe(int row, int col); // '퀸 끼리 공격하지 않는 자리인가?' 검사하는 함수
void displayBoard(); // 결과로 나온 해를 체스판 처럼 구현하여 보여주는 함수
void findsolution(); //  해를 찾는 함수

int main()
{
	findsolution(); // 최종적인 해를 구하여 표시
	printf("\n");
	printf("해의 갯수 : %d\n", cnt); // 해의 갯수를 표시
	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 1 2 3  4  5  6  7 ->col
bool issafe(int row, int col) // 서로 공격하지 않는 위치를 구성해줌                                                                                                                         Q               * <- nQueen[direction=1] = 1
{  //                                                                                                                                                                                                                        *          *    <- nQueen[direction=2] = ? 어딘가에 있다 하면
	int direction; // 퀸이 저장된 열을 지정하는 변수                                                                                                                                                        *    *      <- nQueen[direction=3] = ?
	for (direction = row - 1; direction > 0; direction--) // 배열이므로 0행부터시작하니 초기값은 행-1로 지정하고 줄여가면서 검사                                       * -> 이 위치를 검사하는데 col - nQueen[direction] == row-direction
	{////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// row-direction - 1, 2, 3 ,.....row-1 1행부터 검사하고자하는 행까지(세로를 증가)
		if (nQueen[direction] == col) return false;
		else if( abs(col - nQueen[direction]) == row - direction) return false; /////////////////////////////////////////// col - nQueen[direction](가로를 증가해서 지금 찾는 위치까지) 절댓값은 오른쪽에서 왼쪽으로 검사할때
	} // 퀸이 저장된 열과 사용자가 지정하는 열이 같은가? 또는 대각선은 행과 열이 동일하므로 세로와 가로를 증가시키며 중간점에서(대각선에서 만난다) ->->->ㅣ  가로늘리기
																																																									  //  Y   세로늘리기
	return true; // 안걸리면 true를 반환                                                                                                                                                                                  Y
}

void displayBoard() // 체스판 생성 함수
{
	int row, col;

	for (row = 1; row <= size; row++) printf("%2d", row); // 행이 사이즈를 초과하면 개행문자 총 8개의 행이 만들어져야 하므로
	printf("\n");

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			if (nQueen[row] == col) printf(" Q"); // 퀸의 위치를 열의 위치로 nQueen배열에 저장해 놨으므로 지정하는 행 일때 그 열에 퀸을 놓는다.
			else printf(" *"); // 퀸이 아니면 *로 표시 공백을 쓸라했으나 알아보기힘들어 *로 표시했습니다.
		}
		printf("\n");
	}
	printf("\n");
}

void findsolution() // 퀸을 놓는다.
{
	int row, col; // 행과 열을 선언

	for (row = 1, col = 1; row > 0;)
	{
		if (issafe(row, col)) // 행과 열을 늘려가며 퀸의 위치가 안전하면
		{
			nQueen[row] = col; // 행의 그 열의 위치를 nQueen배열에 저장하고
			col = 1; // 열은 1부터 다시시작함 다시 답을 계속 찾아가야 하므로
			if (++row <= size) continue; // 행이 사이즈만큼 도달하면 다시 반복문 지속
		}
		else if (++col <= size) continue; // 배치할 자리 없으면 위에서 부터 다시 답을 찾아라

		if (row > size) // 마지막 행까지 퀸이 위치하면 
		{
			displayBoard(); // 퀸의 위치를 그리고
			col = nQueen[--row] + 1; // 행을 감소하면서 (위로가면서) 계속한다.
			cnt++; // 해답을 찾았으면 답의 갯수가 증가되야하니까 증가시킨다.
		}
		while (col > size) // 퀸이 배치할 곳을 못찾으면
		{
			col = nQueen[--row] + 1; // 배치할 자리가 없으니까 위에 부터 다시 배치한다.(백트레킹)
		}
	}
}
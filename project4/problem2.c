#include <stdio.h>
#include<string.h>
#define WORKER 3
#define MAX_LEN 100
struct person 
{
	char name[50];
	char phone[20];
	int pay_hour;
	int work_hour;
	int total_pay;
};

int main()
{
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	char temp1[MAX_LEN];
	char temp2[MAX_LEN];
	int tmp1;
	int tmp2;
	int tmp3;
	char copy1[MAX_LEN];
	char copy2[MAX_LEN];
	int copyd1;
	int copyd2;
	int j = 0;
	struct person p[3] = {};

    printf("새로운 근로자 등록\n");
	for (int i = 0; i < WORKER; i++)
	{
		printf("이름 : "); scanf(" %s", p[i].name);
		printf("전화번호 : "); scanf(" %s", p[i].phone);
		printf("근무시간 : "); scanf(" %d", &p[i].pay_hour);
		printf("시간당 임금 : "); scanf(" %d", &p[i].work_hour);
		printf("\n");
	}
	fp1=fopen("input.txt", "w");
	fprintf(fp1, "%d\n", WORKER);
	for (int i = 0; i < WORKER; i++)
	{
		fprintf(fp1,"%s\n%s\n%d\n%d\n",p[i].name, p[i].phone, p[i].pay_hour, p[i].work_hour);
	}
	fclose(fp1);
	fp2 = fopen("output.txt", "w");
	fclose(fp2);
	fp1=fopen("input.txt", "r");
	fp2=fopen("output.txt", "w");
	
	fseek(fp1, 1, SEEK_SET);
	while (0 < fscanf(fp1,"%s %s %d %d", copy1, copy2, &copyd1, &copyd2))
	{
		p[j].total_pay = copyd1 * copyd2;
		j++;
	}
	
	for (int phase=1; phase< WORKER; phase++)
	{
		for (int k = 0; k < WORKER-phase; k++)
		{
			if (p[k].total_pay < p[k+1].total_pay)
			{
				strcpy(temp1, p[k].name);
				strcpy(p[k].name, p[k+1].name);
				strcpy(p[k+1].name, temp1);
				
				strcpy(temp2, p[k].phone);
				strcpy(p[k].phone, p[k+1].phone);
				strcpy(p[k+1].phone, temp2);
		
				tmp1 = p[k].work_hour;
				p[k].work_hour = p[k+1].work_hour;
				p[k+1].work_hour = tmp1;

				tmp2 = p[k].pay_hour;
				p[k].pay_hour = p[k+1].pay_hour;
				p[k+1].pay_hour = tmp2;

				tmp3 = p[k].total_pay;
				p[k].total_pay = p[k+1].total_pay;
				p[k+1].total_pay = tmp3;
			} 
		}
	}
	
	fprintf(fp2, "Name\tPhone\t\tWorking Hour\tpay/hour\t\ttotal pay\n");
	for (int i = 0; i < WORKER; i++)
	{
		fprintf( fp2,"%s\t%s\t%d\t\t%d\t\t%d\n", p[i].name, p[i].phone, p[i].pay_hour, p[i].work_hour,p[i].total_pay);
	}
	fclose(fp1);
	fclose(fp2);
}

#include "score.h"

// �л��� �й� �̸� ������ �ϳ��� �μ��� ����
typedef struct student
{
	char std[11];
	char name[10];
	int kor, eng, math;

}S;
static S temp[] = { "","",0,0,0 }, arra[] = { "","",0,0,0 }, modi[] = { "","",0,0,0 }, stu[] = { "","",0,0,0 };

int count = 0;

int main(void)
{
	int number, i;
	open();
	for (; ; ) {

		clrsrc();
		menu();
		printf("���ϴ� �޴��� ��ȣ�� �Է��ϼ���.");
		scanf("%d", &number);
		if (count <= 0 && number != 1) {
			clrsrc();
			printf("------------------------------------\n");
			printf("!         �ڷᰡ �����ϴ�           !\n");
			printf("------------------------------------\n");
			getch();
		}
		else {
			switch (number) {
			case 1:
			{
				clrsrc();
				printf("����������������������������������������������\n");
				printf("��         ������ �̸��� �Է����ּ���.      ��\n");
				printf("����������������������������������������������\n");
				input();
				count++;
				break;
			}
			case 2:
			{
				clrsrc();
				printf("��������������������������������������������\n");
				printf("�� �����Ͻ� ������� ��ȣ�� �Է����ּ���. ��\n");
				printf("��������������������������������������������\n");
				deletedata();
				break;
			}
			case 3:
			{
				clrsrc();
				printf("������������������������������������������������\n");
				printf("��    �̸��� ������������ ���� �Ͻ÷��� 0     ��\n");
				printf("�������������� �����Ͻ÷��� 1�� �Է��� �ּ���.��\n");
				printf("������������������������������������������������\n");
				array();
				break;
			}
			case 4:
			{
				clrsrc();
				printf("����������������������������������������������\n");
				printf("��         ��ü ���� ��� �� �Դϴ�.        ��\n");
				printf("�� ���� �Ͻ÷��� �ƹ� �� �̳� �Է��� �ּ���.��\n");
				printf("����������������������������������������������\n");
				open();
				getch();
				break;
			}
			case 5:
			{
				clrsrc();
				printf("����������������������������������\n");
				printf("��   ������ ��ȣ�� �����ּ���.  ��\n");
				printf("����������������������������������\n");
				modify();
				break;
			}
			case 6:
			{
				clrsrc();
				printf("����������������������������\n");
				printf("��     ���� ���Դϴ�.     ��\n");
				printf("����������������������������\n");

				for (i = 3; i > 0; i--) {
					Sleep(1000);
					printf(".\n");
				}
				exit(1);
			}
			default:
			{
				clrsrc();
				break;
			}
			}
		}
	}
	return 0;
}

// ���� ȭ��
void menu()
{
	printf("����������������������������\n");
	printf("��    �������� ���α׷�   ��\n");
	printf("����������������������������\n");
	printf("1.�Է�\n");
	printf("2.����\n");
	printf("3.����\n");
	printf("4.����\n");
	printf("5.����\n");
	printf("6.����\n");
}

// �й� �̸� ������ �Է��� ���Ͽ� ����
void input()
{
	FILE*score;
	score = fopen("score.txt", "at");
	if (score) {
		printf("�й��� �Է����ּ���.");
		scanf("%s", &stu[0].std);
		printf("�̸��� �Է����ּ���.");
		scanf("%s", &stu[0].name);
		printf("���� ������ �Է����ּ���.");
		scanf("%d", &stu[0].kor);
		printf("���� ������ �Է����ּ���.");
		scanf("%d", &stu[0].eng);
		printf("���� ������ �Է����ּ���.");
		scanf("%d", &stu[0].math);
		fprintf(score, "%s %s %3d %3d %3d\n", stu[0].std, stu[0].name, stu[0].kor, stu[0].eng, stu[0].math);
	}
	fclose(score);
}

// ���ϴ� �л��� ���� ������ ����
void deletedata()
{
	int number5, k, ck;
	open();
	ck = count - 1;
	printf("������ȣ : ");
	scanf("%d", &number5);
	number5 -= 1;
	for (int q = 0; q < ck; q++) {
		if (q >= number5) {
			temp[q] = stu[q + 1];
		}
		else {
			temp[q] = stu[q];
		}
		printf("%03d : %s %s  %3d  %3d  %3d\n", (q + 1), temp[q].std, temp[q].name, temp[q].kor, temp[q].eng, temp[q].math);
	}
	getch();
	printf("����������������������������\n");
	printf("��     �����Ǿ����ϴ�.    ��\n");
	printf("������ ������ ���� �մϴ�.��\n");
	printf("����������������������������\n");
	FILE*score3;
	score3 = fopen("score.txt", "wt");
	if (score3) {
		for (k = 0; k < ck; k++) {
			fprintf(score3, "%s %s %3d %3d %3d\n", temp[k].std, temp[k].name, temp[k].kor, temp[k].eng, temp[k].math);
		}
	}
	fclose(score3);
	Sleep(3000);
}

// �л����� �������� �̸������� ����
void array()
{
	int h, j, g, arr, number4, ci;
	open();
	
	for (; ; ) {
		scanf("%d", &arr);
		if (arr == 0) {
			for (h = 0; h < (count - 1); h++) {
				for (j = h + 1; j < count; j++) {
					ci = stricmp(stu[h].name, stu[j].name);
					if (ci <= (-1)) {
						arra[0] = stu[h];
						stu[h] = stu[j];		
						stu[j] = arra[0];
					}
				}
			}
			break;
		}
		else if (arr == 1) {
			for (h = 0; h < (count - 1); h++) {
				for (j = h + 1; j < count; j++) {
					ci = stricmp(stu[h].name, stu[j].name);
					if (ci >= (1)) {
						arra[0] = stu[h];
						stu[h] = stu[j];
						stu[j] = arra[0];
					}
				}
			}
			break;
		}
		else clrsrc(); continue;
	}
	clrsrc();
	printf("��������������������������������������\n");
	printf("��    ���ĵ� ���� ������Դϴ�.     ��\n");
	printf("�� ���� �Ͻ÷��� 0�� �Է��� �ּ���. ��\n");
	printf("��������������������������������������\n");
	output();
	scanf("%d", &number4);
	if (number4 == 0) {
		clrsrc();
		printf("����������������������������\n");
		printf("������ ������ ���� �մϴ�.��\n");
		printf("����������������������������\n");
		FILE*score4;
		score4 = fopen("score.txt", "wt");
		if (score4) {
			for (g = 0; g < count; g++) {
				fprintf(score4, "%s %s %3d %3d %3d\n", stu[g].std, stu[g].name, stu[g].kor, stu[g].eng, stu[g].math);
			}
		}
		fclose(score4);
		Sleep(3000);
	}
}

// �л����� �������� ����
void open()
{
	int n;
	printf("------------------------------------\n");
	printf("    |  �й�  | �̸� |����|����|����|\n");
	printf("------------------------------------\n");
	FILE*score;
	score = fopen("score.txt", "rt");
	if (score) {
		for (n = 0; ; n++) {
			if (fscanf(score, "%s %s %3d %3d %3d\n", &stu[n].std, &stu[n].name, &stu[n].kor, &stu[n].eng, &stu[n].math) == EOF) {
				break;
			}
			printf("%03d : %s %s  %3d  %3d  %3d\n", (n + 1), stu[n].std, stu[n].name, stu[n].kor, stu[n].eng, stu[n].math);
		}
	}
	count = n;
	fclose(score);
}

// ������ �л��� ���� ����
void modify()
{
	int mnum, anum, z = 0;
	open();
	printf("���� ��ȣ : ");
	scanf("%d", &mnum);
	mnum -= 1;
	modi[0] = stu[mnum];
	for (; ; z++) {
		printf("������ �׸��� ������ �ּ���.\n");
		printf("0.����\n");
		printf("1.�й�\n");
		printf("2.�̸�\n");
		printf("3.����\n");
		printf("4.����\n");
		printf("5.����\n");
		printf("�׸� ��ȣ : ");
		scanf("%d", &anum);
		if (anum == 0) {
			break;
		}
		switch (anum) {
		case 1:
		{
			printf("������ �й��� �Է����ּ���.");
			scanf("%s", &modi[0].std);
			break;
		}
		case 2:
		{
			printf("������ �̸��� �Է����ּ���.");
			scanf("%s", &modi[0].name);
			break;
		}
		case 3:
		{
			printf("������ ���� ������ �Է����ּ���.");
			scanf("%d", &modi[0].kor);
			break;
		}
		case 4:
		{
			printf("������ ���� ������ �Է����ּ���.");
			scanf("%d", &modi[0].eng);
			break;
		}
		case 5:
		{
			printf("������ ���� ������ �Է����ּ���.");
			scanf("%d", &modi[0].math);
			break;
		}
		default:
			continue;
		}
	}
	if (z != 0) {
		stu[mnum] = modi[0];
		clrsrc();
		printf("����������������������������\n");
		printf("������ ������ ���� �մϴ�.��\n");
		printf("����������������������������\n");
		savedata();
		Sleep(3000);
	}
	else {
		clrsrc();
		printf("����������������������������\n");
		printf("������ ������ �����ϴ�.��\n");
		printf("����������������������������\n");
		Sleep(3000);
	}
}

// ����� �л� ���� ����
void output()
{
	int m = 0;
	for (m = 0; m < count; m++) {
		printf("%03d : %s %s  %3d  %3d  %3d\n", (m + 1), stu[m].std, stu[m].name, stu[m].kor, stu[m].eng, stu[m].math);
	}
}

// �Է�,����,������ �л����� ����
void savedata()
{
	int u = 0;
	FILE*score1;
	score1 = fopen("score.txt", "wt");
	if (score1) {
		for (u = 0; u < count; u++) {
			fprintf(score1, "%s %s %3d %3d %3d\n", stu[u].std, stu[u].name, stu[u].kor, stu[u].eng, stu[u].math);
		}
	}
	fclose(score1);
}
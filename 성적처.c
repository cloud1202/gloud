#include "score.h"

// 학생의 학번 이름 성적을 하나의 인수로 선언
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
		printf("원하는 메뉴의 번호를 입력하세요.");
		scanf("%d", &number);
		if (count <= 0 && number != 1) {
			clrsrc();
			printf("------------------------------------\n");
			printf("!         자료가 없습니다           !\n");
			printf("------------------------------------\n");
			getch();
		}
		else {
			switch (number) {
			case 1:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃         성적과 이름을 입력해주세요.      ┃\n");
				printf("┗━━━━━━━━━━━━━━━━━━━━━┛\n");
				input();
				count++;
				break;
			}
			case 2:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃ 삭제하실 사용자의 번호를 입력해주세요. ┃\n");
				printf("┗━━━━━━━━━━━━━━━━━━━━┛\n");
				deletedata();
				break;
			}
			case 3:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃    이름의 오름차순으로 정렬 하시려면 0     ┃\n");
				printf("┃내림차순으로 정렬하시려면 1을 입력해 주세요.┃\n");
				printf("┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
				array();
				break;
			}
			case 4:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("┃         전체 성적 출력 중 입니다.        ┃\n");
				printf("┃ 종료 하시려면 아무 것 이나 입력해 주세요.┃\n");
				printf("┗━━━━━━━━━━━━━━━━━━━━━┛\n");
				open();
				getch();
				break;
			}
			case 5:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━━━━┓\n");
				printf("┃   수정할 번호를 눌러주세요.  ┃\n");
				printf("┗━━━━━━━━━━━━━━━┛\n");
				modify();
				break;
			}
			case 6:
			{
				clrsrc();
				printf("┏━━━━━━━━━━━━┓\n");
				printf("┃     종료 중입니다.     ┃\n");
				printf("┗━━━━━━━━━━━━┛\n");

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

// 메인 화면
void menu()
{
	printf("┏━━━━━━━━━━━━┓\n");
	printf("┃    성적관리 프로그램   ┃\n");
	printf("┗━━━━━━━━━━━━┛\n");
	printf("1.입력\n");
	printf("2.삭제\n");
	printf("3.정렬\n");
	printf("4.보기\n");
	printf("5.수정\n");
	printf("6.종료\n");
}

// 학번 이름 성적을 입력후 파일에 저장
void input()
{
	FILE*score;
	score = fopen("score.txt", "at");
	if (score) {
		printf("학번을 입력해주세요.");
		scanf("%s", &stu[0].std);
		printf("이름을 입력해주세요.");
		scanf("%s", &stu[0].name);
		printf("국어 성적을 입력해주세요.");
		scanf("%d", &stu[0].kor);
		printf("영어 성적을 입력해주세요.");
		scanf("%d", &stu[0].eng);
		printf("수학 성적을 입력해주세요.");
		scanf("%d", &stu[0].math);
		fprintf(score, "%s %s %3d %3d %3d\n", stu[0].std, stu[0].name, stu[0].kor, stu[0].eng, stu[0].math);
	}
	fclose(score);
}

// 원하는 학생의 정보 삭제후 저장
void deletedata()
{
	int number5, k, ck;
	open();
	ck = count - 1;
	printf("삭제번호 : ");
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
	printf("┏━━━━━━━━━━━━┓\n");
	printf("┃     삭제되었습니다.    ┃\n");
	printf("┃변경 내용을 저장 합니다.┃\n");
	printf("┗━━━━━━━━━━━━┛\n");
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

// 학생들의 정보들을 이름순서로 정렬
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
	printf("┏━━━━━━━━━━━━━━━━━┓\n");
	printf("┃    정렬된 성적 출력중입니다.     ┃\n");
	printf("┃ 저장 하시려면 0을 입력해 주세요. ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━┛\n");
	output();
	scanf("%d", &number4);
	if (number4 == 0) {
		clrsrc();
		printf("┏━━━━━━━━━━━━┓\n");
		printf("┃정렬 내용을 저장 합니다.┃\n");
		printf("┗━━━━━━━━━━━━┛\n");
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

// 학생들의 정보들을 열람
void open()
{
	int n;
	printf("------------------------------------\n");
	printf("    |  학번  | 이름 |국어|영어|수학|\n");
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

// 선택한 학생의 정보 수정
void modify()
{
	int mnum, anum, z = 0;
	open();
	printf("수정 번호 : ");
	scanf("%d", &mnum);
	mnum -= 1;
	modi[0] = stu[mnum];
	for (; ; z++) {
		printf("수정할 항목을 선택해 주세요.\n");
		printf("0.종료\n");
		printf("1.학번\n");
		printf("2.이름\n");
		printf("3.국어\n");
		printf("4.영어\n");
		printf("5.수학\n");
		printf("항목 번호 : ");
		scanf("%d", &anum);
		if (anum == 0) {
			break;
		}
		switch (anum) {
		case 1:
		{
			printf("수정할 학번을 입력해주세요.");
			scanf("%s", &modi[0].std);
			break;
		}
		case 2:
		{
			printf("수정할 이름을 입력해주세요.");
			scanf("%s", &modi[0].name);
			break;
		}
		case 3:
		{
			printf("수정할 국어 성적을 입력해주세요.");
			scanf("%d", &modi[0].kor);
			break;
		}
		case 4:
		{
			printf("수정할 영어 성적을 입력해주세요.");
			scanf("%d", &modi[0].eng);
			break;
		}
		case 5:
		{
			printf("수정할 수학 성적을 입력해주세요.");
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
		printf("┏━━━━━━━━━━━━┓\n");
		printf("┃변경 내용을 저장 합니다.┃\n");
		printf("┗━━━━━━━━━━━━┛\n");
		savedata();
		Sleep(3000);
	}
	else {
		clrsrc();
		printf("┏━━━━━━━━━━━━┓\n");
		printf("┃변경 내용이 없습니다.┃\n");
		printf("┗━━━━━━━━━━━━┛\n");
		Sleep(3000);
	}
}

// 저장된 학생 정보 열람
void output()
{
	int m = 0;
	for (m = 0; m < count; m++) {
		printf("%03d : %s %s  %3d  %3d  %3d\n", (m + 1), stu[m].std, stu[m].name, stu[m].kor, stu[m].eng, stu[m].math);
	}
}

// 입력,수정,삭제된 학생정보 저장
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
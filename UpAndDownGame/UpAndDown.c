#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {

	int n = 1, target, count, answer, ceilNum, bottomNum = 1;
	char retry;

	while (n) {
		printf("======================UP and Down!!=====================");
		printf("\n 1 ~ n 까지의 수 n을 입력하세요 : ");
		while (1)
		{
			scanf_s("%d", &ceilNum);
			while (getchar() != '\n');
			if (ceilNum > 1)
				break;
			else
				printf("\n 1보다 큰 자연수를 입력해주세요 : ");
		}

		printf("\n 시도할 횟수를 입력하세요 : ");

		while (1)
		{
			scanf_s("%d", &count);
			while (getchar() != '\n');
			if (count >= 1)
				break;
			else
				printf("\n 0보다 큰 자연수를 입력해주세요 : ");
		}
		printf("\n====================== START ======================\n");

		srand(time(0));
		target = rand() % ceilNum + 1;//1~n까지의 랜덤숫자 추출

		while (count) {
			printf("\n %d이상 ~ %d이하의 숫자를 입력하세요: ", bottomNum, ceilNum);
			scanf_s("%d", &answer);

			while (getchar() != '\n');
			if (answer == target)
			{
				printf("정답입니다\n");
				break;
			}
			else if (answer > ceilNum || answer < bottomNum || answer == 0)
				printf("%d ~ %d 사이의 숫자를 입력해주세요.\n", ceilNum, bottomNum);
			else
			{
				printf("틀렸습니다.");
				count--;
				if (count == 0)
				{
					printf("\n기회가 더이상 없습니다.\n");
					printf("정답은 %d입니다.", target);
					break;
				}
				if (answer > target)
				{
					printf("(DOWN)\n");
					ceilNum = answer;
				}
				else {
					printf("(UP)\n");
					bottomNum = answer;
				}
			}
		}
		fflush(stdin);
		printf("\n 한번 더 하시겠습니까? (y/n) \n");
		while (1)
		{
			scanf_s(" %c", &retry);

			printf("\n");
			if (retry == 'y')
			{
				count = 10;
				ceilNum = 1, bottomNum = 100;
				break;
			}
			else if (retry == 'n')
			{
				printf("게임을 종료합니다.\n");
				n = 0; // 제일 윗단의 while문의 루프를 멈춤
				break;
			}
			else
				printf("y나 n중 하나를 입력하세요.\n");
		}
	}
}	
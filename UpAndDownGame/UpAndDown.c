#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {

	int n = 1, target, count, answer, ceilNum, bottomNum = 1;
	char retry;

	while (n) {
		printf("======================UP and Down!!=====================");
		printf("\n 1 ~ n ������ �� n�� �Է��ϼ��� : ");
		while (1)
		{
			scanf_s("%d", &ceilNum);
			while (getchar() != '\n');
			if (ceilNum > 1)
				break;
			else
				printf("\n 1���� ū �ڿ����� �Է����ּ��� : ");
		}

		printf("\n �õ��� Ƚ���� �Է��ϼ��� : ");

		while (1)
		{
			scanf_s("%d", &count);
			while (getchar() != '\n');
			if (count >= 1)
				break;
			else
				printf("\n 0���� ū �ڿ����� �Է����ּ��� : ");
		}
		printf("\n====================== START ======================\n");

		srand(time(0));
		target = rand() % ceilNum + 1;//1~n������ �������� ����

		while (count) {
			printf("\n %d�̻� ~ %d������ ���ڸ� �Է��ϼ���: ", bottomNum, ceilNum);
			scanf_s("%d", &answer);

			while (getchar() != '\n');
			if (answer == target)
			{
				printf("�����Դϴ�\n");
				break;
			}
			else if (answer > ceilNum || answer < bottomNum || answer == 0)
				printf("%d ~ %d ������ ���ڸ� �Է����ּ���.\n", ceilNum, bottomNum);
			else
			{
				printf("Ʋ�Ƚ��ϴ�.");
				count--;
				if (count == 0)
				{
					printf("\n��ȸ�� ���̻� �����ϴ�.\n");
					printf("������ %d�Դϴ�.", target);
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
		printf("\n �ѹ� �� �Ͻðڽ��ϱ�? (y/n) \n");
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
				printf("������ �����մϴ�.\n");
				n = 0; // ���� ������ while���� ������ ����
				break;
			}
			else
				printf("y�� n�� �ϳ��� �Է��ϼ���.\n");
		}
	}
}	
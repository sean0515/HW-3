#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST };
int rollDice(void);

int main(void)
{
	int sum;
	int myPoint;

	enum Status gameStatus;

	srand(time(NULL));
	sum = rollDice();

	switch (sum)
	{
	case 7:
		gameStatus = WON;
		break;

	case 11:
		gameStatus = WON;
		break;

	case 2:
		gameStatus = LOST;
		break;

	case 3:
		gameStatus = LOST;
		break;

	case 12:
		gameStatus = LOST;
		break;

	default:
		gameStatus = CONTINUE;
		myPoint = sum;
		printf("Point is %d\n", myPoint);
		break;
	}

	while (gameStatus == CONTINUE)
	{
		sum = rollDice();
		if (sum == 7)
		{
			gameStatus = LOST;
		}
		if (sum == myPoint)
		{
			gameStatus = WON;
		}
	}

	if (gameStatus == WON)
	{
		printf("Player wins\n");
	}
	else
	{
		printf("Player loses\n");
	}

	system("pause");
	return 0;
}

int rollDice(void)
{
	int die1;
	int die2;
	int worksum;

	die1 = 1 + (rand() % 6);
	die2 = 1 + (rand() % 6);
	worksum = die1 + die2;
	printf("Player rolled %d + %d = %d\n", die1, die2, worksum);
	return worksum;
}


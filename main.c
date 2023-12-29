#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	printf("*****************************\n");
	printf("* Welcome to the Guess Game *\n");
	printf("*****************************\n\n");

	int seed = time(0);
	srand(seed);

	int
			secret_number = rand() % 100,
			guess,
			attempts_amount = 5;

	double points = 1000;

	for (int i = 1; i <= attempts_amount; i++)
	{
		printf("Attempt %d\n", i);
		printf("What is your guess? ");
		scanf("%d", &guess);

		if (guess < 0)
		{
			printf("You can't guess negative numbers!\n\n");
			i--;
			continue;
		}

		if (secret_number == guess)
		{
			printf("Congratulations! You got it right!\n\n");
			printf("You got it right in %d attempts!\n", i);
			printf("Total points: %.1f\n", points);
			break;
		}
		else
		{
			printf("Sorry, you got it wrong!\n\n");

			if (guess > secret_number)
			{
				printf("Your guess is higher than the secret number.\n");
			}
			else
			{
				printf("Your guess is lower than the secret number.\n");
			}
		}

		double lost_points = fabs((guess - secret_number) / (double)2);
		points -= lost_points;
	}

	printf("End of game!\n");
}

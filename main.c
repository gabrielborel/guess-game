#include <stdio.h>
#include <math.h>

void main()
{
	printf("*****************************\n");
	printf("* Welcome to the Guess Game *\n");
	printf("*****************************\n\n");

	int
			secret_number = 50,
			guess,
			attempts_amount = 0;

	double points = 1000.0;

	while (1)
	{
		printf("Attempt %d\n", attempts_amount + 1);
		printf("What is your guess? ");
		scanf("%d", &guess);

		if (guess < 0)
		{
			printf("You can't guess negative numbers!\n\n");
			continue;
		}

		if (secret_number == guess)
		{
			printf("Congratulations! You got it right!\n\n");
			printf("You got it right in %d attempts!\n", attempts_amount + 1);
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

		attempts_amount++;
		double lost_points = fabs((guess - secret_number) / 2.0);
		points = points - lost_points;
	}
}

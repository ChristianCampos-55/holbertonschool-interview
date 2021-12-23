#include "holberton.h"

/**
 * main - Entry point function
 * @argc: argument counter
 * @argv: argument vector
 * Return: 1, or zilch upon failure
 */

int main(int argc, char **argv)
{
	int holder_a, holder_b = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (holder_a = 1; argv[holder_a]; holder_a++)
	{
		for (holder_b = 0; argv[holder_a][holder_b]; holder_b++)
		{
			if (argv[holder_a][holder_b] < '0' || argv[holder_a][holder_b] > '9')
			{
				printf("Error\n");
				exit(98);

			}
		}
	}
	if (*argv[1] == '0' || *argv[2] == '0')
		printer(NULL, 0);

	if (!multiplier(argv[1], argv[2]))
		return (1);

	return (0);
}

/**
 * multiplier - miltiplies two numbers
 * @vect_a: int in string
 * @vect_b: int in string
 * Return: 1, or zilch upon failure
 */

int multiplier(char *vect_a, char *vect_b)
{
	int s1, s2, adder, exp_a, exp_b = 0;
	int *vect_c;
	int i, j;

	s1 = strlen(vect_a);
	s2 = strlen(vect_b);

	vect_c = calloc(s1 + s2, sizeof(s1 + s2));

	if (!vect_c)
		return (0);

	for (i = s1 - 1; i >= 0; i--)
	{
		exp_a = vect_a[i] - '0';
		for (j = s2 - 1; j >= 0; j--)
		{
			exp_b = vect_b[j] - '0';
			adder = (exp_a * exp_b) + vect_c[i + j + 1];
			vect_c[i + j] += adder / 10;
			vect_c[i + j + 1] = adder % 10;
		}
	}

	printer(vect_c, s1 + s2);
	free(vect_c);
	return (1);
}

/**
 * printer - prints final number
 * @vect_c: number to print
 * @s: size of number
 */

void printer(int *vect_c, int s)
{
	int holder = 0;

	if (!vect_c && !s)
	{
		printf("0\n");
		exit(0);
	}

	while (vect_c[holder] == 0)
		holder++;

	for (; holder < s; holder++)
		printf("%d", vect_c[holder]);

	printf("\n");
}

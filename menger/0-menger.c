#include "menger.h"

/**
 *menger - draws a 2D Menger Sponge
 *@level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int len, i, j, n;

	if (level < 0)
		return;

	len = (int) pow(3, level);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			char print_char = '#';

			for (n = 1; n < len; n *= 3)
			{
				if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
				{
					print_char = ' ';
					break;
				}
			}

			putchar(print_char);
		}

		putchar('\n');
	}
}

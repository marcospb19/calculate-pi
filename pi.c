#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <limits.h>


/**
 * Little crazy project.
 *
 * Explanation if pending on each function, as I don't know if anyone
 * is going to read this, I'm not wasting my time, otherwise, leave an
 * issue on GitHub asking for it and I'll be happy to do it :D.
 *
 * So... really... don't expect to understand the function
 *     void optimized_64bit_linear_half_quadrant_method()
 *
 * After 8 months of programming, in 2018, I saw this video about PI
 *     https://www.youtube.com/watch?v=5cNnf_7e92Q
 *
 * Where Daniel Shiffman applies the Monte Carlo method to calculate PI,
 * but it's not meant to be accurate neither deterministic, it's just random.
 *
 * My approach addapt the formula (circle inside of square) using matrices
 * with fixed sizes to calculate PI. This method isn't as near as efficient
 * as any of the others well-known and famous ones, but I find it very
 * interesting that I could make this work and calculate some digits of PI
 * using a given formula, and several incredible optimizations.
 *
 * EDIT: OMG there's also this optimization while calculating consecutive
 * quadratic numbers that I discovered in highschool, oh man, it really
 * feels great to use that little snippet of childhood (teenager me?)
 * for something today (I mean, actually, it has only been 4 years HMMM).
 * I don't know, this was not meant to be an optimization (I wasn't even
 * into programming) but instead just a trick to be faster on exams and
 * also teach people how quadratic equations growth are predictably related
 * to odd numbers. (this optimization decreased from 8.5s to 5.3s)
 *
 * Maybe I'm getting crazy or something? xD
 */


void simple_quadratic_method()
{
	const int MAXN = sqrt(INT_MAX) - 1;
	const int DIST = MAXN * MAXN;

	const int OUTSIDE = MAXN * MAXN;
	int inside = 0;

	printf("MAXN = %d\n" , MAXN);
	printf("DIST = %d\n" , DIST);

	for (int i = 1 ; i < MAXN ; i++)
	{
		for (int j = 0 ; j < MAXN ; j++)
		{
			int temp = i * i;
			if (temp + j * j < DIST)
			{
				inside++;
			}
		}
	}

	printf("points counted inside = %d\n" , ++inside);
	printf("%.20lf\n" , (double)(inside) / OUTSIDE * 4);
}


void optimized_64bit_linear_half_quadrant_method()
{
	const uint64_t MAXN = sqrt(ULONG_MAX) - 1;
	const uint64_t DIST = MAXN * MAXN;

	const uint64_t OUTSIDE = MAXN * MAXN;
	uint64_t inside = 0;

	printf("MAXN = %ld\n" , MAXN);
	printf("DIST = %ld\n" , DIST);

	uint64_t x = 1;
	uint64_t y = MAXN;

	uint64_t x_squared = x * x;
	uint64_t y_squared = y * y;

	while (x < y)
	{
		if (x_squared + y_squared > DIST)
		{
			y--;
			y_squared -= (y + y + 1);
		}

		x_squared += (x + x + 1);
		x++;

		inside += y - x;
	}

	inside -= x;

	printf("points counted inside = %ld\n" , ++inside);
	printf("MAXN = %ld\n" , MAXN);
	printf("x = y = %ld\n" , x);
	printf("%.20lf\n" , (double)(inside) / OUTSIDE * 8);
}


int main()
{
	// O(n²) with int32_t
	// simple_quadratic_method();

	// O(n) with int64_t (takes ~5.6s)
	optimized_64bit_linear_half_quadrant_method();

	// Unimplemented, will never finish on my computer
	// optimized_128bit_linear_half_quadrant_method();
}

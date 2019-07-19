#include "stdio.h"
#include "stdlib.h"


/** This function is calculating N factorial ...
*    @param The times of factorial
*    @return Result
*
*    Description:
*	 N! = 1 * 2 * 3 * 4 * 5 .... * N
*/
int factorial(int N)
{
	if (N == 1)
		return 1;

	// decreasing
	return (N*factorial(N-1));
}

/** This function is calculating arithmetic series ...
*    @param The last terms
*    @return Result
*
*    Description:
*	 1 + 2 + 3 + 4 + 5 ....
*/
int arithmetic(int factor)
{
	if(factor == 1)
		return 1;

	// decreasing
	return( factor + arithmetic(factor - 1));
}

/** This function is calculating the different arithmetic series...
*    @param The last terms
*    @return Result
*
*    Description:
*	 1 - 2 + 3 - 4 + 5 - 6 ....
*/
int different_arithmetic(int factor)
{
	if(factor == 1)
		return 1;

	// determine the term position
	factor = (factor%2 == 0) ? -factor:factor;

	return( factor + arithmetic(factor - 1));
}

/** This function is calculating the Fibonacci number...
*    @param The last terms
*    @return Result
*
*	Description:
*	0, 1, 1 ,2, 3, 5 .....
*
*/
int fibonacci(int sum)
{
	if (sum == 1)
		return 0;
	else if(sum == 2 | sum == 3)
		return 1;
	else {
		// decreasing
		return (fibonacci(sum-1) + fibonacci(sum-2));
	}
}


/** This function is calculating the GCD of two integers by Euclidean algorithm...
*    @param integer 1
*    @param integer 2
*    @return GCD
*
*    Idea:
*	 1. GCD(A,0) = A and GCD(B,0) = B
*	 2. If A = B⋅Q + R and B≠0 then GCD(A,B) = GCD(B,R)
*	    where Q is an integer, R is an integer between 0 and B-1
*/
int euclidean_division (int a, int b)
{
	if(a%b == 0)
		return 1;
	else
		return euclidean_division(b, a%b);
}

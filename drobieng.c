/*The program calculates the sum, difference (minus), product (multiplication) and quotient (division) of fractions (a/b) and (c/d) v1.0 by Keksovname*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int fraction1, fraction2, fraction3, fraction4, temporarya, temporaryb, wholepart, fractionalpart, itemp, i,integer1,integer2,temporary,temporary2;
	volatile char action;
	printf("Enter the whole part (0 if there is none), space fraction (of the form 5/4), space (sign + - * or /) space the whole part (0 if not present) and the second fraction (of the form 3/8)\n");
	scanf("%d %d/%d %c %d %d/%d",&integer1,&fraction1, &fraction2,&action,&integer2,&fraction3, &fraction4);
	printf("You entered %d\n",action);
	printf("You entered %d %d/%d %d %d/%d\n",integer1, fraction1, fraction2,integer2, fraction3, fraction4);
	if(integer1>0)
	{
		temporary =integer1*fraction2+fraction1;
		fraction1=temporary;
	}
	if(integer2>0)
	{
		temporary2=integer2*fraction4+fraction3;
		fraction3=temporary2;
	}
	temporarya = fraction1 * fraction4;	//temporary variables for calculation
	temporaryb = fraction2 * fraction4;	//temporary variables for calculation
	fraction3 = fraction3 * fraction2;	//calculate
	fraction4 = fraction4 * fraction2;	//calculate
	printf("a=%d/b=%d c=%d/d=%d\n", temporarya, temporaryb, fraction3, fraction4);
	int x=action;
	if(x==43)//values ​​in scanf %c but I can't compare string to string! Therefore, I compare it with the ASCII value
	{
		itemp = temporarya + fraction3;
	}
	if(x==45)//if the sign is minus then minus
	{
		itemp=temporarya-fraction3;
	}
	if(x==42)
	{
		itemp=temporarya*fraction3;
		temporaryb=temporaryb*fraction4;
	}
	if(x==47)
	{
		int temporary3=fraction3;
		fraction3=fraction4;
		fraction4=temporary3;
		itemp=temporarya*fraction3;
		temporaryb=temporaryb*fraction4;
	}
	int gcd(int a, int b)	//Euclidean algorithm
	{
		int c;
		while (b)
		{
			c = a % b;
			a = b;
			b = c;
		}

		return abs(a);
	}

	i = gcd(itemp, temporaryb);	//Euclidean algorithm, find the total number for division.
	printf("i=%d\n", i);	//what is the number to make the numerator and denominator.
	if (i > 0)
	{
		itemp = itemp / i;	//divide the numerator by the total number for division
		temporaryb = temporaryb / i;	//divide the denominator by the total number for division
	}

	wholepart = itemp / temporaryb;	//select the whole part
	printf("Whole part=%d\n", wholepart);	//print the whole part
	fractionalpart = itemp % temporaryb;
	if(fractionalpart==0)
	{
		printf("The result is equal to the whole part=%d", wholepart);
	}
	else
	{
		printf("Numerator=%d\n", fractionalpart);
		printf("The result is equal to the whole part=%d %d/%d", wholepart, fractionalpart, temporaryb);
	}	//We display the result

	return 0;
}

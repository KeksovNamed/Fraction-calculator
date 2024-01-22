/*The program calculates the sum, difference (minus), product (multiplication) and quotient (division) of fractions (a/b) and (c/d) v1.1 by Keksovname*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int fraction1, fraction2, fraction3, fraction4, temporarya, temporaryb, wholepart, fractionalpart, itemp, i,integer1,integer2,temporary,temporary2;
	volatile char action;
	printf("Enter the whole part (0 if there is none), space fraction (of the form 5/4), space (sign + - * or /) space the whole part (0 if not present) and the second fraction (of the form 3/8)\n");
	scanf("%d %d/%d %c %d %d/%d",&integer1,&fraction1, &fraction2,&action,&integer2,&fraction3, &fraction4);
	printf("You entered %d\n",action);
	printf("You entered %d %d/%d %d %d/%d\n",integer1, fraction1, fraction2,integer2, fraction3, fraction4);
	if(integer1>0) {
		temporary =integer1*fraction2+fraction1;
		fraction1=temporary;
		printf("Numerator of the first fraction =%d\n",fraction1);

	}
	if(integer2>0) {
		temporary2=integer2*fraction4+fraction3;
		fraction3=temporary2;
		printf("Numerator of the second fraction =%d\n",fraction3);
	}
	printf("Приведение к общему знаменателю\n");
	temporarya = fraction1 * fraction4;	//temporary variables for calculation
	printf("%d*%d=%d\n",fraction1,fraction4,temporarya);
	printf("%d*%d=%d\n",fraction2,fraction4,fraction4*fraction2);
	temporaryb = fraction2 * fraction4;	//temporary variables for calculation
	printf("%d*%d=%d\n",fraction3,fraction2,fraction3*fraction2);
	printf("%d*%d=%d\n",fraction4,fraction2,fraction2 * fraction4);
	fraction3 = fraction3 * fraction2;	//calculate
	fraction4 = fraction4 * fraction2;	//calculate
	printf("The result is\n");
	printf("%d/%d %d/%d\n", temporarya, temporaryb, fraction3, fraction4);
	int x=action;
	if(x==43) {//if the sign is plus then plus
		printf("Addition\n");
		itemp = temporarya + fraction3;
		printf("%d+%d=%d/%d\n",temporarya,fraction3,temporarya + fraction3,fraction4);
	}
	if(x==45) {
		//if the sign is minus then minus
		printf("Subtraction\n");
		itemp=temporarya-fraction3;
		printf("%d=%d-%d\n",itemp,temporarya-fraction3);
		printf("Result =%d/%d\n",itemp,temporaryb);
	}
	if(x==42) { // if the multiplication sign
		printf("Multiplication\n");
		itemp=temporarya*fraction3;
		printf("%d=%d*%d\n",itemp,temporarya,fraction3);
		temporaryb=temporaryb*fraction4;
		printf("%d/%d\n",itemp,temporaryb);
	}
	if(x==47) { //if the sign is division
		printf("Деление\n");
		int temporary3=fraction3;
		fraction3=fraction4;
		fraction4=temporary3;
		itemp=temporarya*fraction3;
		printf("%d=%d*%d\n",itemp,temporarya,fraction3);
		temporaryb=temporaryb*fraction4;
		printf("%d=%d*%d\n",temporaryb,temporaryb,fraction4);
	}
	int gcd(int a, int b) {	//Euclidean algorithm
		int c;
		while (b) {
			c = a % b;
			a = b;
			b = c;
		}

		return abs(a);
	}

	i = gcd(itemp, temporaryb);	//Euclidean algorithm, find the total number for division.
	printf("i=%d\n", i);	//what is the number to make the numerator and denominator.
	if (i > 0) {
		printf("Selecting a whole part\n");
		itemp = itemp / i;	//divide the numerator by the total number for division
		temporaryb = temporaryb / i;	//divide the denominator by the total number for division
	}

	wholepart = itemp / temporaryb;	//select the whole part
	printf("Whole part =%d=%d/%d\n",wholepart,itemp,temporaryb);
	fractionalpart = itemp % temporaryb;
	printf("The fractional part is equal to %d=%d remainder of the division %d\n",fractionalpart,itemp,temporaryb);
	if(fractionalpart==0) {
		printf("The result is equal to the whole part=%d", wholepart);
	} else {
		printf("Numerator=%d\n", fractionalpart);//we output the numerator.
		printf("The result is equal to the whole part=%d %d/%d", wholepart, fractionalpart, temporaryb);	//Let's see the result
	}

	return 0;
}

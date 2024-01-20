/*Программа вычисляет сумму,разность(минус), произведение(умножение) и частное(деление) дробей (a/b) и (c/d) v1.0 by Keksovname*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int fraction1, fraction2, fraction3, fraction4, temporarya, temporaryb, wholepart, wholepart2, itemp, i,integer1,integer2,temporary,temporary2;
	volatile char action;
	printf("Введите целую часть(0 если её нет) пробел дробь(вида 5/4) пробел(знак + - * или /)пробел целую часть(0 если нету) и второю дробь(вида 3/8)\n");
	scanf("%d %d/%d %c %d %d/%d",&integer1,&fraction1, &fraction2,&action,&integer2,&fraction3, &fraction4);
	printf("Вы ввели %d\n",action);
	printf("Вы ввели %d %d/%d %d %d/%d\n",integer1, fraction1, fraction2,integer2, fraction3, fraction4);
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
	temporarya = fraction1 * fraction4;	//временные переменные для вычисления
	temporaryb = fraction2 * fraction4;	//временные переменные для вычисления
	fraction3 = fraction3 * fraction2;	//вычисляем
	fraction4 = fraction4 * fraction2;	//вычисляем
	printf("a=%d/b=%d c=%d/d=%d\n", temporarya, temporaryb, fraction3, fraction4);	//tmpa=a tmpb=b а c и d без изменений
	int x=action;
	if(x==43)//значения в scanf %c но я не могу сравнить строку со строкой! Поэтому сравниваю со значением ASCII
	{
		itemp = temporarya + fraction3;
	}
	if(x==45)//если знак минус тогда минус
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
	int gcd(int a, int b)	//алгоритм Евклида
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

	i = gcd(itemp, temporaryb);	//алгоритм Евклида,находим общее число для деления.
	printf("i=%d\n", i);	//чему равно число для делания числителя и знаменателя.
	if (i > 0)
	{
		itemp = itemp / i;	//делим числитель на общее число для деления
		temporaryb = temporaryb / i;	//делим знаменатель на общее число для деления
	}

	wholepart = itemp / temporaryb;	//выделяем целую часть
	printf("Целая часть=%d\n", wholepart);	//печатаем целую часть
	wholepart2 = itemp % temporaryb;
	if(wholepart2==0)
	{
		printf("Результат равен целая часть=%d", wholepart);
	}
	else
	{
		printf("Числитель=%d\n", wholepart2);//выводим числитель.
		printf("Результат равен целая часть=%d %d/%d", wholepart, wholepart2, temporaryb);	//Вывовим результат
	}

	return 0;
}

/*Программа вычисляет сумму,разность(минус), произведение(умножение) и частное(деление) дробей (a/b) и (c/d) v1.1 by Keksovname*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	int fraction1, fraction2, fraction3, fraction4, temporarya, temporaryb, wholepart, fractionalpart, itemp, i,integer1,integer2,temporary,temporary2;
	volatile char action;
	printf("Введите целую часть(0 если её нет) пробел дробь(вида 5/4) пробел(знак + - * или /)пробел целую часть(0 если нету) и второю дробь(вида 3/8)\n");
	scanf("%d %d/%d %c %d %d/%d",&integer1,&fraction1, &fraction2,&action,&integer2,&fraction3, &fraction4);
	printf("Вы ввели %d\n",action);
	printf("Вы ввели %d %d/%d %d %d/%d\n",integer1, fraction1, fraction2,integer2, fraction3, fraction4);
	if(integer1>0) {
		temporary =integer1*fraction2+fraction1;
		fraction1=temporary;
		printf("Числитель первой дроби =%d\n",fraction1);

	}
	if(integer2>0) {
		temporary2=integer2*fraction4+fraction3;
		fraction3=temporary2;
		printf("Числитель второй дроби =%d\n",fraction3);
	}
	printf("Приведение к общему знаменателю\n");
	temporarya = fraction1 * fraction4;	//временные переменные для вычисления
	printf("%d*%d=%d\n",fraction1,fraction4,temporarya);
	printf("%d*%d=%d\n",fraction2,fraction4,fraction4*fraction2);
	temporaryb = fraction2 * fraction4;	//временные переменные для вычисления
	printf("%d*%d=%d\n",fraction3,fraction2,fraction3*fraction2);
	printf("%d*%d=%d\n",fraction4,fraction2,fraction2 * fraction4);
	fraction3 = fraction3 * fraction2;	//вычисляем
	fraction4 = fraction4 * fraction2;	//вычисляем
	printf("Результат равен\n");
	printf("%d/%d %d/%d\n", temporarya, temporaryb, fraction3, fraction4);	//tmpa=a tmpb=b а c и d без изменений
	int x=action;
	if(x==43) {//если знак плюс тогда плюс
		printf("Сложение\n");
		itemp = temporarya + fraction3;
		printf("%d+%d=%d/%d\n",temporarya,fraction3,temporarya + fraction3,fraction4);
	}
	if(x==45) {
		//если знак минус тогда минус
		printf("Вычитание\n");
		itemp=temporarya-fraction3;
		printf("%d=%d-%d\n",itemp,temporarya-fraction3);
		printf("Результат =%d/%d\n",itemp,temporaryb);
	}
	if(x==42) { // если знак умножение
		printf("Умножение\n");
		itemp=temporarya*fraction3;
		printf("%d=%d*%d\n",itemp,temporarya,fraction3);
		temporaryb=temporaryb*fraction4;
		printf("%d/%d\n",itemp,temporaryb);
	}
	if(x==47) { //если знак деление
		printf("Деление\n");
		int temporary3=fraction3;
		fraction3=fraction4;
		fraction4=temporary3;
		itemp=temporarya*fraction3;
		printf("%d=%d*%d\n",itemp,temporarya,fraction3);
		temporaryb=temporaryb*fraction4;
		printf("%d=%d*%d\n",temporaryb,temporaryb,fraction4);
	}
	int gcd(int a, int b) {	//алгоритм Евклида
		int c;
		while (b) {
			c = a % b;
			a = b;
			b = c;
		}

		return abs(a);
	}

	i = gcd(itemp, temporaryb);	//алгоритм Евклида,находим общее число для деления.
	printf("i=%d\n", i);	//чему равно число для делания числителя и знаменателя.
	if (i > 0) {
		printf("Выделение целой части\n");
		itemp = itemp / i;	//делим числитель на общее число для деления
		temporaryb = temporaryb / i;	//делим знаменатель на общее число для деления
	}

	wholepart = itemp / temporaryb;	//выделяем целую часть
	printf("Целая часть =%d=%d/%d\n",wholepart,itemp,temporaryb);
	fractionalpart = itemp % temporaryb;
	printf("Дробная часть равна %d=%d остаток от деления %d\n",fractionalpart,itemp,temporaryb);
	if(fractionalpart==0) {
		printf("Результат равен целая часть=%d", wholepart);
	} else {
		printf("Числитель=%d\n", fractionalpart);//выводим числитель.
		printf("Результат равен целая часть=%d %d/%d", wholepart, fractionalpart, temporaryb);	//Вывовим результат
	}

	return 0;
}

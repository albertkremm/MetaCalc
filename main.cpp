#include <iostream>
#include <math.h>
#include "clearscreen.h"
using namespace std;

void welcome()
{
	clearScreen();
	cout << "Калькулятор Металла\n";
	cout << "Альберт Кремм, 2023\n\n";
}

int metalType()
{
	bool typesel = true;

	cout << "---------------\n";
	cout << "ВЫБОР МАТЕРИАЛА\n";
	cout << "---------------\n\n";

	cout << "1. Черная сталь \n"
		<< "2. Нержавеющая сталь \n"
		<< "3. Алюминий\n"
		<< "4. Черная сталь (по AJAN)\n"
		<< "5. Ввести значение вручную.\n"
		<< endl
		<< "Ваш выбор: ";

	int t;
	int maxMenuIndex = 5;

	while (typesel)
	{
		cin >> t;
		cout << endl;

		if ((t >= 1 && t <= maxMenuIndex))
		{
			typesel = false;
		}
		else
		{
			cout << "Ничего не выбрано!"
			<< " Выберите тип металла из списка!\n";
		}
	}
	return t;
}

double getDensity(int metalType)
{
	double density;

	switch (metalType)
	{
	case 1:
		density = 7.85;
		break;

	case 2:
		density = 8;
		break;

	case 3:
		density = 2.7;
		break;

	case 4:
		density = 7.8675;
		break;

	case 5:
		cout << "Введите значение плотности: ";
		cin >> density;
		cout << endl;
		break;

	default:
		cout << "Ошибка! Выберите тип металла из списка\n";
	}
	return density;
}

double rectangleCalc(double density)
{
	double thick, lenght, wide, count, divide, weight;
	divide = 1000000;

	welcome();

	cout << "-------------\n";
	cout << "ПРЯМОУГОЛЬНИК\n";
	cout << "-------------\n\n";

	cout << "Толщина: ";
	cin >> thick;
	cout << "Длина: ";
	cin >> lenght;
	cout << "Ширина: ";
	cin >> wide;
	cout << "Количество: ";
	cin >> count;
	cout << endl;

	weight = (thick * lenght * wide * density * count) / divide;


	if (weight < 1000)
	{
	cout << "ИТОГ: \n";
	cout << weight << " кг \n";
	}

	if (weight >= 1000)
	{
	cout << "ИТОГ: \n";
	cout << weight / 1000 << " тонн \n";
	}

	welcome();

	cout << "--------------------------\n";
	cout << "РАСЧЕТ СТОИМОСТИ МАТЕРИАЛА\n";
	cout << thick << "x";
	cout << lenght << "x"; 
	cout << wide << "мм - "; 
	cout << count << "шт - "; 

	if (weight < 1000)
	{
	cout << weight << "кг\n";
	}

	if (weight > 1000)
	{
	cout << weight / 1000 << "тонн \n"; 
	}

	cout << "--------------------------\n\n";
	return weight;
}

double roundCalc(double density) 
{
	double thick, radius, diameter, count, divide, weight, pi, square;
	divide = 1000000;
	pi = 3.14159265358;

	welcome();

	cout << "----";
	cout << "\nКРУГ\n";
	cout << "----\n\n";

	cout << "Толщина: ";
	cin >> thick;

	cout << "Диаметр: ";
	cin >> diameter;

	cout << "Количество: ";
	cin >> count;
	cout << endl;

	radius = diameter / 2;
	square = pow(radius, 2);
	weight = density * (count * thick * square * pi) / divide;

	if (weight < 1000)
	{
	cout << weight << "кг\n";
	}

	if (weight > 1000)
	{
	cout << weight / 1000 << "тонн \n"; 
	}
	cout << "ИТОГ: \n"
	<< weight << "кг \n" 
	<< weight / 1000 << "тонн\n";
		
	welcome();

	cout << "--------------------------\n";
	cout << "РАСЧЕТ СТОИМОСТИ МАТЕРИАЛА\n";
	cout << thick << " мм, D = "
	<< diameter << " мм, "
	<< count << " шт  - ";

	if (weight < 1000)
	{
	cout << weight << "кг\n";
	}

	if (weight > 1000)
	{
	cout << weight / 1000 << "тонн \n"; 
	}

	cout << "--------------------------\n\n";

	return weight;
}

int inputForm()
{
	welcome();
	bool formsel = true;
	cout << "---------------------\n"
	<< "ВЫБОР ФОРМЫ МАТЕРИАЛА\n"
	<< "---------------------\n\n";  

	cout << "1. Прямоугольник \n"
		<< "2. Круг \n"
		<< endl
		<< "Ваш выбор: ";
	int f;
	int maxMenuIndex = 2;

	while (formsel)
	{
		cin >> f;
		cout << endl;

		if ((f >= 1) && (f <= maxMenuIndex))
		{
			formsel = false;
		}
		else
		{
			cout << "Ничего не выбрано\n";
		}

		
	}
	
	return f;
}

double metalPrice(double weight)
{
	double mprice, kgprice;

	cout << "Введите цену за кг металла: ";
	cin >> kgprice;

	if (weight < 100 && weight < 500)
	{
		mprice = weight * kgprice * 3;
	}

	if (weight >= 500 && weight < 1000)
	{
		mprice = weight * kgprice * 2;
	}

	if (weight >= 1000)
	{
		mprice = weight * kgprice;
	}

	if (mprice < 1000000)
	{
		cout << "Стоимость материала: ";
		cout << mprice << " руб.\n";
	}

	if (mprice >= 1000000)
	{
		cout << "Стоимость материала: ";
		cout << mprice / 1000000 << " млн.руб\n";
	}

	return mprice;
	return weight;
}

double cutPrice()
{
	double h, min, sec, totalmin, cutprice;

	cout << "----------------------";
	cout << "\nРАСЧЕТ СТОИМОСТИ РЕЗКИ\n";
	cout << "----------------------\n\n"; 
	cout << "Введите время резки: \n";
	cout << "Часов: ";
	cin >> h;
	cout << "Минут: ";
	cin >> min;
	cout << "Секунд: ";
	cin >> sec;

	totalmin = (h * 60) + min + (sec / 60);
	cutprice = (totalmin / 0.85) * 130;
	
	if (cutprice < 1000000)
	{
		cout << "\nСтоимость резки: " << cutprice << " руб.\n\n";
	}

	if (cutprice > 1000000)
	{
		cout << "\nСтоимость резки: " 
		<< cutprice / 1000000 << "млн. руб\n\n";
	}
	return cutprice;
}

double totalPrice(double mprice, double cutprice)
{
	double total;
	total = mprice + cutprice;

	cout << "-------------------------------------\n";
	cout << "ИТОГОВАЯ СТОИМОСТЬ ЗАКАЗА: ";

	if (total < 1000000)
	{
		cout << total << " руб.\n";
	}

	if (total > 1000000)
	{
		cout << total / 1000000 << " млн. руб. \n";
	}

	cout << "--------------------------------------\n\n";
	return total;
}

int endScreen()
{
	int end;

	cout << "1. Повторить\n"
		 << "2. Выйти\n"
		 << endl
		 << "Ваш выбор: ";
	cin >> end;

	return end;
}

int main()
{
	bool work = true;
	double weight;

	while (work)
	{
		setlocale(LC_ALL, "Russian");
		welcome();
		int typeMetal = metalType();
		double density = getDensity(typeMetal);
		int metalForm = inputForm();

		switch (metalForm)
		{
		case 1:
			weight = rectangleCalc(density);
			break;

		case 2:
			weight = roundCalc(density);
			break;

		default:
			cout << "Ошибка! Выберите форму металла из списка!" << endl;
			break;
		}

		double mprice = metalPrice(weight);
		double cprice = cutPrice();
		double total = totalPrice(mprice, cprice);

		int end = endScreen();
		
		switch (end)
		{
		case 1:
			work = true;
			break;
		case 2:
			work = false;
			break;
		default:
			cout << "Ну ты че...\n";
		}
	}
}


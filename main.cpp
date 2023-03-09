#include <iostream>
#include <math.h>
#include "clearscreen.h"
using namespace std;

void welcome()
{
	clearScreen();
	cout << "Калькулятор Металла\n";
	cout << "Альберт Кремм, ООО "ТехМет", 2022 - 2023\n";
	cout << "------------------------\n\n";
}

int metalType()
{
	bool typesel = true;

	cout << "Выберите тип металла: \n"
		<< "1. Черная сталь \n"
		<< "2. Нержавеющая сталь \n"
		<< "3. Алюминий\n"
		<< "4. Черная сталь (по AJAN)\n"
		<< "5. Ввести значение вручную.\n"
		<< "-----------\n"
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
			cout << "Ничего не выбрано! Выберите тип металла из списка!\n";
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

		cout << "Введите размеры в мм: \n\n";
		cout << "Толщина : ";
		cin >> thick;
		cout << "Длина: ";
		cin >> lenght;
		cout << "Ширина: ";
		cin >> wide;
		cout << "Количество: ";
		cin >> count;
		cout << endl;

		weight = (thick * lenght * wide * density * count) / divide;

		cout << "ИТОГ: \n";
		cout << weight << " кг \n"
			<< weight / 1000 << "тонн\n\n";

		return weight;
}

double roundCalc(double density) 
{
		double thick, radius, diameter, count, divide, weight, pi, square;
		divide = 1000000;
		pi = 3.14159265358;

		welcome();

		cout << "Введите размеры в миллиметрах:\n\n";

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

		cout << "ИТОГ: \n"
			<< weight << "кг \n"
			<< weight / 1000 << "тонн\n\n";

		return weight;
}

int inputForm()
{
	bool formsel = true;
	welcome();
	cout << "Выберите форму листа: \n"
		<< "1. Прямоугольник \n"
		<< "2. Круг \n"
		<< "----------\n"
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

		cout << mprice << " руб. | "
			 << mprice / 1000000 << "млн. руб. \n";
	}

	if (weight >= 500 && weight < 1000)
	{
		mprice = weight * kgprice * 2;

		cout << mprice << " руб. | "
			 << mprice / 1000000 << "млн. руб. \n";
	}

	if (weight >= 1000)
	{
		mprice = weight * kgprice;
		cout << mprice << " руб. | "
			 << mprice / 1000000 << "млн. руб. \n";
	}

	return mprice;
	return weight;
}

double cutPrice()
{
	double h, min, sec, totalmin, cutprice;

	cout << "\nВведите время резки: \n";
	cout << "Часов: ";
	cin >> h;
	cout << "Минут: ";
	cin >> min;
	cout << "Секунд: ";
	cin >> sec;

	totalmin = (h * 60) + min + (sec / 60);
	cutprice = (totalmin / 0.85) * 130;
	cout << "\nСтоимость резки: " << cutprice << " руб.";
	return cutprice;
}

double totalPrice(double mprice, double cutprice)
{
	double total;
	total = mprice + cutprice;

	cout << "\nИтог: \n"
		<< total << " руб | " << total / 1000000 << " млн. руб. \n";

	return total;
}

int endScreen()
{
	int end;

	cout << "\n\n--\n";
	cout << "1. Повторить\n"
		 << "2. Выйти\n"
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
		}
	}
}


#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

void welcome()
{
	cout << "����������� �������\n\n";
}

int metalType()
{
	bool typesel = true;

	cout << "�������� ��� �������: \n"
		<< "1. ������ ����� \n"
		<< "2. ����������� ����� \n"
		<< "3. ��������\n"
		<< "4. ������ ����� (�� AJAN)\n"
		<< "5. ������ �������� �������.\n\n"
		<< "��� �����: ";

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
			cout << "������ �� �������! " 
				 << "�������� ��� ������� �� ������!\n";
		}
	}
	return t;
}

double getDensity(int metalType) //���� (�� ��� � �������) �� ���������� �������� ������� metalType, ���?
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
		cin >> density;
		break;

	default:
		cout << "������! �������� ��� ������� �� ������\n";
	}
	return density;
}

double rectangleCalc(double density) //� ��� �������� �������� ���������, � ������ �� ��� � ��� ��� ����? 
{
		double thick, lenght, wide, count, divide, weight;
		divide = 1000000;

		cout << "����������� �������\n\n";

		cout << "������� ������� � ��: \n\n";
		cout << "������� : ";
		cin >> thick;
		cout << "�����: ";
		cin >> lenght;
		cout << "������: ";
		cin >> wide;
		cout << "����������: ";
		cin >> count;
		cout << endl;

		weight = (thick * lenght * wide * density * count) / divide;

		cout << "����: \n";
		cout << weight << " �� \n"
			<< weight / 1000 << "����\n\n";

		return weight;
}

double roundCalc(double density) 
{
		double thick, radius, diameter, count, divide, weight, pi, square;
		divide = 1000000;
		pi = 3.14159265358;

		cout << "����������� �������\n\n";

		cout << "������� ������� � �����������:\n\n";

		cout << "�������: ";
		cin >> thick;
		cout << "�������: ";
		cin >> diameter;
		cout << "����������: ";
		cin >> count;
		cout << endl;

		radius = diameter / 2;
		square = pow(radius, 2);
		weight = density * (thick * square * pi) / divide;

		cout << "����: \n"
			<< weight << "�� \n"
			<< weight / 1000 << "����\n\n";

		return weight;
}

double perimeterCalc(double density)
{
	double perimeter, thick, weight;

	cout << "����������� �������\n\n";

	cout << "������� ������� � �����������:\n\n";

	cout << "�������: ";
	cin >> thick;

	cout << "��������: ";
	cin >> perimeter;
	cout << endl;

	weight = ((pow(2, perimeter)) / 4) * thick * density / 1000000;
	cout << weight << " �� \n";

	return weight;
}

int inputForm()
{
	bool formsel = true;
	cout << "�������� ����� �����: \n"
		<< "1. ������������� \n"
		<< "2. ���� \n"
		<< "3. ���� ������������ ����� (���� ���������) \n"
		<< "��� �����: ";
	int f;
	int maxMenuIndex = 3;

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
			cout << "������ �� �������\n";
		}

		
	}
	system("CLS");
	return f;
}

double metalPrice(double weight)
{
	double mprice, kgprice;

	cout << "������� ���� �� �� �������: ";
	cin >> kgprice;

	mprice = weight * kgprice;

	if (weight <= 100)
	{
		cout << pow (mprice, 3) << " ���. | "
			 << pow (mprice, 3) / 1000000 << "���. ���. \n";
	}
	
	if (weight <= 500)
	{
		cout << pow(mprice, 2) << " ���. | "
			 << pow(mprice, 2) / 1000000 << "���. ���. \n";
	}

	if (weight >= 1000)
	{
		cout << mprice << " ���. | "
			 << mprice / 1000000 << "���. ���. \n";
	}

	return mprice;
	return weight;
}

double cutPrice()
{
	double h, min, sec, totalmin, cutprice;

	cout << "\n������� ����� �����: \n";
	cout << "�����: ";
	cin >> h;
	cout << "�����: ";
	cin >> min;
	cout << "������: ";
	cin >> sec;

	totalmin = (h * 60) + min + (sec / 60);
	cutprice = (totalmin / 0.85) * 130;
	cout << "\n��������� �����: " << cutprice << " ���.";
	return cutprice;
}

double totalPrice(double mprice, double cutprice)
{
	double total;
	total = mprice + cutprice;

	cout << "\n����: \n"
		<< total << " ��� | " << total / 1000000 << " ���. ���. \n";

	return total;
}

int endScreen()
{
	int end;

	cout << "\n\n--\n";
	cout << "1. ���������\n"
		 << "2. �����\n"
		 << "��� �����: ";
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

		case 3:
			weight = perimeterCalc(density);
			break;

		default:
			cout << "������! �������� ����� ������� �� ������!" << endl;
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
		case 2:
			work = false;
		}
	}
}
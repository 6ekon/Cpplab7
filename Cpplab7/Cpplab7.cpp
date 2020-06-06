#include <iostream>
#include <queue>
#include <stack>
#include <time.h>
using namespace std;

void task1()
{
	queue <int> Numbers;
	cout << "Введите кол-во чисел для ввода: ";
	int size = 0;
	int count = 0;
	int numbers = 0;
	int avg = 0;
	cin >> size;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		numbers = 10 - rand() % 20;
		Numbers.push(numbers);
		avg += numbers;
		count++;
	}
	avg = avg / count;
	cout << "Элементы очереди: ";
	for (int i = 0; i < size; i++)
	{
		cout << Numbers.front() << " ";
		Numbers.pop();
	}
	cout << endl << "Среднее арифметическое чисел очереди: " << avg << endl << endl;
}

queue<double> Numbers;

void dequeue()
{
	Numbers.pop();
}

void enqueue()
{
	double a;
	cout << "Введите число :";
	cin >> a;
	Numbers.push(a);
}

void Print()
{
	double buff[100];
	int i = 0;
	cout << "Ваша очередь: \n  ";
	while (!Numbers.empty())
	{
		cout << Numbers.front() << "  ";
		buff[i] = Numbers.front();
		Numbers.pop();
		i++;
	}
	for (int j = 0; j < i; j++)
		Numbers.push(buff[j]);
	cout << "\n";
}

double Negative()
{
	double sum = 0;
	double masss[100];
	int i = 0;
	while (!Numbers.empty())
	{
		masss[i] = Numbers.front();
		Numbers.pop();
		if (masss[i] < 0)
		{
			sum += masss[i];
		}
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		Numbers.push(masss[j]);
	}
	cout << "\n";
	return sum;
}

void task2()
{
	while (true)
	{
		int choice;
		cout << "Добавить элемент в очередь - 1\n Удалить элемент очереди - 2\n Выполнить поставленную задачу - 3\n Вывести на экран - 4\n -->";
		cin >> choice;
		switch (choice)
		{
		case 1:
			enqueue();
			system("cls");
			break;
		case 2:
			dequeue();
			system("cls");
			break;
		case 3:
			Numbers.push(-2.1);
			Numbers.push(1.3);
			Numbers.push(-1.34);
			Numbers.push(3.3);
			Print();
			dequeue();
			Numbers.push(2.9);
			Print();

			cout << "Сумма отрицательных чисел: " << Negative() << "\n\n\n";

			break;
		case 4:
			Print();
			break;
		default:
			break;
		}
	}
}

int main()
{
	setlocale(0, "");
	int task;
	cout << "Выберите задание (доступны 1, 2): ";
	cin >> task;
	switch (task)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
		/*case 3:
			task3();
			break;*/
	}
	return 0;
}

#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
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


struct Manip
{
	double data = 0;
	Manip* next = nullptr;
};

struct Adding
{
	Manip* head = nullptr, * tail = nullptr;
	size_t count = 0;

	void New(double value)
	{
		if (!head)
		{
			head = new Manip();
			head->data = value;
		}
		else if (!tail)
		{
			tail = new Manip();
			tail->data = value;
			head->next = tail;
		}
		else
		{
			tail->next = new Manip();
			tail->next->data = value;
			tail = tail->next;
		}
		count++;
	}

	void NewMan(Manip* node)
	{
		if (!head)
		{
			head = node;
		}
		else if (!tail)
		{
			tail = node;
			head->next = tail;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}
		count++;
	}

	void Ins(double by_num, double value)
	{
		Manip* insertance;
		for (Manip* next = head; next; next = next->next)
		{
			if (next->data < by_num)
			{
				insertance = new Manip();
				insertance->data = value;
				insertance->next = next->next;
				next->next = insertance;
				next = next->next;
				count++;
			}
		}
	}

	void Rem(double minVal, double maxVal)
	{
		if (head)
		{
			Manip* save;
			while (head && head->data >= minVal && head->data <= maxVal)
			{
				save = head->next;
				delete head;
				head = save;
				if (head == tail)
					tail = nullptr;
				count--;
			}
			for (Manip* next = head; next; next = next->next)
			{
				while (next->next && next->next->data >= minVal && next->next->data <= maxVal)
				{
					save = next->next->next;
					delete next->next;
					next->next = save;
					count--;
				}
			}
		}
	}

	static void integrate(Adding& queue1, Adding& queue2)
	{
		if (queue1.head != queue2.head)
		{
			Adding queue;
			while (queue1.head && queue2.head)
			{
				if (queue1.head->data < queue2.head->data)
				{
					queue.NewMan(queue1.head);
					queue1.head = queue1.head->next;
				}
				else
				{
					queue.NewMan(queue2.head);
					queue2.head = queue2.head->next;
				}
			}
			if (!queue1.head)
			{
				while (queue2.head)
				{
					queue.NewMan(queue2.head);
					queue2.head = queue2.head->next;
				}
			}
			else if (!queue2.head)
			{
				while (queue1.head)
				{
					queue.NewMan(queue1.head);
					queue1.head = queue1.head->next;
				}
			}
			queue1.head = queue.head;
			queue2.head = queue.head;
		}
	}

	void sort_ascendinG()
	{
		if (tail)
			for (size_t i = 0; i < count; i++)
			{
				for (Manip* next = head; next; next = next->next)
				{
					if (next->next && next->data > next->next->data)
						std::swap(next->data, next->next->data);
				}
			}
	}

	void show()
	{
		if (head)
		{
			for (Manip* next = head; next; next = next->next)
			{
				std::cout << std::setw(5) << next->data << " ";
			}
			std::cout << std::endl;
		}
		else std::cout << "NULL" << std::endl;
	}
};

void task3()
{
	Manip* head = nullptr, * tail = nullptr;
	size_t count = 0;

	Adding fadd, sadd;
	fadd.New(5);
	fadd.New(12);
	fadd.New(-9);
	fadd.sort_ascendinG();
	cout << "Первая очередь: ";
	fadd.show();
	sadd.New(1);
	sadd.New(0);
	sadd.New(-6);
	sadd.sort_ascendinG();
	cout << "Вторая очередь: ";
	sadd.show();
	Adding::integrate(fadd, sadd);
	cout << "Измененная: ";
	fadd.show();
	cout << "Указатель: Начало -  " << fadd.head  << "\tКонец - " << fadd.tail;
}

int main()
{
	setlocale(0, "");
	int task;
	cout << "Выберите задание (доступны 1, 2, 3): ";
	cin >> task;
	cout << endl;
	switch (task)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	}
	return 0;
}

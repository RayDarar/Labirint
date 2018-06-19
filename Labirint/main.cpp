//Игра была написана мной в самом начале изучения программирования
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <Windows.h>
#include <cctype>
#include <conio.h>
using namespace std;

int res, N, SPECIAL = 5, kon = 0, win1 = 0;
char a[100][100];

void lab()//Генерация
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			a[i][j] = rand() % 10 + 1;
			if (a[i][j] <= 4)
				a[i][j] = '/';
			else if (a[i][j] > 4)
				a[i][j] = '*';
		}
}
void pr()//Просмотр матрицы
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void menu()//Меню
{
	cout << "Осталось способностей:\t" << SPECIAL << endl;
	cout << "1)Двигать влево(1)\n2)Двигать вправо(2)\n3)Двигать верх(3)\n4)Двигать вниз(4)\n5)Проиграл\n6)Использовать способность(6)" << endl;
	cin >> res;
	system("cls");
}
void genPL()//Сгенерировали персонажа
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == '*')
			{
				a[i][j] = 'A';
				return;
			}
		}
	}
}
void Player()//Игрок
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 'A')//Нашли ранее сгенерированного персонажа
			{
				if (res == 1)//Лево(Работает)
				{
					if (a[i][j - 1] == '@')//подарочек 
					{
						win1++;
						return;
					}
					if (a[i][j - 1] == '/')//Проверка на /
					{
						cout << "Там стена, ты умер!" << endl;
						kon++;
						return;
					}
					if (a[i][j - 1] == '*')//Проверка на *
					{
						swap(a[i][j], a[i][j - 1]);//меняем позицию игрока и свободную клетку
						return;
					}
				}
				if (res == 2)//Направо(Работает)
				{
					if (a[i][j + 1] == '@')//подарочек 
					{
						win1++;
						return;
					}
					if (a[i][j + 1] == '/')//Проверка на /
					{
						cout << "Там стена, ты умер!" << endl;
						kon++;
						return;
					}
					if (a[i][j + 1] == '*')//Проверка на *
					{
						swap(a[i][j], a[i][j + 1]);//меняем позицию игрока и свободную клетку
						return;
					}
				}
				if (res == 3)//Верх(Работает)
				{
					if (a[i - 1][j] == '@')//подарочек 
					{
						win1++;
						return;
					}
					if (a[i - 1][j] == '/')//Проверка на /
					{
						cout << "Там стена, ты умер!" << endl;
						kon++;
						return;
					}
					if (a[i - 1][j] == '*')//Проверка на *
					{
						swap(a[i][j], a[i - 1][j]);//меняем позицию игрока и свободную клетку
						return;
					}
				}
				if (res == 4)//Вниз(Работает)
				{
					if (a[i + 1][j] == '@')//подарочек 
					{
						win1++;
						return;
					}
					if (a[i + 1][j] == '/')//Проверка на /
					{
						cout << "Там стена, ты умер!" << endl;
						kon++;
						return;
					}
					if (a[i + 1][j] == '*')//Проверка на *
					{
						swap(a[i][j], a[i + 1][j]);//меняем позицию игрока и свободную клетку
						return;
					}
				}
			}//if
		}//for2
	}//for1
}//func
void SP1()//Способности
{
	if (SPECIAL == 0)
	{
		cout << "Способностей не осталось((" << endl;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 'A')//Ищем персонажа
			{
				cout << "В какую сторону используем?\n1)влево(1)\n2)вправо(2)\n3)верх(3)\n4)вниз(4)" << endl;
				cin >> res;
				if (res == 1)//Лево
				{
					if (a[i][j - 1] == '/')//Проверка на /
					{
						cout << "Ломаем стенку...." << endl;
						Sleep(500);
						a[i][j - 1] = '*';
						SPECIAL--;
						return;
					}
					if (a[i][j - 1] == '*')//Проверка на *
					{
						cout << "Там свободно дурачок))" << endl;
						return;
					}
				}
				if (res == 2)//Направо(Работает)
				{
					if (a[i][j + 1] == '/')//Проверка на /
					{
						cout << "Ломаем стенку...." << endl;
						Sleep(500);
						a[i][j + 1] = '*';
						SPECIAL--;
						return;
					}
					if (a[i][j + 1] == '*')//Проверка на *
					{
						cout << "Там свободно дурачок))" << endl;
						return;
					}
				}
				if (res == 3)//Верх
				{
					if (a[i - 1][j] == '/')//Проверка на /
					{
						cout << "Ломаем стенку...." << endl;
						Sleep(500);
						a[i - 1][j] = '*';
						SPECIAL--;
						return;
					}
					if (a[i - 1][j] == '*')//Проверка на *
					{
						cout << "Там свободно дурачок))" << endl;
						return;
					}
				}
				if (res == 4)//Вниз
				{
					if (a[i + 1][j] == '/')//Проверка на /
					{
						cout << "Ломаем стенку...." << endl;
						Sleep(500);
						a[i + 1][j] = '*';
						SPECIAL--;
						return;
					}
					if (a[i + 1][j] == '*')//Проверка на *
					{
						cout << "Там свободно дурачок))" << endl;
						return;
					}
				}
			}
		}
	}
}
void genWIN()
{
	int R, R1;
	R = rand() % N + (N / 2);
	R1 = rand() % N + (N / 2);
	a[R >= N ? N - 1 : R][R1 >= N ? N - 1 : R1] = '@';
}

void main()
{
Begin:
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	cout << "Вы подросток отправляетесь на поиски подарка своей девушке в пустошах.\nИ в один день узнаете, что подарок где то в лабиринте...." << endl;
	_getch();
	cout << "\t\"Лабиринт\"" << endl;
	cout << "Введите размер лабиринта(100 максимум)" << endl;
	cin >> N;
	cout << "Генерация лабиринта...." << endl;
	Sleep(1000);
	lab();
	cout << "Генерация Игрока...." << endl;
	Sleep(500);
	genPL();
	cout << "Генерация подарочка...." << endl;
	Sleep(750);
	genWIN();
	cout << "ВНИМАНИЕ У ТЕБЯ ЕСТЬ 5 ЗАРЯДОВ СПОСОБНОСТИ ЛОМАТЬ СТЕНЫ!, трать с умом" << endl;
	_getch();
	cout << "\t\"Приятной игры!" << endl;
b1:
	pr();
	menu();
	if (res == 5)
		goto konec;

	else if (res == 6)
		SP1();

	Player();
	if (kon == 1)
		goto konec;

	if (win1 == 1)
		goto VIBOR;

	goto b1;
VIBOR:
	cout << "Перед тем как взять подарок ты подумал!" << endl;
	_getch();
	cout << "А так тебе это надо?" << endl;
	_getch();
	cout << "Что же ты сделаешь!\n1)Возьму, я хочу быть счастлив!\n2)ТЯН НЕ НУЖНА!" << endl;
	cin >> res;
	if (res == 1)
		goto WINER;

	else if (res == 2)
		goto LOSER;

WINER:
	cout << "Ты нашел подарок своей девушке!" << endl;
	_getch();
	cout << "Она сказала, что хочет с тобой пожениться!" << endl;
	_getch();
	cout << "Довольный ты идешь спать!" << endl;
	_getch();
	for (int i = 0; i < N; i++)
	{
		cout << "Zzz)))";
		Sleep(500);
	}
	cout << endl;
	goto konec;
LOSER:
	cout << "Ты сломал подарок своей девушке!" << endl;
	_getch();
	cout << "Она возненавидела тебя!" << endl;
	_getch();
	cout << "Немного подумав ты решил поспать!" << endl;
	_getch();
	for (int i = 0; i < N; i++)
	{
		cout << "Zzz((( ";
		Sleep(500);
	}
	cout << endl;
	goto konec;

konec:
	cout << "Побробуешь заново?\n1)Да\n2)Нет" << endl;
	cin >> res;
	if (res == 1)
		goto Begin;

	else if (N == 2)
		cout << "Прощай" << endl;

	_getch();
}

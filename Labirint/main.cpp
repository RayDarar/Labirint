//���� ���� �������� ���� � ����� ������ �������� ����������������
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

void lab()//���������
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
void pr()//�������� �������
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void menu()//����
{
	cout << "�������� ������������:\t" << SPECIAL << endl;
	cout << "1)������� �����(1)\n2)������� ������(2)\n3)������� ����(3)\n4)������� ����(4)\n5)��������\n6)������������ �����������(6)" << endl;
	cin >> res;
	system("cls");
}
void genPL()//������������� ���������
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
void Player()//�����
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 'A')//����� ����� ���������������� ���������
			{
				if (res == 1)//����(��������)
				{
					if (a[i][j - 1] == '@')//��������� 
					{
						win1++;
						return;
					}
					if (a[i][j - 1] == '/')//�������� �� /
					{
						cout << "��� �����, �� ����!" << endl;
						kon++;
						return;
					}
					if (a[i][j - 1] == '*')//�������� �� *
					{
						swap(a[i][j], a[i][j - 1]);//������ ������� ������ � ��������� ������
						return;
					}
				}
				if (res == 2)//�������(��������)
				{
					if (a[i][j + 1] == '@')//��������� 
					{
						win1++;
						return;
					}
					if (a[i][j + 1] == '/')//�������� �� /
					{
						cout << "��� �����, �� ����!" << endl;
						kon++;
						return;
					}
					if (a[i][j + 1] == '*')//�������� �� *
					{
						swap(a[i][j], a[i][j + 1]);//������ ������� ������ � ��������� ������
						return;
					}
				}
				if (res == 3)//����(��������)
				{
					if (a[i - 1][j] == '@')//��������� 
					{
						win1++;
						return;
					}
					if (a[i - 1][j] == '/')//�������� �� /
					{
						cout << "��� �����, �� ����!" << endl;
						kon++;
						return;
					}
					if (a[i - 1][j] == '*')//�������� �� *
					{
						swap(a[i][j], a[i - 1][j]);//������ ������� ������ � ��������� ������
						return;
					}
				}
				if (res == 4)//����(��������)
				{
					if (a[i + 1][j] == '@')//��������� 
					{
						win1++;
						return;
					}
					if (a[i + 1][j] == '/')//�������� �� /
					{
						cout << "��� �����, �� ����!" << endl;
						kon++;
						return;
					}
					if (a[i + 1][j] == '*')//�������� �� *
					{
						swap(a[i][j], a[i + 1][j]);//������ ������� ������ � ��������� ������
						return;
					}
				}
			}//if
		}//for2
	}//for1
}//func
void SP1()//�����������
{
	if (SPECIAL == 0)
	{
		cout << "������������ �� ��������((" << endl;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 'A')//���� ���������
			{
				cout << "� ����� ������� ����������?\n1)�����(1)\n2)������(2)\n3)����(3)\n4)����(4)" << endl;
				cin >> res;
				if (res == 1)//����
				{
					if (a[i][j - 1] == '/')//�������� �� /
					{
						cout << "������ ������...." << endl;
						Sleep(500);
						a[i][j - 1] = '*';
						SPECIAL--;
						return;
					}
					if (a[i][j - 1] == '*')//�������� �� *
					{
						cout << "��� �������� �������))" << endl;
						return;
					}
				}
				if (res == 2)//�������(��������)
				{
					if (a[i][j + 1] == '/')//�������� �� /
					{
						cout << "������ ������...." << endl;
						Sleep(500);
						a[i][j + 1] = '*';
						SPECIAL--;
						return;
					}
					if (a[i][j + 1] == '*')//�������� �� *
					{
						cout << "��� �������� �������))" << endl;
						return;
					}
				}
				if (res == 3)//����
				{
					if (a[i - 1][j] == '/')//�������� �� /
					{
						cout << "������ ������...." << endl;
						Sleep(500);
						a[i - 1][j] = '*';
						SPECIAL--;
						return;
					}
					if (a[i - 1][j] == '*')//�������� �� *
					{
						cout << "��� �������� �������))" << endl;
						return;
					}
				}
				if (res == 4)//����
				{
					if (a[i + 1][j] == '/')//�������� �� /
					{
						cout << "������ ������...." << endl;
						Sleep(500);
						a[i + 1][j] = '*';
						SPECIAL--;
						return;
					}
					if (a[i + 1][j] == '*')//�������� �� *
					{
						cout << "��� �������� �������))" << endl;
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
	cout << "�� ��������� ������������� �� ������ ������� ����� ������� � ��������.\n� � ���� ���� �������, ��� ������� ��� �� � ���������...." << endl;
	_getch();
	cout << "\t\"��������\"" << endl;
	cout << "������� ������ ���������(100 ��������)" << endl;
	cin >> N;
	cout << "��������� ���������...." << endl;
	Sleep(1000);
	lab();
	cout << "��������� ������...." << endl;
	Sleep(500);
	genPL();
	cout << "��������� ���������...." << endl;
	Sleep(750);
	genWIN();
	cout << "�������� � ���� ���� 5 ������� ����������� ������ �����!, ����� � ����" << endl;
	_getch();
	cout << "\t\"�������� ����!" << endl;
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
	cout << "����� ��� ��� ����� ������� �� �������!" << endl;
	_getch();
	cout << "� ��� ���� ��� ����?" << endl;
	_getch();
	cout << "��� �� �� ��������!\n1)������, � ���� ���� ��������!\n2)��� �� �����!" << endl;
	cin >> res;
	if (res == 1)
		goto WINER;

	else if (res == 2)
		goto LOSER;

WINER:
	cout << "�� ����� ������� ����� �������!" << endl;
	_getch();
	cout << "��� �������, ��� ����� � ����� ����������!" << endl;
	_getch();
	cout << "��������� �� ����� �����!" << endl;
	_getch();
	for (int i = 0; i < N; i++)
	{
		cout << "Zzz)))";
		Sleep(500);
	}
	cout << endl;
	goto konec;
LOSER:
	cout << "�� ������ ������� ����� �������!" << endl;
	_getch();
	cout << "��� ������������� ����!" << endl;
	_getch();
	cout << "������� ������� �� ����� �������!" << endl;
	_getch();
	for (int i = 0; i < N; i++)
	{
		cout << "Zzz((( ";
		Sleep(500);
	}
	cout << endl;
	goto konec;

konec:
	cout << "���������� ������?\n1)��\n2)���" << endl;
	cin >> res;
	if (res == 1)
		goto Begin;

	else if (N == 2)
		cout << "������" << endl;

	_getch();
}

#include<iostream>
using namespace std;

#define delimiter "\n===========================================================\n"

template<typename T>T** Allocale(const int m, const int n);
template<typename T>void FillRand(T Arr[], const int n, int minRand = 0, int maxRand = 100);
template<typename T>void FillRand(T** Arr, const int m, const int n);
template<typename T>void Print(T** Arr, const int m, const int n);
template<typename T>void Delete(T*** Arr, const int m);
template<typename T>T** AddRow(T** Arr, int& m, const int n);	//��������� ������ � ������
template<typename T>T** AppendRow(T** Arr, int& m, const int n);
template<typename T>T** InsertRow(T** Arr, int& m, const int n, int Index);
template<typename T>T** DelFirstRow(T** Arr, int& m);
template<typename T>T** DelLastRow(T** Arr, int& m);
template<typename T>T** EraseRow(T** Arr, int& m, int Index);
template<typename T>void AppendCol(T **Arr, const int m, int &n);
template<typename T>void AddColls(T** Arr, const int m, int& n);
template<typename T>void AddColIndex(T** Arr, const int m, int& n, int Index);
template<typename T>void DellColIndex(T** Arr, const int m, int& n, int Index);
template<typename T>void DellendCol(T **Arr, const int m, int &n);
template<typename T>void DellColl(T **Arr, const int m, int &n);

typedef double DataType;

void main()
{
	setlocale(LC_ALL, "Russian");

	int m;
	int n;
	int Index;
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������: "; cin >> n;
	DataType** Arr = Allocale<DataType>(m, n);  //** Arr - ��������� �� ������ ����������

												//���������� �����:
												//Allocale(m, n);
												//////////////////////////////////////////

												/*for (int i = 0; i < m; i++)
												{
												for (int j = 0; j < n; j++)
												{
												cout << Arr[i][j] << "\t";
												}
												cout << endl;
												}
												cout << endl;*/

	FillRand(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//���������� ������ � �����:
	cout << "���������� ������ � ����� �������: " << endl;
	Arr = AppendRow(Arr, m, n);
	FillRand(Arr[m - 1], n, 0, 1000);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//���������� ������ � ������:
	cout << "���������� ������ � ������ �������: " << endl;
	Arr = AddRow(Arr, m, n);
	FillRand(Arr[0], n, 0, 1000);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//���������� ������ �� �������:
	cout << "���������� ������ �� �������: " << endl;
	cout << "������� ������ ����������� ������: ";
	cin >> Index;
	Arr = InsertRow(Arr, m, n, Index);
	FillRand(Arr[Index], n, 0, 1000);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//�������� ������ ������:
	cout << "�������� ������ ������:\n";
	//int *FirstRow = Arr[0];
	Arr = DelFirstRow(Arr, m);
	Print(Arr, m, n);
	cout << delimiter << endl;
	//cout << "� ��� ����� �� ��������, �� �� ����� :-)\n";
	//for (int i = 0; i < n; i++)cout << FirstRow[i] << "\t"; cout << endl;

	//�������� ��������� ������:
	cout << "�������� ��������� ������:\n";
	Arr = DelLastRow(Arr, m);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//�������� ������ �� �������:
	cout << "�������� ������ �� �������: ";
	cin >> Index;
	Arr = EraseRow(Arr, m, Index);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//���������� ������ � �����:
	cout << "���������� ������� � ����� �������: " << endl;
	AppendCol(Arr, m, n);
	//FillRand(Arr[n - 1], n, 0, 1000);
	Print(Arr, m, n);
	cout << delimiter << endl;

	cout << "���������� ������� � ������ �������: " << endl;
	AddColls(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;

	Index = 0;
	cout << "������� ������ ������������ �������: ";
	cin >> Index;
	AddColIndex(Arr, m, n, Index);
	Print(Arr, m, n);
	cout << delimiter << endl;

	cout << "�������� ������� �� �������" << endl;
	cout << "������� ������ ���������� �������: "; cin >> Index;
	DellColIndex(Arr, m, n, Index);
	Print(Arr, m, n);
	cout << delimiter << endl;

	cout << "�������� ������� � ����� �������" << endl;
	DellendCol(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;

	cout << "�������� ������� � ������ �������" << endl;
	DellColl(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;

	//�������� �����:
	Delete(&Arr, m);
}
template<typename T>T** Allocale(const int m, const int n)
{
	T **Arr = new T*[m];
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new T[n]{};
	}
	return Arr;
}
template<typename T>void FillRand(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Arr[i][j] = rand() % 100 / 10.;
		}
	}
}
template<typename T>void FillRand(T Arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % (maxRand - minRand) + minRand;
	}
}
template<typename T>void Print(T** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template<typename T>void Delete(T*** Arr, const int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[](*Arr)[i];
	}
	delete[] * Arr;
	*Arr = nullptr;
}
template<typename T>T** AddRow(T** Arr, int& m, const int n)
{
	T** Buff = new T*[m + 1];
	for (int i = 0; i < m; i++)
	{
		Buff[i + 1] = Arr[i];
	}
	delete[] Arr;
	Buff[0] = new T[n]{};
	m++;
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>T** AppendRow(T** Arr, int& m, const int n)
{
	T** Buff = new T*[m + 1];
	for (int i = 0; i < m; i++)
	{
		Buff[i] = Arr[i];
	}
	delete[] Arr;
	Buff[m] = new T[n]{};
	m++;
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>T** InsertRow(T** Arr, int& m, const int n, int Index)
{
	T** Buff = new T*[m + 1];
	for (int i = 0; i < Index; i++)
	{
		Buff[i] = Arr[i];
	}
	for (int i = Index; i < m; i++)
	{
		Buff[i + 1] = Arr[i];
	}
	delete[] Arr;
	Buff[Index] = new T[n]{};
	m++;
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>T** DelFirstRow(T** Arr, int& m)
{
	T** Buff = new T*[--m];
	for (int i = 0; i < m; i++)
	{
		Buff[i] = Arr[i + 1];
	}
	delete[] Arr[0];
	delete[] Arr;
	//Buff[0] = new int[n] {};
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>T** DelLastRow(T** Arr, int& m)
{
	T** Buff = new T*[--m];

	for (int i = 0; i < m; i++)
	{
		Buff[i] = Arr[i];
	}
	delete[] Arr[m];
	delete[] Arr;
	//Buff[0] = new int[n] {};
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>T** EraseRow(T** Arr, int& m, int Index)
{
	T** Buff = new T*[--m];
	for (int i = 0; i < Index; i++)
	{
		Buff[i] = Arr[i];
	}
	for (int i = Index; i < m; i++)
	{
		Buff[i] = Arr[i + 1];
	}
	delete[] Arr[Index];
	delete[] Arr;
	//Buff[0] = new int[n] {};
	Arr = Buff;
	Buff = nullptr;
	return Arr;
}
template<typename T>void AppendCol(T **Arr, const int m, int &n)
{
	T *Buffer;
	for (int i = 0; i < m; i++)
	{
		Buffer = new T[n + 1]{};	//������� ����� ������, �� 1 ������� ������.
		for (int j = 0; j < n; j++)Buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
}
template<typename T>void AddColls(T** Arr, const int m, int& n)
{
	/*int** Buff = new int*[n + 1];
	for (int i = 0; i < n; i++)
	{
	Buff[i + 1] = Arr[i];
	}
	delete[] Arr;
	Buff[0] = new int[m] {};
	n++;
	Arr = Buff;
	Buff = nullptr;
	return Arr;*/

	T *Buff;	//��������� �� �������� ������.
	for (int i = 0; i < m; i++)
	{
		Buff = new T[n + 1]{};	//������� �������� ������.
								//�������� �������� ������ � ��������:
		for (int j = 0; j < n; j++)Buff[j + 1] = Arr[i][j];
		delete[] Arr[i];	//������� �������� ������.
		Arr[i] = Buff;
	}
	n++;
}
template<typename T>void AddColIndex(T** Arr, const int m, int& n, int Index)
{
	T* Buff;
	for (int i = 0; i < m; i++)
	{
		Buff = new T[n + 1]{};
		for (int j = 0; j < Index; j++)Buff[j] = Arr[i][j];
		for (int j = Index; j < n; j++)Buff[j + 1] = Arr[i][j];

		delete[] Arr[i];
		//������� ���
		Arr[i] = Buff;
	}
	n++;
}
template<typename T>void DellColIndex(T** Arr, const int m, int& n, int Index)
{
	T* Buff;
	for (int i = 0; i < m; i++)
	{
		Buff = new T[n]{};
		for (int j = 0; j < Index; j++)Buff[j] = Arr[i][j];
		for (int j = Index; j < n; j++)Buff[j] = Arr[i][j + 1];

		delete[] Arr[i];
		//������� ���
		Arr[i] = Buff;
	}
	n--;
}
template<typename T>void DellendCol(T **Arr, const int m, int &n)
{
	T *Buffer;
	for (int i = 0; i < m; i++)
	{
		Buffer = new T[n]{};
		for (int j = 0; j < n; j++)Buffer[j] = Arr[i][j];
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
}
template<typename T>void DellColl(T **Arr, const int m, int &n)
{
	T *Buffer;
	for (int i = 0; i < m; i++)
	{
		Buffer = new T[n]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
}
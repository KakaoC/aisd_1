#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

using namespace std;

double epsilon = 0.000000001;

class matrix
{
private:
	double** data;
	int columns, rows;

public:
	matrix() 
	{
		columns = 3;
		rows = 3;
		data = new double*[rows];
		for (int i = 0; i < rows; ++i)
		{
			data[i] = new double[columns];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = 1;
			}
		}
	}

	matrix(int rows_, int columns_) 
	{
		if (columns_ < 1 or rows_ < 1) throw "Invalid matrix size";

		columns = columns_;
		rows = rows_;

		data = new double* [rows];
		for (int i = 0; i < rows; ++i)
		{
			data[i] = new double[columns];
		}

		cout << "Input your values" << "\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++)
			{
				double _temp;
				cout << "Input value of index [" << i + 1 << "][" << j + 1 << "]: ";
				cin >> _temp;
				data[i][j] = _temp;
				cout << endl;
			}
		}
	}

	matrix(const matrix& m) 
	{
		data = new double* [m.rows];
		for (int i = 0; i < m.rows; ++i)
		{
			data[i] = new double[m.columns];
		}

		rows = m.rows;
		columns = m.columns;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = m.data[i][j];
			}
		}

	}

	matrix(double** temp, int rows_, int columns_) 
	{
		if (rows_ < 1 or columns_ < 1) throw "Invalid matrix size";

		rows = rows_;
		columns = columns_;

		data = new double* [rows];
		for (int i = 0; i < rows; ++i)
		{
			data[i] = new double[columns];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = temp[i][j];
			}
		}
	}

	matrix(const matrix& a, const matrix& b, const matrix& c) 
	{
		if ((a.rows != 1 or a.columns != 3) or (b.rows != 1 or b.columns != 3) or (c.rows != 1 or c.columns != 3)) throw "Invalid matrix size";

		rows = columns = 3;

		data = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[columns];
		}

		for (int i = 0; i < rows; i++)
		{
			int k = 0;
			int j = 0;

			data[j][i] = a.data[k][i];
			j++;

			data[j][i] = b.data[k][i];
			j++;

			data[j][i] = c.data[k][i];
		}

	}

	~matrix() 
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;
	}

	//Getters
	int get_rows() const { return rows; }

	int get_columns() const { return columns; }

	// оператор () для чтения/записи элемента матрицы по указанным индексам;
	double& operator()(int i, int j) const
	{
		if ((i < 0 or i >= rows) or (j < 0 or j >= columns)) throw "Invalid index";
		return data[i][j];
	}

	//операторы сложения и вычитания матриц;
	matrix& operator+=(const matrix& m) 
	{
		if (rows != m.rows or columns != m.columns) throw "Size of matrix doesn't equal";
		double** temp;

		temp = new double* [m.rows];
		for (int i = 0; i < m.rows; ++i)
		{
			temp[i] = new double[m.columns];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				temp[i][j] = data[i][j] + m.data[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;

		data = temp;
		return *this;
	}

	matrix operator+(const matrix& m) const 
	{
		matrix temp(*this);
		temp += m;
		return temp;
	}

	matrix& operator-=(const matrix& m) 
	{
		if (rows != m.rows or columns != m.columns) throw "Size of matrix doesn't equal";
		double** temp;

		temp = new double* [m.rows];
		for (int i = 0; i < m.rows; ++i)
		{
			temp[i] = new double[m.columns];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				temp[i][j] = data[i][j] - m.data[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			delete[] data[i];
		}
		delete[] data;

		data = temp;
		return *this;
	}

	matrix operator-(const matrix& m) const 
	{
		matrix temp(*this);
		temp -= m;
		return temp;
	}
  //оператор умножения матриц+остаток надо сделать
 
 int main()
{
	matrix a;
	matrix b;
	double n = 1;
	while (true)
	{
		system("cls");
		cout << "first matrix\n\n";
		cout << a << endl;
		cout << "second matrix\n\n";
		cout << b << endl;
		cout << "1 - Create matrix" << endl;
		cout << "2 - Enter value by index" << endl;
		cout << "3 - Matrix addition" << endl;
		cout << "4 - Matrix subtraction" << endl;
		cout << "5 - Matrix multiplication" << endl;
		cout << "6 - Multiplication matrix by scalar" << endl;
		cout << "7 - Division matrix by scalar" << endl;
		cout << "8 - Matrix trace calculation" << endl;
		cout << "9 - Task" << endl;
		cout << "0 - Matrix comparison" << endl;
		cout << "esc - Exit" << endl;
		int z = getch();
		int l = '3';
		system("cls");
		if (z == '1' || z == '2' || (z > '5' && z < '9'))
		{
			cout << "1 - Work with first matrix" << endl;
			cout << "2 - Work with second matrix" << endl;
			while (l != '1' && l != '2') l = getch();
			system("cls");
		}
		if (z == '6' || z == '7')
		{
			cout << "Enter  scalar value" << endl;
			cin >> n;
			system("cls");
		}
		if (z == '1')
		{
			int x = '3';
			cout << "1 - Create random matrix" << endl;
			cout << "2 - Create matrix manually" << endl;
			while (x != '1' && x != '2') x = getch();
			try
			{
				if (x == '1')
				{
					matrix d;
					if (l == '1') a = d;
					else b = d;
				}
				else
				{
					int rows, columns;
					cout << "Enter number of rows" << endl;
					cin >> rows;
					cout << "Enter number of columns" << endl;
					cin >> columns;
					matrix d(rows, columns);
					if (l == '1') a = d;
					else b = d;
				}
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				if (getch()) z = 0;
			}
			system("cls");
		}
		if (z == '2')
		{
			int index_row, index_column;
			double value;
			cout << "Enter index_row" << endl;
			cin >> index_row;
			cout << "Enter index_column" << endl;
			cin >> index_column;
			cout << "Enter value" << endl;
			cin >> value;
			try
			{
				if (l == '1') a(index_row, index_column) = value;
				else b(index_row, index_column) = value;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
				if (getch()) z = 0;
			}
			system("cls");
		}
		if (z == '3')
		{
			try
			{
				matrix d = a + b;
				cout << "Matrix addition" << endl;
				cout << d;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '4')
		{
			try
			{
				matrix d = a - b;
				cout << "Matrix subtraction" << endl;
				cout << d;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '5')
		{
			try
			{
				matrix d = a * b;
				cout << "Matrix multiplication" << endl;
				cout << d;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '6')
		{
			matrix d;
			matrix f;
			cout << "Multiplication matrix by scalar" << endl;
			if (l == '1') d = a * n;
			else d = b * n;
			cout << d;
			cout << "\nMultiplication scalar by matrix" << endl;
			if (l == '1') f = n * a;
			else f = n * b;
			cout << f;
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '7')
		{
			try
			{
				matrix d;
				if (l == '1') d = a / n;
				else d = b / n;
				cout << "Division matrix by scalar" << endl;
				cout << d;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '8')
		{
			double trace_ = 0;
			try
			{
				if (l == '1') trace_ = a.trace();
				else trace_ = b.trace();
				cout << "Matrix trace" << endl;
				cout << trace_;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '9')
		{
			cout << "Create first vector" << endl;
			matrix a1(1, 3);
			cout << "Create second vector" << endl;
			matrix a2(1, 3);
			cout << "Create third vector" << endl;
			matrix a3(1, 3);
			if (coplanarns(a1, a2, a3)) cout << "Vectors are coplanar";
			else cout << "Vectors are not coplanar";
			if (getch()) z = 0;
			system("cls");
		}
		if (z == '0')
		{
			cout << "Enter epsilon" << endl;
			cin >> epsilon;
			if (a == b) cout << "Matrices are the same";
			if (a != b) cout << "Matrices are different";
			if (getch()) z = 0;
		}
		if (z == 27)
		{
			return 0;
		}
	}
}

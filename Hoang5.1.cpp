#include "Lab51.h"
#include <iostream>
#include <ctime>


Matrix::Matrix()
{
	row = 0;
	col = 0;
	elem = nullptr;
}

Matrix::Matrix(int row_temp, int col_temp)
{	
	this->row = row_temp;
	this->col = col_temp;

	this->elem = new int[row * col];

	for (int i = 0; i < row * col; i++)
		this->elem[i] = 1 + rand() % 20;
}

Matrix::~Matrix()
{
	if (this->elem != nullptr)
		delete[] this->elem;
}

Matrix::Matrix(const Matrix& orig)
{
	this->row = orig.row;
	this->col = orig.col;

	if (orig.elem != nullptr)
		this->elem = new int[this->row * this->col];
	else this->elem = nullptr;

	if (this->elem != nullptr)
		for (int i = 0; i < this->row * this->col; i++)
			this->elem[i] = orig.elem[i];
}

void Matrix::set_row(int temp)
{
	int* temp_arr = this->elem;
	if (this->elem != nullptr)
		delete[] this->elem;
	this->elem = new int[temp * this->col];
	for (int i = 0; i < temp * this->col && i < this->row * this->col; i++)
		this->elem[i] = temp_arr[i];
	delete[] temp_arr;
	this->row = temp;
}

void Matrix::check_memory()
{
	std::cout << std::endl << this->elem << std::endl;
}

int Matrix::get_elem(int i, int j) const
{
	return this->elem[i * col + j];
}

int Matrix::get_rows()
{
	return row;
}

int Matrix::get_columns()
{
	return col;
}

void Matrix::print()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << this->elem[i * this->col + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::input(int new_row, int new_col)
{
	this->row = new_row;
	this->col = new_col;
	if (this->elem != nullptr)
		delete[]this->elem;
	this->elem = new int[this->row * this->col];
	for (int i = 0; i < this->row * this->col; i++)
		std::cin >> this->elem[i];
}

void Matrix::input(int new_row)
{
	this->row = new_row;
	this->col = new_row;
	if (this->elem != nullptr)
		delete[] this->elem;
	this->elem = new int[row * col];
	for (int i = 0; i < row * col; i++)
		std::cin >> this->elem[i];
}

void Matrix::auto_input(int new_row, int new_col)
{
	srand((unsigned)time(0));
	this->row = new_row;
	this->col = new_col;

	if (this->elem != nullptr)
	{
		delete[]this->elem;
		this->elem = new int[this->row * this->col];
		for (int i = 0; i < this->row * this->col; i++)
			this->elem[i] = 1 + rand() % 20;
	}
}

int Matrix::trace()
{
	if (this->col != this->row)
	{
		std::cout << "\nError: Matrix is ??not square\n";
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			if (i == j)
				sum += elem[i * this->col + j];

	return sum;
}

void Matrix::mult_by_num(int num)
{
	for (int i = 0; i < this->row * this->col; i++)
		this->elem[i] *= num;
}

bool Matrix::mult(const Matrix second)
{
	if (this->col != second.row)
	{
		std::cout << "Error: the number of columns of the first matrix is not equal to the number of rows of the second matrix\n";
		return false;
	}

	int* res = new int[this->row * second.col];
	int i, j, k;

	for (i = 0; i < this->row * second.col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * second.col + j] += this->elem[i * this->col + k] * second.elem[k * second.col + j];
		}
	}

	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
			std::cout << res[i * second.col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;

	return true;
}

bool Matrix::sum(Matrix second)
{
	if ((this->row != second.row) && (this->col != second.col))
	{
		std::cout << "Error: Matrix sizes are not equal\n";
		return false;
	}
	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->elem[i] + second.elem[i];

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return true;
}

int** Matrix::submatrix(int** matrix, unsigned int n, unsigned int x, unsigned int y) {
	int** submatrix = new int* [n - 1];
	int subi = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		submatrix[subi] = new int[n - 1];
		int subj = 0;
		if (i == y) {
			continue;
		}
		for (unsigned int j = 0; j < n; j++)
		{
			if (j == x)
				continue;
			submatrix[subi][subj] = matrix[i][j];
			subj++;
		}
		subi++;
	}

	return submatrix;
}

int Matrix::determinant(int** matrix, unsigned int n) {
	int det = 0;
	if (n == 2)
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	for (unsigned int x = 0; x < n; ++x)
		det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix(matrix, n, x, 0), n - 1));

	return det;
}

void Matrix::det()
{
	int** matr = new int* [this->row];

	for (int i = 0; i < this->row; i++)
		matr[i] = new int[this->col];

	for (int i = 0; i < this->row; i++)
		for (int j = 0; j < this->col; j++)
			matr[i][j] = this->elem[i * this->col + j];

	int det = determinant(matr, this->row);
	std::cout << det << std::endl;
}
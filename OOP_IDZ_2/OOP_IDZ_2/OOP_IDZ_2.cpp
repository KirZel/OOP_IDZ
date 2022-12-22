
#include <iostream>

int main()
{
	int n; int m;
	int a = 0; int b = 0; int  f = 0;
	int** mat;

	while (true) {
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Error" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}

	while (true) {
		std::cin >> m;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Error" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	mat = new int* [n];
	for (int i = 0; i < n; i++)
		mat[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			std::cin >> mat[i][j];
		}
	std::cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << "\n";
	}


	do {
		f = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++)
			{
				a = a + mat[i - 1][j];

			}


			for (int j = 0; j < m; j++)
			{
				b = b + mat[i][j];
			}

			if (a < b) {
				std::swap(mat[i - 1], mat[i]);
				f++;

			}
			a = 0;
			b = 0;
		}

		std::cout << "\n";
	}

	while (f != 0);


	std::cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << "\n";


	}

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	
}
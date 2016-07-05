#include <iostream>

using namespace std;

int main()
{
	int i, j, n, m;
	cout << " Введите число уравнений: ";


	cin >> n;
	m=n+1;
    float *xx = new float [m];
	float **matrix = new float *[n];


	for (i=0; i<n; i++)
	{
		matrix[i] = new float [m];
	}


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			cout << "Элемент " << "[" << i+1 << " , " << j+1 << "]: " ;
			cin >> matrix[i][j];
		}
	}

	cout << "Матрица: " << endl;

	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

    float ved_elem;
	int k;
	for (i=0; i<n; i++)
	{
		ved_elem=matrix[i][i];
		for (j=n;j>=i;j--){
			matrix[i][j]/=ved_elem;
		}

		for (j=i+1;j<n;j++)
		{
			ved_elem=matrix[j][i];

			for (k=n;k>=i;k--)
			{
				matrix[j][k]-=ved_elem*matrix[i][k];
			}
		}
	}

	xx[n-1] = matrix[n-1][n];

	for (i=n-2; i>=0; i--)
	{
		xx[i] = matrix[i][n];

		for (j=i+1;j<n;j++)
		{
			xx[i]-=matrix[i][j]*xx[j];
		}
	}

	for (i=0; i<n; i++)
	{
		cout << xx[i] << " ";
	}

	cout << endl;
    for (i=0; i<n; i++)
    {
        delete[] matrix[i] ;
    }
    delete[] matrix;
    delete[] xx;
    return 0;
}


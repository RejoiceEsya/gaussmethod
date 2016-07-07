#include <iostream>
#include <stdlib.h>
#include "gausscalc.h"
using namespace std;



int main(int argc, char *argv[])
{
    int i, j, n = 5, m;
    if (argc>1) n=atoi(argv[1]);
    if (n<1) n=3;
    cout << " Введенное число уравнений: "<<n<<endl;
	m=n+1;
    //double h;
    double *xx = new double [m];
    double **matrix = new double *[n];
	for (i=0; i<n; i++)
	{
        matrix[i] = new double [m];
	}


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
            if (i==j) matrix[i][j]=1;
            else matrix[i][j]=0;

		}
        matrix[i][n]=i;
	}
   /* for (j=0;j<m;j++)
    {
     h=matrix[0][j];
     matrix[0][j]=matrix[n-1][j];
     for (int r=0; r<n;r++)
        if(matrix[i][r]>max) max=matrix[i][r];
     ved_elem=max;  matrix[n-1][j]=h;
    }*/

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


    gausscalc(matrix, n, xx);
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


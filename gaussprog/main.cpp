#include <iostream>
#include <stdlib.h>
using namespace std;

void gausscalc(float **matrix, int n, float *xx)
{
    float ved_elem;
    int k, i,j;
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
   }

int main(int argc, char *argv[])
{
    int i, j, n = 4, m;
    if (argc>1) n=atoi(argv[1]);
    if (n<1) n=3;
    cout << " Введенное число уравнений: "<<n<<endl;
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
            if (i==j) matrix[i][j]=1;
            else matrix[i][j]=0;

		}
        matrix[i][n]=i;
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


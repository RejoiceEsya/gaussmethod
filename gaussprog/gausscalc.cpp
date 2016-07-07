void gausscalc(double **matrix, int n, double *xx)
{
    double ved_elem;
    int k, i,j,max;
    max=-1000;
    for (i=0; i<n; i++)
    {
        for (int r=0; r<n;r++)
           if(matrix[i][r]>max) max=matrix[i][r];
        ved_elem=max;
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

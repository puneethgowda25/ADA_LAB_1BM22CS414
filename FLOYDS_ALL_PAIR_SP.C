#include<stdio.h>


void floyd(int a[4][4], int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
		    }
	    }
	}
	printf("All Pairs Shortest Path is :\n");
		for(int i=0;i<n;i++)
	    {
	    	for(int j=0;j<n;j++)
	    	{
	    		printf("%d ",a[i][j]);
			}
	    	printf("\n");
		}
}
int main()
{
    int n ;
    printf("Enter the value for n: ");
    scanf("%d",&n);
    int mat[n][n];

    printf("Enter the graph in the form of matrix ");
    printf("\n");
    for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			    scanf("%d",&mat[i][j]);
			}
		}



	floyd(mat,n);
}

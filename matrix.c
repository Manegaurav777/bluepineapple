#include<stdio.h>
#define max 50
int main()
{
    int a[max][max],b[max][max], final[max][max];
    int arow,acol,brow,bcol;
    int i,j,k;
    
    printf("Enter the rows and column of the matix A : ");
    scanf("%d%d",&arow,&acol);

    printf("Enter elements of matix A : \n");
    for (i = 0; i<arow; i++)
    {
    	for (j = 0; j<acol; j++)
    	{
    		scanf("%d",&a[i][j]);
    	}
    }
    
    printf("Enter the rows and column of the matix B : ");
    scanf("%d%d",&brow,&bcol);

    if(brow!=acol)
    {
    	printf("Multiplication not possible \n");
    }
  else
  {
  	printf("Enter elements of matix B : \n");
  	for (i = 0; i<brow ;i++)
  	{
  		for (j = 0; j<bcol; j++)
  		{
  			scanf("%d",&b[i][j]);
  		}
  	} 
  }
    
    for (i = 0; i <arow; i++)
    {
       for (j = 0; j < bcol; j++)
       {
           final[i][j]=0;
       	for (k = 0; k <brow; k++)
       	{
       		final[i][j] += a[i][k] * b[k][j];
       	}
       }
    }
    printf("\n Final Matrix : \n");
    for (i = 0; i <arow; i++)
    {
    	for ( j = 0; j <bcol; j++)
    	{
    		printf("\t %d  ",final[i][j] );
    	}
    	printf("\n");
    }
    return 0;
}
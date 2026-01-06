#include<stdio.h>
int main()
{
    int matrix[5][5];
    int i ,j;
    //filling the matrix
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i+j==4)
            {
                //diagonal
                matrix[i][j]=0;
            }
            else if(i+j<4)
            {
                //upper triangle
                matrix[i][j]=1;
            }
            else
            {
                //lower triangle
                matrix[i][j]=-1;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%5d",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

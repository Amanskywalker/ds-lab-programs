/*****************************************************************************
Design, develop, and execute a program in C to read a sparse matrix
of integer values and to search the sparse matrix for an element
specified by the user. Print the result of the search appropriately.
Use the triple <row, column, value> to represent an element in the
sparse matrix.
*****************************************************************************/

#include<stdio.h>

struct spas
{
    int r,c,v;
}s[100];

int mat[100][100];

void read(int n)
{
    int i,r1,c1;
    for(i=1;i<=n;i++)
    {
        printf("Enter Row   :");
        scanf("%d",&s[i].r);
        printf("Enter Column:");
        scanf("%d",&s[i].c);
        printf("Enter Value :");
        scanf("%d",&s[i].v);
        r1=s[i].r;
        c1=s[i].c;
        mat[r1][c1]=s[i].v;
    }
}

void write(int n)
{
    int i,j,r2,c2;
    r2=s[0].r;
    c2=s[0].c;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void search(int n)
{
    int k,i,pos=0;
    printf("Enter the Element to search:");
    scanf("%d",&k);
    for(i=1;i<=n;i++)
    {
        if(k==s[i].v)
        {
            pos=i;
            break;
        }

    }
    if(pos)
        printf("Key Found at row=%d\t Column=%d \n",s[pos].r,s[pos].c);
    else
        printf("Key not Found\n");
}

int main()
{
    printf("Enter number of Rows   :");
    scanf("%d",&s[0].r);
    printf("Enter number of Columns:");
    scanf("%d",&s[0].c);
    printf("Enter number of Values :");
    scanf("%d",&s[0].v);
    read(s[0].v);
    search(s[0].v);
    write(s[0].v);
    return 0;
}

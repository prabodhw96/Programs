#include <iostream>
#include <cstdlib>
using namespace std;

int i, j;

void read_matrix(int m[10][10], int row, int col)
{
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			cout<<"A["<<i<<"]["<<j<<"]: ";
			cin>>m[i][j];
		}
	}
}

void display_matrix(int m[10][10], int row, int col)
{
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			cout<<m[i][j]<<"\t";
		cout<<endl;
	}
}

void upper_tri(int m[][10], int row, int col)
{
	int flag=1;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(i>j && m[i][j] != 0)
				flag = 0;
		}
	}
	if(flag) cout<<"\nUpper Triangular Matrix"<<endl;
	else cout<<"\nNot an Upper Triangular Matrix"<<endl;
}

void sum_dia(int m[][10], int row, int col)
{
	int sum = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(i==j)
				sum += m[i][j];
		}
	}
	cout<<"\nSum of diagonal elements is "<<sum<<endl;
}

void transpose_matrix(int m[][10], int row, int col, int trans[][10])
{
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			trans[j][i] = m[i][j];
}

void addition(int a[][10], int b[][10], int row, int col, int add[][10])
{
	for(i=0; i<row; i++)
		for(j=0; j<col; j++)
			add[i][j] = a[i][j] + b[i][j];
}

void subtraction(int a[][10], int b[][10], int row, int col, int sub[][10])
{
	for(i=0; i<row; i++)
		for(j=0; j<row; j++)
			sub[i][j] = a[i][j] - b[i][j];
}

void multiplication(int a[][10], int b[][10], int row, int col, int prod[][10])
{
	int k, sum=0;
	for(i=0; i<row; i++)
	{
        for(j=0; j<col; j++)
        {
            for(k=0; k<row; k++)
				sum += a[i][k]*b[k][j];
            prod[i][j] = sum;
            sum = 0;
        }
	}
}

int main()
{
	int ch, m1[10][10], m2[10][10], add[10][10], sub[10][10], prod[10][10], trans[10][10], row1, col1, row2, col2;
	x:cout<<"In square matrix, row = column.\n(Note that the row and column must be less than 10)\nEnter value: ";
	cin>>row1;
	if(row1>10 || row1<1)
		goto x;
	col1 = row1; row2 = row1; col2 = col1;
	cout<<"\nMatrix 1: \nRow = "<<row1<<", "<<"Column = "<<col1<<endl;
	cout<<"Enter "<<row1*col1<<" numbers for first matrix"<<endl;
	read_matrix(m1, row1, col1);
	cout<<"\nMatrix 2: \nRow = "<<row2<<", "<<"Column = "<<col2<<endl;
	read_matrix(m2, row2, col2);
	cout<<"\nHere is first matrix: "<<endl;
	display_matrix(m1, row1, col1);
	cout<<"\nHere is second matrix: "<<endl;
	display_matrix(m2, row2, col2);
	while(1)
	{
		cout<<"\n1.Check whether the first matrix is upper traingular."<<endl;
		cout<<"2. Sum of diagonal elements of first matrix."<<endl;
		cout<<"3. Transpose of first matrix"<<endl;
		cout<<"4.Check whether the second matrix is upper traingular."<<endl;
		cout<<"5. Sum of diagonal elements of second matrix."<<endl;
		cout<<"6. Transpose of second matrix"<<endl;
		cout<<"7. Addition of two matrices"<<endl;
		cout<<"8. Subtraction of two matrices"<<endl;
		cout<<"9. Multiplication of two matrices"<<endl;
		cout<<"10. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: upper_tri(m1, row1, col1);
			break;
			case 2: sum_dia(m1, row1, col1);
			break;
			case 3: transpose_matrix(m1, row1, col1, trans);
			cout<<"\nTranspose of first matrix: "<<endl;
			display_matrix(trans, col1, row1);
			break;
			case 4: upper_tri(m2, row2, col2);
			break;
			case 5: sum_dia(m2, row2, col2);
			break;
			case 6: transpose_matrix(m2, row2, col2, trans);
			cout<<"\nTranspose of second matrix: "<<endl;
			display_matrix(trans, col2, row2);
			break;
			case 7: addition(m1, m2, row1, col1, add);
			cout<<"\nAddition of first and second matrix: "<<endl;
			display_matrix(add, row1, col1);
			break;
			case 8: subtraction(m1, m2, row1, col1, sub);
			cout<<"\nSubtraction of first and second matrix: "<<endl;
			display_matrix(sub, row1, col1);
			break;
			case 9: multiplication(m1, m2, row1, col1, prod);
			cout<<"\nProduct of first and second matrix: "<<endl;
			display_matrix(prod, row1, col1);
			break;
			case 10: exit(0);
			break;
			default: cout<<"\nInvalid Choice"; break;
		}
	}
	return 0;
}
#include"syscall.h"
#define MAX_ELEMENT 100
int ReadArray(int *a);
void PrintArray(int a[],int n);

int main(){

	int a[MAX_ELEMENT],n = 0;
	n = ReadArray(a);
	if(n == 0) PrintString("n > 100, vui long nhap lai.");
//Your code
//Bubble sort
//...
	BubbleSort(a, n);
	PrintArray(a, n);
	return 0;
}
int ReadArray(int *a){
	int n = 0,i;
	PrintString("Nhap n: ");
	n = ReadInt();
	if(n > 100)
	{
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		PrintString("Nhap a[");
		PrintInt(i);
		PrintString("]:");
		a[i] = ReadInt();
	}
	return n;
}
void PrintArray(int a[],int n){
	int i;
	for (i = 0; i < n ; i++)
	{
		PrintString("a[");
		PrintInt(i);
		PrintString("] = ");
		PrintInt(a[i]);
		PrintChar('\n');
	}
}

void BubbleSort(int a[], int n)
{
	int i, j;
	int flag;
	for(i = 0; i < n - 1;i++)
	{
		flag = 0;
		for(j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				int temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				flag = 1;
			}
		}
		if(flag == 0) break;
	}	
}
	

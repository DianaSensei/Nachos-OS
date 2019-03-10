#include"syscall.h"
#define MAX_ELEMENT 100
int ReadArray(int *a);
void PrintArray(int a[],int n);

int main(){

	int a[MAX_ELEMENT],n = 0;
	n = ReadArray(a);
//Your code
//Bubble sort
//...
	PrintArray(a,n);
	return 0;
}
int ReadArray(int *a){
	int n = 0,i;
	PrintString("Nhap n:");
	n = ReadInt();
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
	

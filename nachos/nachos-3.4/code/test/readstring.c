#include"syscall.h"

int main(){
	char buffer[255];
	ReadString(buffer,255);
	PrintString(buffer);
	return 0;
}

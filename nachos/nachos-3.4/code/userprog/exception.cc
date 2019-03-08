// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

//void
//ExceptionHandler(ExceptionType which)
//{
//    int type = machine->ReadRegister(2);
//
//    if ((which == SyscallException) && (type == SC_Halt)) {
//	DEBUG('a', "Shutdown, initiated by user program.\n");
//   	interrupt->Halt();
//   } else {
//	printf("Unexpected user mode exception %d %d\n", which, type);
//	ASSERT(FALSE);
//    }
//}
#define MAX_LENGTH 10
#define MAX_CHAR 1024
#define MASK_GET_NUM 0xF
void 
ExceptionHandler(ExceptionType which)
{
	int type =machine->ReadRegister(2);
	if(which == SyscallException) {
		switch(type) { 
			case SC_Sub:{           
				int op1;
				op1 = machine->ReadRegister(4);    
				int  op2;
				op2 = machine->ReadRegister(5);    
				int result;
				result= op1 - op2;    
				machine->WriteRegister(2,result);
				break;
			}
			

			case SC_ReadInt:
			{
				int number = 0;
				int nDigit = 0;
				char* bufer = new char[MAX_LENGTH];
				nDigit = synchcons->Read(bufer, MAX_LENGTH);
				int i = bufer[0] == '-' ? 1:0 ;
				for (; i < nDigit; ++i)
				{	
					number = number*10 + (int) (bufer[i] & MASK_GET_NUM);
				}
				number = bufer[0] == '-' ? -1*number : number;
				machine->WriteRegister(2, number);
				delete bufer;
				break;
			}

			case SC_PrintInt:
			{
				char s[MAX_LENGTH], tmp;
				char neg = '-';
				int i, n, mid, sz;
				i = n = 0;
				n = machine->ReadRegister(4);
				if (n < 0)
				{//print '-' if number < 0
					synchcons->Write(&neg,1);
					n = -n;
				}
				do {//convert int to char[]
					s[i++] = n%10 + '0';
				}	while (( n /= 10) > 0);
				// reserve
				sz = i;
				s[sz] = '\n';
				mid = i / 2;
				while (i-->mid)
				{
					tmp = s[sz-i-1];
					s[sz-i-1] = s[i];
					s[i] = tmp;
				}
				synchcons->Write(s, sz);
				break;
			}
						
			case SC_ReadChar:
			{
				int size;
				char buf[MAX_LENGTH];
				size = synchcons->Read(buf, MAX_LENGTH);
				machine->WriteRegister(2, buf[size-1]);
				break;
			}
			
			case SC_PrintChar:
			{
				char c;
				c = (char) machine->ReadRegister(4);
				synchcons->Write(&c, 1);
				break;
			}
			
			case SC_ReadString:
			{
				int length = machine->ReadRegister(5);
				int addArg1 = machine->ReadRegister(4);
				char* s = new char[MAX_CHAR];
				int size = synchcons->Read(s,length);
				
				int i = 0;
				int c = 0;
				do {//save value to Arg1.
					c = (int) s[i];
					machine->WriteMem(addArg1+i, 1, c);
					i++;
				} while (i < length && c != 0);
				delete[]s;
				break;
			}
			case SC_PrintString:
			{
				int addArg1 = machine->ReadRegister(4);
				char* s = new char[MAX_CHAR];
				int c;
				//Read value from Arg1.
				for (int i = 0; i < MAX_CHAR; ++i)
				{
					machine->ReadMem(addArg1+i, 1, &c);
					s[i] = c;
					if (c == 0) break;
				}
				//Print each char to screen. Not include '\n'. 
				int i = 0;
				while (s[i] != 0 && s[i] != '\n')
				{
					synchcons->Write(s+i, 1);
					i++;
				}
				//s[i] = '\n';
				//synchcons->Write(s+i, 1);
				delete[]s;
				break;
			}
			case SC_Halt:
			DEBUG('a', "Shutdown, initiated by user program.\n");
			interrupt->Halt();
			break;
		}
	}
     // increment value in PC register         
	machine->registers[PrevPCReg] =       machine->registers[PCReg];
	machine->registers[PCReg] =       machine->registers[NextPCReg];
	machine->registers[NextPCReg] += 4;
}


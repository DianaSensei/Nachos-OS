#include "syscall.h"

int main()
{
	PrintString("** Gioi thieu ve nhom : \n- 1753130 - Doan Trieu Vinh.\n- 1753107 - Nguyen Duc Thong.\n\n** Mo ta ve thuat toan Bubble Sort : \nThuat toan sap xep Bubble Sort thuc hien sap xep day so bang cach lap lai cong viec doi cho 2 phan tu lien tiep nhau neu chung dung sai thu tu (so sau be hon so truoc trong truong hop sap xep tang dan) cho den khi day so duoc sap xep.\n");
	PrintString("Gia su ta sap xep day so [7 1 4 2 8] tang dan : \n- Lan lap dau tien: \n+ ( 7 1 4 2 8 ) –> ( 1 7 4 2 8 ), o day, thuat toan se so sanh hai phan tu dau tien va doi cho cho nhau do 7 > 1.\n+ Sau do tiep tuc nhay len cap 7 va 4 de so sanh : ( 1 7 4 2 8 ) –>  ( 1 4 7 2 8 ), doi cho do 7 > 4.\n+ Cap phan tu tiep theo 7 va 2 : ( 1 4 7 2 8 ) –>  ( 1 4 2 7 8 ), doi cho do 7 > 2.\n+ ( 1 4 2 7 8 ) –> ( 1 4 2 7 8 ), cap tiep theo khong can doi cho do da o dung thu tu (8 > 7).\n");
	PrintString("- Lan lap thu 2: \n+ ( 1 4 2 7 8 ) –> ( 1 4 2 7 8 )\n+ ( 1 4 2 7 8 ) –> ( 1 2 4 7 8 ), doi cho do 4 > 2\n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\nBay gio day da duoc sap xep dung thu tu tu be den lon nhung thuat toan chung ta chua the nhan ra ma can phai co them 1 vong lap sao cho no co the chay tu dau toi cuoi ma khong phai doi cho phan tu bat ki lan nao nua thi moi dung lai.\n");
	PrintString("- Lan lap thu 3: \n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\n+ ( 1 2 4 7 8 ) –> ( 1 2 4 7 8 )\n");
	
	return 0;
}

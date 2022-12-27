#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

double Inter(double PrevBalance,double inter)
{
	return PrevBalance*(inter/100);
}

double Tol(double PrevBalance,double Inter)
{
	return PrevBalance+Inter;
}

double New(double Total, double Payment)
{
	return Total - Payment;
}

int main(){	
	double PrevBalance,Interest,Interest1,Total,Payment,NewBalance;
	int year = 1;

	cout << "Enter initial loan: ";
	cin >> PrevBalance;
	cout << "Enter interest rate per year (%): ";
	cin >> Interest;
	cout << "Enter amount you can pay per year: ";
	cin >> Payment;
	
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

while (PrevBalance > 0)
{
	Interest1 = Inter(PrevBalance, Interest);
	Total = Tol(PrevBalance, Interest1);
	if (Payment > Total) Payment = Total;

	NewBalance = New(Total,Payment);

	cout << fixed << setprecision(2); 
	cout << setw(13) << left << year; 
	cout << setw(13) << left << PrevBalance;
	cout << setw(13) << left << Interest1;
	cout << setw(13) << left << Total;
	cout << setw(13) << left << Payment;
	cout << setw(13) << left << NewBalance;
	cout << "\n";		


	year++;	
	PrevBalance = NewBalance;
}
	
	return 0;
}

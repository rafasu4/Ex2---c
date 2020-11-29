#ifndef MYBANK
#define MYBANK

void initial();

double openAccount(double amount);

double accountRemain(double accountNumber);

double deposit (double amount, double accountNumber);

double withdraw(double amount, double accountNumber);

double closeAccount(double accountNumber);

void interest (double interes);

void printAll();

void closeAll();

#endif

#include "TicketMachine.h"

#include <iostream>
using namespace std;


TicketMachine::TicketMachine():PRICE(0)
{
    //ctor
}

TicketMachine::~TicketMachine()
{
    //dtor
}

void TicketMachine::getMoney()
{
    cout << "pls input the balance " << endl;
    cin >> balance;

}

void TicketMachine::showBalance()
{
    cout << "your balance is " << balance << "!" << endl;

}

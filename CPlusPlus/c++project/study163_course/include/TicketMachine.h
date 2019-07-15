#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H


class TicketMachine
{
    public:
        TicketMachine(); //构造函数 constructor
        virtual ~TicketMachine();  // 虚析构函数 destructor
        void showPrompt();
        void getMoney();
        void printTicket();
        void showBalance();
        void printError();

    protected:

    private:
        const int PRICE;
        int balance;
        int total;

};   //一定要有这个分号，不然编译器会以为这个class没有定义完成

#endif // TICKETMACHINE_H

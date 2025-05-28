#include "account.h"
#include<iostream>
//四舍五入到小数点后两位
double SavingsAccount::round(double amount)
{
    return (int)(amount * 100 + (amount > 0 ? 0.5 : -0.5)) / 100.0;
}
SavingsAccount::SavingsAccount(int date, int id, double rate)
    :id(id), balance(0.0), rate(rate), lastDate(date), accumulation(0.0) {}
int SavingsAccount::getId()  const { return id; }
double SavingsAccount::getBalance()  const { return balance; }
double SavingsAccount::getRate()  const { return rate; }
void SavingsAccount::record(int date, double amount) {
    int miku = date - lastDate;//miku是距离上次存钱的天数
    accumulation += miku * balance;
    balance += amount;
    lastDate = date;
}
void SavingsAccount::deposit(int date, double amount) {
    record(date, round(amount));
}
void SavingsAccount::withdraw(int date, double amount) {
    record(date, -round(amount));
}
void SavingsAccount::show() const {
    int intpart = (int)balance;//整数部分
    int decpart = (int)(balance - intpart) * 100 + 0.5;//小数部分四舍五入
    std::cout << "#" << id << "\tBalance:" << intpart << "."
        << (decpart < 10 ? "0" : "") << decpart;//补零显示
}
void SavingsAccount::settle(int date) {
    double interest = accumulation * rate / 365; // 计算利息
    interest = round(interest);
    record(date, interest);
    accumulation = 0; // 重置累积
}
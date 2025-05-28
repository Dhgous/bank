#include "account.h"
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
//四舍五入到小数点后两位
double SavingsAccount::round(double amount) {
    return std::round(amount * 100) / 100.0;
}
SavingsAccount::SavingsAccount(int date, int id, double rate)
    :id(id), balance(0.0), rate(rate), lastDate(date), accumulation(0.0) {
    cout << date << "\t#" << id << " is created" << endl;
}
int SavingsAccount::getId()  const { return id; }
double SavingsAccount::getBalance()  const { return balance; }
double SavingsAccount::getRate()  const { return rate; }
void formatOutput(double value) {
    int intPart = static_cast<int>(value);
    double fractional = value - intPart;
    // 四舍五入到分
    int cents = static_cast<int>(round(fractional * 100.0));
    // 处理进位
    if (cents >= 100) {
        intPart += 1;
        cents -= 100;
    }
    // 输出整数部分
    cout << intPart;
    // 输出小数部分
    if (cents > 0) {
        cout << '.';
        // 输出十位数
        if (cents >= 10) {
            cout << cents / 10;
            // 输出个位数
            if (cents % 10 != 0) {
                cout << cents % 10;
            }
        }
        // 输出个位数
        else {
            cout << '0' << cents;
        }
    }
}
void SavingsAccount::record(int date, double amount) {
    int miku = date - lastDate;//miku是距离上次存钱的天数
    accumulation += miku * balance;
    balance += amount;
    lastDate = date;
    cout << date << "\t#" << id << "\t";//交易记录
    if (amount >= 0) {
        cout << amount;
    }
    else {
        cout << amount; // 负数自带负号
    }
    cout << "\t" << fixed << setprecision(2) << balance << endl;
}
void SavingsAccount::deposit(int date, double amount) {
    record(date, round(amount));
}
void SavingsAccount::withdraw(int date, double amount) {
    record(date, -round(amount));
}
void SavingsAccount::show() const {
    cout << "#" << id << "\tBalance: ";
    formatOutput(balance);
}
//利息计算
void SavingsAccount::settle(int date) {
    // 先计算并记录从上次操作到结算日期的天数
    int days = date - lastDate;
    accumulation += days * balance;

    // 计算利息并四舍五入
    double interest = accumulation * rate / 365;
    interest = round(interest);

    // 重置累积并记录利息
    accumulation = 0;
    record(date, interest);
}
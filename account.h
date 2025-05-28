#ifndef account_h
#define account_h
class SavingsAccount {
private:
	int id;
	double balance;//余额
	double rate;//年利率
	int lastDate;//最后一次操作日期
	double accumulation;//余额
	void record(int date, double amount);//交易记录
	static double round(double amount);//四舍五入
public:
	SavingsAccount(int date, int id, double rate);
	//获取账户信息
	int getId() const;//返回账户ID
	double getBalance() const;//返回当前余额
	double getRate() const;//返回年利率
	//操作函数
	void show() const;//显示账户信息
	void deposit(int date, double amount);//存
	void withdraw(int date, double amount);//取
	void settle(int date);//利息
};
#endif

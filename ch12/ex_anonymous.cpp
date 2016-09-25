#include <iostream>
using namespace std;

class R {//分数类
	int n;//分子
	int d;//分母
public:
	R(int n, int d = 1) :n(n), d(d) {//初始化列表
		cout << "R(" << n << '/' << d << ")" << endl;
	}
	R add(const R& r2) {
		int nd = d*r2.d;
		int nn = d*r2.n + n*r2.d;
		return R(nn, nd);//匿名对象
	}
	R mul(const R& r2) {
		return R(n*r2.n, d*r2.d);
	}
	void show() {
		cout << n << '/' << d << endl;
	}
	~R()
	{
		cout << "~(" << n << '/' << d << ")" << endl;
	}
};

int main() {
	R a(2, 5), b(3, 8);
	a.add(b).show();
	cout << "-------------------1" << endl;
	a.add(R(3, 5)).show();
	cout << "-------------------2" << endl;
	a.add(R(3)).show();
	cout << "-------------------3" << endl;
	a.add(3).show();
	cout << "-------------------4" << endl;
	a.mul(4).show();
	cout << "-------------------4" << endl;
	return 0;
}
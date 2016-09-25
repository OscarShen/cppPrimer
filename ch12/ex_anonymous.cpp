#include <iostream>
using namespace std;

class R {//������
	int n;//����
	int d;//��ĸ
public:
	R(int n, int d = 1) :n(n), d(d) {//��ʼ���б�
		cout << "R(" << n << '/' << d << ")" << endl;
	}
	R add(const R& r2) {
		int nd = d*r2.d;
		int nn = d*r2.n + n*r2.d;
		return R(nn, nd);//��������
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
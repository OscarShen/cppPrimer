#include <iostream>
#include <stdexcept>
using namespace std;

typedef int T;
class A {//数组类，封装和增强数组的功能
	T* a;
	int len;

public:
	A(const A& r) {
		a = new T[r.len];
		for (int i = 0; i < r.len; ++i) {
			a[i] = T(r.at(i));
		}
		len = r.len;
	}

	A(int n, const T& init = T()) :a(new T[n]), len(n) {
		for (int i = 0; i < n; ++i)
			a[i] = init;
		cout << a << "创建数组" << len << "个元素" << endl;
		for (int i = 0; i < n; ++i)
			cout << &a[i] << endl;
	}

	~A()
	{
		cout << "释放数组" << a << endl;
		delete[] a; a = nullptr;
	}

	//下标访问
	T& at(int idx) const {
		if (idx < 0 || idx >= len)
			throw out_of_range("out of range");
		return a[idx];
	}

	//返回元素数量
	int size() { return len; }

	//重新设置元素和大小
	void resize(int newsize, const T& val = T()) {
		if (newsize <= len)len = newsize;
		else {
			T* np = new T[newsize];
			for (int i = 0; i < len; i++)
				np[i] = a[i];
			for (int j = len; j < newsize; ++j)
				np[j] = val;
			delete[] a;
			a = np;
			len = newsize;
		}
	}

	//将元素填充进入对象中
	void fill(const T& element,const int start, const int step = 0) {
		if (start + step < 0 || start + step >= len)
			throw out_of_range("out of range");
		for (int i = start; i < start + step; ++i) {
			a[i] = element;
		}
		cout << &element << endl;
		cout << &a[start] << endl;
	}

	A& filter(A& arr) {
		for (int i = 0; i < len; ++i)
			if (arr.at(i) % 2)
				cout << arr.at(i) << ' ';
		cout << endl;
		return arr;
	}

	//打印里面所有的元素（调试使用）
	void print() {
		for (int i = 0; i < len; ++i)
			cout << a[i] << " ";
		cout << endl;
	}
};

int main() {
	A x(20);
	x.at(3) = 5;
	x.print();
	A y(10, 6);
	y.resize(15, 9);
	y.print();
	cout << "-----------------" << endl;
	x.fill(5, 3);
	cout << "-----------------" << endl;
	x.filter(x);

	A z(x);
}
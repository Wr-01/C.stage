#include<iostream>
using namespace std;

//函数参数传递的方法：值传递、地址传递、引用传递

//值传递，交换两数的值
//void swap_1(int x, int y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
////地址传递,通过指针交换两数的值
//void swap_2(int* x, int* y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
////引用传递
//void swap_3(int & x, int & y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}

////返回局部变量引用
//int& func1() {
//	int a = 10;
//	return a;
//}
////返回静态变量引用
//int& func2() {
//	static int a = 20;
//	return a;
//}
//
////引用实际上是一个指针常量（指针的指向不可改变，值可以改变） 转换为 int* const ref = &a;
//int func(int& ref) {
//	ref = 100; // ref是引用，转换为*ref = 100
//	return ref;
//}

void add1(const int& x) {
	//x=x + 1;
	cout<<x + 1<<endl;
}
void add2(int& y) {
	y=y + 2;
}

int main() {

	//int& b = 10;//定义引用时直接赋值是错误的，引用本身需要一块合法的内存空间
	const int& b = 100;
	//加上const之后不报错，是因为编译器内部自动优化代码，int temp = 100; const int& ref = temp;

	int a = 1;
	cout << "a:" << a << endl;
	//add1(a);
	//cout << "a:" << a << endl;
	add2(a);
	cout << "a:" << a << endl;

	//int a = 10;
	//int b = 5;
	////自动转换为 int* const ref = &a; 指针常量是指针指向不可改，也说明为什么引用不可更改
	//int& ref = a;
	////int& ref = b;
	//ref = 20; //内部发现ref是引用，自动帮我们转换为: *ref = 20;

	//cout << "a:" << a << endl;
	//cout << "ref:" << ref << endl;

	//cout<<func(a)<<endl;
	//cout << func(b) << endl;

	//int& ret1 = func1();
	//cout << "ret1=" << ret1 << endl;
	//cout << "ret1=" << ret1 << endl;

	//int& ret2 = func2();
	//cout << "ret2=" << ret2 << endl;
	//cout << "ret2=" << ret2 << endl;

	//func2() = 30;
	//cout << "ret2=" << ret2 << endl;

	//int a = 2;
	//int b = 4;
	//swap_1(a, b);
	//cout << "a:" << a <<" "<<"b:" << b << endl;
	//swap_2(&a, &b);
	//cout << "a:" << a <<" "<< "b:" << b << endl;
	////int c = 2;
	////int d = 4;
	//swap_3(a, b);
	//cout << "a:" << a <<" "<< "b:" << b << endl;

	//int a = 10;
	//int n = 20;
	////int& c;
	//int& c = n;
	//cout << "c=" << c << endl;
	//c = a;
	//cout << "a=" << a << endl;
	//cout << "n=" << n << endl;
	//cout << "c=" << c << endl;
	//int& b = a;
	//cout << a << endl;
	//cout << b << endl;
	//b = 20;
	//cout << a << endl;
	//cout << b << endl;

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

//�����������ݵķ�����ֵ���ݡ���ַ���ݡ����ô���

//ֵ���ݣ�����������ֵ
//void swap_1(int x, int y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}
////��ַ����,ͨ��ָ�뽻��������ֵ
//void swap_2(int* x, int* y) {
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
////���ô���
//void swap_3(int & x, int & y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}

////���ؾֲ���������
//int& func1() {
//	int a = 10;
//	return a;
//}
////���ؾ�̬��������
//int& func2() {
//	static int a = 20;
//	return a;
//}
//
////����ʵ������һ��ָ�볣����ָ���ָ�򲻿ɸı䣬ֵ���Ըı䣩 ת��Ϊ int* const ref = &a;
//int func(int& ref) {
//	ref = 100; // ref�����ã�ת��Ϊ*ref = 100
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

	//int& b = 10;//��������ʱֱ�Ӹ�ֵ�Ǵ���ģ����ñ�����Ҫһ��Ϸ����ڴ�ռ�
	const int& b = 100;
	//����const֮�󲻱�������Ϊ�������ڲ��Զ��Ż����룬int temp = 100; const int& ref = temp;

	int a = 1;
	cout << "a:" << a << endl;
	//add1(a);
	//cout << "a:" << a << endl;
	add2(a);
	cout << "a:" << a << endl;

	//int a = 10;
	//int b = 5;
	////�Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	//int& ref = a;
	////int& ref = b;
	//ref = 20; //�ڲ�����ref�����ã��Զ�������ת��Ϊ: *ref = 20;

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
#include<iostream>
using namespace std;

class Complex
{
private:
	double _real;//ʵ��
	double _imag;//�鲿
public:
	Complex(double, double);//���캯��
	Complex(Complex& c);//�������캯��
	~Complex();//��������
	void show();
	//�����͸����ļ���
	Complex operator+(Complex& c);
	Complex operator-(Complex& c);
	Complex operator*(Complex& c);
	Complex operator/(Complex& c);
	//������ʵ���ļ���
	Complex operator+(int& c);
	Complex operator-(int& c);
	Complex operator*(int& c);
	Complex operator/(int& c);
};

Complex::Complex(double real = 0, double imag = 0)//���캯��
{
	_real = real;
	_imag = imag;
}

Complex::Complex(Complex& c)
{
	_real = c._real;
	_imag = c._imag;
}

Complex::~Complex()
{
	_real = 0.0;
	_imag = 0.0;
}

void Complex::show()
{
	cout << _real << " + " << _imag << " * i"<<endl;
}

Complex Complex::operator+(Complex& c)
{
	Complex sum;
	sum._real = this->_real + c._real;
	sum._imag = this->_imag + c._imag;
	return sum;
}

Complex Complex::operator-(Complex& c)
{
	Complex sub;
	sub._real = _real - c._real;
	sub._imag = _imag - c._imag;
	return sub;
}

Complex Complex::operator*(Complex& c)
{
	//(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
	Complex mul;
	mul._real = _real * (c._real) - _imag * (c._imag);
	mul._imag = _imag * (c._real) + _real * (c._imag);
	return mul;
}

Complex Complex::operator/(Complex& c)
{
	//(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
	Complex div;
	div._real = (_real*c._real + _imag * c._imag) / (c._real*c._real + c._imag*c._imag);
	div._imag = (_imag*c._real - _real * c._imag) / (c._real*c._real + c._imag*c._imag);
	return div;
}

Complex Complex::operator+(int& c)
{
	Complex sum;
	sum._real = _real + c;
	sum._imag = _imag;
	return sum;
}

Complex Complex::operator-(int& c)
{
	Complex sub;
	sub._real = _real - c;
	sub._imag = _imag;
	return sub;
}

Complex Complex::operator*(int& c)
{
	Complex mul;
	mul._real = _real * c;
	mul._imag = _imag;
	return mul;
}

Complex Complex::operator/(int& c)
{
	Complex div;
	div._real = _real / c;
	div._imag = _imag;
	return div;
}

int main()
{
	Complex c1;
	Complex c2(2, 3);
	Complex c3(7, 8);
	Complex c4(3, 4);
	Complex out;
	cout << "      ����1:  ";
	c1.show();
	cout << "      ����2:  ";
	c2.show();
	cout << "      ����3:  ";
	c3.show();
	cout << "      ����4:  ";
	c4.show();
	cout << "����1,2���:  ";
	out = c1 + c2;
	out.show();
	cout << "����3,4����� ";
	out = c3 - c4;
	out.show();
	cout << "����2,3��ˣ� ";
	out = c2 * c3;
	out.show();
	cout << "����2,4����� ";
	out = c2 / c4;
	out.show();
	system("pause");
	return 0;
}
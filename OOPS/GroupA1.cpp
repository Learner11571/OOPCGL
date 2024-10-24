#include <iostream>
using namespace std;
class complex
{
public:
    float real, img;
    complex() {}
    complex operator+(complex);
    complex operator*(complex);
    friend ostream &operator<<(ostream &, complex &);
    friend istream &operator>>(istream &, complex &);
};
complex complex::operator+(complex obj)
{
    complex temp;
    temp.real = real + obj.real;
    temp.img = img + obj.img;
    return (temp);
}
istream &operator>>(istream &is, complex &obj)
{
    is >> obj.real;
    is >> obj.img;
    return is;
}
ostream &operator<<(ostream &outt, complex &obj)
{
    outt << " " << obj.real;
    outt << "+" << obj.img << "i";
    return outt;
}
complex complex::operator*(complex obj)
{
    complex temp;
    temp.real = real * obj.real - img * obj.img;
    temp.img = img * obj.real + real * obj.img;
    return (temp);
}
int main()
{
    complex a, b, c, d;
    cout << "\n The first Complex number is: ";
    cout << "\nEnter real and img: ";
    cin >> a;
    cout << "\n The second Complex number is: ";
    cout << "\nEnter real and img: ";
    cin >> b;
    cout << "\n\n Arithmetic operations ";
    c = a + b;
    cout << "\n Addition = ";
    cout << c;
    d = a * b;
    cout << "\n Multiplication = ";
    cout << d;
    cout << endl;
    return 0;
}
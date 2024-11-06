#include<iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()  // construct by default
    {
        cout << "Construct\n";
        x = y = 0;
    }
    friend ostream& operator<<(ostream&os,Point&obj) {
        os <<"X = " << obj.GetX()<<"\tY = " << obj.GetY();
        return os;
    }
    friend istream& operator>>(istream& is, Point& obj) {
        int _x;
        int _y;
        is >> _x;
        is >> _y;
        obj.SetX(_x);
        obj.SetY(_y);
        return is;
    }
    Point(int x1, int y1)   // Construct by 2 param
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    // ���������� �������� ��������

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    }
    void SetX(int a)
    {
        x = a;
    }
    void SetY(int a)
    {
        y = a;
    }
};

Point operator+(int a, Point b)
{
    Point rez;
    rez.SetX(b.GetX() + a);
    rez.SetY(b.GetY() + a);
    return rez;
}
//Point operator+( Point b, int a)
//{
//    Point rez;
//    rez.SetX(b.GetX() + a);
//    rez.SetY(b.GetY() + a);
//    return rez;
//}

Point operator--(Point& a) {
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return a;
}

Point operator--(Point& a, int) {
    Point temp;
    a.SetX(a.GetX() - 1);
    a.SetY(a.GetY() - 1);
    return temp;
}
Point operator++(Point& a)// ++a
{
    a.SetX(a.GetX() + 10);
    a.SetY(a.GetY() + 10);
    return a;

}
Point operator++(Point& a, int)// a++
{
    Point temp = a;
    a.SetX(a.GetX() + 10);
    a.SetY(a.GetY() + 10);
    return temp;
}

Point operator-(int a, Point& b) {
    Point temp(a - b.GetX(), a - b.GetY());
    return temp;
}

Point operator*(int a, Point& b) {
    Point temp(a * b.GetX(), a * b.GetY());
    return temp;
}
Point operator/(int a, Point& b) {
    Point temp(a / b.GetX(), a / b.GetY());
    return temp;
}

int operator+(Point& a, Point& b) {
    int temp = a.GetX() + b.GetX() + a.GetY() + b.GetY();
    return temp;
}

int main()
{
    srand(unsigned(time(0)));

    Point a(1, 2);
    Point b(3, 4);
    a.Output();
    Point c;
    cin >> c;
    cout << c;
    /// ��
    //// ---------- ������� 1
    //Point q = 100 - a;
    //q = 10*a;
    //q = 100 / a;
    //int res = a + b;//  ����� �������!

    //Point t = --a;
    //Point d = a--;



}
#include <iostream>
#include <string>
using namespace std;

class publication
{
private:
    string title;
    float price;

public:
    void getdata(void)
    {
        string t;
        float p;
        cout << "Enter title of publication: ";
        cin >> t;
        cout << "Enter price of publication: ";
        cin >> p;
        title = t;
        price = p;
    }

    void putdata(void)
    {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public publication
{
private:
    int pagecount;

public:
    void getdata(void)
    {
        publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }

    void putdata(void)
    {
        publication::putdata();
        cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication
{
private:
    float ptime;

public:
    void getdata(void)
    {
        publication::getdata();
        cout << "Enter tape's playing time (in min): ";
        cin >> ptime;
    }

    void putdata(void)
    {
        publication::putdata();
        cout << "Tape's playing time: " << ptime << endl;
    }
};

int main(void)
{
    book b;
    tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
    return 0;
}

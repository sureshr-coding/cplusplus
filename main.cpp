#include <iostream>

using namespace std;

class array {
    int *p;
    int size;
public:
    array (int s)
    {
        try {
            p = new int[s];
        } catch (bad_alloc) {
            cout << "Allocation failure in constructor array" << endl;
            exit(0);
        }
        size = s;
    }
    ~array() {
        delete [] p;
        p = nullptr;
    }

    array(const array &cs)
    {
        try {
            p = new int[cs.size];
            cout << "new initialization" << endl;
        } catch (bad_alloc) {
            cout << "Allocation failure in copy constructor" << endl;
            exit (0);
        }
        int i;
        for (i=0; i < cs.size; i++) {
            p[i] = cs.p[i];
        }
        size = cs.size;
    }
};

class loc
{
    int longitude, latitude;
public:
    loc(int a, int b)
    {
        longitude = a;
        latitude = b;
    }

    loc()
    {
        longitude = 0;
        latitude = 0;
    }

    void show()
    {
        cout << "longitude " << longitude << endl;
        cout << "latitude " << latitude << endl;
    }

    loc operator+(loc a);
    loc operator-(loc a);
    loc operator=(loc a);
    loc operator++();
};

loc loc::operator+(loc a)
{
    loc temp;
    temp.longitude = longitude + a.longitude;
    temp.latitude = latitude + a.latitude;
    return temp;
}

int main() {
    cout << "Hello, World!" << endl;
    string a = "09/03/2023";
    int b = 0, c = 0, d = 0;
    sscanf(a.c_str(), "%d%*c%d%*c%d", &b, &c, &d);
    cout << "b c d are: "<< b << c << d << endl;

    array sam(10);
    array mark = sam;

    loc ax1(40, 50), ax2(50, 60);
    loc ax3 = ax1 + ax2;
    ax3.show();

    int *xx = (int*)malloc(4*sizeof(int));
    xx[0] = 355;
    xx[1] = 3;
    xx[2] = 51;
    xx[3] = 31;
    xx[4] = 31;
    xx[5] = 355;
    xx[6] = 3;
    xx[7] = 51;
    xx[8] = 31;
    xx[9] = 31;

    cout << "xx0 " << xx[0] << endl;
    cout << "xx1 " << xx[1] << endl;
    cout << "xx2 " << xx[2] << endl;
    cout << "xx3 " << xx[3] << endl;
    cout << "xx4 " << xx[4] << endl;
    cout << "size of xx " << sizeof(xx) << endl;
    cout << "size of int " << sizeof(int) << endl;
    cout << "1. address of xx " << &xx << endl;
    int *xx1 = xx++;
    cout << "2. address of xx " << &xx1 << endl;

    cout << "2. address of xx " << &(++xx) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
using namespace std;

class My_exception_1 {};
class My_exception_2
{
    string msg;
    int code;
public:
    My_exception_2(int code, string msg) : code(code), msg(msg) {}
    string message() const { return msg; }
    int getCode() const { return code; }
};
class My_exception_3 : public invalid_argument
{
    string msg;
public:
    My_exception_3(string msg) : invalid_argument(msg) {}
};


double GeoProg(int b1, int n, int q)
{
    return b1 * (pow(q, n) - 1) / (q - 1);
}

double GeoProg_1(int b1, int n, int q) throw()
{
    return b1 * (pow(q, n) - 1) / (q - 1);
}

double GeoProg_2(int b1, int n, int q) throw(invalid_argument)
{
    if (b1 == 0) throw invalid_argument("Error № 1  - nulevoy nachalniy chlen!!!!");
    if (q == 0) throw invalid_argument("Error № 2  - nulevoy coefficient!!!!");
    if (q == 1) throw invalid_argument("Error № 3  - edinichniy coefficient!!!!");
    if (n <= 1) throw invalid_argument("Error № 4  - nedopustimiy nomer chlena!!!!");
    return b1 * (pow(q, n) - 1) / (q - 1);
}

double GeoProg_3_1(int b1, int n, int q) throw(My_exception_1)
{
    return b1 * (pow(q, n) - 1) / (q - 1);
}

double GeoProg_3_2(int b1, int n, int q) throw(My_exception_2)
{
    if (b1 == 0) throw My_exception_2(1, "Error № 1  - nulevoy nachalniy chlen!!!!");
    if (q == 0) throw My_exception_2(2, "Error № 2  - nulevoy coefficient!!!!");
    if (q == 1) throw My_exception_2(3, "Error № 3  - edinichniy coefficient!!!!");
    if (n <= 1) throw My_exception_2(4, "Error № 4  - nedopustimiy nomer chlena!!!!");
    return b1 * (pow(q, n) - 1) / (q - 1);
}

double GeoProg_3_3(int b1, int n, int q) throw(My_exception_3)
{
    if (b1 == 0) throw My_exception_3("Error № 1  - nulevoy nachalniy chlen!!!!");
    if (q == 0) throw My_exception_3("Error № 2  - nulevoy coefficient!!!!");
    if (q == 1) throw My_exception_3("Error № 3  - edinichniy coefficient!!!!");
    if (n <= 1) throw My_exception_3("Error № 4  - nedopustimiy nomer chlena!!!!");
    return b1 * (pow(q, n) - 1) / (q - 1);
}

void main()
{
    int count = 0;
    cin >> count;
    int b1 = 0, q = 0, n = 0;
    for (int i = 0; i < count; i++)
    {
        try
        {

            cin >> b1 >> q >> n;
            cout << GeoProg_3_2(b1, n, q) << endl;

        }
        catch (My_exception_2 exception)
        {
            cout << exception.message() << endl;

        }
    }
    //return 0;
}
#include <iostream>
#include <string>
#include "calculator.h"

using namespace std;

int main()
{
    Calculator calc;
    double res;
    string line;
    string p_input;

    cout << "Entering 'q' or 'stop' will stop." << endl;

    getline(cin, line);
    while (line != "q" || line != "stop") {
        calc = Calculator();
        p_input = line;
        res = calc.calculate(p_input);
        cout << line << " " << res << endl;
        getline(cin, line);
    }
    return 0;
}

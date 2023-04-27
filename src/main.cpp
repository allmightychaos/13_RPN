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

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line == "clear") {
            system("clear");
            continue;
        }
        else if (line == "q" || line == "stop") {
            break;
        }
        else {
            calc = Calculator();
            p_input = line;
            res = calc.calculate(p_input);
            cout << line << " " << res << endl;
        }
    }

    return 0;
}

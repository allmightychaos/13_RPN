#include <iostream>
#include <string>
#include <iomanip>
#include "calculator.h"

using namespace std;

int main()
{
    system("clear");
    Calculator calc;
    double res;
    string line;
    string p_input;
    const int max_calc_length = 10;
    const int total_length = 15;

    cout << "Entering 'q' or 'stop' will stop." << endl;

    while (true) {
        try {
            cout << "> ";
            getline(cin, line);

            if (line == "clear") {
                system("clear");
                continue;
            }
            else if (line == "q" || line == "stop") {
                system("clear");
                break;
            }
            else {
                calc = Calculator();
                p_input = line;
                res = calc.calculate(p_input);

                string truncated_input = p_input.substr(0, max_calc_length);
                if (p_input.length() > max_calc_length) {
                    truncated_input = truncated_input.substr(0, truncated_input.length() - 2) + "...";
                }

                cout << setw(total_length - 2) << left << truncated_input << "= " << res << "\n" << endl;
            }
        }
        catch (const std::invalid_argument) {
            cout << "Invalid input. Try again!" << endl;
            continue;
        }
        catch (const std::logic_error) {
            cout << "Error: Invalid RPN expression. Try again!" << endl;
            continue;
        }
    }

    return 0;
}

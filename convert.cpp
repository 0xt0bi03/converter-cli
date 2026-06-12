#include <bits/stdc++.h>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

unordered_map<string, double> length = {
    {"mm", 0.001},
    {"cm", 0.01},
    {"dm", 0.1},
    {"m", 1.0},
    {"km", 1000.0},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1609.344},
    {"nmi", 1852.0},
    {"um", 1e-6},
    {"nm", 1e-9}
};

double calculate(const string& from, const string& to, double value)
{
    return value * length[from] / length[to];
}

void printHelp()
{
	clearScreen();
    cout << "CONVERTER++\n\n";
    cout << "Usage:\n";
    cout << "  convert <from> <to> <value>\n\n";
    cout << "Examples:\n";
    cout << "  convert cm m 100\n";
    cout << "  convert km mi 5\n\n";
    cout << "Options:\n";
    cout << "  --help         Show this help message\n";
    cout << "  --list-units   Show all available units\n";
}

void listUnits()
{
    cout << "Available units:\n";

    for (const auto& unit : length)
    {
        cout << "  " << unit.first << '\n';
    }
}

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        string arg = argv[1];

        if (arg == "--help")
        {
            printHelp();
            return 0;
        }

        if (arg == "--list-units")
        {
            listUnits();
            return 0;
        }
    }

    if (argc != 4)
    {
        cerr << "Usage: convert <from> <to> <value>\n";
        cerr << "Try 'convert --help' for more information.\n";
        return 1;
    }

    string from = argv[1];
    string to = argv[2];

    if (!length.count(from))
    {
        cerr << "Error: Unknown unit '" << from << "'\n";
        return 1;
    }

    if (!length.count(to))
    {
        cerr << "Error: Unknown unit '" << to << "'\n";
        return 1;
    }

    double value;

    try
    {
        value = stod(argv[3]);
    }
    catch (...)
    {
        cerr << "Error: Invalid number '" << argv[3] << "'\n";
        return 1;
    }

    double result = calculate(from, to, value);

    cout << result << '\n';

    return 0;
}
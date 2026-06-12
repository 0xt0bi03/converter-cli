#include <bits/stdc++.h>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


// length
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

// weight
unordered_map<string, double> mass = {
	{"mg", 1e-6},        // milligram
    {"g", 0.001},        // gram
    {"kg", 1.0},         // kilogram (base unit)
    {"t", 1000.0},       // metric ton
    {"oz", 0.0283495},   // ounce
    {"lb", 0.453592},    // pound
    {"st", 6.35029},     // stone
    {"ust", 907.185},    // US short ton
    {"lt", 1016.05},     // Long ton (UK)
    {"ug", 1e-9}         // microgram
};

unordered_map <string, unordered_map<string, double>> units = {{"length", length}, {"mass", mass}};

double calculate(const string& param, const string& from, const string& to, double value)
{
	return value * units[param][from] / units[param][to];
}

void printHelp()
{
	clearScreen();
    cout << "CONVERTER++\n\n";
    cout << "Usage:\n";
    cout << "  convert <param> <from> <to> <value>\n\n";
    cout << "Examples:\n";
    cout << "  convert length cm m 100\n";
    cout << "  convert mass kg g 5\n\n";
    cout << "Options:\n";
    cout << "  --help         Show this help message\n";
    cout << "  --list-units   Show all available units\n";
}

void listUnits()
{
    cout << "Length units:\n";
    for (const auto& unit : length)
        cout << "  " << unit.first << '\n';

    cout << "\nMass units:\n";
    for (const auto& unit : mass)
        cout << "  " << unit.first << '\n';
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

    if (argc != 5)
    {
        cerr << "Usage: convert <param> <from> <to> <value>\n";
        cerr << "Try 'convert --help' for more information.\n";
        return 1;
    }

	string param = argv[1];
    string from = argv[2];
    string to = argv[3];

	if(param != "length" && param != "mass")
	{
		cerr << "Error: Unknown unit '" << param << "'\n";
        return 1;
	}

    if (!units[param].count(from))
	{
		cerr << "Error: Unknown unit '" << from << "'\n";
		return 1;
	}

	if (!units[param].count(to))
	{
		cerr << "Error: Unknown unit '" << to << "'\n";
		return 1;
	}

    double value;

    try
    {
        value = stod(argv[4]);
    }
    catch (...)
    {
        cerr << "Error: Invalid number '" << argv[4] << "'\n";
        return 1;
    }

    double result = calculate(param, from, to, value);

    cout << result << " " << to << '\n';

    return 0;
}
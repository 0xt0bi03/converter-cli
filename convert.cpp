#include <bits/stdc++.h>
using namespace std;

// this clears the screen 
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

// time
unordered_map<string, double> time_data = {
    {"ns", 1e-9},          // nanosecond
    {"us", 1e-6},          // microsecond
    {"ms", 1e-3},          // millisecond
    {"s", 1.0},            // second
    {"min", 60.0},         // minute
    {"h", 3600.0},         // hour
    {"d", 86400.0},        // day
    {"wk", 604800.0},      // week
    {"mo", 2629800.0},     // month (30.44 days average)
    {"yr", 31557600.0}     // year (365.25 days)
};

// data
unordered_map<string, double> data_speed = {
    {"b", 1.0 / 8.0},                // bit
    {"B", 1.0},                      // byte
    {"KB", 1000.0},
    {"MB", 1000.0 * 1000.0},
    {"GB", 1000.0 * 1000.0 * 1000.0},
    {"TB", 1000.0 * 1000.0 * 1000.0 * 1000.0},

    {"KiB", 1024.0},
    {"MiB", 1024.0 * 1024.0},
    {"GiB", 1024.0 * 1024.0 * 1024.0},
    {"TiB", 1024.0 * 1024.0 * 1024.0 * 1024.0}
};

unordered_map<string, double> area = {
    {"mm2", 1e-6},
    {"cm2", 1e-4},
    {"m2", 1.0},
    {"km2", 1e6},
    {"ha", 10000.0},      // hectare
    {"ac", 4046.8564224}, // acre
    {"ft2", 0.09290304},
    {"yd2", 0.83612736},
    {"mi2", 2589988.110336}
};

unordered_map<string, double> volume = {
    {"mm3", 1e-9},
    {"cm3", 1e-6},
    {"m3", 1.0},
    {"L", 0.001},
    {"mL", 1e-6},
    {"ft3", 0.0283168},
    {"yd3", 0.764555},
    {"gal", 0.00378541}, // US gallon
    {"qt", 0.000946353},
    {"pt", 0.000473176}
};


unordered_map<string, double> speed = {
    {"mps", 1.0},
    {"kph", 0.277778},
    {"mph", 0.44704},
    {"fps", 0.3048},
    {"knot", 0.514444}
};

unordered_map<string, double> pressure = {
    {"Pa", 1.0},
    {"kPa", 1000.0},
    {"MPa", 1e6},
    {"bar", 100000.0},
    {"atm", 101325.0},
    {"psi", 6894.757},
    {"torr", 133.322}
};

unordered_map<string, double> energy = {
    {"J", 1.0},
    {"kJ", 1000.0},
    {"MJ", 1e6},
    {"Wh", 3600.0},
    {"kWh", 3.6e6},
    {"cal", 4.184},
    {"kcal", 4184.0},
    {"BTU", 1055.06}
};

unordered_map<string, double> power = {
    {"W", 1.0},
    {"kW", 1000.0},
    {"MW", 1e6},
    {"GW", 1e9},
    {"hp", 745.7}
};

unordered_map<string, double> force = {
    {"N", 1.0},
    {"kN", 1000.0},
    {"MN", 1e6},
    {"lbf", 4.44822},
    {"kgf", 9.80665}
};

unordered_map<string, double> frequency = {
    {"Hz", 1.0},
    {"kHz", 1e3},
    {"MHz", 1e6},
    {"GHz", 1e9},
    {"THz", 1e12}
};


unordered_map<string, double> angle = {
    {"rad", 1.0},
    {"deg", 0.01745329252},
    {"grad", 0.01570796327},
    {"rev", 6.28318530718}
};

// all the units for calling
unordered_map <string, unordered_map<string, double>> units = {
	{"length", length}, 
	{"mass", mass},
	{"time", time_data},
	{"data", data_speed},
	{"area", area},
	{"volume", volume},
	{"speed", speed},
	{"pressure", pressure},
	{"energy", energy},
	{"power", power},
	{"force", force},
	{"frequency", frequency},
	{"angle", angle},
};

double calculate(const string& param, const string& from, const string& to, double value)
{
    return value * units.at(param).at(from) / units.at(param).at(to);
}


// this prints the help function to how to use it
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

// lists all the units available for conversion
void listUnits()
{	
	for(const auto& it : units)
	{
		cout << it.first << ":\n";
		for(const auto& iter : it.second)
		{
			cout << "  " << iter.first << endl;
		}
		cout << endl;
	}
}

// main function which calls everything
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

	if (!units.count(param))
	{
		cerr << "Error: Unknown parameter '" << param << "'\n";
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
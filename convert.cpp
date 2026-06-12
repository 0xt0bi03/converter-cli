#include <bits/stdc++.h>
using namespace std;

// clearing the screen.
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

double calculate(double value, string from, string to)
{
	return (value * (length[from]) / (length[to]));
	// return to_value;
}


string conversion()
{
	// string msmnts = 
	// "Length"
	// "Weight/Mass"
	// "Temperature"
	// "Area"
	// "Volume"
	// "Time"
	// "Speed"
	// "Data Storage (KB, MB, GB, etc.)"
	// "Angle";
	string from, to;
	string measurement; double value;
	while (true)
	{
		cout << "Enter the unit you want to convert from: ";
		cin >> from;
		if(length[from])
		{
			break;
		}
		else
        {
            cout << "Invalid entry..." << endl;
            cin.clear();   // fix state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the bufffer
        }
	}
	while (true)
	{
		cout << "Enter the unit you want to convert to: ";
		cin >> to;
		if(length[to])
		{
			break;
		}
		else
        {
            cout << "Invalid entry..." << endl;
            cin.clear();   // fix state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the bufffer
        }
	}
	while (true)
	{
		cout << "Enter the value: ";
		
		if(cin >> value)
		{
			break;
		}
		else
        {
            cout << "Invalid entry..." << endl;
            cin.clear();   // fix state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the bufffer
        }
	}

}


int main()
{
	clearScreen();
	cout << "CONVERTER++" << endl;
	cout << endl;

	return 0;
}

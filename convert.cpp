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

struct data_point
{
	string from;
	string to;
	double value;
};


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


// Length values to convert
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

// this is where calculation happens
double calculate(string from, string to, double value)
{
	return (value * (length[from]) / (length[to]));
	// return to_value;
}


// this is where input happens
data_point conversion()
{
	data_point dataholder;
	// asking values
	string from, to;
	string measurement; double value;
	while (true)
	{
		cout << "Enter the unit you want to convert from: ";
		cin >> dataholder.from;
		if(length[dataholder.from])
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
		cin >> dataholder.to;
		if(length[dataholder.to])
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
		
		if(cin >> dataholder.value)
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
	return dataholder;
}


int main()
{
	clearScreen();
	cout << "CONVERTER++" << endl;
	cout << endl;
	data_point recieved = conversion();

	double ans = calculate(recieved.from, recieved.to, recieved.value);

	cout << ans << " " << recieved.to << endl;


	return 0;
}

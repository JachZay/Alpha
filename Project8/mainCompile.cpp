#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "compileHeader.h"

using namespace std;

int main()
{
	cout << "1. Story Mode\n2. Test Mode\n3. Game Options\n4. Exit" << endl;
	int mainMenuOption;
	cin >> mainMenuOption;
	switch (mainMenuOption)
	{
	case 1:
		cout << "Entering story mode..." << endl;
		break;

	case 2:
		cout << "Entering system test menu..." << endl;
		menu();
		break;

	case 3:
		cout << "Game options" << endl;
		break;

	case 4:
		cout << "Exit" << endl;
		break;
	}
	return(0);
}
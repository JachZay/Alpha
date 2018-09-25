#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "compileHeader.h"

//Function prototypes
//int D20();
//int combat();
//int inventory();
//int playerhealth(int);
//int opponenthealth(int);
//int opponentlevel();
//int menu();

int menu()
{
	int game = 1;
	std::cout << "1. Skill Check\n2. Combat\n3. View/Edit Inventory\n4. Session victories\n5. Option 5\n6. Exit" << endl;
	while (game == 1)
	{
		int option, victorystate = 0;

		cin >> option;
		switch (option)
		{
		case 1:
			std::cout << "Checking skill..." << endl;
			std::cout << D20() << endl;
			break;
		case 2:
			std::cout << "Combat..." << endl;
			combat();
			std::cout << "\n1. SKill Check\n2. Combat\n3. View/Edit Inventory\n4. Session victories\n5. Option 5\n6. Exit" << endl;
			break;
		case 3:
			std::cout << "Opening inventory..." << endl;
			inventory();
			std::cout << "\n1. SKill Check\n2. Combat\n3. View/Edit Inventory\n4. Session victories\n5. Option 5\n6. Exit" << endl;
			break;
		case 4:
			std::cout << "Viewing session victories..." << endl;
			std::cout << victorycount << endl;
			std::cout << "\n1. SKill Check\n2. Combat\n3. View/Edit Inventory\n4. Session victories\n5. Option 5\n6. Exit" << endl;
			break;
		case 5:
			std::cout << "case 5" << endl;
			std::cout << "\n1. SKill Check\n2. Combat\n3. View/Edit Inventory\n4. Session victories\n5. Option 5\n6. Exit" << endl;
			break;
		case 6:
			game = 2;
		}
	}
	std::cout << "exiting program, "; system("pause");
	return(0);
}

int D20()
{
	int result;
	srand(time(NULL));
	result = rand() % 20 + 1;

	//cout << result << endl;

	return(result);
}

int inventory()
{
	std::cout << "Inventory: " << endl;
	int option, count = 0;
	while (count <= 4)
	{
		std::cout << count + 1 << ". " << invNames[count] << "  -  Damage = " << invDamage[count] << "  -  Range = " << invRange[count] << endl;
		count++;
	}

	std::cout << "1. Add pre-made item\n2.Return to main menu" << endl;
	cin >> option;
	if (option == 3)
	{
		std::cout << "\nwhich slot would you like to change?  slot #";
		cin >> count;
		count -= 1;
		std::cout << "\ncurrently: " << endl;
		std::cout << invNames[count] << "  -  Damage =" << invDamage[count] << "  -  Range = " << invRange[count] << endl;
		std::cout << "New item:" << endl;
		int newDamage, newRange;
		string newName;
		std::cout << "Name: ";
		cin >> newName;
		invNames[count] = newName;
		std::cout << "Damage: ";
		cin >> newDamage;
		invDamage[count] = newDamage;
		std::cout << "Range: ";
		cin >> newRange;
		invRange[count] = newRange;
		std::cout << "\nNew item confirmation: ";
		std::cout << invNames[count] << "  -  Damage = " << invDamage[count] << "  -  Range = " << invRange[count] << endl;
	}

	else if (option == 1)
	{
		weapons();
		std::cout << "confirm inventory: " << endl;
		count = 0;
		while (count <= 4)
		{
			std::cout << count + 1 << ". " << invNames[count] << "  -  Damage = " << invDamage[count] << "  -  Range = " << invRange[count] << endl;
			count++;
		}

	}

	else if (option == 2)
		std::cout << "Returning to main menu...\n" << endl;


	return(0);
}

int weapons()
{
	int count;
	std::cout << "\nwhich slot would you like to change?  slot #";
	cin >> count;
	count -= 1;

	std::cout << "What would you like to put in this inventory slot?" << endl;
	std::cout << "1. Baton\n2. Dual knives\n3. Laser rifle\n4. Laser pistol" << endl;

	int option;
	cin >> option;
	if (option == 1)
	{
		string weaponName[] = { "Baton" };
		int weaponDamage[] = { 2 };
		int weaponRange[] = { 1 };
	}

	else if (option == 2)
	{
		string weaponName[] = { "Dual knives" };
		int weaponDamage[] = { 3 };
		int weaponRange[] = { 1 };

		invNames[count] = weaponName[0];
		invDamage[count] = weaponDamage[0];
		invRange[count] = weaponRange[0];
	}

	else if (option == 3)
	{
		string weaponName[] = { "Laser rifle" };
		int weaponDamage[] = { 2 };
		int weaponRange[] = { 3 };

		invNames[count] = weaponName[0];
		invDamage[count] = weaponDamage[0];
		invRange[count] = weaponRange[0];
	}

	else if (option == 4)
	{
		string weaponName[] = { "Laser pistol" };
		int weaponDamage[] = { 2 };
		int weaponRange[] = { 2 };

		invNames[count] = weaponName[0];
		invDamage[count] = weaponDamage[0];
		invRange[count] = weaponRange[0];
	}

	else if (option == 5)
	{
		string weaponName[] = { "Empty" };
		int weaponDamage[] = { 0 };
		int weaponRange[] = { 0 };

		invNames[count] = weaponName[0];
		invDamage[count] = weaponDamage[0];
		invRange[count] = weaponRange[0];
	}

	return(0);
}

int playerhealth(int change)
{
	phealth += change;

	if (phealth < 0)
	{
		phealth = 0;
	}

	return(phealth);
}
int opponenthealth(int change)
{
	ohealth += change;

	if (ohealth < 0)
	{
		ohealth = 0;
	}

	return(ohealth);
}
int opponentlevel()
{
	int option;
	std::cout << "1. Easy, 1 damage\n2. normal, 2 damage\n3. hard, 3 damage\n4. heroic, 4 damage\n5. Legend, 5 damage" << endl;
	cin >> option;
	if (option == 1)
	{
		std::cout << "EASY has been selected" << endl;
	}
	else if (option == 2)
	{
		std::cout << "NORMAL has been selected" << endl;
	}
	else if (option == 3)
	{
		std::cout << "HARD has been selected" << endl;
	}
	else if (option == 4)
	{
		std::cout << "HEROIC has been selected" << endl;
	}
	else if (option == 5)
	{
		std::cout << "LEGEND has been selected" << endl;
	}


	return(option);
}

int combat()
{
	int turn = 0, result, damage, sOption, range = 1, count = 0, advantage, victory, passfail, odamage;

	std::cout << "Inventory opening, which weapon would you like to use?" << endl;

	while (count <= 4)
	{
		std::cout << invNames[count] << endl;
		count++;
	}

	cin >> count;
	count -= 1;

	std::cout << "Opponent level select: " << endl;

	odamage = opponentlevel();

	while (playerhealth(0) > 0 && opponenthealth(0) > 0)
	{
		if (turn % 2 == 0)
		{
			std::cout << "Player turn: " << "\n" << endl;

			std::cout << "1. Attack\t2. Health check\n3. Inventory\t4. Flee" << endl;
			cin >> sOption;
			switch (sOption)
			{
			case 1:
				if (range == invRange[count])
				{
					std::cout << "currently in range" << endl;

					result = D20();
					std::cout << "D20 result: " << result << endl;
					if (result < 15 || range != invRange[count])
					{
						std::cout << "failed" << endl;
						opponenthealth(0);
						std::cout << "no damage dealt\n" << "\n" << endl;
						turn += 1;
					}
					else if (result >= 15 && result < 20)
					{
						std::cout << "passed!" << endl;
						opponenthealth(-invDamage[count]);
						std::cout << "opponent health -" << invDamage[count] << "\n" << endl;
						turn += 1;
					}
					else if (result == 20)
					{
						std::cout << "perfect 20!" << endl;
						invDamage[count] += 2;
						opponenthealth(-invDamage[count]);
						invDamage[count] -= 2;
						std::cout << "opponent health -" << (invDamage[count] + 2) << "\n" << endl;
						turn += 1;
					}
					break;
				}
				else
				{
					std::cout << "Currently not in range, move reccomended" << endl;
					std::cout << "Current range, " << range << endl;
					std::cout << "Weapon range, " << invRange[count] << endl;
					std::cout << "Change range? \n1. Yes, move\n2. No, stay" << endl;
					cin >> sOption;
					switch (sOption)
					{
					case 1:
						std::cout << "Current range: " << range << endl;
						std::cout << "1. Move closer -1 \n2. Move farther +1" << endl;
						cin >> sOption;
						switch (sOption)
						{
						case 1:
							range--;
							break;
						case 2:
							range++;
							break;
						}
						std::cout << "New Range: " << range << "\n" << endl;
						break;
					}

					result = D20();
					std::cout << "D20 result: " << result << endl;
					if (result < 15 || range != invRange[count])
					{
						std::cout << "failed" << endl;
						opponenthealth(0);
						std::cout << "no damage dealt\n" << "\n" << endl;
						turn += 1;
					}
					else if (result >= 15 && result < 20)
					{
						std::cout << "passed!" << endl;
						opponenthealth(-invDamage[count]);
						std::cout << "opponent health -" << invDamage[count] << "\n" << endl;
						turn += 1;
					}
					else if (result == 20)
					{
						std::cout << "perfect 20!" << endl;
						invDamage[count] += 2;
						opponenthealth(-invDamage[count]);
						invDamage[count] -= 2;
						std::cout << "opponent health -" << (invDamage[count] + 2) << "\n" << endl;
						turn += 1;
					}
					break;
				}

			case 2:
				std::cout << "player health: " << phealth << endl;
				std::cout << "Attempt health check?\n1. Yes\n2. No" << endl;
				int option;
				cin >> option;
				switch (option)
				{
				case 1:
					std::cout << "Checking attempt:" << endl;
					result = D20();
					std::cout << result << endl;
					if (result < 15)
					{
						std::cout << "failed" << endl;
						playerhealth(0);
						std::cout << "Heal failed" << "\n" << endl;
						turn += 1;
					}
					else if (result >= 15 && result < 20)
					{
						std::cout << "Check passed!" << endl;
						playerhealth(odamage);
						std::cout << "player health +" << "" << endl;
						turn += 1;
					}
					else if (result == 20)
					{
						std::cout << setw(70) << "perfect 20!" << endl;
						odamage += 2;
						playerhealth(odamage);
						odamage -= 2;
						std::cout << setw(70) << "player health -" << odamage + 2 << endl;
						turn += 1;
					}
				}
				break;
			}
			std::cout << setw(40) << "player health: " << phealth << endl;
			std::cout << setw(40) << "Opponent health: " << ohealth << endl;
			std::cout << "\n" << endl;
		}

		else if (turn % 2 == 1)
		{
			std::cout << setw(70) << "Opponents turn:" << endl;
			result = D20();
			std::cout << result << endl;
			if (result < 15)
			{
				std::cout << setw(70) << "failed" << endl;
				playerhealth(0);
				std::cout << setw(70) << "no damage dealt" << "\n" << endl;
				turn += 1;
			}
			else if (result >= 15 && result < 20)
			{
				std::cout << setw(70) << "passed!" << endl;
				playerhealth(-odamage);
				std::cout << setw(70) << "player health -" << odamage << "\n" << endl;
				turn += 1;
			}
			else if (result == 20)
			{
				std::cout << setw(70) << "perfect 20!" << endl;
				odamage += 2;
				playerhealth(-odamage);
				odamage -= 2;
				std::cout << setw(70) << "player health -" << odamage + 2 << "\n" << endl;
				turn += 1;
			}

			std::cout << setw(40) << "player health: " << playerhealth(0) << endl;
			std::cout << setw(40) << "Opponent health: " << opponenthealth(0) << "\n" << endl;
			std::cout << "\n" << endl;
			//system("pause");
		}

	}

	if (opponenthealth(0) <= 0)
	{
		std::cout << "player win!" << endl;
		victorycount += 1;
		ohealth = 15;
	}
	else if (playerhealth(0) <= 0)
	{
		std::cout << "opponent win!" << endl;
		victorycount += 0;
		phealth = 15;
	}
	result = 1;
	return(result);
}
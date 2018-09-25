#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//Function prototypes
int D20();
int combat();
int inventory();
int playerhealth(int);
int opponenthealth(int);
int opponentlevel();
int menu();

//inventory
string invNames[5] = { "Baton", "Dual knives", "Laser rifle", "Laser pistol", "Empty" };
int invDamage[5] = { 2, 3, 2, 2 };
int invRange[5] = { 1, 1, 3, 2 };
int weapons();

//misc
int victorycount = 0;
int phealth = 15;
int ohealth = 15;


//items

//characters


#endif
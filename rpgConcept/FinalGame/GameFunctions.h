#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cmath> //sqrt() *square root*, abs() *absolute value*, pow()
#include <string>
#include <cstring>
#include <vector>


int Attack(int a) //physical attack, which is dice roll assault + Str = Assault
{
	//Holds the rolled number a taget deals as damage
	int Assault = rand() % 10;
	int c = a + Assault;
	return c;
}

int Heal(int d)
{
	int e = rand() % 10+2; //Holds the rolled number a taget heals
	int f = d + e;
	return f;
}



int LevelUp(int g)//when 1000 exp is earned, player stats, and health all increase
{
	int z = rand() % 2 + 2;//holds the number by which a stat is increased
	int y = z + g;
	return y;
}

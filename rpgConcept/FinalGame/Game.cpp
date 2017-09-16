#include "GameFunctions.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath> //sqrt() *square root*, abs() *absolute value*, pow()
#include <string>
#include <cstring>
#include <vector>
#include <fstream> //allows for files to be used

using namespace std;

class JobSuperClass
{
public:
	JobSuperClass();
	

	
	~JobSuperClass();

	//Ability scores
	int Str;
	int Smarts;
	int Agi;
	int HealthMax;
	int Level;
	char job;

	int GetMaxMana()
	{
		return Smarts * 2;
	}

	//temporary scores
	int HealthCurrent;
	int EXP;
	int ManaCurrent;
	int StrCurrent;
	int AgiCurrent;
	int SmartsCurrent;
	int Regen;


	//Ability information
	string AbilityDescription;
	int AbilityTimer;
	void EndofTurn()
	{
		
		AbilityTimer--;
		if (AbilityTimer == 0)
		{
			AbilityEnd();
		}
	}

	void AbilityEnd()
	{
		cout << "Abilty is done, go home!";
	}

	void UseAbility() //
	{
		
		HealthCurrent += 20;
		ManaCurrent--;
		AbilityTimer = 3;
		
	}

	void Rest()
	{
		HealthCurrent = HealthMax;
		ManaCurrent = GetMaxMana();
		
	}



private:

};

JobSuperClass::JobSuperClass()
{
	Str = 1;
	Smarts = 1;
	Agi = 1;
	HealthMax = 1;
	EXP = 0;
	job = 'x';
	Rest();
	AbilityDescription = "You did it";
	AbilityTimer = 1;
}



JobSuperClass::~JobSuperClass()
{
}

class Barbarian : public JobSuperClass
{
public:
	using JobSuperClass::UseAbility;
	using JobSuperClass::AbilityEnd;
	Barbarian();
	void UseAbility()
	{
	
	}
	void AbilityEnd()
	{
		
	}
};

Barbarian::Barbarian() //Barbarian class
{
	Str = 22;
	Smarts = 2;
	Agi = 22;
	HealthMax = 22;
	EXP = 0;
	job = 'b';
	Rest();
	StrCurrent = Str;
	AgiCurrent = Agi;
	SmartsCurrent = Smarts;
	HealthCurrent = HealthMax;
	Regen = 0;
	AbilityDescription = "You fly into a rage! Increasing your health by 15 and your damage by 5!";
	


}


class Cleric : public JobSuperClass
{
public:
	using JobSuperClass::UseAbility;
	using JobSuperClass::AbilityEnd;
	Cleric();
	void UseAbility()
	{
		
	}
	void AbilityEnd()
	{
		
	}
};


Cleric::Cleric() //Cleric Class
{
	Str = 4;
	Smarts = 5;
	Agi = 3;
	HealthMax = 18;
	EXP = 0;
	job = 'c';
	Rest();
	StrCurrent = Str;
	AgiCurrent = Agi;
	SmartsCurrent = Smarts;
	HealthCurrent = HealthMax;
	Regen = 0;
}


class Rogue : public JobSuperClass
{
public:
	using JobSuperClass::UseAbility;
	using JobSuperClass::AbilityEnd;
	Rogue();
	void UseAbility()
	{

	}
	void AbilityEnd()
	{

	}
};


Rogue::Rogue() //Rogue Class
{
	Str = 4;
	Smarts = 2;
	Agi = 6;
	HealthMax = 16;
	EXP = 0;
	job = 'r';
	Rest();
	StrCurrent = Str;
	AgiCurrent = Agi;
	SmartsCurrent = Smarts;
	HealthCurrent = HealthMax;
	Regen = 0;
	AbilityDescription = "You become far more alert than usual, increasing your chance to hit and dodge by 5!";

}




class Wizard : public JobSuperClass
{
public:
	using JobSuperClass::UseAbility;
	using JobSuperClass::AbilityEnd;
	Wizard();
	void UseAbility()
	{

	}
	void AbilityEnd()
	{

	}
};


Wizard::Wizard() //Wizard Calss
{

	Str = 2;
	Smarts = 6;
	Agi = 4;
	HealthMax = 14;
	EXP = 0;
	job = 'w';
	Rest();
	StrCurrent = Str;
	AgiCurrent = Agi;
	SmartsCurrent = Smarts;
	HealthCurrent = HealthMax;
	Regen = 0;
	AbilityDescription = "You cast a powerful spell increasing your intelegence!";

	
	
}



void main()
{

	//Character stats
	JobSuperClass PlayerClass; //Holds player class choice




	int Chance = 0; //Holds the chance for an action working
	int Layers = 0; //Holds how deep the player has gone into the forest of no return
	bool Town = true; //Holds whether the player is in a safe place to rest
	bool Forest;//Holds whether the player is in the forest or not
	bool Encounter = false; //Holds whether the player is in combat or not
	bool GameOver = false; //Checks to see if the player has lost the game
	bool SpecialAttack = false;//checks to see if the special attack has been used in an encounter
	bool GameWon = false; //checks to see if the player has won the game.
	bool ForestDone = false; //Checks to see if the Demon of the Forest is defeated
	bool TowerDone = false; //Checks to see if the Tower of Fear has been claimed
	bool Tower = false;//checks to see if player is in tower
	bool FloorOne = false;//checks to see if the player is on floor one of the tower
	bool FloorTwo = false;//holds whether player is on the second floor
	bool FloorOneEnemy = true;//holds whether the enemy of floor one is defeated
	bool FloorTwoEnemy = true;//holds the floor two enemy
	bool FloorThree = false; //holds whether the player is on the third floor of the tower or not
	bool FloorThreeEnemy = true;//Holds whther the player has defested the third and final enemy of the tower
	bool Key = false;//Holds whether the player holds the key or not
	bool Door = false;//Holds whether the door is open or not
	char Choice; //holds player action
	char ChoiceA; //holds player input during camp and village


	//strings
	string EnemyName[20];//enemy names
	string EnemyPosDescriptor[10];//enemy positive descriptor
	string EnemyNegDescrptor[10];//enemy negative descriptor
	string TownResponse[10];//town response

	string PosDescriptor;//holds the enemy positive descriptor
	string NegDescriptor;//holds the enmy negative descriptor
	string Response;//holds the towns response
	string Name; //holds the enemy name

	//ifstreams
	ifstream inputFileName;//input from the EnemyNames file
	ifstream inputFilePosDescriptor;//input from the EnemyPositive file
	ifstream inputFileNegDescriptor;//input from the EnemyNegative file
	ifstream inputFileTownResponse;//input from the VillageTalk file

	//open files
	inputFileName.open("EnemyNames.txt");
	inputFilePosDescriptor.open("EnemyPositive.txt");
	inputFileNegDescriptor.open("EnemyNegative.txt");
	inputFileTownResponse.open("VillageTalk.txt");


	//check for errors

	if (inputFileName)
	{
		//read data from file
		for (int i = 0; i < 19; i++)
		{
			//must use getline to avoid only getting the first letter from the line
			getline(inputFileName, EnemyName[i]);
		}



	}
	if (inputFilePosDescriptor)
	{
		//read data from file
		for (int i = 0; i < 9; i++)
		{
			//must use getline to avoid only getting the first letter from the line
			getline(inputFilePosDescriptor, EnemyPosDescriptor[i]);
		}



	}

	if (inputFileNegDescriptor)
	{
		//read data from file
		for (int i = 0; i < 9; i++)
		{
			//must use getline to avoid only getting the first letter from the line
			getline(inputFileNegDescriptor, EnemyNegDescrptor[i]);
		}

	}

	if (inputFileTownResponse)
	{
		//read data from file
		for (int i = 0; i < 9; i++)
		{
			//must use getline to avoid only getting the first letter from the line
			getline(inputFileTownResponse, TownResponse[i]);
		}

	}



	//enemy stats
	int EnemyHealth = 0; //Enemy health
	int EnemyDef = 0; //Holds enemy armor rating
	bool EnemyTurn = false; //tells whether it is an emeies turn or not


	//Shared stats
	int Damage = 0; //Holds the damage a target recieves
	int Hit = 0; //Holds the number rolled to see if an attack succeeds
	int Healing = 0; //holds the healing a character recieves


	//Dice rolls
	int Interact = 0; //Holds the dice rolled for an encounter
	int EnemyNameList = 0; //holds the dice rolled for the enemy name
	int EncounterChance = 0; //Holds the encounter chance dice roll
	srand(time(NULL));

	//introduce the game
	cout << "After several weeks of travel, you arrive in the village of Crisis." << endl << endl;
	cout << "You're reasons for coming here are you own, but your goal is clear; Slay the Demon of the Forest, and claim the Tower of Fear as your own!" << endl << endl;
	cout << "Venture fourth champion, and meet your destiny!" << endl;
	system("pause");


	//Have the player choose a class
	char PlayerClassChoice;

	system("CLS");
	cout << "Please choose your class, using the first initial of the class you want to play as:" << endl << endl;
	cout << "Barbarian: " << "Health: 22, " << "Strength: 6, " << "Intelegence: 2, " << "Agility: 4, " << "Mana: 4" << endl;
	cout << "Cleric: " << "Health: 18, " << "Strength: 4, " << "Intelegence: 5, " << "Agility: 3, " << "Mana: 10" << endl;
	cout << "Rogue: " << "Health: 16, " << "Strength: 4, " << "Intelegence: 2, " << "Agility: 6, " << "Mana: 4" << endl;
	cout << "Wizard: " << "Health: 14, " << "Strength: 2, " << "Intelegence: 6, " << "Agility: 4, " << "Mana: 12" << endl;
	cin >> PlayerClassChoice;

	//check to make sure they chose a proper class
	while (PlayerClassChoice != 'B' && PlayerClassChoice != 'b' && PlayerClassChoice != 'C' && PlayerClassChoice != 'c' && PlayerClassChoice != 'R' && PlayerClassChoice != 'r' && PlayerClassChoice != 'W' && PlayerClassChoice != 'w')
	{
		system("CLS");
		cout << "That is not an option. Please choose your class, using the first initial of the class you want to play as:" << endl << endl;
		cout << "Barbarian: " << "Health: 22, " << "Strength: 6, " << "Intelegence: 2, " << "Agility: 4, " << "Mana: 4" << endl;
		cout << "Cleric: " << "Health: 18, " << "Strength: 4, " << "Intelegence: 5, " << "Agility: 3, " << "Mana: 10, " << endl;
		cout << "Rogue: " << "Health: 16, " << "Strength: 4, " << "Intelegence: 2, " << "Agility: 6, " << "Mana: 4" << endl;
		cout << "Wizard: " << "Health: 14, " << "Strength: 2, " << "Intelegence: 6, " << "Agility: 4, " << "Mana: 12" << endl;
		cin >> PlayerClassChoice;
	}

	//set player stats based on player choice

	PlayerClass = JobSuperClass();

	//stats for Barbarian
	if (PlayerClassChoice == 'B' || PlayerClassChoice == 'b')
	{

		PlayerClass = Barbarian();
		/*HealthMax = 22;
		Health = 22;
		Str = 6;
		Smarts = 2;
		Agi = 4;
		ManaMax = Smarts * 2;
		Mana = ManaMax;*/
	}
	//stats for Cleric
	if (PlayerClassChoice == 'C' || PlayerClassChoice == 'c')
	{

		PlayerClass = Cleric();
		/*HealthMax = 18;
		Health = 18;
		Str = 4;
		Smarts = 5;
		Agi = 3;
		ManaMax = Smarts * 2;
		Mana = ManaMax;*/
	}
	//Stats for Rogue
	if (PlayerClassChoice == 'R' || PlayerClassChoice == 'r')
	{
		PlayerClass = Rogue();
		/*HealthMax = 16;
		Health = 16;
		Str = 4;
		Smarts = 2;
		Agi = 6;
		ManaMax = Smarts * 2;
		Mana = ManaMax;*/
	}
	//Stats for Wizard
	if (PlayerClassChoice == 'W' || PlayerClassChoice == 'w')
	{
		PlayerClass = Wizard();
		/*HealthMax = 14;
		Health = 14;
		Str = 2;
		Smarts = 6;
		Agi = 4;
		ManaMax = Smarts * 2;
		Mana = ManaMax;*/
	}





		

	while (GameWon != true)
	{
		while (Town == true)
		{
			//have the player decide what to do next, Rest, forest, tower or village
			system("CLS");



			cout << "You are currently in the village of Crisis, it is safe to rest here without fear of monsters attacking you!" << endl;
			cout << "What will you do?" << endl;
			cout << "________________________________________________________________________________________________________________________" << endl << endl;

			cout << "Forest | Tower | Rest | Village" << endl;
			cin >> ChoiceA;
			while (ChoiceA != 'R' && ChoiceA != 'r' && ChoiceA != 'V' && ChoiceA != 'v' && ChoiceA != 'T' && ChoiceA != 't' && ChoiceA != 'F' && ChoiceA != 'f')
			{
				system("CLS");
				cout << "You loiter around town for a bit, before deciding to do something productive." << endl;
				cout << "Forest | Tower | Rest | Village" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;

				cout << "What will you do?" << endl;
				cin >> ChoiceA;
			}
			if (ChoiceA == 'R' || ChoiceA == 'r')//player recovers
			{
				system("CLS");
				PlayerClass.Rest();
				cout << "You rest at the local Inn, recovering all of your Health and Mana " << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;

				system("pause");
			}
			if (ChoiceA == 'F' || ChoiceA == 'f')//Player enters the forest
			{
				Town = false;
				Forest = true;
				system("CLS");
				cout << "You venture fourth, deep into the Forest of no Return!" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				Layers++;
				system("pause");

			}
			if (ChoiceA == 'V' || ChoiceA == 'v')//player interacts with village
			{
				system("CLS");
				Interact = rand() % 9;
				Response = TownResponse[Interact];
				cout << "You spend some time in the village, interacting with it's people" << endl << endl;
				cout << Response << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				system("pause");
			}
			if (ChoiceA == 'T' || ChoiceA == 't')//Sends player to the tower
			{
				system("CLS");
				cout << "You muster your courage and head toward the tower of Fear!" << endl << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				Tower = true;
				Town = false;
				system("pause");
			}
		}
		while (Tower == true)//The player approaches the Tower of Fear
		{
			//The player can decide to enter the tower, or leave before it is too late
			system("CLS");
			cout << "Before you stands a forboding tower, reaching for the heavens, as though in defiance to the Gods." << endl << endl;
			cout << "Will you enter, and claim the tower as your own?" << endl << endl;
			cout << "Yes | No" << endl;
			cout << "________________________________________________________________________________________________________________________" << endl << endl;
			cin >> ChoiceA;

			while (ChoiceA != 'N' && ChoiceA != 'n' && ChoiceA != 'Y' && ChoiceA != 'y')
			{
				system("CLS");
				cout << "Before you stands a forboding tower, reaching for the heavens, as though in defiance to the Gods.khkhkh" << endl << endl;
				cout << ChoiceA << endl;
				cout << "Will you enter, and claim the tower as your own?" << endl << endl;
				cout << "Yes | No" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				cin >> ChoiceA;

			}


			if (ChoiceA == 'N' || ChoiceA == 'n') //Sends player back to town
			{
				system("CLS");
				cout << "You decide to return to the safety of the village, the tower can wait for now..." << endl;
				Tower = false;
				Town = true;
				system("pause");
			}

			if (ChoiceA == 'Y' || ChoiceA == 'y')
			{
				system("CLS");
				cout << "You muster your courage, and enter the Tower of Fear!" << endl;
				FloorOne = true;
				system("pause");
			}

			//Floors and the enemies on them
			while (FloorOne == true && FloorOneEnemy == true)//Floor one encounter
			{
				system("CLS");
				cout << "As you enter the tower, you feel as though you are being watched..." << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				system("pause");
				system("CLS");

				cout << "You barely manage to avoid losing your head, as an armor clad warrior appears before you!" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				Encounter = true;
				system("pause");


				EnemyDef = 18;//enemy defense
				EnemyHealth = 22;//enemy health


				system("CLS");
				while (Encounter == true)
				{
					//activate cleric regeneration
					if (PlayerClass.HealthCurrent < PlayerClass.HealthMax)
					{
						PlayerClass.HealthCurrent += PlayerClass.Regen;
						if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
						{
							PlayerClass.HealthCurrent = PlayerClass.HealthMax;
						}
					}



					cout << "An armored foe blocks your path!" << endl;

					//ask for user input on what they want to do
					cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
					cout << "Your turn" << endl << endl;
					cout << "What will you do?" << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					cout << "Attack | Heal | Run | Special" << endl;
					cin >> Choice;

					//ensure user input is accurate and correct
					while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h' && Choice != 'S' && Choice != 's')
					{
						system("CLS");
						cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
						cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

						cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
						cout << "Your turn" << endl << endl;
						cout << "What will you do?" << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;

						cout << "Attack | Heal | Run | Special" << endl;
						cin >> Choice;
					}

					if (Choice == 'S' || Choice == 's')//special action
					{
						system("CLS");

						if (PlayerClass.ManaCurrent < 1)
						{
							cout << "You don't have enough mana to do that!" << endl << endl;
							system("pause");
						}

						else if (SpecialAttack == false)
						{

							if (PlayerClass.job == 'b')//Barbarian special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								PlayerClass.HealthCurrent += 15;
								PlayerClass.StrCurrent += 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								cout << endl << endl;
								system("pause");
							}






							if (PlayerClass.job == 'c')//Cleric special ability
							{


								cout << PlayerClass.AbilityDescription << endl;
								cout << "You fill yourself with holy light, healing you each turn for 5 points!" << endl << endl;
								PlayerClass.Regen = 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								system("pause");


							}

							if (PlayerClass.job == 'w')//Wizard special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								SpecialAttack = true;
								PlayerClass.SmartsCurrent += 5;
								EnemyHealth = EnemyHealth - PlayerClass.SmartsCurrent;
								PlayerClass.ManaCurrent -= 2;
								cout << "You deal " << PlayerClass.SmartsCurrent << " points of damage!" << endl << endl;
								if (EnemyHealth <= 0)
								{
									cout << "The Knight falls over defeated!" << endl << endl;
									PlayerClass.EXP = PlayerClass.EXP + 200;
									cout << "You earned " << 200 << "EXP!" << endl << endl;
									FloorOneEnemy = false;
									Encounter = false;
									system("pause");

								}

								else if (SpecialAttack == true)
								{
									system("pause");
									EnemyTurn = true;
								}


							}

							if (PlayerClass.job == 'r')//Rogue special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								PlayerClass.AgiCurrent += 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								cout << endl;
								system("pause");

							}

						}

						else
						{
							cout << "You are far too worn out to use this ability so soon..." << endl << endl;
							system("pause");
						}

					}

					if (Choice == 'A' || Choice == 'a')//attack action
					{
						Hit = rand() % 20 + 1 + PlayerClass.AgiCurrent;
						if (Hit >= EnemyDef)
						{
							system("CLS");
							Damage = Attack(PlayerClass.StrCurrent);
							EnemyHealth = EnemyHealth - Damage;

							cout << "You attack! Dealing " << Damage << " damage to the " << NegDescriptor << " " << Name << "!" << endl << endl;

							if (EnemyHealth <= 0)
							{
								cout << "The knight falls over, defeated." << endl << endl;
								PlayerClass.EXP = PlayerClass.EXP + 200;
								cout << "You earned 200 EXP!" << endl << endl;
								FloorOneEnemy = false;
								Encounter = false;

							}
							else
							{
								EnemyTurn = true;
							}
							system("pause");
						}
						else if (Hit < EnemyDef)
						{
							system("CLS");
							cout << "Your attack misses as you swing too wide! " << endl << endl;
							EnemyTurn = true;
							system("pause");
						}
					}
					else if (Choice == 'H' || Choice == 'h') //Heal action
					{

						if (PlayerClass.ManaCurrent < 1)
						{
							system("CLS");
							cout << "You don't have enough mana to do that!" << endl << endl;
							system("pause");
						}

						else if (PlayerClass.ManaCurrent > 0)
						{
							system("CLS");
							Healing = Heal(PlayerClass.SmartsCurrent);
							PlayerClass.HealthCurrent = PlayerClass.HealthCurrent + Healing;
							PlayerClass.ManaCurrent--;
							cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
							system("pause");

							if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
							{
								PlayerClass.HealthCurrent = PlayerClass.HealthMax;
							}
							EnemyTurn = true;
						}
					}
					else if (Choice == 'R' || Choice == 'r')//escape action
					{
						system("CLS");
						cout << "You attempt to run away" << endl << endl;
						Interact = rand() % 20 + 1;
						if ((PlayerClass.AgiCurrent + Interact) > EnemyDef)
						{
							Encounter = false;
							Tower = false;
							cout << "You escape from the Knight, and flee from the tower..." << endl << endl;
							system("pause");
						}
						else if
						{
							cout << "The Knight blocks the exit as you try to escape!" << endl << endl;
							EnemyTurn = true;
							system("pause");
						}

					}
					while (EnemyTurn == true)//Enemy action
					{
						system("CLS");
						cout << "The Kinght swings its great axe about wildly!" << endl << endl;
						Hit = rand() % 20 + 3;
						if (Hit >= PlayerClass.AgiCurrent + 10)
						{
							Damage = Attack(4);
							PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
							cout << "It deals you " << Damage << " damage." << endl << endl;
							EnemyTurn = false;
							system("pause");
							//check to see if player lost the game
							if (PlayerClass.HealthCurrent <= 0)
							{
								GameOver = true;
								if (GameOver == true)
								{
									system("CLS");
									cout << "Your vision fades as your blood escapes your body, and you die. Game Over!" << endl;
									system("pause");
									exit(0);
								}
							}
						}
						else
						{
							system("CLS");
							cout << "The Knight swings its great axe wildly!" << endl << endl;
							cout << "But you manage to evade it's attack!" << endl << endl;
							EnemyTurn = false;
							system("pause");
						}


					}

				}


			}//floor one with enemy
			while (FloorOne == true && FloorOneEnemy == false)//floor one empty
			{
				//Reset stats after combat
				if (SpecialAttack = true)
				{
					SpecialAttack = false;
				}

				if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
				{
					PlayerClass.HealthCurrent = PlayerClass.HealthMax;
				}

				if (PlayerClass.AgiCurrent > PlayerClass.Agi)
				{
					PlayerClass.AgiCurrent = PlayerClass.Agi;
				}

				if (PlayerClass.StrCurrent > PlayerClass.Str)
				{
					PlayerClass.StrCurrent = PlayerClass.Str;
				}

				if (PlayerClass.Regen > 0)
				{
					PlayerClass.Regen = 0;
				}

				//Player Level up
				if (PlayerClass.EXP >= 1000)
				{
					PlayerClass.EXP -= 1000;
					cout << "You leveled up!" << endl << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					PlayerClass.Agi = LevelUp(PlayerClass.Agi);
					PlayerClass.Str = LevelUp(PlayerClass.Str);
					PlayerClass.Smarts = LevelUp(PlayerClass.Smarts);


					cout << "Agility:" << endl;
					cout << PlayerClass.AgiCurrent << " ----------> " << PlayerClass.Agi << endl << endl;

					cout << "Strength:" << endl;
					cout << PlayerClass.StrCurrent << " ----------> " << PlayerClass.Str << endl << endl;

					cout << "Intelegence:" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;

					cout << "Mana" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;



					PlayerClass.AgiCurrent = PlayerClass.Agi;
					PlayerClass.Str = PlayerClass.Str;
					PlayerClass.Smarts = PlayerClass.Smarts;
					system("pause");

				}



				system("CLS");
				cout << "The room is dreary but safe for now..." << endl << endl;
				cout << "Please choose a course of action:" << endl << endl;



				//inform the player how deep into the tower they are

				cout << "You are on the first floor of the tower." << endl << endl;
				cout << "What would you like to do?" << endl << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				
				cout << "Venture | Rest | Withdraw" << endl;
				cin >> ChoiceA;

				//Ensureing player makes a valid choice
				while (ChoiceA != 'R' && ChoiceA != 'r' && ChoiceA != 'V' && ChoiceA != 'v' && ChoiceA != 'W' && ChoiceA != 'w')
				{
					system("CLS");
					cout << "You meander around the room, questioning your life choices up until this point, and then decide to be productive." << endl;
					cout << "What would you like to do?" << endl << endl;

					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cout << "Venture | Rest | Withdraw" << endl;
					cin >> ChoiceA;
				}

				//player rests
				if (ChoiceA == 'R' || ChoiceA == 'r')
				{

					system("CLS");
					PlayerClass.Rest();
					cout << "You manage to rest peacefully through the night, recovering all of your Health and Mana." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					system("pause");

				}

				//Player ventures on
				if (ChoiceA == 'V' || ChoiceA == 'v')
				{
					
					system("CLS");
					cout << "You climb ever higher into the tower..." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					FloorTwo = true;
					FloorOne = false;
					system("pause");

				}

				//Player leaves the tower
				if (ChoiceA == 'W' || ChoiceA == 'w')
				{
					system("CLS");
					Layers = 0;
					cout << "You decide to return to town." << endl << endl;
					FloorOne == false;
					Tower = false;
					Town = true;
					system("pause");
				}

			}//
			while (FloorTwo == true && FloorTwoEnemy == true)//floor two encounter
			{
				system("CLS");
				cout << "Some how, this room is even darker than the last, but your opponent, a Knight bearing a gaudy symbol, stands before you patiently." << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				system("pause");
				system("CLS");

				cout << "'What do you hope to accomplish here? Do you seek Glory? Power? Wisdom? or Fortune?'" << endl << endl;
				cout << "What is it that you seek?" << endl;
				cout << "Glory | Power | Wisdom | Fortune" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				cin >> ChoiceA;

				while (ChoiceA != 'G' && ChoiceA != 'g' && ChoiceA != 'P' && ChoiceA != 'p' && ChoiceA != 'W' && ChoiceA != 'w' && ChoiceA != 'F' && ChoiceA != 'f')
				{
					system("CLS");
					cout << "The Gaudy Knight stands patiently waiting for your response..." << endl << endl;
					cout << "What is it that you seek?" << endl;
					cout << "Glory | Power | Wisdom | Fortune" << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cin >> ChoiceA;

				}

				if (ChoiceA == 'G' || ChoiceA == 'g')
				{
					cout << "'Then come! Have your glory!'" << endl << endl;
					cout << "You feel healthier all of a sudden!" << endl << "Your Max Health increases by 5!" << endl;
					PlayerClass.HealthMax = PlayerClass.HealthMax + 5;
					PlayerClass.HealthCurrent = PlayerClass.HealthMax;
					Encounter = true;
					system("pause");

				}
				if (ChoiceA == 'P' || ChoiceA == 'p')
				{
					cout << "'True power must be taken, it cannot be given!'" << endl << endl;
					cout << "You feel stronger all of a sudden!" << endl << "Your strength increases by 2!" << endl;
					PlayerClass.Str = PlayerClass.Str + 2;
					PlayerClass.StrCurrent = PlayerClass.Str;
					Encounter = true;
					system("pause");

				}

				if (ChoiceA == 'W' || ChoiceA == 'w')
				{
					cout << "'Then let us test your wisdom!'" << endl << endl;
					cout << "You feel wiser all of a sudden!" << endl << "Your intelegence increases by 2!" << endl;
					PlayerClass.Smarts = PlayerClass.Smarts + 2;
					PlayerClass.SmartsCurrent = PlayerClass.Smarts;
					PlayerClass.ManaCurrent = PlayerClass.Smarts * 2;
					Encounter = true;
					system("pause");

				}

				if (ChoiceA == 'F' || ChoiceA == 'f')
				{
					cout << "'How far will your greed truly take you?'" << endl << endl;
					cout << "You feel more agile all of a sudden!" << endl << "Your agility increases by 2!" << endl;
					PlayerClass.Agi = PlayerClass.Agi + 2;
					PlayerClass.AgiCurrent = PlayerClass.Agi;
					Encounter = true;
					system("pause");

				}




				EnemyDef = 20;//enemy defense
				EnemyHealth = 30;//enemy health


				system("CLS");
				while (Encounter == true)
				{
					//activate cleric regeneration
					if (PlayerClass.HealthCurrent < PlayerClass.HealthMax)
					{
						PlayerClass.HealthCurrent += PlayerClass.Regen;
						if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
						{
							PlayerClass.HealthCurrent = PlayerClass.HealthMax;
						}
					}



					cout << "The Gaudy Knight blocks your path!" << endl;

					//ask for user input on what they want to do
					cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
					cout << "Your turn" << endl << endl;
					cout << "What will you do?" << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					cout << "Attack | Heal | Run | Special" << endl;
					cin >> Choice;

					//ensure user input is accurate and correct
					while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h' && Choice != 'S' && Choice != 's')
					{
						system("CLS");
						cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
						cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

						cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
						cout << "Your turn" << endl << endl;
						cout << "What will you do?" << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;

						cout << "Attack | Heal | Run | Special" << endl;
						cin >> Choice;
					}

					if (Choice == 'S' || Choice == 's')//special action
					{
						system("CLS");

						if (PlayerClass.ManaCurrent < 1)
						{
							cout << "You don't have enough mana to do that!" << endl << endl;
							system("pause");
						}

						else if (SpecialAttack == false)
						{

							if (PlayerClass.job == 'b')//Barbarian special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								PlayerClass.HealthCurrent += 15;
								PlayerClass.StrCurrent += 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								cout << endl << endl;
								system("pause");
							}






							if (PlayerClass.job == 'c')//Cleric special ability
							{


								cout << PlayerClass.AbilityDescription << endl;
								cout << "You fill yourself with holy light, healing you each turn for 5 points!" << endl << endl;
								PlayerClass.Regen = 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								system("pause");


							}

							if (PlayerClass.job == 'w')//Wizard special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								SpecialAttack = true;
								PlayerClass.SmartsCurrent += 5;
								EnemyHealth = EnemyHealth - PlayerClass.SmartsCurrent;
								PlayerClass.ManaCurrent -= 2;
								cout << "You deal " << PlayerClass.SmartsCurrent << " points of damage!" << endl << endl;
								if (EnemyHealth <= 0)
								{
									cout << "The Knight falls over defeated!" << endl << endl;
									PlayerClass.EXP = PlayerClass.EXP + 400;
									cout << "You earned " << 400 << "EXP!" << endl << endl;
									FloorOneEnemy = false;
									Encounter = false;
									system("pause");

								}

								else if (SpecialAttack == true)
								{
									system("pause");
									EnemyTurn = true;
								}


							}

							if (PlayerClass.job == 'r')//Rogue special ability
							{

								cout << PlayerClass.AbilityDescription << endl;
								PlayerClass.AgiCurrent += 5;
								PlayerClass.ManaCurrent--;
								SpecialAttack = true;
								cout << endl;
								system("pause");

							}

						}

						else
						{
							cout << "You are far too worn out to use this ability so soon..." << endl << endl;
							system("pause");
						}

					}

					if (Choice == 'A' || Choice == 'a')//attack action
					{
						Hit = rand() % 20 + 1 + PlayerClass.AgiCurrent;
						if (Hit >= EnemyDef)
						{
							system("CLS");
							Damage = Attack(PlayerClass.StrCurrent);
							EnemyHealth = EnemyHealth - Damage;

							cout << "You attack! Dealing " << Damage << " damage to the " << NegDescriptor << " " << Name << "!" << endl << endl;

							if (EnemyHealth <= 0)
							{
								cout << "The Gaudy Knight falls over, defeated." << endl << endl;
								PlayerClass.EXP = PlayerClass.EXP + 400;
								cout << "You earned 400 EXP!" << endl << endl;
								FloorTwoEnemy = false;
								Encounter = false;
								cout << "The Gaudy Knight struggles to speak:" << endl;
								cout << "'You have proven your mettle, continue into the tower, and claim what is yours.'";
							}
							else
							{
								EnemyTurn = true;
							}
							system("pause");
						}
						else if (Hit < EnemyDef)
						{
							system("CLS");
							cout << "Your attack misses as you swing too wide! " << endl << endl;
							EnemyTurn = true;
							system("pause");
						}
					}
					else if (Choice == 'H' || Choice == 'h') //Heal action
					{

						if (PlayerClass.ManaCurrent < 1)
						{
							system("CLS");
							cout << "You don't have enough mana to do that!" << endl << endl;
							system("pause");
						}

						else if (PlayerClass.ManaCurrent > 0)
						{
							system("CLS");
							Healing = Heal(PlayerClass.SmartsCurrent);
							PlayerClass.HealthCurrent = PlayerClass.HealthCurrent + Healing;
							PlayerClass.ManaCurrent--;
							cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
							system("pause");

							if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
							{
								PlayerClass.HealthCurrent = PlayerClass.HealthMax;
							}
							EnemyTurn = true;
						}
					}
					else if (Choice == 'R' || Choice == 'r')//escape action
					{
						system("CLS");
						cout << "You cannot run away from this fight!" << endl << endl;

					}
					while (EnemyTurn == true)//Enemy action
					{
						system("CLS");
						cout << "The Gaudy Kinght swings its sword at you swiftly!" << endl << endl;
						Hit = rand() % 20 + 6;
						if (Hit >= PlayerClass.AgiCurrent + 10)
						{
							Damage = Attack(7);
							PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
							cout << "It deals you " << Damage << " damage." << endl << endl;
							EnemyTurn = false;
							system("pause");
							//check to see if player lost the fight
							if (PlayerClass.HealthCurrent <= 0)
							{
								GameOver = true;
								if (GameOver == true)
								{
									system("CLS");
									cout << "Your vision fades as your blood escapes your body, and you go unconcious." << endl;
									system("pause");
									Tower = false;
									FloorTwo = false;
									FloorTwoEnemy = false;
									Town = true;
									system("CLS");
									cout << "You awaken a few days later in Crisis. Asking around, it seems the villagers found you unconsious on the outskirts of town..." << endl;
									system("pause");


								}
							}
						}
						else
						{
							system("CLS");
							cout << "The Gaudy Knight swings its sword at you swiftly!" << endl << endl;
							cout << "But you manage to evade it's attack!" << endl << endl;
							EnemyTurn = false;
							system("pause");
						}


					}

				}


			}
			while (FloorTwo == true && FloorTwoEnemy == false)//floor two empty
			{
				//Reset stats after combat
				if (SpecialAttack = true)
				{
					SpecialAttack = false;
				}

				if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
				{
					PlayerClass.HealthCurrent = PlayerClass.HealthMax;
				}

				if (PlayerClass.AgiCurrent > PlayerClass.Agi)
				{
					PlayerClass.AgiCurrent = PlayerClass.Agi;
				}

				if (PlayerClass.StrCurrent > PlayerClass.Str)
				{
					PlayerClass.StrCurrent = PlayerClass.Str;
				}

				if (PlayerClass.Regen > 0)
				{
					PlayerClass.Regen = 0;
				}

				//Player Level up
				if (PlayerClass.EXP >= 1000)
				{
					PlayerClass.EXP -= 1000;
					cout << "You leveled up!" << endl << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					PlayerClass.Agi = LevelUp(PlayerClass.Agi);
					PlayerClass.Str = LevelUp(PlayerClass.Str);
					PlayerClass.Smarts = LevelUp(PlayerClass.Smarts);


					cout << "Agility:" << endl;
					cout << PlayerClass.AgiCurrent << " ----------> " << PlayerClass.Agi << endl << endl;

					cout << "Strength:" << endl;
					cout << PlayerClass.StrCurrent << " ----------> " << PlayerClass.Str << endl << endl;

					cout << "Intelegence:" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;

					cout << "Mana" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;



					PlayerClass.AgiCurrent = PlayerClass.Agi;
					PlayerClass.Str = PlayerClass.Str;
					PlayerClass.Smarts = PlayerClass.Smarts;
					system("pause");

				}



				system("CLS");
				cout << "The room is silent and empty..." << endl << endl;
				cout << "Please choose a course of action:" << endl << endl;



				//inform the player how deep into the tower they are

				cout << "You are on the second floor of the tower." << endl << endl;
				cout << "You managed to make camp without incident." << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				cout << "What would you like to do?" << endl << endl;
				cout << "Venture | Rest | Withdraw" << endl;
				cin >> ChoiceA;

				//Ensureing player makes a valid choice
				while (ChoiceA != 'R' && ChoiceA != 'r' && ChoiceA != 'V' && ChoiceA != 'v' && ChoiceA != 'W' && ChoiceA != 'w')
				{
					system("CLS");
					cout << "You meander around your camp a bit, questioning your life choices up until this point, and then decide to be productive." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cout << "What would you like to do?" << endl << endl;
					cout << "Venture | Rest | Withdraw" << endl;
					cin >> ChoiceA;
				}

				//player rests
				if (ChoiceA == 'R' || ChoiceA == 'r')
				{


					PlayerClass.Rest();
					cout << "You manage to rest peacefully through the night, recovering all of your Health and Mana." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					system("pause");

				}

				//Player ventures on
				if (ChoiceA == 'V' || ChoiceA == 'v')
				{
					FloorOne = false;
					system("CLS");
					cout << "You climb ever higher into the tower..." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					FloorThree = true;
					FloorTwo = false;
					system("pause");

				}

				//Player leaves the forest
				if (ChoiceA == 'W' || ChoiceA == 'w')
				{
					Layers = 0;
					cout << "You decide to return to town." << endl << endl;
					Town = true;
					Tower = false;
					FloorTwo = false;
					system("pause");
				}

			}
			while (FloorThree == true && FloorThreeEnemy == true)//final floor
			{
				cout << "A large door blocks your path." << endl << endl;
				system("pause");
				if (Key = false)
				{
					system("CLS");
					cout << "You attempt to open the door, but find it is locked. You will need to find the key to proceed any further." << endl;
					cout << "You decide to go back to the village for now." << endl;
					system("pause");
					FloorThree = false;
					Tower = false;
					Town = true;

				}
				if(Key = true)
				{
					system("CLS");
					cout << "You have the key to this door, if you enter you will not be able to leave before your task is done..." << endl << endl;
					cout << "Venture | Withdraw" << endl << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cin >> ChoiceA;

				}

				while (ChoiceA != 'V' && Choice != 'v' && Choice != 'W' && Choice != 'w')
				{
					system("CLS");
					cout << "You have the key to this door, if you enter you will not be able to leave before your task is done..." << endl << endl;
					cout << "Venture | Withdraw" << endl << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cin >> ChoiceA;

				}
				
				if (ChoiceA == 'V' || ChoiceA == 'v')
				{
					system("CLS");
					cout << "You open the door, and step into the darkeness beyond..." << endl;
					Door = true;
					system("pause");
				}

				if (ChoiceA == 'W' || ChoiceA == 'w')
				{
					system("CLS");
					cout << "You decide to take a bit more time to prepare." << endl;
					Tower = false;
					FloorThree = false;
					system("pause");

				}

				//third encounter
			}

		}
		while (Forest == true)//while the player is in the forest
		{
			while (Encounter == false && Forest == true) // while the player is not in combat: request player action, Venture goes deeper, rest heals, and withdraw returns to town
			{
				system("CLS");







				//Reset stats after combat
				if (SpecialAttack = true)
				{
					SpecialAttack = false;
				}

				if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
				{
					PlayerClass.HealthCurrent = PlayerClass.HealthMax;
				}

				if (PlayerClass.AgiCurrent > PlayerClass.Agi)
				{
					PlayerClass.AgiCurrent = PlayerClass.Agi;
				}

				if (PlayerClass.StrCurrent > PlayerClass.Str)
				{
					PlayerClass.StrCurrent = PlayerClass.Str;
				}

				if (PlayerClass.Regen > 0)
				{
					PlayerClass.Regen = 0;
				}

				//Player Level up
				if (PlayerClass.EXP >= 1000)
				{
					PlayerClass.EXP -= 1000;
					cout << "You leveled up!" << endl << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					PlayerClass.Agi = LevelUp(PlayerClass.Agi);
					PlayerClass.Str = LevelUp(PlayerClass.Str);
					PlayerClass.Smarts = LevelUp(PlayerClass.Smarts);


					cout << "Agility:" << endl;
					cout << PlayerClass.AgiCurrent << " ----------> " << PlayerClass.Agi << endl << endl;

					cout << "Strength:" << endl;
					cout << PlayerClass.StrCurrent << " ----------> " << PlayerClass.Str << endl << endl;

					cout << "Intelegence:" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;

					cout << "Mana" << endl;
					cout << PlayerClass.SmartsCurrent << " ----------> " << PlayerClass.Smarts << endl << endl;



					PlayerClass.AgiCurrent = PlayerClass.Agi;
					PlayerClass.Str = PlayerClass.Str;
					PlayerClass.Smarts = PlayerClass.Smarts;
					system("pause");

				}

				//inform the player how deep into the forest they are
				system("CLS");
				cout << "You are currently " << Layers << " day(s) into the Forest of no Return." << endl << endl;
				cout << "You managed to make camp without incident." << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;
				cout << "You may be attacked if you try to move any further in, or rest." << endl << endl;
				cout << "What would you like to do?" << endl << endl;
				cout << "Venture | Rest | Withdraw" << endl;
				cin >> ChoiceA;

				//Ensureing player makes a valid choice
				while (ChoiceA != 'R' && ChoiceA != 'r' && ChoiceA != 'V' && ChoiceA != 'v' && ChoiceA != 'W' && ChoiceA != 'w')
				{
					system("CLS");
					cout << "You meander around your camp a bit, questioning your life choices up until this point, and then decide to be productive." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					cout << "What would you like to do?" << endl << endl;
					cout << "Venture | Rest | Withdraw" << endl;
					cin >> ChoiceA;
				}

				//player rests
				if (ChoiceA == 'R' || ChoiceA == 'r')
				{
					system("CLS");
					cout << "You try to rest, and recover your Health and Mana" << endl << endl;
					EncounterChance = rand() % 20 + Layers;
					system("pause");

					if (EncounterChance > 15)
					{
						Encounter = true;
					}
					else
					{
						PlayerClass.Rest();
						cout << "You manage to rest peacefully through the night, recovering all of your Health and Mana." << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;
						system("pause");
					}
				}

				//Player ventures on
				if (ChoiceA == 'V' || ChoiceA == 'v')
				{
					Layers = Layers + 1;
					system("CLS");
					cout << "You venture fourth, moving deeper into the forest." << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					EncounterChance = rand() % 20 + Layers;
					if (EncounterChance > 15)
					{
						Encounter = true;
					}
					else
					{
						cout << "You move through the forest without any interference." << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;
						system("pause");
					}

				}

				//Player leaves the forest
				if (ChoiceA == 'W' || ChoiceA == 'w')
				{
					Layers = 0;
					cout << "You decide to return to town." << endl << endl;
					Town = true;
					Forest = false;
					system("pause");
				}

			}

			//if the player has an encounter
			while (Encounter == true)
			{
				if (EncounterChance < 18)
				{

					EnemyDef = Layers + 10 - rand() % 5;//enemy defense
					EnemyHealth = Layers + 15 - rand() % 5;//enemy health
					Interact = rand() % 9;//find the desriptor for the enemy
					NegDescriptor = EnemyNegDescrptor[Interact];//set the descriptor
					EnemyNameList = rand() % 19;//find the name for the enemy
					Name = EnemyName[EnemyNameList];//set the name of the enemy


					while (Encounter == true)
					{

						system("CLS");




						//activate cleric regeneration
						if (PlayerClass.HealthCurrent < PlayerClass.HealthMax)
						{
							PlayerClass.HealthCurrent += PlayerClass.Regen;
							if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
							{
								PlayerClass.HealthCurrent = PlayerClass.HealthMax;
							}
						}



						cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

						//ask for user input on what they want to do
						cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
						cout << "Your turn" << endl << endl;
						cout << "What will you do?" << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;

						cout << "Attack | Heal | Run | Special" << endl;
						cin >> Choice;

						//ensure user input is accurate and correct
						while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h' && Choice != 'S' && Choice != 's')
						{
							system("CLS");
							cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
							cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

							cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl;
							cout << "________________________________________________________________________________________________________________________" << endl << endl;

							cout << "Attack | Heal | Run | Special" << endl;
							cin >> Choice;
						}

						if (Choice == 'S' || Choice == 's')//special action
						{
							system("CLS");

							if (PlayerClass.ManaCurrent < 1)
							{
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (SpecialAttack == false)
							{

								if (PlayerClass.job == 'b')//Barbarian special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.HealthCurrent += 15;
									PlayerClass.StrCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");
								}






								if (PlayerClass.job == 'c')//Cleric special ability
								{


									cout << PlayerClass.AbilityDescription << endl;
									cout << "You fill yourself with holy light, healing you each turn for 5 points!" << endl << endl;
									PlayerClass.Regen = 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									system("pause");


								}

								if (PlayerClass.job == 'w')//Wizard special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									SpecialAttack = true;
									PlayerClass.SmartsCurrent += 5;
									EnemyHealth = EnemyHealth - PlayerClass.SmartsCurrent;
									PlayerClass.ManaCurrent -= 2;
									cout << "You deal " << PlayerClass.SmartsCurrent << " points of damage!" << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << NegDescriptor << " " << Name << "!" << endl << endl;
										PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");

									}




								}

								if (PlayerClass.job == 'r')//Rogue special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.AgiCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl;
									system("pause");

								}

							}

							else
							{
								cout << "You are far too worn out to use this ability so soon..." << endl << endl;
								system("pause");
							}

						}

						if (Choice == 'A' || Choice == 'a')//attack action
						{
							Hit = rand() % 20 + 1 + PlayerClass.AgiCurrent;



							if (Hit >= EnemyDef)
							{
								if (PlayerClass.job == 'w')
								{
									system("CLS");
									Damage = Attack(PlayerClass.SmartsCurrent);
									EnemyHealth = EnemyHealth - Damage;
									PlayerClass.ManaCurrent--;
									cout << "You attack! Dealing " << Damage << " damage to the " << NegDescriptor << " " << Name << "!" << endl << endl;

									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << NegDescriptor << " " << Name << "!" << endl << endl;
										PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;

									}
									else
									{
										EnemyTurn = true;
									}
									system("pause");
								}
								else {
									system("CLS");
									Damage = Attack(PlayerClass.StrCurrent);
									EnemyHealth = EnemyHealth - Damage;

									cout << "You attack! Dealing " << Damage << " damage to the " << NegDescriptor << " " << Name << "!" << endl << endl;

									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << NegDescriptor << " " << Name << "!" << endl << endl;
										PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;

									}
									else
									{
										EnemyTurn = true;
									}
									system("pause");
								}
							}
							else if (Hit < EnemyDef)
							{
								system("CLS");
								cout << "Your attack misses as you swing too wide! " << endl << endl;
								EnemyTurn = true;
								system("pause");
							}
						}
						else if (Choice == 'H' || Choice == 'h') //Heal action
						{

							if (PlayerClass.ManaCurrent < 1)
							{
								system("CLS");
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (PlayerClass.ManaCurrent > 0)
							{
								system("CLS");
								Healing = Heal(PlayerClass.SmartsCurrent);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent + Healing;
								PlayerClass.ManaCurrent--;
								cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
								system("pause");

								if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
								{
									PlayerClass.HealthCurrent = PlayerClass.HealthMax;
								}
								EnemyTurn = true;
							}
						}
						else if (Choice == 'R' || Choice == 'r')//escape action
						{
							system("CLS");
							cout << "You attempt to run away" << endl << endl;
							Interact = rand() % 20 + 1;
							if ((PlayerClass.AgiCurrent + Interact) > EnemyDef)
							{
								Encounter = false;
								cout << "You managed to flee from the " << NegDescriptor << " " << Name << "!" << endl << endl;
							}
							else
							{
								cout << "You failed to get away from the " << NegDescriptor << " " << Name << "!" << endl << endl;
								EnemyTurn = true;
							}

						}
						while (EnemyTurn == true)//Enemy action
						{
							system("CLS");
							cout << "The " << NegDescriptor << " " << Name << " attacks you!" << endl << endl;
							Hit = rand() % 20 + 3;
							if (Hit >= PlayerClass.AgiCurrent + 10)
							{
								Damage = Attack(0);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
								cout << "It deals you " << Damage << " damage." << endl << endl;
								EnemyTurn = false;
								system("pause");
								//check to see if player lost the game
								if (PlayerClass.HealthCurrent <= 0)
								{
									GameOver = true;
									if (GameOver == true)
									{
										system("CLS");
										cout << "Your vision fades as your blood escapes your body, and you die. Game Over!" << endl;
										system("pause");
										exit(0);
									}
								}
							}
							else
							{
								system("CLS");
								cout << "The " << NegDescriptor << " " << Name << " attacks you!" << endl << endl;
								cout << "But you manage to evade it's attack!" << endl << endl;
								EnemyTurn = false;
								system("pause");
							}

						}
					}
				}
				else if (EncounterChance == 18 || EncounterChance == 19)
				{
					EnemyDef = Layers + 10;
					EnemyHealth = Layers + 15;
					Interact = rand() % 9;//find the desriptor for the enemy
					EnemyNameList = rand() % 19;//find the name for the enemy
					Name = EnemyName[EnemyNameList];//set the name of the enemy

					while (Encounter == true)
					{

						system("CLS");




						//activate cleric regeneration
						if (PlayerClass.HealthCurrent < PlayerClass.HealthMax)
						{
							PlayerClass.HealthCurrent += PlayerClass.Regen;
							if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
							{
								PlayerClass.HealthCurrent = PlayerClass.HealthMax;
							}
						}



						cout << "You encounter a " << Name << "!" << endl;

						//ask for user input on what they want to do
						cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
						cout << "Your turn" << endl << endl;
						cout << "What will you do?" << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;

						cout << "Attack | Heal | Run | Special" << endl;
						cin >> Choice;

						//ensure user input is accurate and correct
						while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h' && Choice != 'S' && Choice != 's')
						{
							system("CLS");
							cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
							cout << "You encounter a " << Name << "!" << endl;

							cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl;
							cout << "________________________________________________________________________________________________________________________" << endl << endl;

							cout << "Attack | Heal | Run | Special" << endl;
							cin >> Choice;
						}

						if (Choice == 'S' || Choice == 's')//special action
						{
							system("CLS");

							if (PlayerClass.ManaCurrent < 1)
							{
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (SpecialAttack == false)
							{

								if (PlayerClass.job == 'b')//Barbarian special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.HealthCurrent += 15;
									PlayerClass.StrCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");
								}






								if (PlayerClass.job == 'c')//Cleric special ability
								{


									cout << PlayerClass.AbilityDescription << endl;
									cout << "You fill yourself with holy light, healing you each turn for 5 points!" << endl;
									PlayerClass.Regen = 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");


								}

								if (PlayerClass.job == 'w')//Wizard special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									SpecialAttack = true;
									PlayerClass.SmartsCurrent += 5;
									EnemyHealth = EnemyHealth - PlayerClass.SmartsCurrent;
									PlayerClass.ManaCurrent -= 2;
									cout << "You deal " << PlayerClass.SmartsCurrent << " points of damage!" << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << Name << "!" << endl << endl;
										PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");

									}

									else if (SpecialAttack == true)
									{
										system("pause");
										EnemyTurn = true;
									}


								}

								if (PlayerClass.job == 'r')//Rogue special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.AgiCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");
								}

							}

							else
							{
								cout << "You are far too worn out to use this ability so soon..." << endl << endl;
								system("pause");
							}

						}

						if (Choice == 'A' || Choice == 'a')//attack action
						{
							Hit = rand() % 20 + 1 + PlayerClass.AgiCurrent;
							if (Hit >= EnemyDef)
							{
								system("CLS");
								Damage = Attack(PlayerClass.StrCurrent);
								EnemyHealth = EnemyHealth - Damage;

								cout << "You attack! Dealing " << Damage << " damage to the " << Name << "!" << endl << endl;


								if (EnemyHealth <= 0)
								{
									cout << "You killed the " << NegDescriptor << " " << Name << "!" << endl << endl;
									PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
									cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
									Encounter = false;


								}
								else
								{
									EnemyTurn = true;
								}
								system("pause");
							}
							else if (Hit < EnemyDef)
							{
								system("CLS");
								cout << "Your attack misses as you swing too wide! " << endl << endl;
								EnemyTurn = true;
								system("pause");
							}
						}
						else if (Choice == 'H' || Choice == 'h') //Heal action
						{

							if (PlayerClass.ManaCurrent < 1)//if they dont have enough mana
							{
								system("CLS");
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (PlayerClass.ManaCurrent > 0) //if they do have enough mana
							{
								system("CLS");
								Healing = Heal(PlayerClass.SmartsCurrent);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent + Healing;
								PlayerClass.ManaCurrent--;
								cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
								system("pause");

								if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
								{
									PlayerClass.HealthCurrent = PlayerClass.HealthMax;
								}
								EnemyTurn = true;
							}
						}
						else if (Choice == 'R' || Choice == 'r')//escape action
						{
							system("CLS");
							cout << "You attempt to run away" << endl << endl;
							Interact = rand() % 20 + 1;
							if ((PlayerClass.AgiCurrent + Interact) > EnemyDef)
							{
								Encounter = false;
								cout << "You managed to flee from the " << Name << "!" << endl << endl;
							}
							else
							{
								cout << "You failed to get away from the " << Name << "!" << endl << endl;
								EnemyTurn = true;
							}

						}
						while (EnemyTurn == true)//Enemy action
						{
							system("CLS");
							cout << "The " << NegDescriptor << " " << Name << " attacks you!" << endl << endl;
							Hit = rand() % 20 + 3;
							if (Hit >= PlayerClass.AgiCurrent + 10)
							{
								Damage = Attack(0);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
								cout << "It deals you " << Damage << " damage." << endl << endl;
								EnemyTurn = false;
								system("pause");
								//check to see if player lost the game
								if (PlayerClass.HealthCurrent <= 0)
								{
									GameOver = true;
									if (GameOver == true)//ending game if player dies
									{
										system("CLS");
										cout << "Your vision fades as your blood escapes your body, and you die. Game Over!" << endl;
										system("pause");
										exit(0);
									}
								}
							}
							else
							{
								system("CLS");
								cout << "The " << Name << " attacks you!" << endl << endl;
								cout << "But you manage to evade it's attack!" << endl << endl;
								EnemyTurn = false;
								system("pause");
							}

						}
					}
				}

				else if (EncounterChance >= 20)

				{
					EnemyDef = Layers + 10 + rand() % 5 + 1;
					EnemyHealth = Layers + 15 + rand() % 10 + 1;
					Interact = rand() % 9;//find the desriptor for the enemy
					PosDescriptor = EnemyPosDescriptor[Interact];//set the enemy descriptor
					EnemyNameList = rand() % 19;//find the name for the enemy
					Name = EnemyName[EnemyNameList];//set the name of the enemy


					while (Encounter == true)
					{

						system("CLS");




						//activate cleric regeneration
						if (PlayerClass.HealthCurrent < PlayerClass.HealthMax)
						{
							PlayerClass.HealthCurrent += PlayerClass.Regen;
							if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
							{
								PlayerClass.HealthCurrent = PlayerClass.HealthMax;
							}
						}



						cout << "You encounter a " << PosDescriptor << " " << Name << "!" << endl;

						//ask for user input on what they want to do
						cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
						cout << "Your turn" << endl << endl;
						cout << "What will you do?" << endl;
						cout << "________________________________________________________________________________________________________________________" << endl << endl;

						cout << "Attack | Heal | Run | Special" << endl;
						cin >> Choice;

						//ensure user input is accurate and correct
						while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h' && Choice != 'S' && Choice != 's')
						{
							system("CLS");
							cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
							cout << "You encounter a " << PosDescriptor << " " << Name << "!" << endl;

							cout << "Health: " << PlayerClass.HealthCurrent << "/" << PlayerClass.HealthMax << endl << "Mana: " << PlayerClass.ManaCurrent << "/" << PlayerClass.GetMaxMana() << endl << "EXP: " << PlayerClass.EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl;
							cout << "________________________________________________________________________________________________________________________" << endl << endl;

							cout << "Attack | Heal | Run | Special" << endl;
							cin >> Choice;
						}

						if (Choice == 'S' || Choice == 's')//special action
						{
							system("CLS");

							if (PlayerClass.ManaCurrent < 1)
							{
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (SpecialAttack == false)
							{

								if (PlayerClass.job == 'b')//Barbarian special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.HealthCurrent += 15;
									PlayerClass.StrCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");
								}






								if (PlayerClass.job == 'c')//Cleric special ability
								{


									cout << PlayerClass.AbilityDescription << endl;
									cout << "You fill yourself with holy light, healing you each turn for 5 points!" << endl;
									PlayerClass.Regen = 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");


								}

								if (PlayerClass.job == 'w')//Wizard special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									SpecialAttack = true;
									PlayerClass.SmartsCurrent += 5;
									EnemyHealth = EnemyHealth - PlayerClass.SmartsCurrent;
									PlayerClass.ManaCurrent -= 2;
									cout << "You deal " << PlayerClass.SmartsCurrent << " points of damage!" << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << PosDescriptor << " " << Name << "!" << endl << endl;
										PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");

									}

									else
									{
										system("pause");
										EnemyTurn = true;
									}


								}

								if (PlayerClass.job == 'r')//Rogue special ability
								{

									cout << PlayerClass.AbilityDescription << endl;
									PlayerClass.AgiCurrent += 5;
									PlayerClass.ManaCurrent--;
									SpecialAttack = true;
									cout << endl << endl;
									system("pause");
								}

							}

							else if (SpecialAttack == true)
							{
								cout << "You are far too worn out to use this ability so soon..." << endl << endl;
								system("pause");
							}

						}

						if (Choice == 'A' || Choice == 'a')//attack action
						{
							Hit = rand() % 20 + 1 + PlayerClass.AgiCurrent;
							if (Hit >= EnemyDef)
							{
								system("CLS");
								Damage = Attack(PlayerClass.StrCurrent);
								EnemyHealth = EnemyHealth - Damage;

								cout << "You attack! Dealing " << Damage << " damage to the " << PosDescriptor << " " << Name << "!" << endl << endl;

								if (EnemyHealth <= 0)
								{
									cout << "You killed the " << PosDescriptor << " " << Name << "!" << endl << endl;
									PlayerClass.EXP = PlayerClass.EXP + (Layers * 20);
									cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
									Encounter = false;

								}
								else
								{
									EnemyTurn = true;
								}
								system("pause");
							}
							else if (Hit < EnemyDef)
							{
								system("CLS");
								cout << "Your attack misses as you swing too wide! " << endl << endl;
								EnemyTurn = true;
								system("pause");
							}
						}
						else if (Choice == 'H' || Choice == 'h') //Heal action
						{

							if (PlayerClass.ManaCurrent < 1)
							{
								system("CLS");
								cout << "You don't have enough mana to do that!" << endl << endl;
								system("pause");
							}

							else if (PlayerClass.ManaCurrent > 0)
							{
								system("CLS");
								Healing = Heal(PlayerClass.SmartsCurrent);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent + Healing;
								PlayerClass.ManaCurrent--;
								cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
								system("pause");

								if (PlayerClass.HealthCurrent > PlayerClass.HealthMax)
								{
									PlayerClass.HealthCurrent = PlayerClass.HealthMax;
								}
								EnemyTurn = true;
							}

						}
						else if (Choice == 'R' || Choice == 'r')//escape action
						{
							system("CLS");
							cout << "You attempt to run away" << endl << endl;
							Interact = rand() % 20 + 1;
							if ((PlayerClass.AgiCurrent + Interact) > EnemyDef)
							{
								Encounter = false;
								cout << "You managed to flee from the " << PosDescriptor << " " << Name << "!" << endl << endl;
							}
							else
							{
								cout << "You failed to get away from the " << PosDescriptor << " " << Name << "!" << endl << endl;
								EnemyTurn = true;
							}

						}
						while (EnemyTurn == true)//Enemy action
						{
							system("CLS");
							cout << "The " << PosDescriptor << " " << Name << " attacks you!" << endl << endl;
							Hit = rand() % 20 + 3;
							if (Hit >= PlayerClass.AgiCurrent + 10)
							{
								Damage = Attack(0);
								PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
								cout << "It deals you " << Damage << " damage." << endl << endl;
								EnemyTurn = false;
								system("pause");
								//check to see if player lost the game
								if (PlayerClass.HealthCurrent <= 0)
								{
									GameOver = true;
									if (GameOver == true)
									{
										system("CLS");
										cout << "Your vision fades as your blood escapes your body, and you die. Game Over!" << endl;
										system("pause");
										exit(0);
									}
								}
							}
							else
							{
								system("CLS");
								cout << "The " << PosDescriptor << " " << Name << " attacks you!" << endl << endl;
								cout << "But you manage to evade it's attack!" << endl << endl;
								EnemyTurn = false;
								system("pause");
							}

						}
					}
				}
				else if (Layers == 21)
				{

				}
			}

		}
	}


		
		
	
	//cout << Health << " " << Str << " " << Agi << " " << Smarts << " " << Mana;



	cin.ignore();
	cin.get();

}

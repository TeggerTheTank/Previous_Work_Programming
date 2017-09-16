#include "GameFunctions.h"
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
	JobSuperClass()
	{
		Str = 1;
		Smarts = 1;
		Agi = 1;
		HealthMax = 1;
		EXP = 0;
		Rest();
		Level = 1;
		
	}

	
	~JobSuperClass();

	//Ability scores
	int Str;
	int Smarts;
	int Agi;
	int HealthMax;
	int Level;
	
	int GetMaxManna()
	{
		return Smarts * 2;
	}

	//temporary scores
	int HealthCurrent;
	int EXP;
	int ManaCurrent;

	int Rest()
	{
		HealthCurrent = HealthMax;
		ManaCurrent = GetMaxManna();
	}


private:

};

JobSuperClass::JobSuperClass()
{
}

JobSuperClass::~JobSuperClass()
{
}



void main()
{

	//Character stats
	char PlayerClass; //Holds player class choice
	char Choice; //holds player action
	char ChoiceA; //holds player input during camp and village
	int Str = 0; //Holds player Strength
	int Agi = 0; //Holds player Agility
	int Smarts = 0; //Holds player Intelegence
	int ManaMax = 0; //Holds players max mana
	int HealthMax = 0; //holds players max health
	int Health = 0; //Holds player health
	int Mana = 0; //Holds player mana
	int Level = 1; //holds character level
	int Chance = 0; //Holds the chance for an action working
	int Layers = 0; //Holds how deep the player has gone into the forest of no return
	float EXP = 0.0; //Holds the total experience of the player
	bool Town = true; //Holds whether the player is in a safe place to rest
	bool Encounter = false; //Holds whether the player is in combat or not


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
	
	//Have the player choose a class
	cout << "Please choose your class, using the first initial of the class you want to play as:" << endl << endl;
	cout << "Barbarian: " << "Health: 22, " << "Strength: 6, " << "Intelegence: 2, " << "Agility: 4, " << "Mana: 4" << endl;
	cout << "Cleric: " << "Health: 18, " << "Strength: 4, " << "Intelegence: 5, " << "Agility: 3, " << "Mana: 10" << endl;
	cout << "Rogue: " << "Health: 16, " << "Strength: 4, " << "Intelegence: 2, " << "Agility: 6, " << "Mana: 4" << endl;
	cout << "Wizard: " << "Health: 14, " << "Strength: 2, " << "Intelegence: 6, " << "Agility: 4, " << "Mana: 12" << endl;
	cin >> PlayerClass;

	//check to make sure they chose a proper class
	while (PlayerClass != 'B' && PlayerClass != 'b' && PlayerClass != 'C' && PlayerClass != 'c' && PlayerClass != 'R' && PlayerClass != 'r' && PlayerClass != 'W' && PlayerClass != 'w')
	{
		system("CLS");
		cout << "That is not an option. Please choose your class, using the first initial of the class you want to play as:" << endl << endl;
		cout << "Barbarian: " << "Health: 22, " << "Strength: 6, " << "Intelegence: 2, " << "Agility: 4, " << "Mana: 4" << endl;
		cout << "Cleric: " << "Health: 18, " << "Strength: 4, " << "Intelegence: 5, " << "Agility: 3, " << "Mana: 10, " << endl;
		cout << "Rogue: " << "Health: 16, " << "Strength: 4, " << "Intelegence: 2, " << "Agility: 6, " << "Mana: 4" << endl;
		cout << "Wizard: " << "Health: 14, " << "Strength: 2, " << "Intelegence: 6, " << "Agility: 4, " << "Mana: 12" << endl;
		cin >> PlayerClass;
	}

	//set player stats based on player choice
	
	//stats for Barbarian
	if (PlayerClass == 'B' || PlayerClass == 'b')
	{
		HealthMax = 22;
		Health = 22;
		Str = 6;
		Smarts = 2;
		Agi = 4;
		ManaMax = Smarts * 2;
		Mana = ManaMax;
	}
	//stats for Cleric
	if (PlayerClass == 'C' || PlayerClass == 'c')
	{
		HealthMax = 18;
		Health = 18;
		Str = 4;
		Smarts = 5;
		Agi = 3;
		ManaMax = Smarts * 2;
		Mana = ManaMax;
	}
	//Stats for Rogue
	if (PlayerClass == 'R' || PlayerClass == 'r')
	{
		HealthMax = 16;
		Health = 16;
		Str = 4;
		Smarts = 2;
		Agi = 6;
		ManaMax = Smarts * 2;
		Mana = GetManaMax;
	}
	//Stats for Wizard
	if (PlayerClass == 'W' || PlayerClass == 'w')
	{
		HealthMax = 14;
		Health = 14;
		Str = 2;
		Smarts = 6;
		Agi = 4;
		ManaMax = Smarts * 2;
		Mana = ManaMax;
	}



		system("CLS");
		cout << "Welcome to the game" << endl;

		while (Layers != 20)
		{
			while (Town == true)
			{
				//have the player decide what to do next, Rest heals, Venture leaves town, and Town gives funny dialogue
				system("CLS");
				cout << "You are currently in a village, it is safe to rest here without fear of monsters attacking you!" << endl;
				cout << "What will you do?" << endl;
				cout << "________________________________________________________________________________________________________________________" << endl << endl;

				cout << "Rest | Venture | Town" << endl;
				cin >> ChoiceA;
				while (ChoiceA != 'R' && ChoiceA != 'r' && ChoiceA != 'V' && ChoiceA != 'v' && ChoiceA != 'T' && ChoiceA != 't')
				{
					system("CLS");
					cout << "You loiter around town for a bit, before deciding to do something productive." << endl;
					cout << "Rest | Venture | Town" << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					cout << "What will you do?" << endl;
					cin >> ChoiceA;
				}
				if (ChoiceA == 'R' || ChoiceA == 'r')
				{
					system("CLS");
					Health = HealthMax;
					Mana = ManaMax;
					cout << "You rest at the local Inn, recovering all of your Health and Mana " << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;

					system("pause");
				}
				else if (ChoiceA == 'V' || ChoiceA == 'v')
				{
					Town = false;
					system("CLS");
					cout << "You venture fourth, deep into the Forest of no Return!" << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					Layers++;

				}
				else if (ChoiceA == 'T' || ChoiceA == 't')
				{
					system("CLS");
					Interact = rand() % 9;
					Response = TownResponse[Interact];
					cout << "You spend some time in the village, interacting with it's people" << endl << endl;
					cout << Response << endl;
					cout << "________________________________________________________________________________________________________________________" << endl << endl;
					system("pause");
				}
			}

			while (Town == false)//while the player is in the forest
			{
				while (Encounter == false && Town == false) // while the player is not in combat: request player action, Venture goes deeper, rest heals, and withdraw returns to town
				{
					system("CLS");
					cout << "You are currently " << Layers << " days into the Forest of no Return." << endl << endl;
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
						if (EncounterChance > 15)
						{
							Encounter = true;
						}
						else
						{
							Health = HealthMax;
							Mana = ManaMax;
							cout << "You manage to rest peacefully through the night, recovering all of your Health and Mana." << endl;
							cout << "________________________________________________________________________________________________________________________" << endl << endl;

						}
					}

					//Player ventures on
					if (ChoiceA == 'V' || ChoiceA == 'v')
						{
							Layers = Layers + 1;
							system("CLS");
							cout << "You venture fourth, moving deeper into the forest."<< endl;
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

							}
						
					}
					if (ChoiceA == 'W' || ChoiceA == 'w')
					{
						Layers = 0;
						cout << "You decide to return to town." << endl << endl;
						Town = true;
					}

				}
				while (Encounter == true)
				{
					if ( EncounterChance < 18)
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
							cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

							cout << "Health: " << Health << "/" << HealthMax << endl << "Mana: " << Mana << "/" << ManaMax << endl << "EXP: " << EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl;
							cout << "________________________________________________________________________________________________________________________" << endl << endl;

							cout << "Attack | Heal | Run" << endl;
							cin >> Choice;
							while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h')
							{
								system("CLS");
								cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
								cout << "You encounter a " << NegDescriptor << " " << Name << "!" << endl;

								cout << "Health: " << Health << "/" << HealthMax << endl << "Mana: " << Mana << "/" << ManaMax << endl << "EXP: " << EXP << "/1000" << endl << endl;
								cout << "Your turn" << endl << endl;
								cout << "What will you do?" << endl;
								cout << "________________________________________________________________________________________________________________________" << endl << endl;

								cout << "Attack | Heal | Run" << endl;
								cin >> Choice;
							}
							if (Choice == 'A' || Choice == 'a')
							{
								Hit = rand() % 20 + 1 + Agi;
								if (Hit >= EnemyDef)
								{
									system("CLS");
									Damage = Attack(Str);
									EnemyHealth = EnemyHealth - Damage;
									cout << endl << endl;
									cout << "You attack! Dealing " << Damage << " to the " << NegDescriptor << " " << Name << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << NegDescriptor << " " << Name << "!" << endl << endl;
										EXP = EXP + (Layers * 20);
										cout << "You earned " << Layers * 20 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");
									}
									else
									{
										EnemyTurn = true;
									}
								}
								else if (Hit < EnemyDef)
								{
									system("CLS");
									cout << "Your attack misses as you swing too wide! " << endl << endl;
									EnemyTurn = true;
								}
							}
							else if (Choice == 'H' || Choice == 'h')
							{
								system("CLS");
								Healing = Heal(Smarts);
								Health = Health + Healing;
								Mana--;
								cout << "You heal yourself for " << Healing << " Points of damage!" << endl;
								system("pause");

								if (Health > HealthMax)
								{
									Health = HealthMax;
								}
								EnemyTurn = true;
							}
							else if (Choice == 'R' || Choice == 'r')
							{
								system("CLS");
								cout << "You attempt to run away" << endl << endl;
								Interact = rand() % 20 + 1;
								if ((Agi + Interact) > EnemyDef)
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
							while (EnemyTurn == true)
							{

								cout << "The " << NegDescriptor << " " << Name << " attacks you!" << endl << endl;
								Hit = rand() % 20 + 3;
								if (Hit >= Agi + 10)
								{
									Damage = Attack(0);
									PlayerClass.HealthCurrent = PlayerClass.HealthCurrent - Damage;
									cout << "It deals you " << Damage << " damage." << endl << endl;
									EnemyTurn = false;
									system("pause");
								}
								else
								{
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
							cout << "You encounter a " << Name << "!" << endl;

							cout << "Health: " << Health << "/" << HealthMax << endl << "Mana: " << Mana << "/" << ManaMax << endl << "EXP: " << EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl << endl;
							cout << "Attack | Heal | Run" << endl;
							cin >> Choice;
							while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h')
							{
								cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
								cin >> Choice;
							}
							if (Choice == 'A' || Choice == 'a')
							{
								Hit = rand() % 20 + 1 + Agi;
								if (Hit >= EnemyDef)
								{
									system("CLS");
									Damage = Attack(Str);
									EnemyHealth = EnemyHealth - Damage;
									cout << endl << endl;
									cout << "You attack! Dealing " << Damage << " to the " << Name << "!" << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << Name << "!" << endl << endl;
										EXP = EXP + (Layers * 25);
										cout << "You earned " << Layers * 25 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");
									}
									else
									{
										EnemyTurn = true;
									}
								}
								else if (Hit < EnemyDef)
								{
									system("CLS");
									cout << "Your attack misses as you swing too wide! " << endl << endl;
									EnemyTurn = true;
								}
							}
							else if (Choice == 'H' || Choice == 'h')
							{
								system("CLS");
								Healing = Heal(Smarts);
								Health = Health + Healing;
								Mana--;
								cout << "You heal yourself for " << Healing << "Points of damage!" << endl;
								system("pause");

								if (Health > HealthMax)
								{
									Health = HealthMax;
								}
								EnemyTurn = true;
							}
							else if (Choice == 'R' || Choice == 'r')
							{
								system("CLS");
								cout << "You attempt to run away" << endl << endl;
								Interact = rand() % 20 + 1;
								if ((Agi + Interact) > EnemyDef)
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

							while (EnemyTurn == true)
							{

								cout << "The" << Name << " attacks you!" << endl << endl;
								Hit = rand() % 20 + 5;
								if (Hit >= Agi + 10)
								{
									Damage = Attack(3);
									Health = Health - Damage;
									cout << "It deals you " << Damage << " damage." << endl << endl;
									EnemyTurn = false;
									system("pause");
								}
								else
								{
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
							cout << "You encounter a " << PosDescriptor << " " << Name << "!" << endl;

							cout << "Health: " << Health << "/" << HealthMax << endl << "Mana: " << Mana << "/" << ManaMax << endl << "EXP: " << EXP << "/1000" << endl << endl;
							cout << "Your turn" << endl << endl;
							cout << "What will you do?" << endl << endl;
							cout << "Attack | Heal | Run" << endl;
							cin >> Choice;
							while (Choice != 'A' && Choice != 'a' && Choice != 'R' && Choice != 'r' && Choice != 'H' && Choice != 'h')
							{
								cout << "That is not a valid action. Please choose to Attack, Heal, or Run." << endl;
								cin >> Choice;
							}
							if (Choice == 'A' || Choice == 'a')
							{
								Hit = rand() % 20 + 1 + Agi;
								if (Hit >= EnemyDef)
								{
									system("CLS");
									Damage = Attack(Str);
									EnemyHealth = EnemyHealth - Damage;
									cout << endl << endl;
									cout << "You attack! Dealing " << Damage << " to the " << Name << "!" << endl << endl;
									if (EnemyHealth <= 0)
									{
										cout << "You killed the " << Name << "!" << endl << endl;
										EXP = EXP + (Layers * 30);
										cout << "You earned " << Layers * 30 << "EXP!" << endl << endl;
										Encounter = false;
										system("pause");
									}
									else
									{
										EnemyTurn = true;
									}
								}
								else if (Hit < EnemyDef)
								{
									system("CLS");
									cout << "Your attack misses as you swing too wide! " << endl << endl;
									EnemyTurn = true;
								}
							}
							else if (Choice == 'H' || Choice == 'h')
							{
								system("CLS");
								Healing = Heal(Smarts);
								Health = Health + Healing;
								Mana--;
								cout << "You heal yourself for " << Healing << "Points of damage!" << endl;
								system("pause");

								if (Health > HealthMax)
								{
									Health = HealthMax;
								}
								EnemyTurn = true;
							}
							else if (Choice == 'R' || Choice == 'r')
							{
								system("CLS");
								cout << "You attempt to run away" << endl << endl;
								Interact = rand() % 20 + 1;
								if ((Agi + Interact) > EnemyDef)
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
							while (EnemyTurn == true)
							{

								cout << "The" << Name << " attacks you!" << endl << endl;
								Hit = rand() % 20 + 5;
								if (Hit >= Agi + 10)
								{
									Damage = Attack(6);
									Health = Health - Damage;
									cout << "It deals you " << Damage << " damage." << endl << endl;
									EnemyTurn = false;
									system("pause");
								}
								else
								{
									cout << "But you manage to evade it's attack!" << endl << endl;
									EnemyTurn = false;
									system("pause");
								}
							}
						}
					}	
				}	
				
			}

		}
	//cout << Health << " " << Str << " " << Agi << " " << Smarts << " " << Mana;



	cin.ignore();
	cin.get();

}
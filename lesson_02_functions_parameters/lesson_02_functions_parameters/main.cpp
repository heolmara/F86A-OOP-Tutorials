#include <iostream>
#include <random>

using namespace std;


int PlayerAttack(int enemyHealth)
{
	enemyHealth -= 10; // enemyHealth = enemyHealth - enemyHealth
	std::cout << "You attack the enemy for 10 damage!\n";

	return enemyHealth;
}

int PlayerHeal(int playerHealth)
{
	int potionUses = 3;
	if (potionUses > 0)
	{
		potionUses -= 1;
		playerHealth += 10;
		std::cout << "You heal for 10 HP!\n";
	}
	else if (potionUses <= 0) // if all potions used
	{
		std::cout << "You have no more potions!\n";
	}

	return playerHealth;
}

void DisplayStats(int playerHealth, int enemyHealth) // displays stats when each attack starts
{
	std::cout << "\nPlayer Health: " << playerHealth << endl;
	std::cout << "Enemy Health: " << enemyHealth << endl;
	std::cout << "1. Attack\n2. Defend\n3. Heal\nChoose: ";
}

int RestartGame(int playerHealth, int enemyHealth)
{
	std::cout << "Restarting!\n";
	playerHealth = 100; // resets player and enemy health when restarting
	enemyHealth = 50;

	return playerHealth, enemyHealth;
}

bool QuitGame(bool quitGame)
{
	std::cout << "Quitting!\n";
	quitGame = true;

	return quitGame;
}

void WinOrDefeat(int playerHealth)
{
	std::cout << ((playerHealth <= 0) ? "You were defeated!\n" : "\nEnemy defeated!\n");
	std::cout << "\nQuit Game?\n1. No\n2. Yes\nChoose: ";
}

int EnemyDamage(int enemyHealth, int choice, int playerHealth) // calculates enemy damage with a random number generator
{
	random_device rd; // set up generator
	mt19937 gen(rd()); // seed mersenne twister (number generator)
	uniform_int_distribution<> dist(5, 15); // gives number between 5 and 15
	
	int enemyDamage = (choice == 2) ? 2 : dist(gen); // defending halves damage
	playerHealth -= enemyDamage;
	std::cout << "The enemy attacks you for " << enemyDamage << " damage!\n";
	return playerHealth;
}


int main()
{
	int playerHealth = 100;
	int enemyHealth = 50;
	int choice = 0;
	string choiceQuit = "null";
	bool quitGame = false;

	while (quitGame == false)
	{
		while (playerHealth > 0 && enemyHealth > 0)
		{
			DisplayStats(playerHealth, enemyHealth);
			cin >> choice;
			switch (choice)
			{
			case 1:																// choice 1: attack
					enemyHealth = PlayerAttack(enemyHealth); 
					break;
			case 2:																// choice 2: defend
					std::cout << "You defend and reduce incoming damage!\n";
					break;
			case 3:																// choice 3: heal
					playerHealth = PlayerHeal(playerHealth);
					break;
			default:															// invalid answer
					std::cout << "Invalid choice, please try again.\n";
					cin >> choice;
					break;
			}
			playerHealth = EnemyDamage(enemyHealth, choice, playerHealth);
		}

		WinOrDefeat(playerHealth);
		cin >> choice;

		switch (choice)
		{
		case 1:																	// choice 1: restart game
				playerHealth, enemyHealth = RestartGame(playerHealth, enemyHealth);
				break;
		case 2:																	// choice 2: quit game
				quitGame = QuitGame(quitGame);
				break;
		default:
				std::cout << "Invalid choice, please try again.\n"; // gets the player to input a new choice if choice is invalid
				cin >> choice;
				break;
		}
	}

	return 0;
}

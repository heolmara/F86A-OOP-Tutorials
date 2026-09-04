#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd; // set up generator
	mt19937 gen(rd()); // seed mersenne twister (number generator)
	uniform_int_distribution<> dist(5, 15); // gives number between 5 and 15

	int playerHealth = 100;
	int enemyHealth = 50;
	int choice = 0;
	int potionUses = 3;
	string choiceQuit = "null";
	bool quitGame = false;

	while (quitGame == false)
	{
		while (playerHealth > 0 && enemyHealth > 0)
		{
			cout << "\nPlayer Health: " << playerHealth << endl;
			cout << "Enemy Health: " << enemyHealth << endl;
			cout << "1. Attack\n2. Defend\n3. Heal (" << potionUses << " left)\nChoose: ";
			cin >> choice;

			if (choice == 1)
			{
				enemyHealth -= 10; // enemyHealth = enemyHealth - enemyHealth
				cout << "You attack the enemy for 10 damage!\n";
			}
			else if (choice == 2)
			{
				cout << "You defend and reduce incoming damage!\n";
			}
			else if (choice == 3)
			{
				if (potionUses > 0)
				{
					potionUses -= 1;
					playerHealth += 10;
					cout << "You heal for 10 HP!\n";
				}
				else if (potionUses <= 0) // if all potions used
				{
					cout << "You have no more potions!\n";
				}
			}
			else
			{
				cout << "Invalid choice, please try again.\n";
				cin >> choice;
			}

			if (enemyHealth > 0)
			{
				int enemyDamage = (choice == 2) ? 2 : dist(gen);
				playerHealth -= enemyDamage;
				cout << "The enemy attacks you for " << enemyDamage << " damage!\n";
			}
		}

		cout << ((playerHealth <= 0) ? "You were defeated!\n" : "\nEnemy defeated!\n");
		cout << "\nQuit Game?\n1. No\n2. Yes\nChoose: ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Restarting!\n";
			playerHealth = 100; // resets player and enemy health when restarting
			enemyHealth = 50;
		}
		else if (choice == 2)
		{
			cout << "Quitting!\n";
			quitGame = true;
		}
		else
		{
			cout << "Invalid choice, please try again.\n";
			cin >> choice;
		}
	}

	return 0;
}
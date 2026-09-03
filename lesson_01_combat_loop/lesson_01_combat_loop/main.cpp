#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd; // set up generator
	mt19937 gen(rd()); // seed mersenne twister (number generator)
	uniform_int_distribution<> dist(10, 20); // gives number between 10 and 20 

	int playerHealth = 100;
	int enemyHealth = 50;
	int choice = 0;

	while (playerHealth > 0 && enemyHealth > 0)
	{
		cout << "\nPlayer Health: " << playerHealth << endl;
		cout << "Enemy Health: " << enemyHealth << endl;
		cout << "1. Attack\n2. Defend\nChoose: ";
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
			playerHealth + 10;
			cout << "You heal for 10 HP!\n";
		}
		if (enemyHealth > 0)
		{

			int enemyDamage = (choice == 2) ? 2 : 5;
			playerHealth -= enemyDamage;
			cout << "The enemy attacks you for " << enemyDamage << " damage!\n";
		}

	}

	cout << ((playerHealth <= 0) ? "You were defeated!\n" : "\nEnemy defeated!\n");
	return 0;
}
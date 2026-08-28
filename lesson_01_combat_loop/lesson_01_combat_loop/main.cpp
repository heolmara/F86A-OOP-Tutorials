#include <iostream>
using namespace std;

int main()
{
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
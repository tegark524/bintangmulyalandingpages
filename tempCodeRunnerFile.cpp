#include <iostream>
using namespace std;

// Base class
class Player {
protected:
    string name;
    int health;

public:
    // Constructor
    Player(string n) {
        name = n;
        health = 100;
        cout << "Player " << name << " created with 100 HP!" << endl;
    }

    // Destructor
    ~Player() {
        cout << "Player " << name << " destroyed!" << endl;
    }

    void displayStatus() {
        cout << "Name: " << name << ", Health: " << health << endl;
    }

    void takeDamage(int dmg) {
        health -= dmg;
        cout << name << " took " << dmg << " damage! Remaining HP: " << health << endl;
        if (health <= 0) {
            cout << name << " has been defeated!" << endl;
        }
    }
};

// Derived class (Inheritance)
class Warrior : public Player {
private:
    int power;

public:
    // Constructor menggunakan initializer list
    Warrior(string n, int p) : Player(n) {
        power = p;
        cout << "Warrior " << name << " ready with " << power << " power!" << endl;
    }

    void attack(Player& target) {
        cout << name << " attacks with power " << power << "!" << endl;
        target.takeDamage(power);
    }
};

// Another Derived class (for more variation)
class Mage : public Player {
private:
    int mana;

public:
    Mage(string n, int m) : Player(n) {
        mana = m;
        cout << "Mage " << name << " appears with " << mana << " mana!" << endl;
    }

    void castSpell(Player& target) {
        if (mana >= 20) {
            cout << name << " casts Fireball!" << endl;
            target.takeDamage(30);
            mana -= 20;
        } else {
            cout << name << " is out of mana!" << endl;
        }
    }
};

int main() {
    // Membuat object Warrior dan Mage
    Warrior w1("GarWarrior", 25);
    Mage m1("GarMage", 40);

    cout << "\n=== Game Start ===\n" << endl;

    w1.displayStatus();
    m1.displayStatus();

    cout << "\n[Round 1]\n";
    w1.attack(m1);

    cout << "\n[Round 2]\n";
    m1.castSpell(w1);

    cout << "\n[Round 3]\n";
    m1.castSpell(w1);

    cout << "\n=== Game End ===" << endl;

    return 0;
}

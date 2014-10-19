#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class TipCalc {
  bool trigger;
  float meal, tax, tip;
public:
  TipCalc() {
    trigger = false;
    meal = 0.0;
    tax = 0.0;
    tip = 0.0;
    srand(time(0));
    user_input();
  }

  int user_input() {
    char input;
    cout << "Please input the meal cost $0.00" << endl;
    cin >> meal;
    cout << "Please input the tax 0%" << endl;
    cin >> tax;
    cout << "Would you like to give a random tip? (y/n)" << endl;
    cin >> input;
    while(input != 'y' && input != 'n') {
      cout << "please enter 'y' or 'n'" << endl;
      cin >> input;
    }
    if(input == 'y') {
      random_tip();
      print_values();
    }
    if(input == 'n') {
      cout << "input tip 0%" << endl;
      cin >> tip;
      print_values();
    }
    return 0;
  }

  int random_tip() {
    if(trigger == false) {
      tip = rand() % 31;
      trigger = true;
    }
    else {
      tip = 0.0;
      trigger = false;
    }
    return 0;
  }

  int print_values() {
    float meal_plus_tax = meal + calculate_rate(meal, tax);
    float total = meal_plus_tax + calculate_rate(meal_plus_tax, tip);
    cout << "cost of meal is $" << meal << endl;
    cout << "tax " << tax << endl;
    cout << "tip " << tip << endl;
    cout << "total amount due: $" << setprecision(4) << total << endl;
    cout << "calculate again? (y/n)" << endl;
    char input;
    cin >> input;
    while(input != 'y' && input != 'n') {
      cout << "please enter 'y' or 'n'" << endl;
      cin >> input;
    }
    if(input == 'y') {
      meal = 0.0;
      tax = 0.0;
      tip = 0.0;
      user_input();
    }
    return 0;
  }
  
  float calculate_rate(float base, float percentage) {
    float amount = base * percentage / 100;
    return amount;
  }
};

int main() {
  TipCalc tip;
  return 0;
}
#include <iostream>
using namespace std;

class TipCalc {
  float meal, tax, tip;
public:
  TipCalc() {
    meal = 0.0;
    tax = 0.0;
    tip = 0.0;
    user_input();
  }

  float user_input() {
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
    }
    cout << "input tip 0%" << endl;
    if(input == 'n') {
      cin >> tip;
      print_values();
    }
  }

  float random_tip() {
    output[] = 
  }
}
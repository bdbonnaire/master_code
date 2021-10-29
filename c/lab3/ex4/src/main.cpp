/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/21 12:21:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <locale> // isdigit
#include <sstream>
#include "bank_account.hpp"
#include "currencies.hpp"

using namespace std;

void bad_ending(int kind)
{
	switch(kind){
		case 0: //bad option
			cout << "That's not an option ! Don't joke around ! GARDS !!\n";
			cin.ignore();
			cout << "\t\t You died, in a ditch, alone and not missed. \n GAME OVER." << endl;
			break;
		case 1: //nonsense
			cout << "Are you stupid ? \n";
			cin.ignore();
			cout << "Oh my, you are ! I'm so sorry it must be so hard for you.\n Let me call the nurse\n";
			cin.ignore();
			cout << "You slowly realize you have been insane all this time. \n The world spins around as you die in madness. \n";
			cin.ignore();
			cout << "GAME OVER : You are mad." << endl;
			break;
		case 2: // forfeit
			cout << "The banker sniffs loudly and shows you the door. \n You feel like a joke.\n ";
			cin.ignore();
			cout << "You live the rest of your life in shame as you wonder what went wrong.\n";
			cin.ignore();
			cout << "GAME OVER : What happened ?.." << endl;
			break;
		case 3: //Peasant
			cout << "Brave man, we do not serve peasants 'round here. Go play with coal or something.\n";
			cin.ignore();
			cout << "GAME OVER : His hands are dirty but his heart is clean.";
			break;
	}
}

template <class Type_currency> void make_account(string name, float amount){
	Type_currency balance(amount);
	Bank_account<Type_currency> account(name, balance);
    cout << "Congratulation Mr. " << name << ", your bank account is created. \n see for yourself :\n";
	cout << account;
	cout << "CONGRATULATIONS !!! YOU WIN !!!";
}

int main(){

	locale loc;
	cout << "Well well well... You'd like to have a bank account ? (Y/n) \n";
	string answer = "";
	cin >> answer;
	if(answer == "y" || answer == "Y" || answer == ""){
		cout << "Are you sure you can handle it ? (Y/n) \n";
		cin >> answer;

		if(answer == "y" || answer == "Y" || answer == ""){
			cout << "Very well, what is your name kind sir ? \n ~~~> ";
			string name;
			cin >> name;

			cout << "How much money do you have ? \n ~~~> ";
			float amount;
			cin >> amount;
			if(amount <= 10)
			{
				bad_ending(3);
				return 0;
			}

			cout << " Do you carry dollaroos(0, default), euroos(1) or peonds (2) ?\n ~~~> ";
			cin >> answer;
			if(answer == ""){
				make_account<Dollar>(name, amount);
				return 0;
			}

			if(isdigit(answer, loc)){
				int choice;
				stringstream(answer) >> choice;
				switch(choice) {
				case 0:
					make_account<Dollar>(name, amount);
					return 0;
					break;

				case 1:
					make_account<Euro>(name, amount);
					return 0;
					break;

				case 2:
					make_account<Pounds>(name, amount);
					return 0;
					break;

				default:
					bad_ending(0);
					break;
				}
			}
			else{
				bad_ending(1);
	
			}
		}
		else{
			bad_ending(2);
		}
	}
	else{
		bad_ending(2);
	}


	
	return 0;
}

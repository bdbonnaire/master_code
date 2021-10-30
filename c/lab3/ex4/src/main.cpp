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

bool isNum(string s)
{
	locale loc;

	for(unsigned long i=0; i < s.size(); i++)
		if(! isdigit(s[0], loc))
			return false;
	return true;
}

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
    cout << "Congratulation Mr. " << name << ", your bank account is created. \n see for yourself :\n\n";
	cout << account;
	cout << "\n CONGRATULATIONS !!!";
}
template void make_account<Dollar>(string name, float amount);
template void make_account<Euro>(string name, float amount);
template void make_account<Pounds>(string name, float amount);

int main(){

	cout << "Well well well... You'd like to have a bank account ? (Y/n) \n";
	string answer = "";
	getline( cin,  answer);
	if(answer == "y" || answer == "Y" || answer.empty()){
		cout << "Are you sure you can handle it ? (Y/n) \n";
		getline( cin,  answer);

		if(answer == "y" || answer == "Y" || answer.empty()){
			cout << "Very well, what is your name kind sir ? \n ~~~> ";
			string name;
			getline(cin, name);

			cout << "How much money do you have ? \n ~~~> ";
			string money;
			float amount;
			
			getline(cin, money);
			if(isNum(money)){
				amount = stof(money);
				if(amount <= 10)
				{
					bad_ending(3);
					return 0;
				}
			}
			else{
				bad_ending(1);
				return 0;
			}

			answer.clear();
			cout << " Do you carry dollaroos(0, default), euroos(1) or peonds (2) ?\n ~~~> ";
			getline( cin,  answer);
			if(answer == ""){
				make_account<Dollar>(name, amount);
				return 0;
			}

			if(isNum(answer)){
				int choice = stoi(answer);
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
		else if(answer == "n"){
			bad_ending(2);
		}
		else{
			bad_ending(1);
		}
	}
	else if(answer == "n"){
		bad_ending(2);
	}
	else{
		bad_ending(1);
	}


	
	return 0;
}

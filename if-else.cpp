//[PakDHE5758](https://github.com/PakDHE5758)
#include <iostream>
using namespace std;

int main(){
	int ticket;
	cout << "Welcome to the Festival.\n 5$ for the ticket\n\n\n";
	cin >> ticket;
	
	if (ticket < 5){
		cout << "Sorry you can't enter the festival";
	}
	else if (ticket > 5){
		cout << "Thank you, here your change";
	}
	else {
		cout << "Thank you here your ticket, enjoy your time";
	}
}
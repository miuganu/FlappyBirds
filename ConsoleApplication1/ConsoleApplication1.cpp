// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <windows.h>
using namespace std;

void sfarsitjoc() 
{
	screen();   

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "" << endl << endl;
	cout << " ------------------------------------------------------------------------- " << endl;
	cout << "|    *****      *     *       * ******       ****  *       ****** ****    |" << endl;
	cout << "|   *          * *    * *   * * *           *    *  *     * *     *   *   |" << endl;
	cout << "|   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    |" << endl;
	cout << "|   *  *  *  *******  *   *   * *           *    *    * *   *     * *     |" << endl;
	cout << "|    *****  *       * *       * ******       ****      *    ***** *   *   |" << endl;
	cout << " ------------------------------------------------------------------------- " << endl;
	cout << "" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "                        S C O R U L   T A U : " << scor << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "          C E L   M A I   M A R E   S C O R : " << highscore << endl;
	cout << "" << endl << endl;
}

void meniu()  
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "" << endl;
	cout << " --------------------------------------------------------  " << endl;
	cout << "|                                                        | " << endl;
	cout << "|   **** *    **** **** **** *   *    ***  * ***  ***    | " << endl;
	cout << "|   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | " << endl;
	cout << "|   ***  *    **** **** **** *****    ***  * ***  *  *   | " << endl;
	cout << "|   *    *    *  * *    *      *      *  * * *  * *  *   | " << endl;
	cout << "|   *    **** *  * *    *      *      ***  * *  * ***    | " << endl;
	cout << " --------------------------------------------------------  " << endl;
	cout << "" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "                  Cel mai bun scor:  " << highscore << endl << endl;
	cout << "" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "                   M E N I U:    " << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "                  1: Incepe jocul" << endl << endl;
	cout << "                  2: Ajutor        " << endl << endl;
	cout << "                  3: Exit        " << endl << endl;
}

void screen() 
{
    int x,y;
    system("cls");  


    for(y=0;y<25;y++) 
    {
        for(x=0;x<30;x++)
        {
            if(x<29) cout<<afisaj[x][y];
            if(x==29) cout<<afisaj[x][y]<<endl;
        }
    }

    cout<<"Scorul tau: "<<scor;
    cout<<""<<endl;
}


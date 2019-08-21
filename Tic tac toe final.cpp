#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

char sq[10] = {'0','1','2','3','4','5','6','7','8','9'};

int board();
void checkWin();
void comp();

int human, i;
char choice, playagain, wish;

int main()
{

	do{
		board();
		
		wishi:
			cout<<"Want to play first or not? :: Y for YES/ N for NO";
			cin>>wish;
			cin.ignore();
			//Human select he will play first or comp
				if(wish=='y'|| wish=='Y'){
					human = 1;
					cout<<"Nice.. Start"<<endl;				
				}
				else if (wish=='n'|| wish=='N'){
					human = 2;
					cout<<"You choose to play computer first.."<<endl;}
				
				else if(wish!='y'||wish!='Y'||wish!='n'||wish!='N')
				{
					cout<<"Please type 'Y' for YES or 'N' for NO"<<endl;
				}
				
			//Selection ends
			Sleep(1400);
			system("cls");
			
			
			do
			{
				board();
				
				human=(human%2);
				cout<<"Press the given button in the block to mark it with X"<<endl;
				if (human!=0)
				{
					cout<<"HUMAN--Press the button to play:";
					cin>>choice;
					
					
					if(choice=='1' && sq[1]=='1')
					sq[1]='X';
					else if(choice=='2' && sq[2]=='2')
					sq[2]='X';
					else if(choice=='3' && sq[2]=='3')
					sq[3]='X';
					else if(choice=='4' && sq[2]=='4')
					sq[4]='X';
					else if(choice=='5' && sq[2]=='5')
					sq[5]='X';
					else if(choice=='6' && sq[2]=='6')
					sq[6]='X';
					else if(choice=='7' && sq[2]=='7')
					sq[7]='X';
					else if(choice=='8' && sq[2]=='8')
					sq[8]='X';
					else if(choice=='9' && sq[2]=='9')
					sq[9]='X';
					
					else  //if space is already filled
					{
						cout<<"Are you doing this intentionally...INVALID MOVE";
						human--;
						cin.ignore();
						cin.get();
					}
					
					i=checkWin();
					human ++;
					
					system("cls");
				}
				
				else if (human ==0) //Computer turn
				{
					comp();
					i = checkWin();
					human++;
				}
			}
			
			
			while(i==-1);
			board();
			if(i==1)
			{
				if(human!=0)
				{
					cout<<"Awesome U win :)";
				}
				else
				{
					cout<<"Better Luck next time";
				}
			}
			
			else if(i==0)
			{
				cout<<"Game is Drawn";
			}
			cin.ignore();
			cin.get();
			cout<<"Would you like to Play again: (ENTER Y for YES:: N for NO";
			cin>>playagain;
			if(playagain=='y'||'Y')
			{
				sq[1]='1';sq[2]='2';sq[3]='3';
				sq[4]='4';sq[5]='5';sq[6]='6';
				sq[7]='7';sq[8]='8';sq[9]='9';
			}
			system("cls");
	}
	
	while (playagain=='y'||'Y');
	return 0;
}

void checkWin()
{
	//horizontal checks
	if(sq[1]==sq[2] && sq[1]==sq[3])
	retrun 1;
	
	else if(sq[4]==sq[5] && sq[4]==sq[6])
	retrun 1;
	
	else if(sq[7]==sq[8] && sq[7]==sq[9])
	retrun 1;
	
	
	//Vertical checks
	
	else if(sq[1]==sq[4] && sq[1]==sq[7])
	retrun 1;
	
	else if(sq[2]==sq[5] && sq[2]==sq[8])
	retrun 1;
	
	else if(sq[3]==sq[6] && sq[3]==sq[9])
	retrun 1;
	
	
	//Diagonal Checks
	
	else if(sq[1]==sq[5] && sq[1]==sq[9])
	retrun 1;
	
	else if(sq[3]==sq[5] && sq[3]==sq[7])
	retrun 1;
	
	//Draw case
	
	else if (sq[1]!='1' && sq[2]!='2'&& sq[3]!='3'&&
			 sq[4]!='4' && sq[5]!='5'&& sq[6]!='6'&&
			 sq[7]!='7' && sq[8]!='8'&& sq[9]!='9')
	return 0;
	else
	return -1;	
}

void board()
{
	cout<< "**\t\t     |     |      \t\t\t**" <<endl;
	cout<< "**\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3]  <<"\t\t\t\t**"<<endl;

	cout<< "**\t\t_____|_____|_____\t\t\t**" <<endl;
	cout<< "**\t\t     |     |     \t\t\t**" <<endl;

	cout<< "**\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6]<<"\t\t\t\t**"<<endl;

	cout<< "**\t\t_____|_____|_____\t\t\t**" <<endl;
	cout<< "**\t\t     |     |     \t\t\t**" <<endl;

	cout<< "**\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9]<< "\t\t\t\t**"<<endl;

	cout<< "**\t\t     |     |      \t\t\t**" <<endl;
}


void comp()
{
if(square[1] =='O' && square[2] =='O' && square[3] =='3') {square[3]='O';}

else if(square[4] =='O' && square[5] =='O' && square[6] =='6') {square[6]='O';}

else if(square[7] =='O' && square[8] =='O' && square[9] =='9') {square[9]='O';}


else if(square[2] =='O' && square[3] =='O' && square[1] =='1'){square[1]='O';}

else if(square[5] =='O' && square[6] =='O' && square[4] =='4'){square[4]='O';}

else if(square[8] =='O' && square[9] =='O' && square[7] =='7'){square[7]='O';}


else if(square[1] =='O' && square[3] =='O' && square[2] =='2') {square[2]='O';}

else if(square[4] =='O' && square[6] =='O' && square[5] =='5') {square[5]='O';}

else if(square[7] =='O' && square[9] =='O' && square[8] =='8') {square[8]='O';}


else if(square[1] =='O' && square[4] =='O' && square[7] =='7') {square[7]='O';}

else if(square[2] =='O' && square[5] =='O' && square[8] =='8') {square[4]='O';}

else if(square[3] =='O' && square[6] =='O' && square[9] =='9') {square[9]='O';}


else if(square[4] =='O' && square[7] =='O' && square[1] =='1') {square[1]='O';}

else if(square[5] =='O' && square[8] =='O' && square[2] =='2') {square[2]='O';}

else if(square[6] =='O' && square[9] =='O' && square[3] =='3') {square[3]='O';}


else if(square[1] =='O' && square[7] =='O' && square[4] =='4') {square[4]='O';}

else if(square[2] =='O' && square[8] =='O' && square[5] =='5') {square[5]='O';}

else if(square[3] =='O' && square[9] =='O' && square[6] =='6') {square[6]='O';}


else if(square[1] =='O' && square[5] =='O' && square[9] =='9') {square[9]='O';}

else if(square[5] =='O' && square[9] =='O' && square[1] =='1') {square[1]='O';}

else if(square[1] =='O' && square[9] =='O' && square[5] =='5') {square[5]='O';}


else if(square[3] =='O' && square[5] =='O' && square[7] =='7'){square[7]='O';}

else if(square[7] =='O' && square[5] =='O' && square[3] =='3'){square[3]='O';}

else if(square[7] =='O' && square[3] =='O' && square[5] =='5'){square[5]='O';}


else if(square[1] =='X' && square[2] =='X' && square[3] =='3') {square[3]='O';}

else if(square[4] =='X' && square[5] =='X' && square[6] =='6') {square[6]='O';}

else if(square[7] =='X' && square[8] =='X' && square[9] =='9') {square[9]='O';}


else if(square[2] =='X' && square[3] =='X' && square[1] =='1'){square[1]='O';}

else if(square[5] =='X' && square[6] =='X' && square[4] =='4'){square[4]='O';}

else if(square[8] =='X' && square[9] =='X' && square[7] =='7'){square[7]='O';}


else if(square[1] =='X' && square[3] =='X' && square[2] =='2'){square[2]='O';}

else if(square[4] =='X' && square[6] =='X' && square[5] =='5'){square[5]='O';}

else if(square[7] =='X' && square[9] =='X' && square[8] =='8'){square[8]='O';}


else if(square[1] =='X' && square[4] =='X' && square[7] =='7'){square[7]='O';}

else if(square[2] =='X' && square[5] =='X' && square[8] =='8'){square[8]='O';}

else if(square[3] =='X' && square[6] =='X' && square[9] =='9'){square[9]='O';}


else if(square[4] =='X' && square[7] =='X' && square[1] =='1'){square[1]='O';}

else if(square[5] =='X' && square[8] =='X' && square[2] =='2'){square[2]='O';}

else if(square[6] =='X' && square[9] =='X' && square[3] =='3'){square[3]='O';}


else if(square[1] =='X' && square[7] =='X' && square[4] =='4') {square[4]='O';}

else if(square[2] =='X' && square[8] =='X' && square[5] =='5') {square[5]='O';}

else if(square[3] =='X' && square[9] =='X' && square[6] =='6') {square[6]='O';}


else if(square[1] =='X' && square[5] =='X' && square[9] =='9') {square[9]='O';}

else if(square[5] =='X' && square[9] =='X' && square[1] =='1') {square[1]='O';}

else if(square[1] =='X' && square[9] =='X' && square[5] =='5') {square[5]='O';}


else if(square[3] =='X' && square[5] =='X' && square[7] =='7')   {square[7]='O';}

else if(square[7] =='X' && square[5] =='X' && square[3] =='3')   {square[3]='O';}

else if(square[7] =='X' && square[3] =='X' && square[5] =='5')   {square[5]='O';}


else if(square[1] =='X' && square[5] =='O' && square[9] =='X')   {square[6]='O';}

else if(square[3] =='X' && square[5] =='O' && square[7] =='X')   {square[4]='O';}

else if(square[5] =='5'){square[5]='O';}

else if(square[1] =='1'){square[1]='O';}

else if(square[9] =='9'){square[9]='O';}
else if(square[7] =='7'){square[7]='O';}

else if(square[3] =='3'){square[3]='O';}
          /***"****************WE can add
else if(square[7] =='7'){square[7]='O';} or
else if(square[3] =='3'){square[3]='O';} or both

to increase the difficulty level*************/
else if(square[2] =='2'){square[2]='O';}

else if(square[4] =='4'){square[4]='O';}

else if(square[6] =='6'){square[6]='O';}

else if (square[8] =='8'){square[8]='O';}

         }


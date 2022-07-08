#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int findwords()
{
        string line;
        int count=0;   
    	
		ifstream mFile ("cards2.txt");  
        
        while(!mFile.eof())
        {
        	getline(mFile, line);
        	count++;
		}

		mFile.close();
		
		return count;
}

void read_data(int* sr,string* name,string* s2,string* s3,string* s4,string* s5)
{
    ifstream iFile("cards2.txt"); 
    int c=0;
    
    while (!iFile.eof())
    {
        string n1,n2;   int n;
        iFile >> n;  
        sr[c]=n;
        
        iFile >> n1;    
        iFile >> n2;    
        name[c]=n1+" "+n2;
        
        iFile >> n1;    
		s2[c]=n1;
        iFile >> n1;    
		s3[c]=n1;
        iFile >> n1;    
		s4[c]=n1;
        iFile >> n1;    
		s5[c]=n1;
        c++;
    }
}

void writeToFile(ofstream &outputfile, string name, string s2, string s3, string s4, string s5)
{	
	outputfile << "HI" << endl;
	
	outputfile << endl << endl << "The card that you get is: " << name<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<endl <<endl;	
}
		


int random_number()
{
   int random = 1 + (rand() % 10);
   return random;
}

int deleteElement(int arr[],string name[],string s2[],string s3[],string s4[],string s5[], int n, int x)
{
    //deleteElement(sr,name,s2,s3,s4,s5,count, i);
// Search x in array
int i;
for (i=0; i<n; i++)
{
	if (arr[i] == x)
		break;
}

// If x found in array
if (i < n)
{
	// reduce size of array and move all
	// elements on space ahead
	n = n - 1;
	for (int j=i; j<n; j++)
	{
		arr[j] = arr[j+1];
		name[j] = name[j+1];
		s2[j] = s2[j+1];
		s3[j] = s3[j+1];
		s4[j] = s4[j+1];
		s5[j] = s5[j+1];
	}
}

return n;
}
float type(string s4, string s3)
{
	float marks;
	if(s4 == "Attack")
		marks = 4;
	else if (s3 == "Balance")
		marks = 3;
	else if (s3 == "Attack")
		marks = 2;
	else if (s3 == "Defense")
		marks = 1;
		
	return marks;
}

float system(string s5)
{
	float marks2;
	if (s5 == "QuadDrive")
		marks2 = 6;
	else if (s5 == "HyperSphere")
		marks2 = 5;
	else if (s5 == "SpeedStorm")
		marks2 = 4;
	else if (s5 == "Burst")
		marks2 = 3;
	else if (s5 == "SwitchStrike")
		marks2 = 2;
	else if (s5 == "DualLayer")
		marks2 = 1;
	else if (s5 == "SlingShock")
		marks2 = 0.5;
		
	return marks2;
}



int main()
{
	string player1_name, player2_name, beyblade_name, product_code, plus_mode, system;
	int cards;
	
	bool logic = false;
	char repeat;
	
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "--                      Welcome to the beyblade game!                   --" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
	
	//getting player 1's and player 2's names
	cout << "Please enter your name." << endl << "Player 1: ";
	getline(cin, player1_name);
	cout << "Player 2: ";
	getline(cin, player2_name);
	cout << "\n*******************************************************************************************************************\n";
	do
	{
		int count=0, round, turn, n, k, cards = 10, marks, marks2, score_player1 = 0, score_player2 = 0;
		float total_marks1, total_marks2, total1, total2, sumScore =0, sumScore2 = 0;
		count=findwords();
		k=count;
		int *sr;  sr= new int[count];
		string *name;  name= new string[count];
		string *s2;  s2= new string[count];  
		string *s3;  s3= new string[count];
		string *s4 ;  s4 = new string[count];
		string *s5 ;  s5 = new string[count];
		string *s6 ;  s6 = new string[count];
		read_data(sr,name,s2,s3,s4,s5);
		
		cout << "\n" << setfill ('-') << setw(50) << "This is round " << 1 << "------------------------------------"<< endl;
		for (round = 2; round <= 6; round++)
		{
			for (turn = 1; turn <= 2; turn++)
			{
			
				
				cout << endl << "Player " << turn << ", ";
				for (k = 2; k <= 2; k++)
				{
					
					cout << "the card has shuffled randomly. Enter any number if you want to pick a card: ";
					cin >> n;
					
					ran:
			     int randomnumber=random_number();
			     randomnumber=randomnumber-1;
								
								if(sr[randomnumber] !=-1)
			    {
			        cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
			          cout<<sr[randomnumber]<<"\t\t"<<name[randomnumber]<<"\t\t"<<s2[randomnumber]<<"\t\t"<<s3[randomnumber]<<"\t\t"<<s4[randomnumber]<<"\t\t"<<s5[randomnumber]<<endl;
			        sr[randomnumber] =-1;
			        cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
			  
			    }
			    else
			    	goto ran;
					cout << "Your mark is " << ::type(s4[randomnumber], s3[randomnumber]) << endl;
					cout << "Your mark is " << ::system(s5[randomnumber]) << endl;
					cards--;
		        	
		        	if (turn == 1)
						total1 =+ ::type(s4[randomnumber], s3[randomnumber]) + ::system(s5[randomnumber]);
					else
						total2 =+ ::type(s4[randomnumber], s3[randomnumber]) + ::system(s5[randomnumber]);
						
						if (total1 > total2)
				{
					score_player1 = 10;
					score_player2 = 0;
				}
				else if (total1 < total2)
				{
					score_player2 = 10;
					score_player1 = 0;
				}
				else if (total1 = total2)
				{
					score_player1 = 0;
					score_player1 = 0;
				}
				}
				
				if (turn == 1)
					sumScore += score_player1;
				else
					sumScore2 += score_player2;
					
				
			}
		
			if (cards == 0)
				{
					cout << "Cards finished" << endl << endl;
					
					cout << "\n" << setfill ('-') << setw(50) << "Total score from round 1 to round " << round-1 << "------------------------------------\n"<< endl;
				cout << "\t Player 1 score " << score_player1 << " player 2 score " << score_player2 << endl;
				cout << "     " << player1_name << ", the player 1 scored "<< total1<<" for now." <<endl;
				cout << "     " << player2_name << ", the player 2 scored "<< total2<< " for now." << endl<< endl <<endl<<endl<<endl;
					
					
					//to compare the marks between 2 players and as well as to determine the winner
					if (sumScore > sumScore2)
					{
						cout << "The winner is \n";
						cout << "*******************************\n";
						cout << "**    " << player1_name << ", the player 1.       **\n";
						cout << "*******************************\n\n";
						cout << player1_name << ", the player 1 beats player 2, " << score_player1 << player2_name  << endl;
					}
						
					else if (sumScore < sumScore2)
					{
						cout << "The winner is \n";
						cout << "*******************************\n";
						cout << "**    " << player2_name << ", the player 2.       **\n";
						cout << "*******************************\n\n";
						cout << player2_name << ", the player 2 beats player 1 by " << sumScore2-sumScore << endl;	
						cout << "Player 2 score: " << sumScore2 << " while player 1 score: " << sumScore<<endl;
									
					}
					else
						cout << "Both of the players are draw.";
				}
			if (round != 6)
			{
				cout << "\n" << setfill ('-') << setw(50) << "Total score from round 1 to round " << round-1 << "------------------------------------\n"<< endl;
				cout << "\t Player 1 score " << score_player1 << " player 2 score " << score_player2 << endl;
				cout << "     " << player1_name << ", the player 1 scored "<< total1<<" for now." <<endl;
				cout << "     " << player2_name << ", the player 2 scored "<< total2<< " for now." << endl<< endl <<endl<<endl<<endl;
				cout << "\n" << setfill ('-') << setw(50) << "This is round " << round << "------------------------------------"<< endl;
				{
					ofstream outputfile;
			    outputfile.open("program3data.txt");
			    
			    	int randomnumber=random_number();
			    	count=findwords();
					k=count;
					int *sr;  sr= new int[count];
					string *name;  name= new string[count];
					string *s2;  s2= new string[count];  
					string *s3;  s3= new string[count];
					string *s4 ;  s4 = new string[count];
					string *s5 ;  s5 = new string[count];
					string *s6 ;  s6 = new string[count];
			    	writeToFile(outputfile, name[randomnumber],s2[randomnumber],s3[randomnumber],s4[randomnumber],s5[randomnumber]);
				}
				
				
			}
				
			else
			{
				//ask if the user want to play again or not
				cout << "\n\n\n\n\nDo you want to play again? Press y if yes, press other keys to terminate.\n";
				cin >> repeat;
			}
	}
} while (repeat == 'y' || repeat == 'Y'); //if the user say yes, it will restart the game
}

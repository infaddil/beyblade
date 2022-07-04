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

int random_number()
{
   int random = 1 + (rand() % 10);
   return random;
}

int deleteElement(int arr[],string name[],string s2[],string s3[],string s4[],string s5[], int n, int x)
{
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

int main()
{
	string player1_name, player2_name, beyblade_name, product_code, type, plus_mode, system;
	int cards = 10, player_turn;
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
		int count=0, round, turn, player_turn, k, cards = 10, n, marks, marks2;
		float total_marks1, total_marks2, total1, total2;
		count=findwords();
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
				int randomnumber=random_number();
			randomnumber=randomnumber-1;
			if(sr[randomnumber] !=-1)
				{
				
				cout << endl << "Player " << turn << ", ";
				
				for (k = 2; k <= 2; k++)
				{
					cout << "the card has shuffled randomly. Enter any number if you want to pick a card: ";
					cin >> player_turn;
					
					cout  << endl << "The card that you get is: " << name[randomnumber]<<" "<<s2[randomnumber]<<" "<<s3[randomnumber]<<" "<<s4[randomnumber]<<" "<<s5[randomnumber]<<endl <<endl;
					cout << "Your mark is " << type(s4[randomnumber], s3[randomnumber]) << endl;
					cards--;
		        
				}
		}	}
			if (round != 6)
			{
				cout << "\n" << setfill ('-') << setw(50) << "Total score from round 1 to round " << round-1 << "------------------------------------\n"<< endl;
				cout << "     " << player1_name << ", the player 1 scored "<< total_marks1<<" for now." <<endl;
				cout << "     " << player2_name << ", the player 2 scored "<< total_marks2<< " for now." << endl<< endl <<endl<<endl<<endl;
				cout << "\n" << setfill ('-') << setw(50) << "This is round " << round << "------------------------------------"<< endl;
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

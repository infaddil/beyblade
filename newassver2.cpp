#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
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

int type(string s4, string s3)
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

void writeToFile(ofstream &outputfile, string name, string s2, string s3, string s4, string s5)
{	
	outputfile << "HI" << endl;
	
	outputfile << endl << endl << "The card that you get is: " << name<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<endl <<endl;	
}

void Winner(float total1, float total2,int i)
{
				
				    if (total1 > total2)
					{
						
						cout << "player 1 wins";
						cout << endl << total1 << " " << total2;
					}
					else
					{
						cout << endl << total1 << " " << total2;
						cout << "player 2 wins";
					}
}



int main ()
{
	string on="yes", player1_name, player2_name;
	float total3, total4;
	
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "--                      Welcome to the beyblade game!                   --" << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
	
	cout << "Player 1, please enter your name: ";
	getline(cin, player1_name);
	cout << endl << "Player 2, please enter your name: ";
	getline(cin, player2_name);
	
	cout << endl << "**************************************************************************"<<endl;
	cout << "**                            Game has started!                         **" << endl << endl;
	
    while(on!="NO"||on!="no")
    {
		int count=0;
		count=findwords();
		int *sr;  sr= new int[count];
		string *name;  name= new string[count];
		string *s2;  s2= new string[count];  
		string *s3;  s3= new string[count];
		string *s4 ;  s4 = new string[count];
		string *s5 ;  s5 = new string[count];
		string *s6 ;  s6 = new string[count];
		read_data(sr,name,s2,s3,s4,s5);
	    
	    int k = count;
	    int check=1,r=1;
	    
    	for(int i=1;i<count;i++)
    	{
	        int n;
	        if(k==11)
	        {
	            cout<<"                              This is round 1." << endl << endl;    
	        }
	         if(k==9)
	        {
	            cout<< endl <<"                              This is round 2." << endl << endl;    
	        }
	           if(k==7)
	        {
	            cout<< endl <<"                              This is round 3." << endl << endl;    
	        }
	              if(k==5)
	        {
	            cout<< endl <<"                              This is round 4." << endl << endl;    
	        }
	             if(k==3)
	        {
	            cout<< endl << "                              This is round 5." << endl << endl;    
	        }
	        
        	if(check==1)
        	{
            	if(i==9)
            	{
            		cout<< player1_name << ", Do you want to take the last card? Press any number only if yes: "; 
            	}
             	else
            	{
          			cout<<player1_name << ", do you want to pick a card? Press any number only if yes: ";    
            	}
           	check=2;
        	}
        	
			else
        	{ 
         	if(i==9)
            {
            	cout<<player2_name <<", Do you want to take the last card? Press any number only if yes: "; 
            }
            else
            {
          		cout<<endl <<player2_name << ", do you want to pick a card? Press any number only if yes: ";  
            }
           	check=1;  
        	}
        	
        	cin>>n;
        	
		    ran:
			int randomnumber=random_number();
			randomnumber=randomnumber-1;
    
		    if(sr[randomnumber] !=-1)
		    {
		    	//cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		    	cout << endl << endl << "The card that you get is: " << name[randomnumber]<<" "<<s2[randomnumber]<<" "<<s3[randomnumber]<<" "<<s4[randomnumber]<<" "<<s5[randomnumber]<<endl <<endl;
		          //cout<<sr[randomnumber]<<"\t\t"<<name[randomnumber]<<"\t\t"<<s2[randomnumber]<<"\t\t"<<s3[randomnumber]<<"\t\t"<<s4[randomnumber]<<"\t\t"<<s5[randomnumber]<<endl;
		        cout << "Your mark is " << type(s4[randomnumber], s3[randomnumber]) << endl;
		        cout << "Your mark is " << system(s5[randomnumber]);
		        
		        float total1 = 0, total2 = 0, marks1, marks2, largest, ptr, a, b;
				total1 = type(s4[randomnumber], s3[randomnumber])+system(s5[randomnumber]);
				total2 =type(s4[randomnumber], s3[randomnumber])+system(s5[randomnumber]);
				
				if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
					{
				    cout << endl << "Your mark for this round is " << total1;
					}
				
				if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10)
					{
				    cout << endl << "Your mark for this round is " << total2;
					}
				
				if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10)
				{
					if (total1 > total2)
					{
					cout << "player 1 wins";
					cout << endl << "Total 1: " << total1 << " while total 2: " << total2;
					}
					else
					{
					cout << endl << "player 2 wins";
					cout << endl << "Total 1: " << total1 << " while total 2: " << total2;
					}
					
				}
//				if (total1 > total2)
//				{
//					cout << "player 1 wins";
//				}
//				else
					//cout << "player 2 wins";
				
				//Winner(total1,total2,i);	
				
				sr[randomnumber] =-1;
		        
//		        cout << "\nThe winner mark is "<<largest;
		        
		        cout<<endl << endl << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
		        
		    }
		    
		    else
		    {
//		        cout << largest;
		        ofstream outputfile;
			    outputfile.open("program3data.txt");
			    for(i=1; i<10; i++)
			    {
			    	writeToFile(outputfile, name[randomnumber],s2[randomnumber],s3[randomnumber],s4[randomnumber],s5[randomnumber]);
			    	outputfile.close();
				}
			        
		    	goto ran;    
		    }
		    k=k-1;
		    }
    
		    cout<<"Do you want to play again ?";
		    cin>>on;
		    
		    if(on=="no"|| on=="NO")
		    {
		    	exit(0);   
		    }
    
    }
    
}



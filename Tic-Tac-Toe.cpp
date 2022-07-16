#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

using namespace std;
int count1,count2;
//2D ARRAY
char MATRIX[3][3]={'1','2','3','4','5','6','7','8','9'};

//START FROM X
char TURN='x';

int COLUMN,ROW;

bool DRAW=false;


//DISPLY OF SCREEN FOR GAME
void DISPLAY_MATRIX()
{
    system("cls"); // used for to cleared screen when new input given...

    cout<<"\t                                           TICK TACK GAME  \n ";
    cout<<"PLAYER_1 [X] 									Win = "<<count1<<endl;					
    cout<<" PLAYER_2 [y] 									Win = "<<count2<<endl;

    cout<<"\t                                              |       |       \n";
    cout<<"\t                                         " << MATRIX[0][0] << "    |   " << MATRIX[0][1] << "   |  " << MATRIX[0][2] << " \n";
    cout<<"\t                                         _____|_______|_____               \n";
    cout<<"\t                                              |       |       \n";
    cout<<"\t                                         " << MATRIX[1][0] << "    |   " << MATRIX[1][1] << "   |  " << MATRIX[1][2] << " \n";
    cout<<"\t                                         _____|_______|_____               \n ";
    cout<<"\t                                              |       |       \n";
    cout<<"\t                                         " << MATRIX[2][0] << "    |   " << MATRIX[2][1] << "   |  " << MATRIX[2][2] << " \n";
    cout<<"\t                                              |       |       \n";


}

// IT WILL HELP TO  CIRCULATE AROUND X AND Y
void PLAYER_TURN()
{
	int CHOSEN;
    if (TURN == 'x')
		cout<<"   player_1 [x] turn  ";
	if(TURN == 'y')
		cout<<"   player_2 [y]  turn  ";
	cin>>CHOSEN;
   if(CHOSEN>9)
   {
       PLAYER_TURN();//RECURSION...
   }


   //THE VALUE WILL DISPLAY ON GAME BOARD ACCORDING TO CHOSEN VALUE

   switch(CHOSEN)
   {
       case 1: ROW=0;COLUMN=0;
       break;

       case 2: ROW=0;COLUMN=1;
       break;

       case 3: ROW=0;COLUMN=2;
       break;

       case 4: ROW=1;COLUMN=0;
       break;

       case 5: ROW=1; COLUMN=1;
       break;

       case 6: ROW=1; COLUMN=2;
       break;

       case 7: ROW=2;COLUMN=0;
       break;

       case 8: ROW=2;COLUMN=1;
       break;

       case 9: ROW=2;COLUMN=2;
       break;
   }

//vilidating the previous entered value
   if(TURN=='x'&& MATRIX[ROW][COLUMN]!='x'&& MATRIX[ROW][COLUMN]!='y')
   {
       MATRIX[ROW][COLUMN]='x';
       TURN='y';
   }


   else if (TURN=='y'&&MATRIX[ROW][COLUMN]!='x'&&MATRIX[ROW][COLUMN]!='y')

   {
    MATRIX[ROW][COLUMN]='y';
    TURN='x';
   }
   DISPLAY_MATRIX();
}
void Comp()
{
	int CHOSEN;
	if (TURN == 'x')
	{
		cout<<"   player_1 [x] turn  ";
	    cin>>CHOSEN;
	}
	else if(TURN == 'y')
	{
		cout<<"   COMPUTER's'  turn  ";
    	int random = 1 + (rand() % 9);
		CHOSEN=random;
	}
   if(CHOSEN>9)
   {
       Comp();//RECURSION...
   }


   //THE VALUE WILL DISPLAY ON GAME BOARD ACCORDING TO CHOSEN VALUE

   switch(CHOSEN)
   {
       case 1: ROW=0;COLUMN=0;
       break;

       case 2: ROW=0;COLUMN=1;
       break;

       case 3: ROW=0;COLUMN=2;
       break;

       case 4: ROW=1;COLUMN=0;
       break;

       case 5: ROW=1; COLUMN=1;
       break;

       case 6: ROW=1; COLUMN=2;
       break;

       case 7: ROW=2;COLUMN=0;
       break;

       case 8: ROW=2;COLUMN=1;
       break;

       case 9: ROW=2;COLUMN=2;
       break;
   }

//vilidating the previous entered value
   if(TURN=='x'&& MATRIX[ROW][COLUMN]!='x'&& MATRIX[ROW][COLUMN]!='y')
   {
       MATRIX[ROW][COLUMN]='x';
       TURN='y';
   }


   else if (TURN=='y'&&MATRIX[ROW][COLUMN]!='x'&&MATRIX[ROW][COLUMN]!='y')

   {
    MATRIX[ROW][COLUMN]='y';
    TURN='x';
   }
   DISPLAY_MATRIX();
}

bool GAME_OVER()
{	
    for(int i=0;i<3;i++)

    //IT WILL CHECK DIFFERENT COMBINATION FOR WINING
        if(MATRIX[i][0]==MATRIX[i][1]&&MATRIX[i][0]==MATRIX[i][2]||MATRIX[0][i]==MATRIX[1][i]&&MATRIX[0][i]==MATRIX[2][i])
        return false;

        if(MATRIX[0][0]==MATRIX[1][1]&&MATRIX[0][0]==MATRIX[2][2]||MATRIX[0][2]==MATRIX[1][1]&&MATRIX[0][2]==MATRIX[2][0])
    return false;

//to check if match is draw
for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)

        if (MATRIX[i][j]!='x'&& MATRIX[i][j]!='y')
        return true;

    DRAW=true;
	char MATRIX[3][3]={'1','2','3','4','5','6','7','8','9'};
    return false;

}

int main()
{
//TWO PLAYERS WILL ENTER THEIR NAMES
	string PLAYER_1_NAME,PLAYER_2_NAME;
	int sw;
	char r;
	cout<<"1. Computer\n2. Vs Player2\nEnter: ";
	cin>>sw;
	switch(sw)
	{
		case 1:
			cout<<" player 1 , please enter your name ";
			cin>>PLAYER_1_NAME;
			cout<<" player 2 , Computer ";
			break;
		case 2:
			cout<<" player 1 , please enter your name ";
			cin>>PLAYER_1_NAME;
			cout<<" player 2 , please enter your name ";
			cin>>PLAYER_2_NAME;
			break;
	}
	while(GAME_OVER())
	{
		system("color B ");
		DISPLAY_MATRIX();
		if(sw == 2)
			PLAYER_TURN();
		else if(sw == 1)
			Comp();
		GAME_OVER();
		}
	 //FILE HANDLING
		if (TURN == 'x' && DRAW == false)
		{
	       cout<<" player_2[y] WINS ...  CONGRATULATIONS chal briyani la ka aa... "<<endl;
	       cout<<" NAME IS  "<<PLAYER_2_NAME<<endl;
	       fstream fs;
	       fs.open("Text.txt",ios::app);
	
			if (!fs)
			{
	           cout<<"sorry!... file couldn't open "<<endl;
			}
			else
			{
	        	fs<<PLAYER_2_NAME;
			}
			fs.close();
			count2=count2+1;
		}
		else if (TURN =='y'&&DRAW==false)
		{
	        cout<<"player_1[x] WINS...  CONGRATULATIONS chal treat khila "<<endl;
	
	        cout<<" NAME IS "<<PLAYER_1_NAME<<endl;
	        fstream fs;
	        fs.open("Text.txt",ios ::app);
	
	        if (!fs)
	        {
	            cout<<"sorry!... file couldn't open  "<<endl;
	        }
	        else
	        {
	            fs<<PLAYER_1_NAME;                                                                                                                     
	        }
	        fs.close();
	        count1=count1+1;
	    }
		else
	    {
		    cout<<" fortunately... Game is DRAWN...!!!  "<<endl;
	        cout<<" ja briyani la ka aa tara kam nhai ha ..."<<endl;
		}

	return 0;
}

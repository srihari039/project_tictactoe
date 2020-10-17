//author : Sri Hari
//complete tictactoe in cpp
//contains dualuser mode and play with computer mode!
//playing with computer has two modes - easy and hard

#include <iostream>
#include <cstdbool>
#include <cmath>
#include <ctime>
using namespace std;

class board
{
	public:
	char grid[3][3];
	board()
	{
		for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++)	
		grid[i][j] = 'z';	
	}
	void showboard()
	{
		cout<<" - - -"<<endl;
		for(int i = 1 ; i < 10 ; i++)
		{
			if(i % 3 == 1)
			cout<<"|";

			cout<<i<<" ";

			if(i % 3 == 0)
			cout<<"|"<<endl;
		}
		cout<<" - - -"<<endl;

	}
	int update(int row,int column,char s)
	{	
		if(row <= 3 and column <= 3 and row >= 1 and column >= 1)
		{
			if(grid[row-1][column-1] == 'z')
			{
				grid[row-1][column-1] = s;
				return 1;
			}
			return 0;
		}
		return 0;
	}
	int updatehelper(int pos, char s)
	{
		if(pos == 1)
		return update(1,1,s);
		else if(pos == 2)
		return update(1,2,s);
		else if(pos == 3)
		return update(1,3,s);
		else if(pos == 4)
		return update(2,1,s);
		else if(pos == 5)
		return update(2,2,s);
		else if(pos == 6)
		return update(2,3,s);
		else if(pos == 7)
		return update(3,1,s);
		else if(pos == 8)
		return update(3,2,s);
		else if(pos == 9)
		return update(3,3,s);
		else return 0;
		
	}
	bool winstatus()
	{
		if(grid[0][0] == grid[0][1] and grid[0][1] == grid[0][2] and grid[0][2] != 'z')
		return true;
		if(grid[1][0] == grid[1][1] and grid[1][1] == grid[1][2] and grid[1][2] != 'z')
		return true;
		if(grid[2][0] == grid[2][1] and grid[2][1] == grid[2][2] and grid[2][2] != 'z')
		return true;

		if(grid[0][0] == grid[1][0] and grid[1][0] == grid[2][0] and grid[2][0] != 'z')
		return true;
		if(grid[0][1] == grid[1][1] and grid[1][1] == grid[2][1] and grid[2][1] != 'z')
		return true;
		if(grid[0][2] == grid[1][2] and grid[1][2] == grid[2][2] and grid[2][2] != 'z')
		return true;

		if(grid[0][0] == grid[1][1] and grid[1][1] == grid[2][2] and grid[2][2] != 'z')
		return true;
		if(grid[0][2] == grid[1][1] and grid[1][1] == grid[2][0] and grid[2][0] != 'z')
		return true;

		return false;
	}
	void print()
	{
		cout<<" - - -"<<endl;
		for(int i = 0 ; i < 3 ; i++)
		{
			cout<<"|";
			for(int j = 0 ; j < 3 ; j++)
			{
				if(grid[i][j] != 'z')
				cout<<grid[i][j]<<" ";
				else
				cout<<"_ ";
				if(j == 2)
				cout<<"|";
			}
			cout<<endl;
		}
		cout<<" - - -"<<endl;
	}
	void clear()
	{
		for(int i = 0 ; i < 3 ; i++)
		for(int j = 0 ; j < 3 ; j++)	
		grid[i][j] = 'z';	
	}
};

class hardmode : public board
{
	public:

	bool ifitiscornerhelper(int i,int j)
	{
		if(i == 1 and j == 1 or i == 3 and j == 3)
		return true;
		else if(i == 1 and j == 3 or i == 3 and j == 1)
		return true;
		else return false;
	}
	bool ifitiscorner(int pos)
	{
		if(pos == 1)
		return ifitiscornerhelper(1,1);
		else if(pos == 2)
		return ifitiscornerhelper(1,2);
		else if(pos == 3)
		return ifitiscornerhelper(1,3);
		else if(pos == 4)
		return ifitiscornerhelper(2,1);
		else if(pos == 5)
		return ifitiscornerhelper(2,2);
		else if(pos == 6)
		return ifitiscornerhelper(2,3);
		else if(pos == 7)
		return ifitiscornerhelper(3,1);
		else if(pos == 8)
		return ifitiscornerhelper(3,2);
		else
		return ifitiscornerhelper(3,3);		
	}
	bool ifitiscomplimentarycorner()
	{
		if(grid[0][0] == grid[2][2] and grid[0][0] != 'z' or grid[0][2] == grid[2][0] and grid[0][2] != 'z')
		return true;
		return false;
	}
	int ifcomputercanblock()
	{
		if(grid[0][0] == grid[2][2] and grid[2][2] == 'x' and grid[1][1] == 'z')
		return 5;
		else if(grid[0][0] == grid[1][1] and grid[1][1] == 'x' and grid[2][2] == 'z')
		return 9;
		else if(grid[1][1] == grid[2][2] and grid[2][2] == 'x' and grid[0][0] == 'z')
		return 1;	

		else if(grid[2][0] == grid[0][2] and grid[0][2] == 'x' and grid[1][1] == 'z')
		return 5;
		else if(grid[2][0] == grid[1][1] and grid[1][1] == 'x' and grid[0][2] == 'z')
		return 3;
		else if(grid[1][1] == grid[0][2] and grid[0][2] == 'x' and grid[2][0] == 'z')
		return 7;	

		else if(grid[0][0] == grid[0][1] and grid[0][1] == 'x' and grid[0][2] == 'z')
		return 3;
		else if(grid[0][0] == grid[0][2] and grid[0][2] == 'x' and grid[0][1] == 'z')
		return 2;
		else if(grid[0][1] == grid[0][2] and grid[0][2] == 'x' and grid[0][0] == 'z')
		return 1;

		else if(grid[1][0] == grid[1][1] and grid[1][1] == 'x' and grid[1][2] == 'z')
		return 6;
		else if(grid[1][0] == grid[1][2] and grid[1][2] == 'x' and grid[1][1] == 'z')
		return 5;
		else if(grid[1][1] == grid[1][2] and grid[1][2] == 'x' and grid[1][0] == 'z')
		return 4;

		else if(grid[2][0] == grid[2][2] and grid[2][2] == 'x' and grid[2][1] == 'z')
		return 8;
		else if(grid[2][0] == grid[2][1] and grid[2][1] == 'x' and grid[2][2] == 'z')
		return 9;
		else if(grid[2][1] == grid[2][2] and grid[2][2] == 'x' and grid[2][0] == 'z')
		return 7;

		else if(grid[0][0] == grid[1][0] and grid[1][0] == 'x' and grid[2][0] == 'z')
		return 7;
		else if(grid[0][0] == grid[2][0] and grid[2][0] == 'x' and grid[1][0] == 'z')
		return 4;
		else if(grid[1][0] == grid[2][0] and grid[2][0] == 'x' and grid[0][0] == 'z')
		return 1;

		else if(grid[0][1] == grid[1][1] and grid[1][1] == 'x' and grid[2][1] == 'z')
		return 8;
		else if(grid[2][1] == grid[0][1] and grid[0][1] == 'x' and grid[1][1] == 'z')
		return 5;
		else if(grid[1][1] == grid[2][1] and grid[2][1] == 'x' and grid[0][1] == 'z')
		return 2;

		else if(grid[0][2] == grid[1][2] and grid[0][2] == 'x' and grid[2][2] == 'z')
		return 9;
		else if(grid[0][2] == grid[2][2] and grid[2][2] == 'x' and grid[1][2] == 'z')
		return 6;
		else if(grid[2][2] == grid[1][2] and grid[1][2] == 'x' and grid[0][2] == 'z')
		return 3;

		else
		return 0;

	}
	int ifcomputercanwin()
	{
		if(grid[0][0] == grid[2][2] and grid[2][2] == 'o' and grid[1][1] == 'z')
		return 5;
		else if(grid[0][0] == grid[1][1] and grid[1][1] == 'o' and grid[2][2] == 'z')
		return 9;
		else if(grid[1][1] == grid[2][2] and grid[2][2] == 'o' and grid[0][0] == 'z')
		return 1;	

		else if(grid[2][0] == grid[0][2] and grid[0][2] == 'o' and grid[1][1] == 'z')
		return 5;
		else if(grid[2][0] == grid[1][1] and grid[1][1] == 'o' and grid[0][2] == 'z')
		return 3;
		else if(grid[1][1] == grid[0][2] and grid[0][2] == 'o' and grid[2][0] == 'z')
		return 7;	

		else if(grid[0][0] == grid[0][1] and grid[0][1] == 'o' and grid[0][2] == 'z')
		return 3;
		else if(grid[0][0] == grid[0][2] and grid[0][2] == 'o' and grid[0][1] == 'z')
		return 2;
		else if(grid[0][1] == grid[0][2] and grid[0][2] == 'o' and grid[0][0] == 'z')
		return 1;

		else if(grid[1][0] == grid[1][1] and grid[1][1] == 'o' and grid[1][2] == 'z')
		return 6;
		else if(grid[1][0] == grid[1][2] and grid[1][2] == 'o' and grid[1][1] == 'z')
		return 5;
		else if(grid[1][1] == grid[1][2] and grid[1][2] == 'o' and grid[1][0] == 'z')
		return 4;

		else if(grid[2][0] == grid[2][2] and grid[2][2] == 'o' and grid[2][1] == 'z')
		return 8;
		else if(grid[2][0] == grid[2][1] and grid[2][1] == 'o' and grid[2][2] == 'z')
		return 9;
		else if(grid[2][1] == grid[2][2] and grid[2][2] == 'o' and grid[2][0] == 'z')
		return 7;

		else if(grid[0][0] == grid[1][0] and grid[1][0] == 'o' and grid[2][0] == 'z')
		return 7;
		else if(grid[0][0] == grid[2][0] and grid[2][0] == 'o' and grid[1][0] == 'z')
		return 4;
		else if(grid[1][0] == grid[2][0] and grid[2][0] == 'o' and grid[0][0] == 'z')
		return 1;

		else if(grid[0][1] == grid[1][1] and grid[1][1] == 'o' and grid[2][1] == 'z')
		return 8;
		else if(grid[2][1] == grid[0][1] and grid[0][1] == 'o' and grid[1][1] == 'z')
		return 5;
		else if(grid[1][1] == grid[2][1] and grid[2][1] == 'o' and grid[0][1] == 'z')
		return 2;

		else if(grid[0][2] == grid[1][2] and grid[0][2] == 'o' and grid[2][2] == 'z')
		return 9;
		else if(grid[0][2] == grid[2][2] and grid[2][2] == 'o' and grid[1][2] == 'z')
		return 6;
		else if(grid[2][2] == grid[1][2] and grid[1][2] == 'o' and grid[0][2] == 'z')
		return 3;

		else
		return 0;

	}
	int ifsideisempty()
	{
		srand(time(NULL));
		int random = 1 + rand()%8;
		if(random % 2 == 1)
		ifsideisempty();
		return random;
	}
	int getacorner()
	{
		srand(time(NULL));
		int random = 1 + rand()%4;
		if(random == 1)
		return 1;
		else if(random == 2)
		return 3;
		else if(random == 3)
		return 7;
		else if(random == 4)
		return 9;
		else
		return getacorner();			
	}
};
class user
{
	public:
	string name;
	char symbol;
	int userscore;
	user()
	{
		userscore = 0;
	}
	void injectname(string s)
	{
		this->name = s;
	}
	void injectsymbol(char s)
	{
		this->symbol = s;
	}
	char getsymbol()
	{
		return this->symbol;
	}
	string getname()
	{
		return this->name;
	}
	void declarewinner()
	{
		this->userscore++;
		cout<<this->name<<" won the game!"<<endl;
		cout<<this->name<<"'s score :"<<this->userscore<<"points"<<endl;
		return;
	}

};
char getcompliment(char symbol)
{
	if(symbol == 'x')
	return 'o';
	else if(symbol == 'X')
	return 'O';
	else if(symbol == 'o')
	return 'x';
	else if(symbol == 'O')
	return 'X';
	else return ' ';
}

void playwithcomputer()
{
	board b;
	b.showboard();
	user member,computer;
	string s;char usersymbol;
	cout<<"Enter your name:";
	cin>>s;
	member.injectname(s);
	computer.injectname("computer");
	char toughness;
	invalid_exception:
	cout<<"easy(e)/hard(h):";
	cin>>toughness;
	if(toughness == 'e' or toughness == 'E')
	{
		cout<<"Enter character you want(x/o):";
		cin>>usersymbol;
		member.injectsymbol(usersymbol);
		computer.injectsymbol(getcompliment(member.getsymbol()));
		while(1)
		{
			int readystatus;
			cout<<"ready(1)quit(0)?";
			cin>>readystatus;
			if(readystatus)
			{
				for(int iterator = 0 ; iterator != 9 ; iterator++)
				{
					if(iterator%2 == 0)
					{
						int position;
						cout<<"you need to enter position in grid:";
						cin>>position;
						int valid = b.updatehelper(position,member.getsymbol());
						if(valid)
						{
							cout<<"after "<<member.getname()<<"'s turn:"<<endl;
							b.print();
							bool winstatus = b.winstatus();
							if(winstatus)
							{
								member.declarewinner();
								b.clear();
								break;
							}
							else
							continue;
						}
						else
						{
							cout<<"Already the position is filled or invalid position"<<endl;
							iterator = iterator - 1;
						}	
					}
					else
					{
						srand(time(NULL));
						int randomx = 1 + rand()%3;
						int randomy = 1 + rand()%3;
						int valid = b.update(randomx,randomy,computer.getsymbol());
						if(valid)
						{
							cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
							b.print();
							bool winstatus = b.winstatus();
							if(winstatus)
							{
								computer.declarewinner();
								b.clear();
								break;
							}
							else
							continue;
						}
						else
						{
							iterator = iterator - 1; 
						}
					}
				}
				b.clear();
			}
			else
			{
				cout<<"take your time to prepare for the game..!"<<endl;
				return;
			}

		}
	}
	else if(toughness == 'h' or toughness == 'H')
	{
		usersymbol = 'x';
		member.injectsymbol(usersymbol);
		computer.injectsymbol(getcompliment(member.getsymbol()));	
		while(1)
		{
			int readystatus,i;
			bool checkifitsmiddle;
			cout<<"ready(1)quit(0)?";
			cin>>readystatus;
			if(readystatus)
			{
				hardmode board;
				int position,valid;
				bool checkifitiscorner,checkcomplimentarycorner;
				for(i = 0 ; i < 9 ; i++)
				{
					if(i % 2 == 0)
					{
						cout<<"you need to enter the position:";
						cin>>position;
						if(position == 5)
						checkifitsmiddle = true;
						int valid = board.updatehelper(position,member.getsymbol());
						if(valid)
						{
							cout<<"after "<<member.getname()<<"'s turn:"<<endl;
							board.print();
							if(i == 0)
							checkifitiscorner = board.ifitiscorner(position);
							if(i == 2)
							checkifitiscorner = board.ifitiscorner(position);

							bool winstatus = board.winstatus();
							if(winstatus)
							{
								member.declarewinner();
								board.clear();
								break;
							}						
						}
						else
						{
							cout<<"Already the position is filled or invalid position"<<endl;
							i = i - 1;
						}
					}
					else
					{
						if(i == 1 and checkifitiscorner)
						{
							int valid = board.update(2,2,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();	
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}	
								continue;						
							}

						}
						if(i == 1 and checkifitsmiddle)
						{
							position = board.getacorner();
							cout<<position;
							int valid = board.updatehelper(position,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();	
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}	
								continue;						
							}							
						}
						if(i == 3)
						{
							position = board.ifcomputercanblock();
							valid = board.updatehelper(position,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();	
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}
								else
								continue;									
							}		
							else if(board.ifitiscomplimentarycorner())
							{
								if(board.ifsideisempty())
								{
									position = board.ifsideisempty();
									valid = board.updatehelper(position,computer.getsymbol());
									if(valid)
									{
										cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
										board.print();	
										bool winstatus = board.winstatus();
										if(winstatus)
										{
											computer.declarewinner();
											board.clear();
											break;
										}
										else
										continue;										
									}
								}
							}			
						}
						if(board.ifcomputercanwin())
						{
							position = board.ifcomputercanwin();
							valid = board.updatehelper(position,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();	
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}	
								continue;							
							} 
						}
						else if(board.ifcomputercanblock())
						{
							position = board.ifcomputercanblock();
							valid = board.updatehelper(position,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();	
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}	
								continue;							
							} 							
						}
						else
						{
							repeat:
							srand(time(NULL));
							int randomx = 1 + rand()%3;
							int randomy = 1 + rand()%3;
							int valid = board.update(randomx,randomy,computer.getsymbol());
							if(valid)
							{
								cout<<"after "<<computer.getname()<<"'s turn:"<<endl;
								board.print();
								bool winstatus = board.winstatus();
								if(winstatus)
								{
									computer.declarewinner();
									board.clear();
									break;
								}
								else
								continue;
							}
							else
							{
								goto repeat;
							}
							
						}
					}
					
				}
				if(i == 9)
				cout<<"match tied!"<<endl;
			}
			else
			{
				cout<<"take your time to prepare for the game..!"<<endl;
				return;
			}
		}	
	}
	else
	{
		cout<<"Looking like you entered invalid character!"<<endl;
		goto invalid_exception;
	}
	
}

void playwithdualuser()
{
	board b;
	b.showboard();
	user member1,member2;
	string s1,s2;char usersymbol;
	cout<<"Enter player1 name:";
	cin>>s1;
	cout<<"Enter player2 name:";
	cin>>s2;
	member1.injectname(s1);
	member2.injectname(s2);
	cout<<"player1 enter character you want to play with(x/o):";
	cin>>usersymbol;
	member1.injectsymbol(usersymbol);
	member2.injectsymbol(getcompliment(member1.getsymbol()));
	while(1)
	{
		int readystatus;
		cout<<"ready(1)quit(0)?";
		cin>>readystatus;
		if(readystatus)
		{
			for(int iterator = 0; iterator != 9 ; iterator++)
			{
				int i,j,position;
				if(iterator%2 == 0)
				{
					cout<<"player1-you need to enter position in grid:";

					cin>>position;
					int valid = b.updatehelper(position,member1.getsymbol());
					if(valid)
					{
						cout<<"after "<<member1.getname()<<"'s turn:"<<endl;
						b.print();
						bool winstatus = b.winstatus();
						if(winstatus)
						{
							member1.declarewinner();
							break;
						}
						else
						continue;
					}
					else
					{
						cout<<"Already the position is filled or invalid position"<<endl;
						iterator = iterator - 1;
					}	
				}
				else
				{
					cout<<"player2-you need to enter position in grid:";

					cin>>position;
					int valid = b.updatehelper(position,member2.getsymbol());
					if(valid)
					{
						cout<<"after "<<member2.getname()<<"'s turn:"<<endl;
						b.print();
						bool winstatus = b.winstatus();
						if(winstatus)
						{
							member2.declarewinner();
							break;
						}
						else
						continue;	
					}
					else
					{
						cout<<"Already the position is filled or invalid position"<<endl;
						iterator = iterator - 1;
					}			
				}
		
			}
			cout<<"match tied!"<<endl;
			b.clear();
		}
	}	

}


int main()
{
	cout<<"Welcome to the game TIC-TAC-TOE"<<endl;
	while(1)
	{
		bool will;
		cout<<"Do you want to play(1/0):";
		cin>>will;
		if(will)
		{
			int playerstat;
			cout<<"Do you want to play with computer(1) or Dual-user(2):";
			cin>>playerstat;
			if(playerstat == 1)
			{
				playwithcomputer();
			}
			if(playerstat == 2)
			{
				playwithdualuser();
			}
		}
		else
		{
			cout<<"Thanks for making out!, Have a great day."<<endl;
			return 0;
		}
	}	
}


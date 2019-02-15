#include <iostream>
#include <windows.h>
#include <fstream>
#include<conio.h>
using namespace std;

const int ROWS = 8;
const int COLS = 8;

const char player_1	= 'X';
const char player_2 = 'O';


/****************************************************************************/

void DisplayBoard(const char board[][COLS])
{
	cout << "\t ";
	for (int c = 0; c < COLS; c++)
		cout <<"  "<< c;
	    cout << endl;
        cout<<"\t +--+--+--+--+--+--+--+--+\n";
    //====================================================
    fstream fr;
    fr.open("game.txt",ios::in|ios::out|ios::app);
    fr << "\t";
    for (int c=0; c < COLS; c++)
        fr <<"  "<< c;
	    fr << endl;
        fr<<"\t +--+--+--+--+--+--+--+--+\n";
    for (int r = 0; r < ROWS; r++)
	{
		fr <<"\t"<< r ;
		for (int c = 0; c < COLS; c++)
			fr <<"| "<< board[r][c];
			fr<<"|";
		fr << endl;
        fr<<"\t +--+--+--+--+--+--+--+--+\n";
	}
    //====================================================
    fstream fs;
    fs.open("save.txt",ios::in|ios::out|ios::app);
    fs << "\t";
    for (int c=0; c < COLS; c++)
        fs <<"  "<< c;
	    fs << endl;
        fs <<"\t +--+--+--+--+--+--+--+--+\n";
    for (int r = 0; r < ROWS; r++)
	{
		fs <<"\t"<< r ;
		for (int c = 0; c < COLS; c++)
			fs <<"| "<< board[r][c];
			fs <<"|";
		fs << endl;
        fs <<"\t +--+--+--+--+--+--+--+--+\n";
	}
    //====================================================

	for (int r = 0; r < ROWS; r++)
	{
		cout <<"\t"<< r ;
		for (int c = 0; c < COLS; c++)
			cout <<"| "<< board[r][c];
			cout<<"|";
		cout << endl;
        cout<<"\t +--+--+--+--+--+--+--+--+\n";
	}

}

/****************************************************************************/

int PlaceDisc(char board[][COLS], int row, int col, char disc)
{
	int num_changed = 0;

	if (board[row][col] != ' ')
		return 0;

	board[row][col] = disc;

	char envious_disc;
	if (disc == player_1)
		envious_disc = player_2;
	else
		envious_disc = player_1;

	int disc_pos = -1;
	for (int c = col + 1; c < COLS && board[row][c] != ' ' && disc_pos == -1; c++)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	if (disc_pos != -1 && disc_pos > col + 1)
	{
		for (int c = col + 1; c < disc_pos; c++)
		{
			board[row][c] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int c = col - 1; c >= 0 && board[row][c] != ' ' && disc_pos == -1; c--)
	{
		if (board[row][c] == disc)
			disc_pos = c;
	}

	if (disc_pos != -1 && disc_pos < col - 1)
	{
		for (int c = col - 1; c > disc_pos; c--)
		{
			board[row][c] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int r = row - 1; r >= 0 && board[r][col] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][col] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	for (int r = row + 1; r < ROWS && board[r][col] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][col] == disc)
			disc_pos = r;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][col] = disc;
			num_changed++;
		}
	}

	disc_pos = -1;
	int c = col - 1;
	for (int r = row - 1; c >= 0 && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col - 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_changed++;
			c--;
		}
	}

	disc_pos = -1;
	c = col + 1;
	for (int r = row - 1; c < COLS && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	if (disc_pos != -1 && disc_pos < row - 1)
	{
		c = col + 1;
		for (int r = row - 1; r > disc_pos; r--)
		{
			board[r][c] = disc;
			num_changed++;
			c++;
		}
	}

	disc_pos = -1;
	c = col - 1;
	for (int r = row + 1; c >= 0 && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c--;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col - 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_changed++;
			c--;
		}
	}

	disc_pos = -1;
	c = col + 1;
	for (int r = row + 1; c < COLS && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++)
	{
		if (board[r][c] == disc)
			disc_pos = r;
		c++;
	}

	if (disc_pos != -1 && disc_pos > row + 1)
	{
		c = col + 1;
		for (int r = row + 1; r < disc_pos; r++)
		{
			board[r][c] = disc;
			num_changed++;
			c++;
		}
	}

	if (num_changed == 0)
		board[row][col] = ' ';

	return num_changed;
}

/****************************************************************************/

int MoveIsPossible(const char board[][COLS], char player)
{
	return 1;
}

/****************************************************************************/
/****************************************************************************/

class GAME{
public:
    int row,col,discs_changed;
    bool invalid_move;

/****************************************************************************/

public:
    void Player_1_Move(char board[][COLS])
    {
        fstream fr;
        fr.open("game.txt",ios::in|ios::out|ios::app);

        if (MoveIsPossible(board, player_1))
            {
		do
		{
			invalid_move = false;

			cout << "Enter Row : ";
			fr << "Enter Row : ";
			cin >> row ;
			fr << row <<endl;
			while (row < 0 || row >= ROWS)
			{
				cout << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				fr << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				cout << "Enter Row : ";
				fr << "Enter Row : ";
				cin >> row;
				fr << row <<endl;
			}

			cout << "Enter Collum : ";
			fr << "Enter Collum : ";
			cin >> col;
			fr<< col <<endl;
			while (col < 0 || col >= COLS)
			{
				cout << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				fr << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				cout << "Enter Collum : ";
				fr << "Enter Collum : ";
				cin >> col;
				fr<< col <<endl;
			}

			if (board[row][col] != ' ')
			{
				cout << "Please enter an empty row and column.\n";
				fr << "Please enter an empty row and column.\n";
				invalid_move = 1;
			}
			else
			{
				discs_changed = PlaceDisc(board, row, col, player_1);
				if (discs_changed == 0)
				{
					cout << "Invalid move.\n";
                    fr << "Invalid move.\n";
					invalid_move = true;
				}
				else
					cout << "===Changed " << discs_changed << " disc.===\n\n";
					fr << "===Changed " << discs_changed << " disc.===\n\n";
            }
		} while (invalid_move);
	}
	else
	{
		cout << "X cannot move.\n";
		fr << "X cannot move.\n";
	}
}

/****************************************************************************/

void SaveBoard(char board[][COLS], char temp_board[][COLS])
{

	for( int i = 0; i < ROWS; i++)
	{
		for(int j =0; j < COLS; j++)
			temp_board[i][j]= board[i][j];
	}
}

/****************************************************************************/

void Player_2_Move(char board[][COLS])
{
        fstream fr;
        fr.open("game.txt",ios::in|ios::out|ios::app);

        if (MoveIsPossible(board, player_2))
            {
		do
		{
			invalid_move = false;

			cout << "Enter Row : ";
			fr << "Enter Row : ";
			cin >> row ;
			fr << row <<endl;
			while (row < 0 || row >= ROWS)
			{
				cout << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				fr << "Please enter a row between 0 and " << (ROWS - 1) << ".\n";
				cout << "Enter Row : ";
				fr << "Enter Row : ";
				cin >> row;
				fr << row <<endl;
			}

			cout << "Enter Collum : ";
			fr << "Enter Collum : ";
			cin >> col;
			fr<< col <<endl;
			while (col < 0 || col >= COLS)
			{
				cout << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
                fr << "Please enter a column between 0 and " << (COLS - 1) << ".\n";
				cout << "Enter Collum : ";
				fr << "Enter Collum : ";
				cin >> col;
				fr<< col <<endl;
			}

			if (board[row][col] != ' ')
			{
				cout << "Please enter an empty row and column.\n";
				fr << "Please enter an empty row and column.\n";
				invalid_move = 1;
			}
			else
			{
				discs_changed = PlaceDisc(board, row, col, player_2);
				if (discs_changed == 0)
				{
					cout << "Invalid move.\n";
                    fr << "Invalid move.\n";
					invalid_move = true;
				}
				else
					cout << "===Changed " << discs_changed << " disc.===\n\n";
					fr << "===Changed " << discs_changed << " disc.===\n\n";
            }
		} while (invalid_move);
	}
	else
	{
		cout << "O cannot move.\n";
		fr << "O cannot move.\n";
	}
}

/****************************************************************************/

void new_game()
{
    fstream fr,fs;
    fr.open("game.txt",ios::in|ios::out|ios::app);
    fs.open("save.txt",ios::in|ios::out|ios::app);
    int x=2,o=2;
	char board[ROWS][COLS];
	cout <<"\n\n\t     *** NEW GAME ***"<<endl<<endl;
	fr <<"\n\n\t     *** NEW GAME ***"<<endl<<endl;
	fs <<"\n\n\t     *** NEW GAME ***"<<endl<<endl;
	strncpy(board[0],"        ", COLS);
	strncpy(board[1],"        ", COLS);
	strncpy(board[2],"        ", COLS);
	strncpy(board[3],"   OX   ", COLS);
	strncpy(board[4],"   XO   ", COLS);
	strncpy(board[5],"        ", COLS);
	strncpy(board[6],"        ", COLS);
	strncpy(board[7],"        ", COLS);

	DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout << endl;
	fr <<endl<<"========================================"<<endl;
	fr << endl;
	fs <<endl<<"========================================"<<endl;
	fs << endl;
    char ch;
	for(int i=1;i<=68;i++){

    cout<<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    fr <<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    fs <<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;

    if((i%2)!=0){
    cout << "Current Player:  X\n"<<endl;
    fr << "Current Player:  X\n"<<endl;
    fs << endl;
    fs <<"========================================"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if(ch=='a'){
        char ch;
        cout << "Did you use this power before...? yes = 'y' or no = 'n' " << endl;
        cin >> ch;
        if (ch == 'y')
        {
            cout << "Sorry,you can not use this power."<<endl;
            Player_1_Move(board);
            x+=discs_changed+1;
            o-=discs_changed;
        }
        else if (ch=='n'){
        if((x>=2)&&(o>=2)){}
        else{
        cout <<"Sorry You can't proceed to next player"<<endl<<endl;
        fr <<"Sorry You can't proceed to next player"<<endl<<endl;
	    Player_1_Move(board);
        x+=discs_changed+1;
        o-=discs_changed;}}
    }
    else if (ch=='b'){
        int r,c;
        char ch;
        cout << "Did you use this power before...? yes = 'y' or no = 'n' " << endl;
        cin >> ch;
        if (ch == 'y')
        {
            cout << "Sorry,you can not use this power."<<endl;
            Player_1_Move(board);
            x+=discs_changed+1;
            o-=discs_changed;
        }
        else if (ch == 'n'){
        cout << "Enter row : ";
        cin >> r;
        cout << "Enter collum :";
        cin >> c;
        board[r][c]='X';
        x+=1;
        o-=1;}
    }
    else{

	Player_1_Move(board);

    x+=discs_changed+1;
    o-=discs_changed;}
    }

	else if((i%2)==0){
    cout << "Current Player:  O\n"<<endl;
    fr << "Current Player:  O\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if(ch=='a'){
        char ch;
        cout << "Did you use this power before...? yes = 'y' or no = 'n' " << endl;
        cin >> ch;
        if (ch == 'y')
        {
            cout << "Sorry,you can not use this power."<<endl;
            Player_1_Move(board);
            x+=discs_changed+1;
            o-=discs_changed;
        }
        else if (ch=='n'){
         if((x>=2)&&(o>=2)){}
         else{
         cout <<"Sorry You can't proceed to next player"<<endl<<endl;
         fr <<"Sorry You can't proceed to next player"<<endl<<endl;
         Player_2_Move(board);
         x-=discs_changed;
         o+=discs_changed+1;}}
    }
    else if (ch=='b'){
        int r,c;
        char ch;
        cout << "Did you use this power before...? yes = 'y' or no = 'n' " << endl;
        cin >> ch;
        if (ch == 'y')
        {
            cout << "Sorry,you can not use this power."<<endl;
            Player_1_Move(board);
            x+=discs_changed+1;
            o-=discs_changed;
        }
        else if (ch == 'n'){
        cout << "Enter row : ";
        cin >> r;
        cout << "Enter collum :";
        cin >> c;
        board[r][c]='O';
        x-=1;
        o+=1;}
    }
    else{

    Player_2_Move(board);

    x-=discs_changed;
    o+=discs_changed+1;}
    }
    DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout<<endl;
    fr <<endl<<"========================================"<<endl;
	fr <<endl;
	fs <<endl<<"========================================"<<endl;
	fs <<endl;
	}
	if(x>o){
        cout<<"\n\t*** PLAYER 1 WIN ***\n";
        fr <<"\n\t*** PLAYER 1 WIN ***\n";}
    else if(x<o){
        cout<<"\n\t*** PLAYER 2 WIN ***\n";
        fr <<"\n\t*** PLAYER 2 WIN ***\n";}
    else{
        cout<<"\n\t*** GAME DRAWN ***\n";
        fr <<"\n\t*** GAME DRAWN ***\n";}
}

/****************************************************************************/
void new_game(int a,int b)
{
    fstream fr;
    int x=a,o=b;
    fr.open("game.txt",ios::in|ios::out|ios::app);
	char board[ROWS][COLS];
	load_game();
    char ch;
	for(int i=1;i<=64;i++){
    cout<<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    fr <<"SCORE:\t O = "<<o<<",  X = "<<x<<endl;
    DisplayBoard(board);
    if((i%2)!=0){
    cout << "Current Player:  X\n"<<endl;
    fr << "Current Player:  X\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if((ch=='a')||(ch=='b')){
        if((x>=2)&&(o>=2)){}
        else{
        cout <<"Sorry You can't proceed to next player"<<endl<<endl;
        fr <<"Sorry You can't proceed to next player"<<endl<<endl;
	    Player_1_Move(board);
        x+=discs_changed+1;
        o-=discs_changed;}
    }
    else{

	Player_1_Move(board);

    x+=discs_changed+1;
    o-=discs_changed;}
    }

	else if((i%2)==0){
    cout << "Current Player:  O\n"<<endl;
    fr << "Current Player:  O\n"<<endl;

    cout << "Super power 1 = a"<<endl;
    cout << "super power 2 = b"<<endl;
    cout << "Any Key for Game Continue..."<<endl;
    cin >> ch;

    fr << "Super power 1 = a"<<endl;
    fr << "super power 2 = b"<<endl;
    fr << "Any Key for Game Continue..."<<endl;
    fr << ch <<endl;

    if((ch=='a')||(ch=='b')){
         if((x>=2)&&(o>=2)){}
         else{
         cout <<"Sorry You can't proceed to next player"<<endl<<endl;
         fr <<"Sorry You can't proceed to next player"<<endl<<endl;
         Player_2_Move(board);
         x-=discs_changed;
         o+=discs_changed+1;}
    }
    else{

    Player_2_Move(board);

    x-=discs_changed;
    o+=discs_changed+1;}
    }
    DisplayBoard(board);
    cout<<endl<<"========================================"<<endl;
	cout<<endl;
    fr <<endl<<"========================================"<<endl;
	fr <<endl;
	}
	if(x>o){
        cout<<"\n\t*** PLAYER 1 WIN ***\n";
        fr <<"\n\t*** PLAYER 1 WIN ***\n";}
    else if(x<o){
        cout<<"\n\t*** PLAYER 2 WIN ***\n";
        fr <<"\n\t*** PLAYER 2 WIN ***\n";}
    else{
        cout<<"\n\t*** GAME DRAWN ***\n";
        fr <<"\n\t*** GAME DRAWN ***\n";}
}
/****************************************************************************/

void load_game()
{
    char board[ROWS][COLS];
    char ch;
    ifstream fs("game.txt",ios::in);

    ch=fs.get();
    while(fs)
    {
        cout << ch;
        ch=fs.get();
    }

    fs.close();
    getch();
}
//void play_game()
};

/****************************************************************************/

void help()
{
    char word;
	ifstream iFile("help.txt");
	word = iFile.get();
	while(iFile)
	{

		cout << word;
		word = iFile.get();
	}
	iFile.close();

	getch();
}

/****************************************************************************/

int main()
{
    GAME G;
    char ch;
    do{
    cout<<"\n\t1. NEW GAME";
    cout<<"\n\t2. LOAD A GAME";
    cout<<"\n\t3. HELP";
    cout<<"\n\t4. QUIT\n";
    ch=getche();
    switch(ch)
    {
        case '1': G.new_game();
                  break;
        case '2': G.load_game();
                  break;
        case '3': help();
                  main();
        case '4': break;
        default : main();
    }
    }while(ch!='4');
    }

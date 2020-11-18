#include <curses.h>
#include <string>

#define PLAYER '@'
#define WALL 'W'
#define OPPONENT 'O'
#define E_TRACE ' '

using namespace std;

// struct Player;
int is_move_okay(int,int);
// 
// 
struct Player
{
    static const int shape_size_row = 2,shape_size_col = 2;
    void appear(const int & move_row,const int & move_col)
    {
        mvaddstr(move_row,move_col,"@@");
        mvaddstr(move_row+this->shape_size_row-1,move_col,"||");
    }
};

void settingGameMap()
{
    WINDOW * w;
    w = initscr();//term 변수 통해 단말기 종류 결정
    curs_set(0);
    // start main
    keypad(stdscr,TRUE);
    timeout(30);
    int row = LINES-1,col = COLS-COLS,move_row = 0,move_col=0;
    for (int i = 0; i < LINES; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i==0||i==LINES-1)
            {
                mvaddch(i,j,'*');   
            }
            else  if (i%2==0&&(j==0||j==COLS-1))
            {
                mvaddch(i,j,'*');   
            }
        }
    }
    int ch = 'y';
    while ((ch!='q')&&(ch='Q'))
    {
        mvaddch(row/2,COLS/2,PLAYER);
        ch = getch();
        switch (ch)
        {
            // case 'w':       
            case KEY_UP:    
                if(is_move_okay(row-1,col)) row -= 1; break;
            case KEY_DOWN:  
                if(is_move_okay(row+1,col)) row += 1; break;
            case KEY_LEFT:  
                if(is_move_okay(row,col-1)) col -= 1; break;
            case KEY_RIGHT: 
                if(is_move_okay(row,col+1)) col += 1; break;
                // mvaddch(row,col-1,E_TRACE);
        }
    }
    endwin();//모든 자원 반납
}
// 
int is_move_okay(int row,int col)
{
    int campare_ch = mvinch(row,col);
    return !(campare_ch==OPPONENT||campare_ch==WALL);
}

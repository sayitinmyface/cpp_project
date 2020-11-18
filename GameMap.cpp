#include <curses.h>
#include <string>
using namespace std;
void settingGameMap()
{
    WINDOW * w;
    w = initscr();//term 변수 통해 단말기 종류 결정
    curs_set(0);
    // start main
    int max_row = LINES-1,max_col=COLS-COLS;
    string str_start = "Game Start";
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
    mvaddstr(max_row/2,COLS/2,str_start.c_str());
    getch();//wait keyboard
    // end main
    endwin();//모든 자원 반납
}
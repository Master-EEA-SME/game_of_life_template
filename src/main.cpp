
#include <thread>
#include <chrono>
#include "Game.hpp"
#include <ncurses.h>
void ncurses_initialiser() 
{
    initscr();              /* Demarre le mode ncurses */
    cbreak();	            /* Pour les saisies clavier (desac. mise en buffer) */
    noecho();               /* Desactive l'affichage des caracteres saisis */
    keypad(stdscr, TRUE);	/* Active les touches specifiques */
    refresh();              /* Met a jour l'affichage */
    curs_set(TRUE);         /* Masque le curseur */
}
int main(int argc, char const *argv[])
{
    ncurses_initialiser();
    Game game = Game(10, 10);
    int iter = 0;
    game.begin();
    game.show();
    printw("Press any key to start\n");
    refresh();
    getch();
    clear();
    do
    {
        game.iterate();
        game.show();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        iter++;
        printw("iteration %d\n", iter);
        refresh();
    } while (1);
    printw("Simulation finished after %d iterations\n", iter);
    printw("Press any key to finish\n");
    getch();
    endwin();
    return 0;
}
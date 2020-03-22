
#include <ncurses.h>
#include <iostream>
#include <string>
#include <unistd.h>

int main()
{	
	initscr();			/* Start curses mode 		  */
	int c;
	char name[100];
	char email[100];

	printw("Enter your name: ");
	// while ((c = getch()) != '\n') {
	// 	name += c;
	// }
	getstr(name);

	erase();

	printw("Enter your email: ");
	// while ((c = getch()) != '\n') {
	// 	email += c;
	// }
	getstr(email);

	printw("Your name is %s\n", name);
	printw("Your email is %s\n", email);

	printw("%d, %d\n", strlen(name), strlen(email));
	refresh();
	sleep(1);
	endwin();			/* End curses mode		  */

	return 0;
}




#include <stdio.h>
#include "draw.h"
int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:\n");
      puts("Select a font:\na(11x16)\tb(5x7)");
      char c;
      scanf("%c", c);
      if(c=='a')
      {
	for (char c = 'A'; c < 'D'; c++)
	  print_char_11x16(c);
      }else if(c=='b')
      {
	for(char c = 'A'; c<'D'; c++)
	  print_char_5x7(c);
      }else{
	puts("Unrecognized input\n");
      }
      break;
    case 'a':
      puts("You selected arrow:");
      print_arrow(5,5);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}

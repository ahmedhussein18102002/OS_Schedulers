#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "./interfaces/data/proccess.h"  // This include All proccess function
#include "./interfaces/schedulars/all.h" // All schedulars
#include "./config.h"
#include "interfaces/data/constants.h"

void print_fifo()
{
  printf("FFFFFFFFFFFFFFFFFFFFFFIIIIIIIIIIFFFFFFFFFFFFFFFFFFFFFF     OOOOOOOOO     \n"
         "F::::::::::::::::::::FI::::::::IF::::::::::::::::::::F   OO:::::::::OO   \n"
         "F::::::::::::::::::::FI::::::::IF::::::::::::::::::::F OO:::::::::::::OO \n"
         "FF::::::FFFFFFFFF::::FII::::::IIFF::::::FFFFFFFFF::::FO:::::::OOO:::::::O\n"
         "  F:::::F       FFFFFF  I::::I    F:::::F       FFFFFFO::::::O   O::::::O\n"
         "  F:::::F               I::::I    F:::::F             O:::::O     O:::::O\n"
         "  F::::::FFFFFFFFFF     I::::I    F::::::FFFFFFFFFF   O:::::O     O:::::O\n"
         "  F:::::::::::::::F     I::::I    F:::::::::::::::F   O:::::O     O:::::O\n"
         "  F:::::::::::::::F     I::::I    F:::::::::::::::F   O:::::O     O:::::O\n"
         "  F::::::FFFFFFFFFF     I::::I    F::::::FFFFFFFFFF   O:::::O     O:::::O\n"
         "  F:::::F               I::::I    F:::::F             O:::::O     O:::::O\n"
         "  F:::::F               I::::I    F:::::F             O::::::O   O::::::O\n"
         "FF:::::::FF           II::::::IIFF:::::::FF           O:::::::OOO:::::::O\n"
         "F::::::::FF           I::::::::IF::::::::FF            OO:::::::::::::OO \n"
         "F::::::::FF           I::::::::IF::::::::FF              OO:::::::::OO   \n"
         "FFFFFFFFFFF           IIIIIIIIIIFFFFFFFFFFF                OOOOOOOOO     \n");

  sleep(1);
  system("clear");
}

void print_sjf()
{
  printf("   SSSSSSSSSSSSSSS           JJJJJJJJJJJFFFFFFFFFFFFFFFFFFFFFF\n "
         " SS:::::::::::::::S          J:::::::::JF::::::::::::::::::::F\n"
         "S:::::SSSSSS::::::S          J:::::::::JF::::::::::::::::::::F\n"
         "S:::::S     SSSSSSS          JJ:::::::JJFF::::::FFFFFFFFF::::F\n"
         "S:::::S                        J:::::J    F:::::F       FFFFFF\n"
         "S:::::S                        J:::::J    F:::::F       FFFFFF\n"
         "S:::::S                        J:::::J    F:::::F             \n"
         " S::::SSSS                     J:::::J    F::::::FFFFFFFFFF   \n"
         "  SS::::::SSSSS                J:::::j    F:::::::::::::::F   \n"
         "    SSS::::::::SS              J:::::J    F:::::::::::::::F   \n"
         "       SSSSSS::::S JJJJJJJ     J:::::J    F::::::FFFFFFFFFF   \n"
         "            S:::::SJ:::::J     J:::::J    F:::::F             \n"
         "            S:::::SJ::::::J   J::::::J    F:::::F             \n"
         "SSSSSSS     S:::::SJ:::::::JJJ:::::::J  FF:::::::FF           \n"
         "S::::::SSSSSS:::::S JJ:::::::::::::JJ   F::::::::FF           \n"
         "S:::::::::::::::SS    JJ:::::::::JJ     F::::::::FF           \n"
         " SSSSSSSSSSSSSSS        JJJJJJJJJ       FFFFFFFFFFF           \n");

  sleep(1);
  system("clear");
}

void print_stcf()
{
  printf("   SSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTT       CCCCCCCCCCCCCFFFFFFFFFFFFFFFFFFFFFF\n"
         " SS:::::::::::::::ST:::::::::::::::::::::T    CCC::::::::::::CF::::::::::::::::::::F\n"
         "S:::::SSSSSS::::::ST:::::::::::::::::::::T  CC:::::::::::::::CF::::::::::::::::::::F\n"
         "S:::::S     SSSSSSST:::::TT:::::::TT:::::T C:::::CCCCCCCC::::CFF::::::FFFFFFFFF::::F\n"
         "S:::::S            TTTTTT  T:::::T  TTTTTTC:::::C       CCCCCC  F:::::F       FFFFFF\n"
         "S:::::S                    T:::::T       C:::::C                F:::::F             \n"
         " S::::SSSS                 T:::::T       C:::::C                F::::::FFFFFFFFFF   \n"
         "  SS::::::SSSSS            T:::::T       C:::::C                F:::::::::::::::F   \n"
         "    SSS::::::::SS          T:::::T       C:::::C                F:::::::::::::::F   \n"
         "       SSSSSS::::S         T:::::T       C:::::C                F::::::FFFFFFFFFF   \n"
         "            S:::::S        T:::::T       C:::::C                F:::::F             \n"
         "            S:::::S        T:::::T        C:::::C       CCCCCC  F:::::F             \n"
         "SSSSSSS     S:::::S      TT:::::::TT       C:::::CCCCCCCC::::CFF:::::::FF           \n"
         "S::::::SSSSSS:::::S      T:::::::::T        CC:::::::::::::::CF::::::::FF           \n"
         "S:::::::::::::::SS       T:::::::::T          CCC::::::::::::CF::::::::FF           \n"
         " SSSSSSSSSSSSSSS         TTTTTTTTTTT             CCCCCCCCCCCCCFFFFFFFFFFF           \n");

  sleep(1);
  system("clear");
}

void print_rr()
{
  printf("RRRRRRRRRRRRRRRRR  RRRRRRRRRRRRRRRRR   \n"
         "R::::::::::::::::R R::::::::::::::::R  \n"
         "R::::::RRRRRR:::::RR::::::RRRRRR:::::R \n"
         "RR:::::R     R:::::RR:::::R     R:::::R\n"
         "  R::::R     R:::::R R::::R     R:::::R\n"
         "  R::::R     R:::::R R::::R     R:::::R\n"
         "  R::::RRRRRR:::::R  R::::RRRRRR:::::R \n"
         "  R:::::::::::::RR   R:::::::::::::RR  \n"
         "  R::::RRRRRR:::::R  R::::RRRRRR:::::R \n"
         "  R::::R     R:::::R R::::R     R:::::R\n"
         "  R::::R     R:::::R R::::R     R:::::R\n"
         "  R::::R     R:::::R R::::R     R:::::R\n"
         "RR:::::R     R:::::RR:::::R     R:::::R\n"
         "R::::::R     R:::::R::::::R     R:::::R\n"
         "R::::::R     R:::::R::::::R     R:::::R\n"
         "RRRRRRRR     RRRRRRRRRRRRRR     RRRRRRR\n");

  sleep(1);
  system("clear");
}

void print_priority()
{
  printf("PPPPPPPPPPPPPPPPP                        iiii                                        iiii          tttt                               \n"
         "P::::::::::::::::P                      i::::i                                      i::::i      ttt:::t                               \n"
         "P::::::PPPPPP:::::P                      iiii                                        iiii       t:::::t                               \n"
         "PP:::::P     P:::::P                                                                            t:::::t                              \n"
         "  P::::P     P:::::Prrrrr   rrrrrrrrr  iiiiiii    ooooooooooo   rrrrr   rrrrrrrrr  iiiiiiittttttt:::::tttttttyyyyyyy           yyyyyyy\n"
         "  P::::P     P:::::Pr::::rrr:::::::::r i:::::i  oo:::::::::::oo r::::rrr:::::::::r i:::::it:::::::::::::::::t y:::::y         y:::::y \n"
         "  P::::PPPPPP:::::P r:::::::::::::::::r i::::i o:::::::::::::::or:::::::::::::::::r i::::it:::::::::::::::::t  y:::::y       y:::::y  \n"
         "  P:::::::::::::PP  rr::::::rrrrr::::::ri::::i o:::::ooooo:::::orr::::::rrrrr::::::ri::::itttttt:::::::tttttt   y:::::y     y:::::y   \n"
         "  P::::PPPPPPPPP     r:::::r     r:::::ri::::i o::::o     o::::o r:::::r     r:::::ri::::i      t:::::t          y:::::y   y:::::y    \n"
         "  P::::P             r:::::r     rrrrrrri::::i o::::o     o::::o r:::::r     rrrrrrri::::i      t:::::t           y:::::y y:::::y     \n"
         "  P::::P             r:::::r            i::::i o::::o     o::::o r:::::r            i::::i      t:::::t            y:::::y:::::y      \n"
         "  P::::P             r:::::r            i::::i o::::o     o::::o r:::::r            i::::i      t:::::t    tttttt   y:::::::::y       \n"
         "PP::::::PP           r:::::r           i::::::io:::::ooooo:::::o r:::::r           i::::::i     t::::::tttt:::::t    y:::::::y        \n"
         "P::::::::P           r:::::r           i::::::io:::::::::::::::o r:::::r           i::::::i     tt::::::::::::::t     y:::::y         \n"
         "P::::::::P           r:::::r           i::::::i oo:::::::::::oo  r:::::r           i::::::i       tt:::::::::::tt    y:::::y          \n"
         "PPPPPPPPPP           rrrrrrr           iiiiiiii   ooooooooooo    rrrrrrr           iiiiiiii         ttttttttttt     y:::::y           \n"
         "                                                                                                                   y:::::y            \n"
         "                                                                                                                  y:::::y             \n"
         "                                                                                                                 y:::::y              \n"
         "                                                                                                                y:::::y               \n"
         "                                                                                                               yyyyyyy                \n");

  sleep(1);
  system("clear");
}

void print_mlfq()
{
  printf("MMMMMMMM               MMMMMMMMLLLLLLLLLLL             FFFFFFFFFFFFFFFFFFFFFF     QQQQQQQQQ      \n"
         "M:::::::M             M:::::::ML:::::::::L             F::::::::::::::::::::F   QQ:::::::::QQ    \n"
         "M::::::::M           M::::::::ML:::::::::L             F::::::::::::::::::::F QQ:::::::::::::QQ  \n"
         "M:::::::::M         M:::::::::MLL:::::::LL             FF::::::FFFFFFFFF::::FQ:::::::QQQ:::::::Q \n"
         "M::::::::::M       M::::::::::M  L:::::L                 F:::::F       FFFFFFQ::::::O   Q::::::Q \n"
         "M:::::::::::M     M:::::::::::M  L:::::L                 F:::::F             Q:::::O     Q:::::Q \n"
         "M:::::::M::::M   M::::M:::::::M  L:::::L                 F::::::FFFFFFFFFF   Q:::::O     Q:::::Q \n"
         "M::::::M M::::M M::::M M::::::M  L:::::L                 F:::::::::::::::F   Q:::::O     Q:::::Q \n"
         "M::::::M  M::::M::::M  M::::::M  L:::::L                 F:::::::::::::::F   Q:::::O     Q:::::Q \n"
         "M::::::M   M:::::::M   M::::::M  L:::::L                 F::::::FFFFFFFFFF   Q:::::O     Q:::::Q \n"
         "M::::::M    M:::::M    M::::::M  L:::::L                 F:::::F             Q:::::O  QQQQ:::::Q \n"
         "M::::::M     MMMMM     M::::::M  L:::::L         LLLLLL  F:::::F             Q::::::O Q::::::::Q \n"
         "M::::::M               M::::::MLL:::::::LLLLLLLLL:::::LFF:::::::FF           Q:::::::QQ::::::::Q \n"
         "M::::::M               M::::::ML::::::::::::::::::::::LF::::::::FF            QQ::::::::::::::Q  \n"
         "M::::::M               M::::::ML::::::::::::::::::::::LF::::::::FF              QQ:::::::::::Q   \n"
         "MMMMMMMM               MMMMMMMMLLLLLLLLLLLLLLLLLLLLLLLLFFFFFFFFFFF                QQQQQQQQ::::QQ \n"
         "                                                                                          Q:::::Q\n"
         "                                                                                           QQQQQQ\n");

  sleep(1);
  system("clear");
}

void print_stride()
{
  printf("                                                                            dddddddd                    \n"
         "   SSSSSSSSSSSSSSS      tttt                              iiii              d::::::d                    \n"
         " SS:::::::::::::::S  ttt:::t                             i::::i             d::::::d                    \n"
         "S:::::SSSSSS::::::S  t:::::t                              iiii              d::::::d                    \n"
         "S:::::S     SSSSSSS  t:::::t                                                d:::::d                     \n"
         "S:::::S        ttttttt:::::ttttttt   rrrrr   rrrrrrrrr  iiiiiii     ddddddddd:::::d     eeeeeeeeeeee    \n"
         "S:::::S        t:::::::::::::::::t   r::::rrr:::::::::r i:::::i   dd::::::::::::::d   ee::::::::::::ee  \n"
         " S::::SSSS     t:::::::::::::::::t   r:::::::::::::::::r i::::i  d::::::::::::::::d  e::::::eeeee:::::ee\n"
         "  SS::::::SSSSStttttt:::::::tttttt   rr::::::rrrrr::::::ri::::i d:::::::ddddd:::::d e::::::e     e:::::e\n"
         "    SSS::::::::SS    t:::::t          r:::::r     r:::::ri::::i d::::::d    d:::::d e:::::::eeeee::::::e\n"
         "       SSSSSS::::S   t:::::t          r:::::r     rrrrrrri::::i d:::::d     d:::::d e:::::::::::::::::e \n"
         "            S:::::S  t:::::t          r:::::r            i::::i d:::::d     d:::::d e::::::eeeeeeeeeee  \n"
         "            S:::::S  t:::::t    ttttttr:::::r            i::::i d:::::d     d:::::d e:::::::e           \n"
         "SSSSSSS     S:::::S  t::::::tttt:::::tr:::::r           i::::::id::::::ddddd::::::dde::::::::e          \n"
         "S::::::SSSSSS:::::S  tt::::::::::::::tr:::::r           i::::::i d:::::::::::::::::d e::::::::eeeeeeee  \n"
         "S:::::::::::::::SS     tt:::::::::::ttr:::::r           i::::::i  d:::::::::ddd::::d  ee:::::::::::::e  \n"
         " SSSSSSSSSSSSSSS         ttttttttttt  rrrrrrr           iiiiiiii   ddddddddd   ddddd    eeeeeeeeeeeeee  \n");

  sleep(1);
  system("clear");
}

/*
 /$$      /$$           /$$   /$$     /$$          /$$$$$$
| $$$    /$$$          | $$  | $$    |__/         /$$__  $$
| $$$$  /$$$$ /$$   /$$| $$ /$$$$$$   /$$        | $$  \__/  /$$$$$$   /$$$$$$   /$$$$$$
| $$ $$/$$ $$| $$  | $$| $$|_  $$_/  | $$ /$$$$$$| $$       /$$__  $$ /$$__  $$ /$$__  $$
| $$  $$$| $$| $$  | $$| $$  | $$    | $$|______/| $$      | $$  \ $$| $$  \__/| $$$$$$$$
| $$\  $ | $$| $$  | $$| $$  | $$ /$$| $$        | $$    $$| $$  | $$| $$      | $$_____/
| $$ \/  | $$|  $$$$$$/| $$  |  $$$$/| $$        |  $$$$$$/|  $$$$$$/| $$      |  $$$$$$$
|__/     |__/ \______/ |__/   \___/  |__/         \______/  \______/ |__/       \_______/

  /$$$$$$            /$$                       /$$           /$$
 /$$__  $$          | $$                      | $$          | $$
| $$  \__/  /$$$$$$$| $$$$$$$   /$$$$$$   /$$$$$$$ /$$   /$$| $$  /$$$$$$   /$$$$$$   /$$$$$$$
|  $$$$$$  /$$_____/| $$__  $$ /$$__  $$ /$$__  $$| $$  | $$| $$ |____  $$ /$$__  $$ /$$_____/
 \____  $$| $$      | $$  \ $$| $$$$$$$$| $$  | $$| $$  | $$| $$  /$$$$$$$| $$  \__/|  $$$$$$
 /$$  \ $$| $$      | $$  | $$| $$_____/| $$  | $$| $$  | $$| $$ /$$__  $$| $$       \____  $$
|  $$$$$$/|  $$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$/| $$|  $$$$$$$| $$       /$$$$$$$/
 \______/  \_______/|__/  |__/ \_______/ \_______/ \______/ |__/ \_______/|__/      |_______/
*/
int main(int argc, char *argv[])
{

  if (argc < 0 || argc > 3)
  {
    printf("-_-\n");
    printf("Can you enter arguments , we don't have time to sanitize you silly inputs\n");
    return 1;
  }

  char *schedular = argv[1];
  char *file_destination = argv[2];

  FILE *file = fopen(file_destination, "r");

  if (file == NULL)
  {
    fprintf(stderr, "Error opening the file\n");
    exit(1);
  }

  // Counting the Number of processes by counting the number of lines
  // NOTE: the file should end with an empty line, to read all processes
  char ch;
  while (!feof(file))
  {
    ch = fgetc(file);
    if (ch == '\n')
    {
      NUM_PROCCSSES++;
    }
  }

  rewind(file);

  // Initialize an array of processes
  init_processes_array(NUM_PROCCSSES);

  // Read and initialize each process from the file
  /*
    init_proccess(
      proccess Obj  => proccess index in the proccesses array to initialize,
      Proccess ID   => should be unquie,
      arrivalTime   => the time at which this proccess comes to the CPU,
      executionTime => the time this proccess will take (not including IO)
      io_interrupt  => After {$1} execution steps the proccess will ask for IO (-1 means no IO)
      priority      => Represends priority in MLFQ and Priority scheduling
      stride        => Represends stride in Stride scheduling
    )
  */
  for (int i = 0; i < NUM_PROCCSSES; ++i)
  {
    char id;
    int arrivalTime, executionTime, io_interrupt, priority, stride;

    // Read values from the file
    if (fscanf(file,
               " %c %d %d %d %d %d",
               &id, &arrivalTime,
               &executionTime, &io_interrupt,
               &priority, &stride) != 6)
    {
      fprintf(stderr, "Error reading values from the file\n");
      exit(1);
    }
    // Initialize the corresponding process
    init_process(&processes[i], id, arrivalTime, executionTime, io_interrupt, priority, stride);
  }

  fclose(file);

  if (strcmp(schedular, "fifo") == 0)
  {
    print_fifo();
    FIFO();
  }
  else if (strcmp(schedular, "sjf") == 0)
  {
    print_sjf();
    SJF();
  }
  else if (strcmp(schedular, "stcf") == 0)
  {
    print_stcf();
    STCF();
  }
  else if (strcmp(schedular, "rr") == 0)
  {
    print_rr();
    RR();
  }
  else if (strcmp(schedular, "priority") == 0)
  {
    print_priority();
    Priority();
  }
  else if (strcmp(schedular, "mlfq") == 0)
  {
    print_mlfq();
    MLFQ();
  }
  else if (strcmp(schedular, "stride") == 0)
  {
    print_stride();
    Stride();
  }
  else
  {
    printf("-_- can't you write a schedualar name, You did not learn how to write letters in school! \n");
  }

  free(processes);

  return 0;
}

#include "xli.h"

struct option long_opt[]
{
  {"task", 1, nullptr, 't'},
  {"init", 0, nullptr, 'i'},
  {0, 0, 0, 0},
};

Xli xli;

int main(int argc, char** argv)
{
  int got_option_name_c;
  while ((got_option_name_c = getopt_long(argc, argv, "t:i", long_opt, NULL)) != -1) 
  {
    switch (got_option_name_c)
    {
      case 't':
        xli.run_task(optarg);
        exit(0);
      break;
      case 'i':
        xli.init();
        exit(0);
      break;
      case '?':
        cerr << "unknown option" << endl;
        exit(-1);      
    }
  }
  exit(0);
}

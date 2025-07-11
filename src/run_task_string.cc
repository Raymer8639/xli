#include "xli.h"
string run_cmd(string cmd)
{
  char result[100000];
  FILE* pop = popen(cmd.c_str(), "r");
  fgets(result, 100000, pop);
  return string(result);
}

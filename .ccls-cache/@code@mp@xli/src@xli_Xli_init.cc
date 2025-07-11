#include "xli.h"

void Xli::init()
{
  cout << "=> start init:" << endl;
  cout << "=> get your workspace path... ";
   
  cout << this->workspace << endl;
  cout << "=> running init commands...";
  string cmd = "cd " + this->workspace + ";mkdir -p build xli src include;touch xli/tasks.yaml;mkdir -p build/objs;touch build.xli";
  run_cmd(cmd); 
  cout << "susess!" << endl;
  cout << "=> end init"<< endl;
}

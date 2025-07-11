#pragma once
#include <iostream>
#include <fstream>
#include <getopt.h>
#include <unistd.h>
#include "yaml-cpp/yaml.h"
using namespace std;

string XLI_workspace;

string run_cmd(string);
class Xli
{
public:
  inline Xli()
  {
    char a[1000];
    getcwd(a, 1000);
    workspace = a;
    XLI_workspace = workspace;
  }
  Xli(char*);
  bool run_task(char*);
  void init();
private:
  char* task_name_now_ = nullptr;
  string workspace;
};

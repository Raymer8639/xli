#include "xli.h"

enum class struct_type
{
  IF = 0,
  TARGET,
  ELSE,
  ELSEIF,
  NULL_
};

struct xli_struct 
{
  char *keyword = nullptr;
  char *task_name = nullptr;
  bool is;
  vector<string> value;
};

struct_type* last_s_t = nullptr;

vector<string> update_task()
{
  string root_build_file_this_line;
  string& rbftl = root_build_file_this_line;
  string root_file = XLI_workspace + "/build.xli";
  fstream root_build_file(root_file.c_str(), ios::in);
  xli_struct xtruct;
  while (root_build_file >> rbftl)
  {
    struct_type s_t = struct_type::NULL_;
    last_s_t = &s_t;

    xtruct.keyword = (char*)rbftl.c_str();
    if (rbftl == "if")
    {
      s_t = struct_type::IF;
    } else if (rbftl == "target")
    {
      s_t = struct_type::TARGET;
    } else if (rbftl == "else")
    {
      if (!((*last_s_t) == struct_type::IF || (*last_s_t) == struct_type::ELSEIF))
        throw "In front of else keyword have no if(else) keyword!";
      
      s_t = struct_type::ELSE;
    } else if (rbftl == "elif")
    {
      if (!(last_s_t == 0))
        throw "In front of else keyword have no if(else) keyword!";;
      s_t = struct_type::ELSEIF;
    }
    root_build_file >> rbftl;
    xtruct.task_name = (char*)rbftl.c_str();
    root_build_file >> rbftl;
    if (rbftl != "=")
      throw "don't have '='";
    root_build_file >> rbftl;
    switch (s_t) 
    {
      case struct_type::TARGET: {
        root_build_file >> rbftl; // skip '{'
        do 
        {
          root_build_file >> rbftl;
          
          

  
        } while (rbftl != "}");
      }
      break;
      case struct_type::IF:
      break;
      case struct_type::ELSEIF:
      break;
      case struct_type::ELSE:
      break;
      default:
        throw "have no keyword!";
        break;
    }

  }

}

bool Xli::run_task(char* task_name)
{
  update_task();
  return 1;
}

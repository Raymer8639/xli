#include "xli.h"

bool skip_no_task_error = 0;

bool if_is_have_target_task(char *task_name,const char *dir)
{
  string build_file_path = XLI_workspace + "/" + dir + "/xli.yaml";
  YAML::Node yaml;
  try 
  {
    yaml = YAML::LoadFile(build_file_path.c_str());
  } catch (YAML::BadFile &bf_e)
  {
    cerr << "There is no xli.yaml file!" << endl;
    exit(-1);
  }
  try
  {
    string temp;
    vector<string> subdirs_v_s;
    string subdirs = yaml["subdirs"].as<string>();
    for (auto a : subdirs)
    {
      if (a != ' ')
        temp += a;
      else {
        subdirs_v_s.push_back(temp);
        temp.clear();
        continue;
      }
      for (auto it = subdirs_v_s.begin(); it != subdirs_v_s.end(); it++) 
      {

        cout << *it << endl;
        skip_no_task_error = 1;
        
        if (if_is_have_target_task(task_name, it->c_str()))
        {
          return 1;
        }

      }

    }
  } catch (YAML::InvalidNode &in_e)
  {}
  try 
  {
    string a = yaml[(const char*)task_name]["type"].as<string>();
    return 1;
  } catch (YAML::InvalidNode &in_e)
  {
    if (!skip_no_task_error)
    {
      cerr << "No that task!" << endl;
      exit(-1);
    } 
  } catch (YAML::BadSubscript bs_e)
  {
    cerr << "There is no important 'sub var'" << endl;
    exit(-1);
  }
  return 0;

}

bool Xli::run_task(char* task_name)
{

  if (!if_is_have_target_task(task_name, "."))
  {
    if (skip_no_task_error)
      cerr << "No that task!" << endl;
    exit(-1);
  }
  cout << "1";
  string build_file_path = XLI_workspace + "/xli.yaml";
  YAML::Node build_file = YAML::LoadFile((char*)build_file_path.c_str());


  return 1;
}

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

//using namespace std;

struct Task{

        int ID = -1;
        std::string title = ""; // string is part of the string class and uses std::
        bool completed = false;
        std::string timestamp = "";

};

void to_json(json &j, const Task &t);
void from_json(const json &j,  Task &t);



#endif
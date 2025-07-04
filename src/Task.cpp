#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "Task.hpp"

using json = nlohmann::json;

    void to_json(json &j, const Task &t)
     {
        j["ID"] = t.ID;
        j["title"] = t.title;
        j["completed"] = t.completed;
        j["timestamp"] = t.timestamp;
     }

     void from_json(const json &j, Task &t)
     {
        t.ID = j.at("ID").get<int>();
        t.title = j.at("title").get<std::string>();
        t.completed = j.at("completed").get<bool>();
        t.timestamp = j.at("timestamp").get<std::string>();
     }

     void Task::mark_done(Task &t)
     {
         t.completed = true;
     }

     bool Task::operator==(const Task &other)
     {
         return(this->ID == other.ID);
     }

  
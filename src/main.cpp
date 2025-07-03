#include <iostream>
#include "Task.hpp"
#include "Storage.hpp"
#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;


int main()
{
    cout << "Task Manager running..." << endl;
    // Task original{2, "Homework", false, "00:10"};
    // json j = original;
    // Task new_original = j.get<Task>(); 
    // cout << j.dump() << endl;
    Storage s("C:/Users/jfire/Desktop/Modern_CLI/tasks.json");
    s.add("Homework");
    s.add("Gym");
    s.add("Sleep");
    return 0;
}
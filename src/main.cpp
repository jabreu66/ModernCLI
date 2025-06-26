#include <iostream>
#include "Task.hpp"
#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;


int main()
{
    cout << "Task Manager running..." << endl;
    Task original{2, "Homework", false, "00:10"};
    json j = original;
    Task new_original = j.get<Task>(); 
    cout << j.dump() << endl;
    return 0;
}
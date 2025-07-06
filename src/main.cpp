#include <iostream>
#include "Task.hpp"
#include "Storage.hpp"
#include <nlohmann/json.hpp>
#include<string>
#include <sstream>

using namespace std;

using json = nlohmann::json;


int main()
{
    cout << "Task Manager running..." << endl;
    cout << "Hello! Welcome to the Task CLI. Your available commands are: add and remove. Please specify one of these commands followed by the name of your task." << endl;
    cout << "If you wish to exit the program, type exit" << endl;

    bool run = true;
    Storage s("C:/Users/jfire/Desktop/Modern_CLI/tasks.json");

    while(run)
    {
        string line;
        std::getline(cin, line);

        stringstream ss(line);
        string operation, task;
        
        ss >> operation >> task;

        if(operation == "add")
        {
            int ID = s.add(task);
            
            cout << "adding " << task << " with ID of " << ID << endl;
        }
        else if(operation == "remove")
        {
            int ID = stoi(task);
            bool removed = s.remove(ID);
            (removed) ? cout << "Removing task with ID of " << ID << endl : cout << "ID doesn't exist" << endl;
        }
        else if(operation == "exit")
        {
            cout << "Exiting the interface " << endl;
            run = false;
        }
        else
        {
            cout << "please enter a valid command " << endl;
        }
    }





    // Task original{2, "Homework", false, "00:10"};
    // json j = original;
    // Task new_original = j.get<Task>(); 
    // cout << j.dump() << endl;


    return 0;
}
#include <iostream>
#include "Task.hpp"
#include "Storage.hpp"
#include <nlohmann/json.hpp>
#include<string>
#include <sstream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;
using json = nlohmann::json;


int main()
{
    cout << "Task Manager running..." << endl;
    cout << "Hello! Welcome to the Task CLI. Your available commands are: add, remove, save, load, and see. Please specify one of these commands followed by the name of your task." << endl;
    cout << "If you wish to exit the program, type exit" << endl;

    bool run = true;
    fs::path tasksFile = fs::current_path() / "tasks.json";
    Storage s(tasksFile.string());

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
         else if(operation == "see")
        {
            vector<Task> tsks = s.getTasks();
            if(tsks.empty())
            {
                cout << "There are no tasks to see" << endl;
            }
            else
            {
                for(Task &t : tsks)
                {
                    cout << t.title << " has ID, " << t.ID << " ";
                }

                cout << endl;
            }
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
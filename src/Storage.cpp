#include "Storage.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <algorithm>

using json = nlohmann::json;


Storage::Storage(std::filesystem::path data_file) : file_path(data_file)
{
    // check if the path exists, if not generate new one
    if(std::filesystem::exists(file_path))
    {
           load(); 
    }
  
}

Storage::~Storage()
{
    save();
    // tasks.clear(); --> This line isn't necessary since the destructor automatically does this when called
}


bool Storage::remove(int id)
{
    if(tasks.empty())
    {
        // std::cout << "There are no tasks to remove." << std::endl;
        return false;
    }

    for(Task t : tasks)
    {
        // std::cout << t.ID << std::endl;
        int t_id = t.ID;
        if((int)t_id == (int)id)
        {
            tasks.erase(std::remove(tasks.begin(), tasks.end(), t));
            return true;
        }
    }

    return false;
    //return false;
}

int Storage::add(std::string title)
{
    nextID++;
    auto time = std::chrono::system_clock::now();
    std::string timestamp = std::format("{:%Y-%m-%d %H:%M:%S}", time); 
    Task t = Task(nextID, title, false, timestamp);
    tasks.push_back(t);
    save();
    return nextID;
}

//Goal of this function should be to read from the tasks vector and write those to the json file, in json format

void Storage::save()
{
    std::ofstream outputFile(file_path, std::ios::trunc); //ios::trunc ensures that we overwrite the file

    if(!outputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }


    json j = tasks;

    outputFile << j.dump() << std::endl; 

    // std::cout << file_path << std::endl;
    // std::cout << std::filesystem::current_path() << std::endl;

    outputFile.close();
}

void Storage::load()
{
    std::ifstream outputFile("tasks.json", std::ios::trunc); //ios::app ensures that we don't overwrite the file if it alr exists, only append to it

    if(!outputFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }

    json j;

    outputFile >> j;

    tasks = j;

    outputFile.close();
}



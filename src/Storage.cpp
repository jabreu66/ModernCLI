#include "Storage.hpp"
#include <iostream>
#include <fstream>

explicit Storage::Storage(std::filesystem::path data_file) : file_path(data_file)
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
    tasks.clear();
}

//Goal of this function should be to read from the tasks vector and write those to the json file, in json format

void Storage::save()
{
    std::ofstream outputFile("tasks.json", std::ios::app); //ios::app ensures that we don't overwrite the file if it alr exists, only append to it

    if(!outputFile.is_open())
    {
        std::cerr << "Error opening the file!"
        return 1;
    }

    if(task.empty())
    {
        std::cout << "There are no tasks to save. " << endl;
        return;
    }

    for(Task t: tasks)
    {
        jsonto_json(json &j, const Task &t);
    }
}

void Storage::load()
{
    std::ifstream outputFile("tasks.json", std::ios::app); //ios::app ensures that we don't overwrite the file if it alr exists, only append to it

    if(!outputFile.is_open())
    {
        std::cerr << "Error opening the file!"
        return 1;
    }
}



#include "Storage.hpp"
#include <iostream>
#include <fstream>

explicit Storage::Storage(std::filesystem::path data_file)
{

    this.file_path = data_file;
    // check if the path exists, if not generate new one
    if(std::filesystem::exists(file_path))
    {
           load(); 
    }
  
}

void Storage::save()
{
    std::ofstream outputFile("tasks.json", std::ios::app); //ios::app ensures that we don't overwrite the file if it alr exists, only append to it

    if(!outputFile.is_open())
    {
        std::cerr << "Error opening the file!"
    }
}

void Storage::load()
{

}



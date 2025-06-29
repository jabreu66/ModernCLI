#include "Storage.hpp"


explicit Storage(std::filesystem::path data_file)
{
    // check if the path exists, if not generate new one
    if(std::filesystem::exists(data_file))
    {
        tasks.size() = 0;
    }
    else
    {
        
    }


  
}
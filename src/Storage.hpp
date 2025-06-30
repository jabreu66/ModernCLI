#ifndef STORAGE_H
#define STORAGE_H
#include<iostream>
#include <filesystem>
#include <vector>
#include "Task.hpp"
#include <nlohmann/json.hpp>


class Storage{
    explicit Storage(std::filesystem::path data_file);
    ~Storage();
    const std::vector<Task>& list() const;
    int add(std::string Title, std::string timestamp);
    //bool mark_done(int id);
    bool remove(int id);
    void save();
    void load();

    private:
        vector<Task> tasks;
        std::filesystem::path file_path;
};





#endif
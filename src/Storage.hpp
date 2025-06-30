#ifndef STORAGE_H
#define STORAGE_H
#include<iostream>
#include <filesystem>
#include <vector>
#include "Task.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <chrono>
#include <ctime>
#include <format>


class Storage{
    explicit Storage(std::filesystem::path data_file);
    ~Storage();
    const std::vector<Task>& list() const;
    int add(std::string title, std::string timestamp);
    //bool mark_done(int id);
    bool remove(int id);
    void save();
    void load();

    private:
        vector<Task> tasks;
        int nextID = -1;
        std::filesystem::path file_path;
};





#endif
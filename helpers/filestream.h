//          filestream.h Helper Header File

#pragma once

#include <fstream>
#include <string>

#include "../containers/dynamic_array.h"

class FileReader
{
    private:
        std::string _path;
    public:
        explicit FileReader(const std::string& path) noexcept : _path(path) {}

        bool read_all(std::string& out)
        {
            std::fstream file;
            file.open(_path, std::ios::in);
            std::string line;
            if (file.is_open())
            {
                while (std::getline(file, line))
                {
                    out += line;
                    out += '\n';
                }
                
                file.close();
                return true;
            }
            return false;
        }

        bool read_lines(STL_type::arr<std::string>& lines_arr_container) const
        {
            std::fstream file;
            file.open(_path, std::ios::in);
            std::string line;
            if (file.is_open())
            {
                file.close();
                while (std::getline(file, line))
                    lines_arr_container.push_back(line);
                
                return true;
            }
            return false;
        }
};
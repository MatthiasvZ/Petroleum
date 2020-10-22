#include "../../Petroleum.h"

#define LENGTH_OF_EXEC_NAME 16

namespace PT
{

void setDataDir(const char* directory)
{
    createDataFolder(directory);
    if (chdir(directory))
        fprintf(stderr, "(Petroleum) ERROR: Couldn't access directory \"%s\"!\n", directory);
}

void createDataFolder(const char* directory)
{
    struct stat buffer;
    if (stat (directory, &buffer) != 0)
    {
        #ifdef DEBUG
            fprintf(stderr, "(Petroleum) DEBUG: Creating data folder at \"%s\"\n", directory);
        #endif // DEBUG
        mkdir(directory, 0755);
    }

    std::string file = directory;
    file.append("/ptconfig");

    if (stat (file.c_str(), &buffer) != 0)
    {
        #ifdef DEBUG
            fprintf(stderr, "(Petroleum) DEBUG: Creating config at \"%s\"\n", directory);
        #endif // DEBUG
        std::ofstream cfg;
        cfg.open(file);
        if (!cfg.is_open())
            fprintf(stderr, "(Petroleum) ERROR: Couldn't create config \"%s\"!\n", directory);
        cfg << "# Configuration of the Petroleum game engine\n";
        cfg << "# DO NOT EDIT unless you know what you are doing!!\n";
        cfg << "# Editing of this file should usally be done by, or using, the overlying game.\n";
        cfg << "# Whitespace and lines starting with hash symbols will be ignored.\n";
        cfg << "\n";
        cfg << "# Use v-sync (0 – 1)\n";
        cfg << "vsync = 0\n";
        cfg << "\n";
        cfg << "# Anti-aliasing level (0 – 8)\n";
        cfg << "msaa = 4\n";
        cfg << "\n";
        cfg << "# Start in fullscreen mode (0 – 1)\n";
        cfg << "fullscreen = 0\n";
    }
}

void createFolder(const char* directory)
{
    struct stat buffer;
    if (stat (directory, &buffer) != 0)
    {
        mkdir(directory, 0755);
        #ifdef DEBUG
            fprintf(stderr, "(Petroleum) DEBUG: Creating folder \"%s\"\n", directory);
        #endif // DEBUG
    }
}

Config parseConfig()
{
    Config result;

    std::fstream cfg;
    cfg.open("ptconfig");
    if (!cfg.is_open())
    {
        fprintf(stderr, "(Petroleum) ERROR: Couldn't access config file! Trying to use defaults instead...\n");
        result.vsync = 0;
        result.msaa = 4;
        result.fullscreen = 0;
    }
    else
    {
        std::string line;
        unsigned int linenum {0};
        while (getline(cfg, line))
        {
            ++linenum;
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

            if (line[0] == '#' || line.empty())
                continue;

            auto delimiterPos = line.find('=');
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);


            if (name == "vsync")
            {
                if (value == "0")
                    result.vsync = false;
                else if (value == "1")
                    result.vsync = true;
                else
                {
                    fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid value in ptconfig (line %d)...\n", linenum);
                }
            }

            else if (name == "msaa")
            {
                try
                {
                    result.msaa = std::stoul(value);
                    if (result.msaa > 8)
                        result.msaa = 8;
                }
                catch (std::invalid_argument const &e)
                {
                    fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid value in ptconfig (line %d)...\n", linenum);
                }
                catch (std::out_of_range const &e)
                {
                fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid value in ptconfig (line %d)...\n", linenum);
                }
            }

            else if (name == "fullscreen")
            {
                if (value == "0")
                    result.fullscreen = false;
                else if (value == "1")
                    result.fullscreen = true;
                else
                {
                    fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid value in ptconfig (line %d)...\n", linenum);
                }
            }

            else
                fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid config name in ptconfig (line %d)...\n", linenum);
        } //end-bracket of while

    }
    return result;
}

std::string getDir()
{
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    std::string sresult( result, (count > 0) ? count : 0 );
    sresult.erase(sresult.end() - (4 + LENGTH_OF_EXEC_NAME), sresult.end());
    return sresult;
}

}

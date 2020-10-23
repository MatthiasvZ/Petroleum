#include "../../Petroleum.h"

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
        cfg << "# OpenGL Version X.x\n";
        cfg << "opengl_major = 4\n";
        cfg << "\n";
        cfg << "# OpenGL Version x.X\n";
        cfg << "opengl_minor = 0\n";
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


inline void setBool(bool& setting, std::string& value, unsigned int& linenum)
{
    if (value == "0")
        setting = false;
    else if (value == "1")
        setting = true;
    else
        fprintf(stderr, "(Petroleum) WARNING: Ignoring invalid value in ptconfig (line %d)...\n", linenum);
}

inline void setUInt(unsigned int& setting, std::string& value, unsigned int& linenum)
{
    try
    {
        setting = std::stoul(value);
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

Config parseConfig()
{
    Config result;
    result.opengl_major = 4;
    result.opengl_minor = 0;
    result.vsync = 0;
    result.msaa = 4;
    result.fullscreen = 0;

    std::fstream cfg;
    cfg.open("ptconfig");
    if (!cfg.is_open())
        fprintf(stderr, "(Petroleum) ERROR: Couldn't access config file! Trying to use defaults instead...\n");
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

            if (name == "opengl_major")
                setUInt(result.opengl_major, value, linenum);
            else if (name == "opengl_minor")
                setUInt(result.opengl_minor, value, linenum);
            else if (name == "vsync")
                setBool(result.vsync, value, linenum);
            else if (name == "msaa")
                setUInt(result.msaa, value, linenum);
            else if (name == "fullscreen")
                setBool(result.fullscreen, value, linenum);
            else
                fprintf(stderr, "(Petroleum) WARNING: Ignoring unknown config name in ptconfig (line %d)...\n", linenum);
        }

    }
    return result;
}

}

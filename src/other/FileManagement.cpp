#include "../../Petroleum.h"
#include <algorithm>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

namespace PT
{

bool g_Fresh {false};

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

        g_Fresh = true;

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
        cfg << "\n";
        cfg << "# Colour where nothing is drawn\n";
        cfg << "clear_colour = black\n";
        cfg << "\n";
        cfg << "# Allow transparency (0 – 1)\n";
        cfg << "enable_blending = 1\n";
        cfg << "\n";
        cfg << "# Capture Mouse (0 – 1)\n";
        cfg << "capture_mouse = 0\n";
        cfg << "\n";
        cfg << "# Resizable Window (0 – 1)\n";
        cfg << "window_resizable = 0\n";
        cfg << "\n";
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
    if (value == "0" || value == "false")
        setting = false;
    else if (value == "1" || value == "true")
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
    result.fresh = g_Fresh;
    result.opengl_major = 4;
    result.opengl_minor = 0;
    result.vsync = false;
    result.msaa = 4;
    result.fullscreen = false;
    result.clear_colour = PT_BLACK;
    result.enable_blending = false;
    result.capture_mouse = false;
    result.window_resizable = false;

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
            else if (name == "clear_colour")
            {
                if (value == "black")
                    result.clear_colour = PT_BLACK;
                else if (value == "white")
                    result.clear_colour = PT_WHITE;
                else if (value == "sky_blue")
                    result.clear_colour = PT_SKY_BLUE;
                else if (value == "petrol")
                    result.clear_colour = PT_PETROL;
                else if (value == "light_grey")
                    result.clear_colour = PT_LIGHT_GREY;
                else if (value == "grey")
                    result.clear_colour = PT_GREY;
                else if (value == "dark_grey")
                    result.clear_colour = PT_DARK_GREY;
                else
                    setUInt(result.clear_colour, value, linenum);
            }
            else if (name == "enable_blending")
                setBool(result.enable_blending, value, linenum);
            else if (name == "capture_mouse")
                setBool(result.capture_mouse, value, linenum);
            else if (name == "window_resizable")
                setBool(result.window_resizable, value, linenum);
            else
                fprintf(stderr, "(Petroleum) WARNING: Ignoring unknown config name in ptconfig (line %d)...\n", linenum);
        }

    }
    return result;
}

void saveConfig(Config cfg)
{
    #ifdef DEBUG
        fprintf(stderr, "(Petroleum) DEBUG: Saving ptconfig\n");
    #endif // DEBUG
    std::ofstream cfgf;
    cfgf.open("ptconfig");
    if (!cfgf.is_open())
        fprintf(stderr, "(Petroleum) ERROR: Couldn't access ptconfig\n");
    cfgf << "# Configuration of the Petroleum game engine\n";
    cfgf << "# DO NOT EDIT unless you know what you are doing!!\n";
    cfgf << "# Editing of this file should usally be done by, or using, the overlying game.\n";
    cfgf << "# Whitespace and lines starting with hash symbols will be ignored.\n";
    cfgf << "\n";
    cfgf << "# OpenGL Version X.x\n";
    cfgf << "opengl_major = " << cfg.opengl_major << "\n";
    cfgf << "\n";
    cfgf << "# OpenGL Version x.X\n";
    cfgf << "opengl_minor = " << cfg.opengl_minor << "\n";
    cfgf << "\n";
    cfgf << "# Use v-sync (0 – 1)\n";
    cfgf << "vsync = " << cfg.vsync << "\n";
    cfgf << "\n";
    cfgf << "# Anti-aliasing level (0 – 8)\n";
    cfgf << "msaa = " << cfg.msaa << "\n";
    cfgf << "\n";
    cfgf << "# Start in fullscreen mode (0 – 1)\n";
    cfgf << "fullscreen = " << cfg.fullscreen << "\n";
    cfgf << "\n";
    cfgf << "# Colour where nothing is drawn\n";
    cfgf << "clear_colour = " << cfg.clear_colour << "\n";
    cfgf << "\n";
    cfgf << "# Allow transparency (0 – 1)\n";
    cfgf << "enable_blending = " << cfg.enable_blending << "\n";
    cfgf << "\n";
    cfgf << "# Capture Mouse (0 – 1)\n";
    cfgf << "capture_mouse = " << cfg.capture_mouse << "\n";
    cfgf << "\n";
    cfgf << "# Resizable Window (0 – 1)\n";
    cfgf << "window_resizable = " << cfg.window_resizable << "\n";
    cfgf << "\n";
}

}

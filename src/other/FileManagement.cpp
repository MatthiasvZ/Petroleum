#include "other/FileManagement.h"

#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>
#define LENGTH_OF_EXEC_NAME 16


void FileManagement::setWorkingDir()
{
    chdir((getDir()).c_str());
}

void FileManagement::createFolders()
{
    struct stat buffer;
    if (stat ("saves", &buffer) != 0)
        mkdir("saves", 0755);
}
std::string FileManagement::getDir()
{
    char result[ PATH_MAX ];
    ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
    std::string sresult( result, (count > 0) ? count : 0 );
    sresult.erase(sresult.end() - (4 + LENGTH_OF_EXEC_NAME), sresult.end());
    return sresult;
}


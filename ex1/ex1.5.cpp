#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main(int argc, char* argv[])
{
    std::ifstream myfile;

    if (argc > 1)
    {
        myfile.open(argv[1]);
        if (!myfile.is_open())
        {
            std::cerr << "File isn't open for reading.\n";
            return 1;
        }
    }

    else
    {
        std::cerr << "Must enter a file to read from.\n";
        return 1;
    }

    std::unordered_set<std::string> lines;
    std::string line;

    while (std::getline(myfile, line))
    {
        auto got = lines.find(line);
        
        if (got == lines.end())
            lines.insert(line);
        else
            std::cout << line << std::endl;
    }

    return 0;
}

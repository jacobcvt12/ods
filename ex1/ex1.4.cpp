#include <iostream>
#include <fstream>
#include <string>
#include <set>

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

    std::set<std::string> lines;
    std::string line;

    while (std::getline(myfile, line))
        lines.insert(line);

    for (auto it = lines.begin(); it != lines.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}

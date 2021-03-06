#include <iostream>
#include <fstream>
#include <string>
#include <queue>

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

    std::queue<std::string> lines;
    std::string line;

    while (std::getline(myfile, line))
    {
        lines.push(line);

        if (lines.size() == 43)
        {
            if (line.length() == 0)
            {
                std::cout << lines.front() << std::endl;
            }

            lines.pop();
        }
    }

    return 0;
}

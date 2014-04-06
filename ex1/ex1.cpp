#include <iostream>
#include <fstream>
#include <string>
#include <stack>

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

    std::stack<std::string> lines;
    std::string line;

    while (std::getline(myfile, line))
    {
        lines.push(line);
    }

    while (!lines.empty())
    {
        std::cout << lines.top() << std::endl;
        lines.pop();
    }

    return 0;
}

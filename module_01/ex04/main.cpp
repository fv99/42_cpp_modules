#include <iostream>
#include <fstream>
#include <string>

std::string replace_sub(const std::string &input, const std::string &old, const std::string &newstr)
{
    std::string output = input;
    size_t i = 0;

    while ((i = output.find(old, i)) != std::string::npos)
    {
        output.erase(i, old.length());
        output.insert(i, newstr);
        i += newstr.length();
    }
    return output;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::string str((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::string replaced = replace_sub(str, s1, s2);

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error creating output file" << std::endl;
        return 1;
    }

    outfile << replaced;
    outfile.close();
    std::cout << "Replacement completed successfully." << std::endl;
    return 0;
}

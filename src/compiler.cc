#include "global.hpp"
#include "lexer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "\033[31mNo arguments provided.\033[0m\n";
        return RUN_FAIL;
    }

    fs::path source_path = argv[1];

    if (!fs::exists(source_path))
    {
        std::cout << "\033[31mFile does not exist.\033[0m\n";
        return RUN_FAIL;
    }

    if (source_path.extension().string() != ".pixel")
    {
        std::cout << "\033[31mWrong file extension.\033[0m\n";
        return RUN_FAIL;
    }

    ifstream source_file(source_path, std::ios::in);

    lexer::lex_file(source_file);

    for (token tk : lexer::tokens)
    {
        std::cout << tk.type << '\t';
        std::cout << tk.value << '\n';
    }

    source_file.close();
    return RUN_SUCCESS;
}
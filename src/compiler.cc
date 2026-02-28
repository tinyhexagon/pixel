#include "global.hpp"
#include "lexer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "\033[31mNo arguments provided.\033[0m\n";
        return RUN_FAIL;
    }

    vector<string> args = {};
    args.reserve(argc);

    for (int i = 0; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    for (string str : args)
    {
        if (str == "--version")
        {
            cout << "Pixel 0.1 by unityLeaf7\n";
            return RUN_SUCCESS;
        }

        if (str == "--help")
        {
            cout << "\nFlag \t\tUse\n----------------------------------\n";
            cout << "--help  \tShows this page\n";
            cout << "--version  \tShows Pixel language version\n";
            cout << "--wiki  \tProvides GitHub wiki for Pixel\n";
            return RUN_SUCCESS;
        }

        if (str == "--wiki")
        {
            cout << "Pixel Wiki on GitHub: \n";
            return RUN_SUCCESS;
        }
    }

    fs::path source_path = argv[1];

    if (!fs::exists(source_path))
    {
        cout << "\033[31mFile does not exist.\033[0m\n";
        return RUN_FAIL;
    }

    if (source_path.extension().string() != ".pixel")
    {
        cout << "\033[31mWrong file extension.\033[0m\n";
        return RUN_FAIL;
    }

    ifstream source_file(source_path, std::ios::in);

    lexer::lex_file(source_file);
    lexer::process_tokens();

    cout << "\nToken Type\tValue\n";
    cout << "-----------------------\n";

    for (const token &tk : lexer::tokens)
    {
        lexer::print_type(tk.type);
        cout << tk.value << "\n";
        cout << "-----------------------\n";
    }

    source_file.close();
    return RUN_SUCCESS;
}
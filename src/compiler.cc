#include "global.hpp"
#include "lexer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        print("\n\033[31mNo arguments provided.\033[0m\n\n");
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
            print("\nPixel 26.1.10\nMade by unityLeaf7\n\n");
            return RUN_SUCCESS;
        }

        if (str == "--help")
        {
            print("\nFlag \t\tUse\n----------------------------------\n");
            print("--help  \tDisplay this page\n");
            print("--version  \tDisplay compiler version\n");
            print("--wiki  \tProvide GitHub wiki\n");
            print("\n");
            print("--lxout  \tDisplay lexer output\n");
            print("\n");
            return RUN_SUCCESS;
        }

        if (str == "--wiki")
        {
            print("Pixel Wiki on GitHub: \n\n");
            return RUN_SUCCESS;
        }

        if (str == "--lxout")
        {
            print_lexerOutput = true;
        }
    }

    fs::path source_path = argv[1];

    if (!fs::exists(source_path))
    {
        print("\n\033[31mFile or flag does not exist.\033[0m\n\n");
        return RUN_FAIL;
    }

    if (source_path.extension().string() != ".pixel")
    {
        print("\n\033[31mWrong file extension.\033[0m\n\n");
        return RUN_FAIL;
    }

    ifstream source_file(source_path, std::ios::in);

    lexer::lex_file(source_file);
    lexer::process_tokens();

    if (!print_lexerOutput)
    {
        return RUN_SUCCESS;
    }

    print("\nToken Type\tValue\n");
    print("-----------------------\n");

    for (const token &tk : lexer::tokens)
    {
        lexer::print_type(tk.type);
        print("{}\n", tk.value);
        print("-----------------------\n");
    }

    print("\n");

    source_file.close();
    return RUN_SUCCESS;
}
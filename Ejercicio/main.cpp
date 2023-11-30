#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false)
{
    string script;
    ifstream file;

    try
    {
        file.open(filename);
        if (!file.is_open())
        {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }

        script.assign((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));

        file.close();

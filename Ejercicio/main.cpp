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
        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const ifstream::failure &e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
        if (file.is_open())
            file.close();
    }
    catch (const exception &e)
    {
        cerr << "Excepción general: " << e.what() << endl;
        if (file.is_open())
            file.close();
    }
    catch (...)
    {
        cerr << "Error desconocido durante la lectura del archivo" << endl;
        if (file.is_open())
            file.close();
    }
}

void load_script()
{
    char filename[500];
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename, true);
}

int main()
{
    load_script();
    return 0;
}


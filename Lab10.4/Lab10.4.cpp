#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void CreateTXT(char* fname)
{
    ofstream fout(fname);

    char ch;
    string s;
    do
    {
        cin.get();
        cin.sync();
        cout << "enter line: ";
        getline(cin, s);
        fout << s << endl;
        cout << "continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintTXT(char* fname)
{
    ifstream fin(fname);
    string s;
    while (getline(fin, s))
    {
        cout << s << endl;
    }
    cout << endl;
}
int ProcessTXT1(char* fname)
{
    ifstream fin(fname);
    string s;
    int k = 0;
    while (getline(fin, s))
    {
        for (unsigned i = 0; i < s.length(); i++)
            if (s[i] == '+' || s[i] == '-' || s[i] == '=')
                k++;
    }     return k;
}
int ProcessTXT2(char* fname)
{
    ifstream fin(fname);
    string s;
    int k = 0;
    while (fin >> s)
    {
        k++;
        cout << k << ": " << s << endl;
    }
    return k;
}
int ProcessTXT3(char* fname)
{
    ifstream fin(fname);
    char s[100];
    char* w;
    int k = 0;
    while (fin.getline(s, sizeof(s)))
    {
        w = strtok(s, " .,:;!?-'");
        while (w != NULL)
        {
            k++;
            cout << k << ": " << w << endl;
            w = strtok(NULL, " .,:;!?-'");
        }
    }
    return k;
}
void SortTXT(char* fname, char* gname)
{
    ofstream g(gname);
    string s, mins, z = "";

    int k;

    do
    {
        k = 0;
        ifstream f(fname);
        while (getline(f, s))
        {
            if (s <= z)
                continue;
            mins = s;

            k++;

            break;
        }

        while (getline(f, s))
        {
            if (s <= z)
                continue;
            if (s < mins)
            {
                mins = s;
                k++;
            }
        }


        z = mins;

        if (k > 0)
            g << z << endl;
        f.close();
    } while (k > 0);
}
void Remove(char* filename,int L)
{
    int pos1,pos2;
    char line[50];
    string checkline;
    ifstream f(filename, ios::in);
    ifstream f(filename);
    ofstream t("TMP.TXT");
    f.open(filename, ios::in);
    int x;
    while (f >> x)
    {             // скануємо заданий файл
        f.getline(line, sizeof(line));
        checkline = line;
        int pos1=checkline.find(" ");
        if (pos1+1 < L)
        {
            checkline.erase(pos1, count);
        }
        if (checkline.length() < L)
        {                             // і копіюємо ті компоненти,
            t << x << endl;           // які потрібно залишити
        }
        if (temp)
            f.close();                   // для вилучення і перейменування
        t.close();                   // файли маютьбути закриті
        remove(filename);            // знищуємо заданий файл
        rename("TMP.TXT", filename); // перейменовуємо тимчасовий файл
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // text files 
    char fname[100];
    cout << "enter file name 1: "; cin >> fname;
    int L;
    CreateTXT(fname);
    PrintTXT(fname);
    cout << "Введіть довжину слів (Слова менші за ці довжину будут видалятися) = ";
    cin >> L;
    cout << "Змінений файл з видалинеми словами, та з видаленими пустими рядками:" << endl;
    //PrintTXT(gname);

    return 0;
}

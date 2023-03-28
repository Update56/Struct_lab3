#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    system("Color F0");
    map<string, int> voc;
    string str;
    ifstream in("text.txt");
    if (in.is_open())
    {
        while (!in.eof())
        {
            getline(in, str, ' ');
            if (str[0] >= 65 && str[0] <= 90)
            {
                str[0] += 32;
            }
            if (str[str.size() - 1] == '.' || str[str.size() - 1] == '!' || str[str.size() - 1] == ',' || str[str.size() - 1] == '?' || str[str.size() - 1] == '\"')
                str[str.size() - 1] = '\0';
                                    
            if (voc.find(str) != voc.end())
            {
                map <string, int> ::iterator it = voc.find(str);
                it->second++;
            }
            else
                voc[str] = 1;
        }
    }
    map <string, int> ::iterator it = voc.begin();
    for (int i = 0; it != voc.end(); it++, i++) {  // выводим их
        cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}

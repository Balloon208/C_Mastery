#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


    map <int, string> pokemonname;
    map <string, int> pokemonnum;

    string console;
    string name;

    int n, m, numconsole;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> name;

        pokemonname[i]=name;
        pokemonnum[name]=i;
    }

    for(int i=0; i<m; i++)
    {
        cin >> console;
        if(console[0]>='0' && console[0]<='9')
        {
            numconsole = stoi(console);
            cout << pokemonname[numconsole] << '\n';
        }
        else
        {
            cout << pokemonnum[console] << '\n';
        }
    }
}



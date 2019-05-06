#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() 
{
    string          line;
    deque<string>   last_lines;
    while( getline( cin, line ) )
    {
        if( last_lines.size() == 6 )
        {
            last_lines.pop_back();
        }
        last_lines.push_front( line );
    }

    for( auto const& s : last_lines )
    {
        cout << s << endl;
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <array>
#include <deque>


using std::deque;
using std::list;
using std::map;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::array;

void addEdge(map<string, vector<string> > &m, string s, vector<string> v)
{
    m.insert(pair<string, vector<string>>(s, v));
}

deque<string> bfs(map<string, vector<string> > &myMap, string &start, string &end)
{
    map<string, int> level ={{start, 0}};
    map<string, string> parent = {{start, "None"}};
    int lvl = 1;
    deque<string> frontier = {start};
    deque<string> path;
    while(frontier.size() > 0)
    {
        deque<string> nextous;
        for(auto it = frontier.begin() ; it != frontier.end(); ++it)
        {   
            for(auto it2 = myMap.find(*it)->second.begin(); it2 != 
                    myMap.find(*it)->second.end(); ++it2)
            {
                if(level.find(*it2) == level.end()) 
                {
                    level[*it2] = lvl;
                    parent[*it2] = *it;
                    nextous.push_back(*it2);
                }
                if(*it2 == end)
                {
                    string rewind = *it2;
                    path.clear(); 
                    while(rewind != start)
                    {
                        path.push_back(rewind);
                        rewind = parent[rewind];
                    }
                    path.push_back(start);
                }
            }
        }
        frontier = nextous;
        ++lvl;
    }
    std::reverse(path.begin(), path.end());
    return path;
}



int main()
{
    map<string, vector<string> > myMap;
    //this part should be replaced by reading the outside data files;
    vector<string> node{"s", "r", "v", "w", "t","x","u", "y"};    
    vector<vector<string> > v{{"r", "w"}, {"s", "v"}, {"r"}
                    ,{"s", "t", "x"}, {"w", "x","u"}, {"t", "w", "u", "y"}
                    ,{"t", "x", "y"}, {"u", "x"}};

    for(int i = 0; i < node.size(); ++i)
    {
        addEdge(myMap, node[i], v[i]);
    }
    //---------------------------
    //we need to prepare to queue to store the nodes, one for waiting nodes and another for      //the visited nodes
    string start = "s", end = "y";
    deque<string> ret;
    ret = bfs(myMap, start, end);
    
   for(auto &c : ret)
    {
        cout << c << "->";
    }
    
    cout << endl; 
    return 0;
}







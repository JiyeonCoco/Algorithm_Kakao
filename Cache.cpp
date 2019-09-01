#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int cacheSize = 5;
vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco",
                          "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
vector<string> cache;
int cacheTime = 0;

int main()
{

    for(int i=0; i<cities.size(); i++)
    {
        std::transform(cities[i].begin(), cities[i].end(),cities[i].begin(), ::toupper);
        std::cout << cities[i] << endl;
    }
    std::cout << endl;

    for(int i=0; i<cities.size(); i++)
    {
        int check = 0;

        for(int j=0; j<cache.size(); j++)
        {
            if((cities[i] == cache[j]))
            {
                cacheTime += 1;
                cache.erase(cache.begin() + j);
                cache.push_back(cities[i]);
                check = 1;
            }
        }

        if(check == 0)
        {
            cacheTime += 5;
            if(cache.size() >= cacheSize)
            {
                cache.erase(cache.begin());
            }

            cache.push_back(cities[i]);
        }
    }

    std::cout << cacheTime << endl;
}
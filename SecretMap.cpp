#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
int sum = 0;
vector<int> line;

void two(int n, int pos, int num, vector<int> arr)
{
    sum = 0;
    if(pos == n-1)
    {
        if(pow(2, pos) <= arr[num]-sum)
        {
            sum += (int)pow(2, pos);
            line.push_back(1);
        }
        else
        {
            line.push_back(0);
        }

        return;
    }
    two(n, pos+1, num, arr);

    if(pow(2, pos) <= arr[num]-sum)
    {
        sum += (int)pow(2, pos);
        line.push_back(1);
    } else
        line.push_back(0);
}

int main()
{
    int n = 6;
    vector<int> arr1 = {46, 33, 33 ,22, 31, 50};
    vector<int> arr2 = {27 ,56, 19, 14, 14, 10};
    vector<string> answer;

    for(int i=0; i<n; i++)
    {
        line.clear();
        two(n, 0, i, arr1);
        two(n, 0, i, arr2);
        char c[16] = {};

        for(int j=0; j<n; j++)
        {
            if(line[j] == 0 && line[j+n] == 0)
                c[j] = ' ';
            else
                c[j] = '#';
        }
        string input(c);

        answer.push_back(input);
        std::cout << answer[i] << endl;
    }
}
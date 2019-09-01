#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
string input;
vector<int> num;

void checkNum(int i)
{
    int a = input[i-1] - '0';

    if(input[i-1] == '0')
    {
        if(input[i-2] == '1')
            a = 10;
        else
            a = 0;
    }

    num.push_back(a);
}

int main()
{
    int value = 0, order = 0;
    input = "1D#2S*3S";
    int answer = 0;
    vector<int> result;

    for(int i=0; i<input.size(); i++)
    {
        if(input[i] == 'S')
        {
            checkNum(i);
            value = num[order++];
            result.push_back(value);
            answer += value;
        }
        else if(input[i] == 'D')
        {
            checkNum(i);
            value = (int)pow(num[order++], 2);
            result.push_back(value);
            answer += value;
        }
        else if(input[i] == 'T')
        {
            checkNum(i);
            value = (int)pow(num[order++], 3);
            result.push_back(value);
            answer += value;

        }
        else if(input[i] == '*')
        {
            if(i <= 2)
            {
                answer += (result[order-1]);
                result[order-1] *= 2;
            }
            else
            {
                answer += (result[order-1] + result[order-2]);
                result[order-2] *= 2;
                result[order-1] *= 2;
            }

        }
        else if(input[i] == '#')
        {
            answer -= 2*result[order-1];
            result[order-1] *= (-1);
        }
    }

    std::cout << answer << endl;
}
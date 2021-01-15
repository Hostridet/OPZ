#include <vector>

using namespace std;
const char Multi = -1;
const char Plus = -2;
const char Minus = -3;
const char Division = -4;

bool GetCheck(const char* str)
{
    int i = 0;
    bool Flag = true;
    while (str[i] != '\0' && i <=500 && Flag)
    {
        if (str[i] == '/' || (str[i] >= '1' && str[i] <= '9') || str[i] == '*' ||
        str[i] == '+' || str[i] == '-' || str[i] == '(' || str[i] == ')' || str[i] == ' ')
            Flag = true;
        else
            Flag = false;
        i++;
    }
    return Flag;
}

void PushToStack(vector<int>& vent,vector<int>& stack, char operation)
{
    if (operation == '/')
        stack.push_back(Division);
    else if (operation == '*') {
        while (!stack.empty() && stack.back() == Division)
        {
            vent.push_back(stack.back());
            stack.pop_back();
        }
        stack.push_back(Multi);
    }
    else {
        while (!stack.empty() && (stack.back() == Division || stack.back() == Multi))
        {
            vent.push_back(stack.back());
            stack.pop_back();
        }
        if (operation == '+')
            stack.push_back(Plus);
        else if (operation == '-')
            stack.push_back(Minus);
    }
}

int StrToInt(const char* str, int& i)
{
    int res = 0;
    char rank = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
        rank++;
    }
    i--;
    return res;
}

void getReadStr (vector<int>& vent, vector<int>& stack, vector<short>& brackets, const char* str)
{
    int i = 0;
    while (str[i] != '\0' && i <= 500)
    {
        if (str[i] >= '1' && str[i] <= '9')
            vent.push_back(StrToInt(str, i));
        else if (str[i] == '+')
            PushToStack(vent, stack, '+');
        else if (str[i] == '-')
            PushToStack(vent, stack, '-');
        else if (str[i] == '*')
            PushToStack(vent, stack, '*');
        else if (str[i] == '/')
            PushToStack(vent, stack, '/');
        else if (str[i] == '(')
            brackets.push_back(stack.size());
        else if (str[i] == ')') {
            while (stack.size() > brackets.back())
            {
                vent.push_back(stack.back());
                stack.pop_back();
            }
            brackets.pop_back();
        }
        i++;
    }
}
float GetResult(const char* str)
{
    vector<int> vent;
    vector<int> stack;
    vector<short> brackets;

    getReadStr (vent, stack, brackets, str);
    while (!stack.empty())
    {
        vent.push_back(stack.back());
        stack.pop_back();
    }
    vector<double> result;
    int i = 0;
    while (i < vent.size()) {
        if (vent[i] > 0) {
            result.push_back(vent[i]);
        } else {
            float b = result.back();
            result.pop_back();
            if (vent[i] == Multi)
                result.back() = result.back() * b;
            else if (vent[i] == Plus)
                result.back() = result.back() + b;
            else if (vent[i] == Minus)
                result.back() = result.back() - b;
            else if (vent[i] == Division)
                result.back() = result.back() / b;
        }
        i++;
    }

    return result.back();

}
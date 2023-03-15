#include <iostream>
#include <stack>
#include <string>

void write_error(std::string s)
{
    std::cout << s << std::endl;
    exit (1);
}

float rev_polish(std::string s)
{
    std::stack<float> stack;
    float op1, op2, res;

    int i = -1;
    int j = 0;
    while (s[++i])
    {
        if (isdigit(s[i]))
            j++;
        if (j == 2)
            write_error("Error");
        else if (!isdigit(s[i]))
            j = 0;
    }
    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            std::string n_str = std::to_string(s[i] - '0');
            float n = stof(n_str);
            stack.push(n);
        }
        else 
        {
            if (stack.empty())
                write_error("Error");
            op2 = stack.top();
            stack.pop();
            if (stack.empty())
                write_error("Error");
            op1 = stack.top();
            stack.pop();
            switch (s[i])
            {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                default:
                    write_error("Error");
            }
            stack.push(res);
        }
    }
    if (stack.empty())
        write_error("Error");
    return stack.top();
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::string s = argv[1];
    float res = rev_polish(s);
    std::cout << res << std::endl;

    return 0;
}
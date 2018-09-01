#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

// Evaluate Reverse Polish Notation
class MySolution
{
public:
    int evaluateReversePolishNotation(const std::string &str){
        std::stack<char> tmp;
        int a;
        for(auto i : str){
            switch(i){
            case '+':
                a = tmp.top();tmp.pop();
                a += tmp.top();tmp.pop();
                tmp.push(a);
                break;
            case '-':
                a = tmp.top();tmp.pop();
                a -= tmp.top(), tmp.pop();
                tmp.push(a);
                break;
            case '*':
                a = tmp.top();tmp.pop();
                a *= tmp.top(), tmp.pop();
                tmp.push(a);
                break;
            case '/':
                a = tmp.top();tmp.pop();
                a /= tmp.top(), tmp.pop();
                tmp.push(a);
                break;
            default:
                tmp.push(i-'0');
            }
        }
        return tmp.top();
    }
};

// Evaluate Reverse Polish Notation
// 递归，时间复杂度O(n)，空间复杂度O(logn)
class Solution_1 {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        if (tokens.empty()) return 0;
        int x, y;
        auto token = tokens.back();  tokens.pop_back();
        if (is_operator(token))  {
            y = evalRPN(tokens);
            x = evalRPN(tokens);
            switch(token[0]) {
            case '+' : x += y; break;
            case '-' : x -= y; break;
            case '*' : x *= y; break;
            default:   x /= y;
            }
        } else  {
            size_t i;
            x = stoi(token, &i);
        }
        return x;
    }
private:
    bool is_operator(const std::string &op) {
        return op.size() == 1 && std::string("+-*/").find(op) != std::string::npos;
    }
};

// Max Points on a Line
// 迭代，时间复杂度O(n)，空间复杂度O(logn)
class Solution_2 {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<std::string> s;
        for (auto token : tokens) {
            if (!is_operator(token)) {
                s.push(token);
            } else {
                int y = stoi(s.top());
                s.pop();
                int x = stoi(s.top());
                s.pop();
                switch(token[0]) {
                case '+' : x += y; break;
                case '-' : x -= y; break;
                case '*' : x *= y; break;
                default:   x /= y;
                }
                s.push(std::to_string(x));
            }
        }
        return stoi(s.top());
    }
private:
    bool is_operator(const std::string &op) {
        return op.size() == 1 && std::string("+-*/").find(op) != std::string::npos;
    }
};

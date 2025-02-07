#ifndef BRACKETCHECK_H
#define BRACKETCHECK_H

#include <iostream>
#include <string>
#include <stack>

class BracketCheck {
public:
    BracketCheck(const std::string& expr) : expression(expr) {

    }

    bool isBalance() const {
        std::stack<char> stack;
        for (char ch : expression) 
        {
            if (isOpenBracket(ch))
             {

                stack.push(ch);

            } else if (isClosBracket(ch)) {

                if (stack.empty() || !bracketMatch(stack.top(), ch)) {

                    return false;

                }

                stack.pop();

            }

        }

        return stack.empty();
    }
    friend std::ostream& operator<<(std::ostream& os, const BracketCheck& bc) {

        os << "The expression: " << bc.expression;

        return os;
    }

private:
    std::string expression;

    bool isOpenBracket(char ch) const {

        return ch == '(' || ch == '{' || ch == '[';

    }

    bool isClosBracket(char ch) const {
        return ch == ')' || ch == '}' || ch == ']';
    }
    
    bool bracketMatch(char opening, char closing) 
        const {
        return (opening == '(' && closing == ')') ||

               (opening == '{' && closing == '}') ||

               (opening == '[' && closing == ']');

    }
};

#endif 
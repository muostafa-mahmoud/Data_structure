#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <chrono>
#include <cctype>
#include <unordered_map>
using namespace std;
using namespace std::chrono;
class InfixToPostfixConverter {
public:
    // Function to convert infix expression to postfix expression
    string convert(const string& infix) {
        stack<char> operators;
        ostringstream output;

        for (char token : infix) {
            if (isspace(token)) {
                // Skip whitespace
                continue;
            }
            if (isdigit(token) || isalpha(token)) {
                // Add operand to output
                output << token;
            } else if (token == '(') {
                // Push '(' to stack
                operators.push(token);
            } else if (token == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    // Pop and output operators
                    output << ' ' << operators.top();
                    operators.pop();
                }
                // Pop '('
                operators.pop();
            }  // Operator
             else
             {
                // Add space before operator
                output << ' ';
                while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                    // Pop and output operators
                    output << operators.top();
                    operators.pop();
                }
                // Push current operator to stack
                operators.push(token);
            }
        }

        // Pop all the operators from the stack
        while (!operators.empty()) {
            output << ' ' << operators.top();
            operators.pop();
        }
        // Return the postfix expression
        return output.str();
    }

private:
    // Function to return precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0; // For '('
    }
};

// Function to measure execution time of a function
template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args... args) {
    auto start = high_resolution_clock::now();
    func(args...);
    auto end = high_resolution_clock::now();
    duration<double> duration = end - start;
    // Return time in seconds
    return duration.count();
}

int main() {
    InfixToPostfixConverter converter;
    // Example infix expression
    string infixExpression = "A + B * C - D";

    // Measure time for converting infix to postfix
    double conversionTime = measureExecutionTime([&converter, &infixExpression]() {
        string postfix = converter.convert(infixExpression);
        cout << "Postfix expression: " << postfix << endl;
    });

    cout << "Time taken to convert infix to postfix: " << conversionTime << " seconds" << endl;

    return 0;
}
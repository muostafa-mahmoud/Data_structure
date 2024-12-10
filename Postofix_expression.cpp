#include <iostream>
#include <stack>
#include <sstream>
#include <chrono>
#include <string>
#include <cctype>
using namespace std;
using namespace chrono;
class PostfixEvaluator {
public:
    // Function to evaluate a postfix expression
    int evaluate(const string& expression) {
        stack<int> stack;
        istringstream tokens(expression);
        string token;

        while (tokens >> token) {
            // If the token is an operand
            if (isdigit(token[0])) {
                stack.push(stoi(token));
            } else { // The token is an operator
                int operand2 = stack.top(); stack.pop();
                int operand1 = stack.top(); stack.pop();
                int result = applyOperator(operand1, operand2, token[0]);
                stack.push(result);
            }
        }
        // The result is the only element left in the stack
        return stack.top();
    }

private:
    // Function to apply an operator to two operands
    int applyOperator(int operand1, int operand2, char op) {
        switch (op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: throw invalid_argument("Invalid operator");
        }
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
    PostfixEvaluator evaluator;
    // Example postfix expression
    string expression = "5 1 2 + 4 * + 3 -";

    // Measure time for evaluating the postfix expression
    double evalTime = measureExecutionTime([&evaluator, &expression]() {
        int result = evaluator.evaluate(expression);
        cout << "Result of the postfix expression: " << result << endl;
    });

    cout << "Time taken to evaluate the postfix expression: " << evalTime << " seconds" << endl;

    return 0;
}
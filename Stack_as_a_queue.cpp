#include <iostream>
#include <queue>
#include <chrono>
using namespace std;
using namespace chrono;
class Stack {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    // Remove the top element from stack
    void pop() {
        if (!q1.empty()) {
            q1.pop();
        }
    }

    // Get the top element of stack
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        throw out_of_range("Stack is empty");
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
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
    Stack stack;

    // Measure time for push operation
    double pushTime = measureExecutionTime([&stack]() {
        for (int i = 0; i < 10000; ++i) {
            stack.push(i);
        }
    });
    cout << "Time taken for 10000 push operations: " << pushTime << " seconds" << endl;

    // Measure time for pop operation
    double popTime = measureExecutionTime([&stack]() {
        for (int i = 0; i < 10000; ++i) {
            stack.pop();
        }
    });
    cout << "Time taken for 10000 pop operations: " << popTime << " seconds" << endl;

    // Measure time for top operation
    double topTime = measureExecutionTime([&stack]() {
        for (int i = 0; i < 10000; ++i) {
            if (!stack.isEmpty()) {
                stack.top();
            }
        }
    });
    cout << "Time taken for 10000 top operations: " << topTime << " seconds" << endl;

    return 0;
}
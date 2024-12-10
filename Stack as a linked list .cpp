#include<bits/stdc++.h>
using namespace std;
struct node{
    int data ;
    struct node*next ;
};
struct node* top = NULL;
void push(int value ){
    struct node *newnode = (struct node*)malloc (sizeof (struct node));
    newnode->data = value ;
    newnode->next = top;
    top = newnode ;
}
void pop() {
    if (top == NULL)
        cout << "stack underflow" << endl;
    else {
        cout << "The popped element is : " << top->data << endl;
        top = top->next;
    }
}
void display () {
    struct node *ptr;
    if (top == NULL)
        cout << "stack is empty ";
    else {
        ptr = top;
        cout << "stack elements are : ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}
int main() {
    int ch, value;
    cout << "1) Push in stack " << endl;
    cout << "2) Pop from stack " << endl;
    cout << "3) Display stack " << endl;
    cout << "4) Exit " << endl;
    do {
        cout << "Enter choice " << endl;
        cin >> ch;
        switch (ch) {
            case 1 : {
                cout << "Enter value to be pushed : " << endl;
                cin >> value;
                push(value);
                break;
            }
            case 2 : {
                pop();
                break;
            }
            case 3 : {
                display();
                break;
            }
            case 4 : {
                cout << "Exit" << endl;
                break;
            }
            default : {
                cout << "Invalid choice" << endl;
            }
        }
    }
    while(ch!=4);
}






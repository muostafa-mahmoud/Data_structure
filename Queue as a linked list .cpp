#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data ;
    struct node *next ;
};
struct node *front =NULL;
struct node *rear =NULL;
struct node *temp;
void enqueue()
{
    int value ;
    cout<<"Insert the element in queue : "<<endl;
    cin>>value ;
    if(rear ==NULL) {
        rear = (struct node *) malloc(sizeof(struct node));
        rear->next = NULL;
        rear->data = value;
        front = rear ;

    }
    else
    {
        temp = (struct node *) malloc(sizeof(struct node));
        rear ->next = temp ;
        temp ->data=value ;
        temp->next= NULL;
        rear = temp;
    }
}
void dequeue()
{
    temp = front ;
    if(front == NULL) {
        cout << "Underflow" << endl;
        return;
    }
else if(temp->next != NULL) {
        temp = temp->next;
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = NULL;
    }
else
    {
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front =NULL;
        rear=NULL;
    }
}
void display ()
{
    temp = front;
    if ((front == NULL) && (rear == NULL)) {
        cout << "Queue is empty " << endl;
        return;
    }
    cout << "Queue elements are : ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int test ;
    cout<<"1) Insert element to queue"<<endl;
    cout<<"2) Delete element from queue"<<endl;
    cout<<"3) Display all the elemnets of queue"<<endl;
    cout<<"4) Exit "<<endl;
    do
    {
        cout<<"Enter your choice : "<<endl;
        cin>>test;
        switch(test)
        {
            case 1:
                enqueue();
            break;
            case 2:
                dequeue();
            break;
            case 3:
                display();
            break;
            case 4 :
                cout<<"Exit"<<endl;
                break;
            default : cout<<"Invalid choice "<<endl;
        }
    }
    while(test!=4);
}
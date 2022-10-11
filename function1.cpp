#include<iostream>
using namespace std;

// class for creating nodes of the linked list
class Node{
    public:
        char data;
        Node* next;
        Node(){
            data = '0';
            next = NULL;
        }
        Node(char data){
            this->data = data;
            this->next = NULL;
        }

};
class LinkedList{
    Node* head;
    public:
         LinkedList(){
             head = NULL;
         }
         // Insert Function
         void insertNode(char data){
             Node* newNode = new Node(data);
             if(head == NULL){
                 head = newNode;
                 return;
             }
             Node* temp = head;
             while(temp->next != NULL){
                 temp = temp->next;
             }
             temp->next = newNode;
         }
         // Delete Function 
         void deleteLastNode(){
             Node* temp = head;
             if(head == NULL){
                 return;
             }
             if(temp->next == NULL){
                 head = NULL;
                 return;
             }
             while(temp->next != NULL && temp->next->next != NULL){
                 temp = temp->next;
             }
             temp->next = NULL;
             return;
         }
         // Print Function
         void printLL(){
             Node* temp = head;
             if(head == NULL){
                 cout<<"Empty Linked List";
                 return;
             }
             while(temp->next != NULL){
                 cout<<temp->data<<" ";
                 temp = temp->next;
             }
             cout<<temp->data<<endl;
             return;
         }
         //Size Function
         int size(){
             Node* temp = head;
             int sizeOfLL = 0;
             if(head == NULL){
                 return sizeOfLL;
             }
             while(temp != NULL){
                 sizeOfLL++;
                 temp = temp->next;
             }
             return sizeOfLL;
         }
         // LastNode function
         char lastNode(){
             Node* temp = head;
             if(head == NULL){
                 return '0';
             }
             while(temp->next != NULL){
                 temp = temp->next;
             }
             return temp->data;

         }
};
// stack implemented using linked list
class Stack{
    LinkedList ll;
    public:
    void push(char data){
        ll.insertNode(data);
        return;
    }
    void pop(){
        ll.deleteLastNode();
        return;
    }
    int size(){
        return ll.size();
    }
    char top(){
        return ll.lastNode();
    }

};
/*
<------------------------------------------------------------------------------------------------------------>
Task 1:
Write a function to convert the infix propositional logic expression into a prefix propositional logic
expression.
<------------------------------------------------------------------------------------------------------------>
*/
void infixToPrefix(){
    cout<<"Enter the infix expression: ";
    string s;
    cin>>s;
    int len = s.size();

    char v[len];
    char display[len];
    for(int i=0;i<len;i++){
        display[i] = -1;
    }

    // for precedence of operators
    char precedence[6];
    precedence[0] = '(';
    precedence[1] = ')';
    precedence[2] = '>';
    precedence[3] = '+';
    precedence[4] = '*';
    precedence[5] = '~';

    Stack stack;
    // reversing the given array
    for(int i=0;i<len;i++){
        v[i] = s[len-i-1];
    }
    // replacing '(' by ')' and ')' by '('
    for(int i=0;i<len;i++){
        if(v[i] == '('){
            v[i] = ')';
        }
        else if(v[i] == ')'){
            v[i] = '(';
        }
    }
    int j = 0;
    // iterating over the whole length of reversed array
    for(int i=0;i<len;i++){
        int pref = 0;
        int prefStack = 0;
        int flag = 0;
        // if it is '(' then directly push this into the stack
        if(v[i] == '('){
            stack.push(v[i]);
        }
        else if(v[i] == '~' || v[i] =='*' || v[i] == '+' || v[i] == '>'){
            // if stack is empty then directly push the operator into stack
            if(stack.size() == 0){
                stack.push(v[i]);
            }
            else{

                // find precedence of v[i] and top ele of stack
                for(int i=0;i<4;i++){
                    if(precedence[i] == v[i]){
                        pref = i;
                        break;
                    }
                }
                for(int i=0;i<4;i++){
                    if(precedence[i] == stack.top()){
                        prefStack = i;
                        break;
                    }
                }

                // if precedence of v[i] is greater than push it in stack
                if( prefStack < pref){
                    stack.push(v[i]);
                }

                // if precedence of v[i] is <= precedence of top ele of stack then empty the stack until
                // v[i] has greater precedence than top ele of stack
                else{
                    while(prefStack >= pref && stack.size() != 0){
                        if(stack.top() == ')' || stack.top() == '('){
                            stack.push(v[i]);
                            flag = 1;
                            break;
                        }
                        display[j] = stack.top();
                        j++;
                        stack.pop();
                    }
                    if(flag==0){
                        stack.push(v[i]);
                    }
                }
            }
        }

        // if ')' this is there then empty the stack until we find '(' and pop this out
        else if(v[i] == ')'){
            while(stack.size() != 0 && stack.top() != '('){
                display[j] = stack.top();
                j++;
                stack.pop();
            }
            stack.pop();
        }
        else{
            display[j] = v[i];
            j++;
        }
    }

    // finally add all the remaining elements of the stack to display array
    while(stack.size() != 0){
        display[j] = stack.top();
        j++;
        stack.pop();
    }
    cout<<"The prefix expression for the given infix expression is:";

    // as the display array length included brackets also so final length will without brackets will
    // be less than len so count the final length
    int count = 0;
    for(int i=0;i<len;i++){
        if(display[i] == -1){
            break;
        }
        count++;
    }

    // now reverse the postfix form to obtain the prefix form
    for(int i=count-1;i>=0;i--){
        cout<<display[i];
    }
    cout<<endl;
}

int main(void){
    infixToPrefix();
    return 0;
}



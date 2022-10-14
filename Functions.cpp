#include<iostream>
using namespace std;

/*
<------------------------------------------------------------------------------------------------------------>
Linked List implementation
<------------------------------------------------------------------------------------------------------------>
*/
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
/*
<------------------------------------------------------------------------------------------------------------>
Stack implementation
<------------------------------------------------------------------------------------------------------------>
*/
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
string infixToPrefix(){
    cout<<"*************************************************************************"<<endl<<endl;
    cout<<"Enter the infix expression: ";
    string s;
    cin>>s;
    cout<<endl;
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
    string prefixStr;
    for(int i=count-1;i>=0;i--){
        prefixStr  += display[i];
    }
    return prefixStr;
}

/*
<------------------------------------------------------------------------------------------------------------>
Task 2:
Write a function to convert the prefix expression into a rooted binary parse tree. 
<------------------------------------------------------------------------------------------------------------>
*/
// to create a BinaryTreeNode which contains data,left pointer and a right pointer
class BinaryTreeNode{
    public:
        char data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        BinaryTreeNode(){
            left = NULL;
            right = NULL;
        }
        BinaryTreeNode(char data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
BinaryTreeNode* prefixToParseTree(string prefixInput, int* i){
    // if string is empty then root points to NULL which is the base case
    if(prefixInput.size() == 0){
        return NULL;
    }
    if(*i==prefixInput.size()){
        return NULL;
    }
    // will create a BinaryTreeNode for each char in prefixInput string
    BinaryTreeNode* root = new BinaryTreeNode(prefixInput[*i]);
    // to increment the pointer so that we can traverse the whole string
    (*i)++;
    int *ptr = i;
    // if root->data contains *,+,> operators so a well formed formula will have both left and right subtrees
    if(root->data == '*' || root->data == '+' || root->data == '>'){
        BinaryTreeNode* leftRoot = prefixToParseTree(prefixInput,ptr);
        BinaryTreeNode* rightRoot = prefixToParseTree(prefixInput,ptr);
        root->left = leftRoot;
        root->right = rightRoot;
        return root;
    }
    // if root->data == '~' means only one side of tree is there which should be right side and root->left == //NULL
    else if(root->data == '~'){
        BinaryTreeNode* rightRoot = prefixToParseTree(prefixInput,ptr);
        root->left = NULL;
        root->right = rightRoot;
    }
    return root;
}

/*
<------------------------------------------------------------------------------------------------------------>
Task 3:
Write a function to traverse the parse tree to output the infix expression back by in-order traversal of the
parse tree. 
<------------------------------------------------------------------------------------------------------------>
*/

// for Inorder traversal we need to first print leftSubtree then root->data and then rightSubtree
void InorderTraversalOfParseTree(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout<<root->data;
        return;
    }
    if(root->left != NULL && root->right == NULL){
        InorderTraversalOfParseTree(root->left);
        cout<<root->data;
        return;
    }
    if(root->right != NULL && root->left == NULL){
        cout<<root->data;
        InorderTraversalOfParseTree(root->right);
        return;
    }
    else{
        InorderTraversalOfParseTree(root->left);
        cout<<root->data;
        InorderTraversalOfParseTree(root->right);
        return;
    }
}

/*
<------------------------------------------------------------------------------------------------------------>
Task 4:
Write a function to compute the height of a parse tree.
<------------------------------------------------------------------------------------------------------------>
*/

/* height of a parseTree can be found by finding max of height of leftSubTree and rightSubTree and adding 1  because of root element
*/
int heightOfParseTree(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    if(root->left != NULL && root->right == NULL){
        return 1+heightOfParseTree(root->left);
    }
    if(root->right != NULL && root->left == NULL){
        return 1+heightOfParseTree(root->right);
    }
    else{
        int leftHeight = heightOfParseTree(root->left);
        int rightHeight = heightOfParseTree(root->right);
        if(leftHeight>=rightHeight){
            return 1+leftHeight;
        }
        else{
            return 1+rightHeight;
        }
    }
}

/*
<------------------------------------------------------------------------------------------------------------>
Task 5:
Write a function to evaluate the truth value of a propositional logic formula, given the truth values of
each propositional atom by traversing the tree in a bottom up fashion. 
<------------------------------------------------------------------------------------------------------------>
*/

// this function will take truth values (T or F) for each atom and return a string
string takeTruthValueOfPropositionalAtoms(string prefix){
    int len = prefix.size();
    int numOfOperators=0;
    for(int i=0;i<len;i++){
        if(prefix[i] == '~' || prefix[i] == '*' || prefix[i] == '+' || prefix[i] =='>'){
            numOfOperators++;
        }
    }
    int numOfAtoms = len - numOfOperators;
    // will make a boolean truthArray of size = number of atoms in prefix formula
    bool truthArray[numOfAtoms];
    cout<<"Enter the truth value of each propositional atom in order: "<<endl<<endl;
    for(int i=0;i<numOfAtoms;i++){
        cout<<"Enter the truth value of atom "<<i+1<<" (T/t for True and F/f for False)"<<endl;
        char ans;
        cin>>ans;
        if(ans == 'T' || ans == 't'){
            truthArray[i] = true;
        }
        else if(ans == 'F' || ans == 'f'){
            truthArray[i] = false;
        }
        else{
            // if user enters anything except 'T/t/F/f' then we will ask user to enter valid symbol until the //user enters a valid char
            while(ans != 'F' || ans != 'f' || ans == 'T' || ans != 't'){
                cout<<"Please enter a valid symbol:"<<endl;
                cin>>ans;
                if(ans == 'T' || ans == 't'){
                    truthArray[i] = true;
                    break;
                }
                else if(ans == 'F' || ans == 'f'){
                    truthArray[i] = false;
                    break;
                }
            }
        }
    }
    cout<<endl;
    // this will copy the truth values to a string which will be returned from the function
    string truthString;
    for(int i=0;i<numOfAtoms;i++){
        truthString[i] = truthArray[i];
    }
    return truthString;
}

// this function finally evaluates the truthValue of given expression using recursion.
bool truthValue(BinaryTreeNode* root, string truthString,int* ptr){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        (*ptr)++;
        return truthString[(*ptr)-1];
    }
    if(root->left == NULL && root->right != NULL){
        bool rightAns = truthValue(root->right,truthString,ptr);
        // only negation can be there as root data
        return !rightAns;
    }
    else{
        bool leftAns = truthValue(root->left,truthString,ptr);
        bool rightAns = truthValue(root->right,truthString,ptr);
        if(root->data == '+'){
            return (leftAns||rightAns);
        }
        else if(root->data == '*'){
            return (leftAns&&rightAns);
        }
        else if(root->data == '>'){
            if(leftAns == true && rightAns == false){
                return false;
            }
            else{
                return true;
            }
        }
    }
    return false;

}

/*
<------------------------------------------------------------------------------------------------------------>
Main Function
<------------------------------------------------------------------------------------------------------------>
*/

int main(void){

    // converting the infix expression to prefix
    string prefix = infixToPrefix();
    cout<<"The prefix expression for the given infix expression is: "<<prefix<<endl<<endl;

    // converting the prefix expression to ParseTree
    int i = 0;
    BinaryTreeNode* root = prefixToParseTree(prefix,&i);

    // finding height of ParseTree
    int height = heightOfParseTree(root);
    cout<<"The height of the Parse Tree is "<<height<<endl<<endl;

    // printing the Inorder Traversal of ParseTree
    cout<<"The Inorder traversal of the Parse Tree is: ";
    InorderTraversalOfParseTree(root);
    cout<<endl<<endl;

    // finding the truth value of expression
    string truthString = takeTruthValueOfPropositionalAtoms(prefix);
    cout<<endl;
    int j =0;
    bool truthValueAns = truthValue(root,truthString,&j);
    if(truthValueAns==1){
        cout<<"The Truth Value of the given propositional logic is "<<"True"<<endl<<endl;
    }
    else{
        cout<<"The Truth Value of the given propositional logic is "<<"False"<<endl<<endl;
    }
    cout<<"*************************************************************************"<<endl;
    return 0;
}



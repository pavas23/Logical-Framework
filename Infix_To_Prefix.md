## InfixToPrefix

- This Function is used to convert Infix to Prefix
- It  takes input of an Infix expression in the form of a string data type, Then the reversed infix expression is stored in an array(but'(' is converted to ')' and vice verca)
-  Precedence of operators is defined along Stack named stack. Also, an array named display is created of same length as the infix string and each eleemnt is initalized to -1
-  Iteration is done through each element of array(reversed string) and  if operator is '(' then its directly pushed into stack once found.
- If operator is either '>' or '+' or '*' or '~', then directly push the operator into stack if stack is empty. 
- If stack is not empty : 1) push the element into the stack provided precedence of current operator is higher than precedence of top element in stack.
-                         2) If precedence of top element of stack is greater than equal to current operator and for a non empty stack,
-                            operator would be added to the display array and then top element of stack would be deleted,provided top element is neither '(' or ')'.
-                            If top element turns out to be '(' or ')', then current operator would be pushed to stack.
- If operator is ')'then empty the stack till we find '(' and pop this.
-  Add charecters to display array
-  Finally add all reamining elements of stack in display array
-  Remove  '(' and ')' and display the reversed display array(since display array has postfix form) to give output of Prefix expression
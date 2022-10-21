## InfixToPrefix

### Algorithm
>
> - This Function is used to convert Infix expression to Prefix expression
> - It takes input of an Infix expression in the form of a string data type, Then the reversed infix expression is stored in an array ( and '(' is converted to ')' and vice versa).
> -  Precedence of operators is defined by the precedence char array. Also, a char array named display is created of same length as the infix string and each eleemnt is initalized to -1 in this array.
> -  Iteration is done through each element of array(reversed string) and  if operator is '(' then its directly pushed into stack once found.
> - If operator is either > or + or * or ~, then directly push the operator into stack if stack is empty. 
> - If stack is not empty
>     - push the element into the stack provided precedence of current operator is higher than precedence of top element in stack.
>     -  If precedence of top element of stack is greater than equal to current operator and for a non empty  stack, then empty the stack and store the elements of stack in display array until the current operator has a higher precedence than the top element of the stack
> -  If top element of stack turns out to be '(' or ')' then current operator would be pushed to stack.
> - If operator is ')' then empty the stack till we find '(' and pop this '(' out.
> -  Add characters to display array
> -  Finally after iteration on infix expression is done, add all reamining elements of stack in display array
> -  Now display the reversed display array (since display array has postfix form) to give output of Prefix expression <br><br>

### Time Complexity
> Since we are scanning all the characters in the infix string at once so Time complexity for this function comes out to be <b>O(n)</b>, Where n is the size of input infix string.

### Space Complexity
> As we have made arrays of size n so the auxiliary space used is space used by these arrays and stack memory.So the Space Complexity is <b>O(n)</b> for this function.
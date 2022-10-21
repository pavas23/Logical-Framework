## TruthValueOfPropositionalLogic

## Algorithm
>
> - In this firstly, we made a function named takeTruthValueOfPropositionalAtoms() which takes the prefix string as function parameter
> - This function is used to take truth value inputs for each propositional atom in the prefix expression from the user
> - Finally this function passes the truthString which contains 0s and 1s to the truthValue() function which evaluates the truth value of the given infix expression
> - This truthValue function takes the root of the BinaryParseTree, truthString returned by the takeTruthValueOfPropositionalAtoms() function and a integer pointer pointing to 0 value as parameters
> - Now in this function we recursively call on the left subtree and right subtree and they will both return the truth values of left and right part and then we see the operator present in root node and evaluate the truth value accordingly.
> - Base cases are:
>   - If root is NULL then tree is empty so it is True by default.
>   - If the left and right pointers are NULL, then we can have only atom in root and we return the truth value of that atom
> - If the left subtree is empty and right subtree has some atoms then only possiblity is that root should have ~ as root data in a well formed formula, so we return the negation of ans returned by right subtree as final truth value for given ParseTree.<br><br>

## Time Complexity
> 
> - For function takeTruthValueOfPropositionalAtoms() the Time Complexity is <b>O(n)</b> as we are scanning through all the atoms.
> - For function truthValue() the Time Complexity is also <b>O(n)</b> as we are iterating over the whole string with help of pointer. <br><br>
> 

## Space Complexity
> 
> - For the function takeTruthValueOfPropositionalAtoms() Space Complexity is <b>O(1)</b> as we have made strings of size n.
> - For function truthValue() the Space Complexity is <b>O(1)</b> as we are not using any auxiliary space. <br><br>



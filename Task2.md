## PrefixToRootedBinaryParseTree

### Algorithm

>
> -  This function prefixToParseTree is used to convert prefix form to Parse tree and returns the root of the Parse Tree.
> -  It has two inputs, one is prefix string obtained from given infix form and other is a integer pointer pointing to 0 value
> -  We create a binary tree node for each charecter in prefixInput string and increment the pointer to traverse through the whole string
> -  If root node contains *,+,> operators so a well formed formula will have both left and right subtrees
> -  if root node contains '~' means only one side of tree is there which should be right side and root->left is NULL
> -  We also make a function printLevelOrderParseTree which is used to print the ParseTree formed level wise.
> -  This function iterates over the height of the Parse Tree and in each iteration it calls another function printLevelOrderParseTreeHelper.
> -  printLevelOrderParseTreeHelper function prints each level of the ParseTree
> -  If it contains only one level i.e only root we directly print it.
> -  If level is greater than 1, then root is not there in that level, only left and right subtrees are there, we pass level-1 here as current level variable as for the original tree, the level variable was equal to level. But for the subtree the level with reference to the left root and right root will be one less in that subtrees<br> <br>

### Time Complexity
>

### Space Complexity
>
## InorderTraversalOfParseTree

### Algorithm

>
> -  The function InorderTraversalOfParseTree is defined and it outputs the infix expression back by in-order traversal.
> -  It initially prints the left subtree, then root node data and then right subtree.
> -  It makes a recursive call on left subtree by passing root->left which is root of left subtree so it will print inorderTraversal for left subtree then once this is done we print root data then we make a recursive call on right subtree which will print inorderTraversal of right subtree and we finally get InOrderTraversal of whole ParseTree
> -  If right subtree is empty and left is not empty, It will just print the left subtree and root node data.
> -  If left subtree is empty and right is not empty, It would print, root node data and then right subtree.
> -  If no subtrees, then only root node data will be printed.
> -  If no root node data and no subtrees then nothing would be printed.<br><br>

### Time Complexity
>

### Space Complexity
>
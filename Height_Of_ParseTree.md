## Height_Of_ParseTree

- The function heightOfParseTree is used to find out maximum height of Parse Tree by finding maximum heights of left subtrees and right subtrees
-  If it has no right or left subtrees, then maximum height is one as it has only root element
- If we have only left subtree, then maximum height of parse tree is 1(due to root element)+height of left subtree
- If we have only right subtree, then maximum height of parse tree is 1(due to root element)+height of right subtree
- If it has both left and right subtrees and height of left subtree is more than that of right subtree, then the maximum height of parse tree is 1(due to root element) + left subtree 
- If it has both left and right subtrees and height of right subtree is more than that of left subtree, then the maximum height of parse tree is 1(due to root element) + right subtree 

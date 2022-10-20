## Prefix_To_Rooted_Binary_ParseTree

-  The function prefixToParseTree is used to convert prefix form to Parse tree
-  It has two inputs, one is prefix string obtained from given infix form and te=he other is a pointer
-  We create a binary tree node for each charecter is prefixInput string and increment the pointer to traverse through the whole string
-  If root node contains *,+,> operators so a well formed formula will have both left and right subtrees
-  if root node '~' means only one side of tree is there which should be right side and root->left is NULL
-  We declare a function heightOfParseTree and printLevelOrderParseTreeHelper which helps in finding the height of parse tree and helping    in level order traversal of parse tree.
- If only its of one level i.e only root exists, then we print it.
-  If level is greater than 1, then root is not there in that level, only left and right subtrees are there, We pass level-1 here as current level as for the original tree, the level was equal to level. But for the subtree the level with reference to the left root and right root will be one less in that subtrees
-  Finally, we call printLevelOrderParseTreeHelper function to print each level of parse tree using iterations.

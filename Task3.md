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
> In this case we are recursively calling on the left and right subtrees so the recurrence relation turns out to be<br>
> T(n) = T(k) + T(n-k-1) + c, where n is total number of nodes , k is number of nodes on one side of tree and remaining n-k-1 nodes on the other side of Parse Tree and c is a constant.<br>
> We have two cases now
> - If the tree is Skewed tree then ( all nodes are on one side of the tree)<br>
>   - then k = 0 <br>
>   - T(n) = T(0) + T(n-1) + c , as T(0) is a constant let it be d<br>
>   - T(n) = T(n-1) + (c+d) , let c+d = a which is another constant<br>
>   - T(n) = T(n-1) + a<br>
>   - Now on solving this recurrence relation we get,<br>
>   - T(n-1) = T(n-2) + a<br>
>   - T(n-2) = T(n-2) + a<br>
>   - T(n-3) = T(n-4) + a<br>
>   - and so on....<br>
>   - T(n) = na <br>
>   - O(n) is Time complexity for this case<br>
> - If the given tree is balanced then (equal number of nodes on both sides)<br>
>   - T(n) = 2T(n/2) + k <br>
>   - T(n/2) = 2T(n/4) + k <br>
>   - T(n/4) = 2T(n/8) + k <br>
>   - .... and so on <br>
>   - On solving this recurrence relation we get T(n) = 2^(log(n)) , where log(n) has base 2 <br>
>   - So T(n) = n <br>
>
> Therefore Time Complexity turns out to be <b>O(n)</b> for this recursive function.<br><br>

### Space Complexity
> Space Complexity is <b>O(1)</b> as we are not using any auxiliary space for this function, only stack memory is being used for recursive calls.
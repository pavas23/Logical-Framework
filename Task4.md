## HeightOfParseTree

## Algorithm
>
> - The Function heightOfParseTree() is used to find out maximum height of Parse Tree by finding maximum heights of left subtrees and right subtrees and adding 1 to it because of root node.
> -  If it has no right or left subtrees, then maximum height is one as it has only root element.
> - If we have only left subtree, then maximum height of parse tree is 1(due to root element)+height of left subtree.
> - If we have only right subtree, then maximum height of parse tree is 1(due to root element)+height of right subtree.
> - If it has both left and right subtrees and height of left subtree is more than that of right subtree, then the maximum height of parse tree is 1(due to root element) + left subtree.
> - If it has both left and right subtrees and height of right subtree is more than that of left subtree, then the maximum height of parse tree is 1(due to root element) + right subtree .<br><br>

<!-- <img src = "/Images/height.png" height="300px" width = "400px"> -->


## Time Complexity
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

## Space Complexity
> Space Complexity is <b>O(1)</b> as we are not using any auxiliary space for this function, only stack memory is being used for recursive calls.

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

    int is_BST_util(Node* root, int min, int max) {
        if(root == nullptr) return 1;
        
        if(root->data < min || root->data > max)
            return 0;
        
        return
            is_BST_util(root->left, min, root->data - 1) &&
            is_BST_util(root->right, root->data + 1, max);
    }

	bool checkBST(Node* root) {
        //is_BST_util(root, min, max)
        //constraints 0 <= data <= 10e4
        return is_BST_util(root, 0, 10e4);
	}
bool is_balanced(Node *root){
    if(root == nullptr){
        return true;
    }
        
    int lh = get_height(root->left);
    int rh = get_height(root->right);
        
    if(abs(lh-rh) <= 1 && is_balanced(root->left) && is_balanced(root->right)){
        return true;
    }
    else{
        return false;
    }
}
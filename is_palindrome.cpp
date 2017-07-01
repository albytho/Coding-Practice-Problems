bool is_palindrome(Node *a){
    vector<char> vec;
    while(a!=nullptr){
        vec.push_back(a->data);
        a=a->next;
    }
    
    for(int index=0; index<vec.size()/2; ++index){
        if(vec[index] != vec[vec.size()-1-index]){
            return false;
        }
    }
    
    return true;
}
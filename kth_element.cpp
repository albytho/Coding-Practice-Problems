int kth_element(int num){
    Node *k = head;
    Node *current = head;
    for(int index=0; index<num-1; ++index){
        if(current==nullptr){
            return -1;
        }
        current = current->next;
    }
        
    while(current->next != nullptr){
        current = current->next;
        k=k->next;
    }
        
    return k->data;
}

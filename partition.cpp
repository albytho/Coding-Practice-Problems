void partition(int n){
    Node *k = head;
    Node *current = head;
    while(current != nullptr){
        if(current->data < n){
            int temp = k->data;
            k->data = current->data;
            current->data = temp;
            k=k->next;
                
        }
        current = current->next;
    }
}
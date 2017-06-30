void remove_middle(Node *middle){
    middle->data = middle->next->data;
        
    Node *temp = middle->next;
    middle->next = temp->next;
    delete temp;
    temp = nullptr;  
}

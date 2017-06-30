void remove_middle(){
    if(head->next != nullptr && head->next->next != nullptr){
        Node *current = head;
        Node *a = head;
        int counter = 0;
        while(current->next != nullptr){
            current = current->next;
            ++counter;
        }
        for(int index=0; index<(counter/2)-1; ++index){
            a=a->next;
        }
        Node *temp = a->next;
        a->next = temp->next;
        delete temp;
        temp = nullptr;
    }
}
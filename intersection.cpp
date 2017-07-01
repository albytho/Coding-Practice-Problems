Node* intersection(Node *a, Node *b){
    Node *temp_a = a;
    Node *temp_b = b;
    int a_size = 0;
    int b_size = 0;
    
    while(temp_a != nullptr){
        ++a_size;
        temp_a = temp_a->next;
    }
    while(temp_b != nullptr){
        ++b_size;
        temp_b = temp_b->next;
    }
    
    if(a_size != b_size){
        if(a_size > b_size){
            int diff = a_size - b_size;
            for(int index=0; index<diff; ++index){
                a=a->next;
            }
        }
        else{
            int diff = b_size - a_size;
            for(int index=0; index<diff; ++index){
                b=b->next;
            }
        }
    }
    
    while(a != nullptr && b!= nullptr){
        if(a == b){
            return a;
        }
    }
    return nullptr;
}
void remove_dubs(){
    unordered_map<int, int> dict;
    Node *a = head;
    while(a != nullptr){
        ++dict[a->data];
        if(dict[a->data] == 2){
            Node *previouse_node = head;
            while(previouse_node->next != a){
                previouse_node = previouse_node->next;
            }
                
            previouse_node->next = a->next;
            --dict[a->data];
            delete a;
            a = previouse_node;
            previouse_node = nullptr;
        }
            
        if(a!=nullptr){
            a=a->next;
        }
    }
}

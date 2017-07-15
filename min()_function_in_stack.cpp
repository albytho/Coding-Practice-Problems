class stack{
public:
    Node *head = nullptr;
    Node *head_min = nullptr;
    int min_elem = INT_MAX;
    
    bool isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }
    
    void push(int elem){
        min_elem = std::min(min_elem,elem);
        Node *a = new Node(elem);
        Node *b = new Node(min_elem);
        
        if(isEmpty()){
            head = a;
            head_min = b;
        }
        else{
            a->next = head;
            head = a;
            
            b->next = head_min;
            head_min = b;
        }
    }
    
    void pop(){
        if(!isEmpty()){
            head = head->next;
            head_min = head_min->next;
        }
    }
    
    int top(){
        return head->val;
    }
    
    int min(){
        return head_min->val;
    }
};
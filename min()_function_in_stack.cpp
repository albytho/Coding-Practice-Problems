//This method uses O(1) speed and O(n) extra space

//The idea is that you as you push elements into the main stack, you
//keep track of the minimum element so far.  Every time you push an elemnt
//into the main stack, you push the mininum element so far into the min stack.
//If you push a new value into the main stack that is lower than the minimum element
//so far, than you make that the new min_element

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
        //If a smaller min_element is found, make that the new min_element
        min_elem = std::min(min_elem,elem);
        Node *a = new Node(elem);
        Node *b = new Node(min_elem);
        
        //You continually keep pushing whatever you have as the min_element into the min_stack every time you
        //push something into the main stack
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

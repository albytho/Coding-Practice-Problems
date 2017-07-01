void list_sum(Node *a, Node *b){
    int carry = 0;
    int sum = 0;
    stack<int> s;
    
    //Iterates through both lists at the same time until one of them ends
    while(a!=nullptr && b!=nullptr){
        sum = a->data + b->data + carry;
        carry = int(sum/10);
        
        //If the digits are both the last digit in the sequence, put the whole
        //sum in there instead of just the mod 10 of it
        if(a->next == nullptr && b->next == nullptr){
            s.push(sum);
        }
        else{
           s.push(sum%10);
        }
        
        //Go to the next locations in the linked lists
        a=a->next;
        b=b->next;
    }
    
    //If linked list "a" has more digits than "b", then put the remainder of "a"s
    //digits into the list
    if(a != nullptr){
        while(a!=nullptr){
            s.push(a->data+carry);
            a=a->next;
            carry=0;
        }
    }
    
    //The same as above but for the case that linked list "b" has more digits
    else if(b != nullptr){
        while(b!=nullptr){
            s.push(b->data+carry);
            b=b->next;
            carry=0;
        }
    }
    
    //Get the digits in the form of an actual number;
    sum = 0;
    while(!s.empty()){
        sum = sum*10+s.top();
        s.pop();
    }
    
    //Put each of the digits in the form of a linked list
    Node *result = new Node(sum%10);
    Node *original = result;
    sum = sum/10;
    while(sum!=0){
        result->next = new Node(sum%10);
        sum=sum/10;
        result=result->next;
    }
    
    
    while(original!=nullptr){
        cout<<original->data<<endl;
        original=original->next;
    }
}
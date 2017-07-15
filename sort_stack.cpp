void sort_stack(stack<double> &original){
    stack<double> new_one;
    while(!original.empty()){
        new_one.push(original.top());
        original.pop();
    }
    
    int curr;
    while(!new_one.empty()){
        curr = new_one.top();
        new_one.pop();
        while(!original.empty() && curr<original.top()){
            new_one.push(original.top());
            original.pop();
        }
        original.push(curr);
    }
}
class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min=val;
        }
        else{
            if(val >= min) st.push(val);
            else{
                st.push(2LL*val-min);
                min=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
            long long n=st.top();
            st.pop();
            if(n < min){
                min = 2*min-n;
            }
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        else{
            long long x=st.top();
            if(x>=min) return x;
            else return min;
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
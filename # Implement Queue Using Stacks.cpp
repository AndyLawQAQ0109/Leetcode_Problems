class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        s1 = stack<int>();
        s2 = stack<int>();
    }
    
    void push(int x) {
        s1.push(x);
        s2.push(x);
    }
    
    int pop() {
        if(s1.empty())
            return -1;

        int tmp = -1;
        int size = 0;
        while(!s1.empty()){           
            s2.push(s1.top());
            s1.pop();
            size++;
        }
        tmp = s2.top();
        s2.pop();
        size--;
        while(size > 0){
            int n_top = s2.top();
            s1.push(n_top);
            s2.pop();
            size--;
        }
        s2 = s1;
        return tmp;
    }
    
    int peek() {
        if(s1.empty())
            return -1;
        int tmp;
        while(!s1.empty()){
            tmp = s1.top();
            s1.pop();
        }
        s1 = s2;
        return tmp;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

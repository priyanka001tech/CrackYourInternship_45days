class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int p;
        if(!s2.empty()){
            p=s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
                int s=s1.top();
                s1.pop();
                s2.push(s);
            }
            p=s2.top();
            s2.pop();
        }
        return p;
    }
    
    int peek() {
        int p;
        if(!s2.empty()){
             p=s2.top();
        }
        else{
            while(!s1.empty()){
                int s=s1.top();
                s1.pop();
                s2.push(s);
            }
            p=s2.top();
        }
        return p;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

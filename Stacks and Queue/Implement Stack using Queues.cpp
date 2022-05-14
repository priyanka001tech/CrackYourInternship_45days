class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int x=q1.front();
            q1.pop();
            q2.push(x);
        }
        while(!q2.empty()){
            int x=q2.front();
            q2.pop();
            q1.push(x);
        }
    }
    
    int pop() {
        int y=q1.front();
        q1.pop();
        return y;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

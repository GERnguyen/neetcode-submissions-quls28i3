class MinStack {
private:
    vector<int> *Stack;
    int Min;
public:
    MinStack() {
        Stack = new vector<int>;
    }
    
    void push(int val) {
        Stack -> push_back(val);
    }
    
    void pop() {
        Stack -> pop_back();
    }
    
    int top() {
        return (*Stack)[Stack -> size() - 1];
    }
    
    int getMin() {
        return *min_element(Stack -> begin(), Stack -> end());
    }
};

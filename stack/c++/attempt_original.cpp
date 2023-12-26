#include <iostream>
#define MAX 10

class Stack {
private:
    int data[MAX];
    int top = 0; // index of top most element

public:
    Stack() {}

    int push(int data){
        std::cout << "Pushing " << data << " To the Stack" << std::endl;
        this->data[this->top] = data;
        this->top = this->top + 1;
        return data; 
    }
    void printTop(){
        std::cout << "Top index is : "<<this->top << std::endl;
    }
    int pop() {
        int original = this->data[this->top - 1];
        std::cout << "Popping " << original << " From the Stack" << std::endl;
        this->data[this->top] = 0;
        this->top = this->top - 1 ;
        return original;
    }
    void printStack() {
        std::cout << "Printing Stack! "<< this->top  << std::endl;
        for(int i = 0 ;i<top ; ++i){
            std::cout << "| " << data[i] << " |" <<std::endl;
        }
        std::cout << "Note : Stack is in opposite order" << std::endl;
    }
    bool isEmpty() { return this->top == -1; }
};

int main() { 
    Stack stack;
    stack.push(1);
    stack.printStack();
    stack.pop();
    stack.push(21);
    stack.push(17);
    stack.printStack();
}
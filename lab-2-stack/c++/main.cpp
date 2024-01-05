#include <iostream>
#define MAX 20

class Stack {
private:
    int data[MAX];
    int top = -1 ;

public:
    Stack() {}

    int push(int data){
        std::cout << (this->top +1 > MAX ) << std::endl;
        if ( (top + 1) >= MAX ){
            throw std::overflow_error("StackOverflow");
        }
        std::cout << "Pushing " << data << " To the Stack" << std::endl;
        this->top = this->top + 1;
        this->data[this->top ] = data;
        this->printStack();
        return data; 
    }
    void printTop(){
        std::cout << "Top is : "<<this->top << std::endl;
    }
    int pop() {
        if (this->top  == -1 ){
            throw std::underflow_error("StackUnderflow");
        }
        int original = this->data[this->top];
        std::cout << "Popping " << original << " From the Stack" << std::endl;
        this->data[this->top] = 0;
        this->top = this->top - 1 ;
        this->printStack();
        return original;
    }
    void printStack() {
        std::cout << "Printing Stack! "<< this->top  << std::endl;
        for(int i = 0 ;i<=top ; ++i){
            std::cout << "| " << data[top - i] << " |" <<std::endl;
        }
    }
    bool isEmpty() { return this->top == -1; }
    bool isFull(){ return top +1 >= MAX; }

    Stack initStack(){
        return *this;   
    }
};

int main() { 
    Stack stack;
    stack.push(21);
    stack.push(43);
    stack.pop();
    stack.printStack();
}
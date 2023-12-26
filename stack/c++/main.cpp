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
        if ( (top + 2) > MAX ){
            throw std::overflow_error("StackOverflow");
        }
        std::cout << "Pushing " << data << " To the Stack" << std::endl;
        this->top = this->top + 1;
        this->data[this->top ] = data;
        return data; 
    }
    void printTop(){
        std::cout << "Top is : "<<this->top << std::endl;
    }
    int pop() {
        if (this->top -1  < -1 ){
            throw std::underflow_error("StackUnderflow");
        }
        int original = this->data[this->top];
        std::cout << "Popping " << original << " From the Stack" << std::endl;
        this->data[this->top] = 0;
        this->top = this->top - 1 ;
        return original;
    }
    void printStack() {
        std::cout << "Printing Stack! "<< this->top  << std::endl;
        for(int i = 0 ;i<=top ; ++i){
            std::cout << "| " << data[top - i] << " |" <<std::endl;
        }
    }
    bool isEmpty() { return this->top == -1; }
};

int main() { 
    Stack stack;
    stack.pop();
}
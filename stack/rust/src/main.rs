#[derive(Debug)]
pub struct Stack<T> {
    items: Vec<T>,
}

impl<T> Stack<T> {
    // Creates a new empty stack
    pub fn new() -> Stack<T> {
        Stack { items: Vec::new() }
    }

    // Pushes an item onto the stack
    pub fn push(&mut self, item: T) {
        self.items.push(item);
    }

    // Pops an item from the stack, returning an Option<T>
    pub fn pop(&mut self) -> Option<T> {
        self.items.pop()
    }

    // Peeks at the top item of the stack without removing it, returning an Option<&T>
    pub fn peek(&self) -> Option<&T> {
        self.items.last()
    }

    // Checks if the stack is empty
    pub fn is_empty(&self) -> bool {
        self.items.is_empty()
    }

    // Returns the number of elements in the stack
    pub fn len(&self) -> usize {
        self.items.len()
    }
}

fn main() {
    // Example usage
    let mut stack = Stack::new();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    println!("Stack: {:?}", stack);

    while let Some(top) = stack.pop() {
        println!("Popped: {}", top);
    }
}

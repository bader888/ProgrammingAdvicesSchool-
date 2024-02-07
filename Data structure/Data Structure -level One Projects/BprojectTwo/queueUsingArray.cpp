// #include <iostream>

// class Queue
// {
// private:
//     int *arr;
//     int front;
//     int rear;
//     int capacity;
//     int size;

// public:
//     Queue(int capacity)
//     {
//         this->capacity = capacity;
//         arr = new int[capacity];
//         front = 0;
//         rear = -1;
//         size = 0;
//     }

//     ~Queue()
//     {
//         delete[] arr;
//     }

//     bool isEmpty()
//     {
//         return size == 0;
//     }

//     bool isFull()
//     {
//         return (size == capacity);
//     }

//     void enqueue(int value)
//     {
//         if (isFull())
//         {
//             std::cout << "Queue is full. Cannot enqueue." << std::endl;
//             return;
//         }
        
//         rear = (rear + 1) % capacity;
//         arr[rear] = value;
//         size++;
//     }

//     void dequeue()
//     {
//         if (isEmpty())
//         {
//             std::cout << "Queue is empty. Cannot dequeue." << std::endl;
//             return;
//         }

//         front = (front + 1) % capacity;
//         size--;
//     }

//     int frontValue()
//     {
//         if (isEmpty())
//         {
//             std::cout << "Queue is empty. No front value." << std::endl;
//             return -1;
//         }

//         return arr[front];
//     }

//     int rearValue()
//     {
//         if (isEmpty())
//         {
//             std::cout << "Queue is empty. No rear value." << std::endl;
//             return -1;
//         }

//         return arr[rear];
//     }
// };

// int main()
// {
//     Queue MyQueue(5);

//     MyQueue.enqueue(1);
//     MyQueue.enqueue(2);
//     MyQueue.enqueue(3);
//     MyQueue.enqueue(4);
//     MyQueue.enqueue(5);

//     std::cout << "Front value: " << MyQueue.frontValue() << std::endl;
//     std::cout << "Rear value: " << MyQueue.rearValue() << std::endl;

//     MyQueue.dequeue();
//     MyQueue.dequeue();

//     std::cout << "Front value: " << MyQueue.frontValue() << std::endl;
//     std::cout << "Rear value: " << MyQueue.rearValue() << std::endl;

//     return 0;
// };
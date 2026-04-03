#include <stdio.h>
#define N 5 // Define the size of the queue

int queue[N];
int front = -1; // Initialize front to -1 indicating the queue is empty
int rear = -1;  // Initialize rear to -1 indicating the queue is empty

// Function to enqueue an element in the circular queue
void enqueue(int x) {
    if (front == -1 && rear == -1) {
        // If the queue is empty
        front = 0;
        rear = 0;
        queue[rear] = x; // Insert the first element
    } else if ((rear + 1) % N == front) {
        // If the queue is full
        printf("Queue is full\n");
    } else {
        // Normal case: insert element and update rear
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (front == -1) {
        // If the queue is empty
        printf("Queue is empty\n");
    } else if (front == rear) {
        // If there is only one element left in the queue
        printf("Dequeued: %d\n", queue[front]);
        front = -1;
        rear = -1; // Reset queue to empty state
    } else {
        // Normal case: remove element and update front
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

// Function to display the elements in the queue
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5); // Queue should be full now
    display();

    dequeue();
    dequeue();
    display();

    enqueue(6);
    display();

    dequeue();
    dequeue();
    dequeue();
    display();

    return 0;
}

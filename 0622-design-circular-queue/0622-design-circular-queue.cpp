
class MyCircularQueue {
    vector<int> arr;
    int front, rear, count, capacity;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : arr[front];
    }

    int Rear() {
        return isEmpty() ? -1 : arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

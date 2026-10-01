class MyCircularQueue {
public:
int *arr;
int currSize,capacity;
int front,rear;

    MyCircularQueue(int k) {
        capacity=k;
      
       arr=new int[k];
       currSize=0;
       front=0;
       rear=-1; 
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rear=(rear+1)%capacity;
        arr[rear]=value;
        currSize++;

        return true;

    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front=(front+1)%capacity;
        currSize--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
     if (isEmpty()) return -1;     
   return arr[rear];
    }
    
    bool isEmpty() {
        if(currSize==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(currSize==capacity){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
class DynamicArray {
private:
    int* Array;
    int capacity;
    int size = 0;
public:

    DynamicArray(int Capacity) {
        Array = new int[Capacity];
        capacity = Capacity;   
    }

    int get(int i) {
        return Array[i];
    }

    void set(int i, int n) {
        Array[i] = n;
    }

    void pushback(int n) {
        int newCapacity = (size == capacity) ? (capacity*2) : capacity;
        int* newArray = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = Array[i];
        }
        newArray[size] = n;
        size++;
        Array = newArray;
        capacity = newCapacity;
    }

    int popback() {
        int* newArray = new int[capacity];
        for (int i = 0; i < size - 1; i++) {
            newArray[i] = Array[i];
        }
       
        int end = Array[size - 1];
        Array = newArray;
        size--;
        return end;
    }

    void resize() {
        capacity *= 2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

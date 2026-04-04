class DynamicArray {
private:
    int* Array;
    int capacity;
    int size = 0;

    void resize() {
        capacity*= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i < size; i++) newArray[i] = Array[i];
        delete[] Array;
        Array = newArray;
    }
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
        if (size == capacity) resize();
        Array[size] = n;
        size++;
    }

    int popback() {
        size--;
        return Array[size];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};

#include <stdexcept>
using std::range_error;
using std::invalid_argument;

template <typename E>
class List{
private:
    int end;
    int capacity;
    E *arr;

    void expand() {
        // Create new array of double the size of the previous array to
        // avoid the cost of the operation.
        E *newArr = new E[capacity*2];
        for (int i = 0; i <= end; i++) {
            newArr[i] = arr[i];
        }

        // Delete old array and set it equal to the address of the new one.
        if (arr != nullptr)
            delete[] arr;
        arr = newArr;
        capacity = capacity*2;
    }

public:
    List(int capacity = 100){
        if (capacity < 1)
            throw invalid_argument("length < 1");
        this->capacity = capacity;
        end = -1;
        arr = new E[capacity];
    }

    ~List() { delete[] arr; }

    void insert(E value, int index) {
        if (index > end + 1 || index < 0)
            throw range_error("index out of range");
        if (end+1 == capacity)
            // Exand the array if it is full.
            expand();
        for (int i = end; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        end++;
    }

    void insert(E value) {
        // If no index is passed, insert at the end.
        insert(value, end+1);
    }

    void remove(int index) {
        if (index > end || index < 0)
            throw range_error("index out of range");
        for (int i = index; i < end; i++) {
            arr[i] = arr[i+1];
        }
        end--;
    }

    void remove() {
        // If no index is passed, remove at the end.
        remove(end);
    }

    E& retrieve(int index) {
        if (index > end || index < 0)
            throw range_error("index out of range");
        return arr[index];
    }

    E& operator[](int index){
        return retrieve(index);
    }

    bool is_empty() { return end == -1; }

    int length() { return end + 1; }

    int size() { return capacity; }

};
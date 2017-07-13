#include <stdexcept>
using std::out_of_range;
using std::invalid_argument;


template <typename E>
class List{
private:
    int end;  // Keeps track of the index where the end of the list is.
    int capacity;  // Keeps track of how many allocated spaces there are
                   // in the array.
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

    bool is_empty() {
        // Returns true if the list is empty. Returns false if
        // the list is not empty.

        return end == -1;
    }

    int length() {
        // Returns the length of the list.

        return end + 1;
    }

    int size() {
        // Returns how many spaces have been allocated for the list.

        return capacity;
    }

    void insert(E value, int index) {
        // Insert data into the list. If no index is specified
        // then the data will be inserted at the end of the list.

        if (index > end + 1 || index < 0)
            throw out_of_range("index out of range");
        if (end+1 == capacity)
            // Expand the array if it is full.
            expand();
        for (int i = end; i >= index; i--) {
            arr[i+1] = arr[i];
        }
        arr[index] = value;
        end++;
    }

    void insert(E value) {
        // Insert a value at the end of the list, unless an index
        // is specified; in that case data will be inserted at
        // that index.

        insert(value, end+1);
    }

    void remove(int index) {
        // Remove data from the list. If no index is specified
        // then the data will be removed from the end of the list.

        if (index > end || index < 0)
            throw out_of_range("index out of range");
        for (int i = index; i < end; i++) {
            arr[i] = arr[i+1];
        }
        end--;
    }

    void remove() {
        // Remove data from the end of the list, unless an index
        // is specified; in that case data will be removed at
        // that index.

        remove(end);
    }

    E& retrieve(int index) {
        // Retrieves data located at the specified index.

        if (index > end || index < 0)
            throw out_of_range("index out of range");
        return arr[index];
    }

    E& operator[](int index){
        // Overloads [] for convention.

        return retrieve(index);
    }

};

#include <iostream>

template<typename T>
class DynamicArray{
    private:
        int size = 0;
        int capacity = 10;
    public:
        T* array;
        //constructors
        DynamicArray(){
            array = new T[this->capacity];
        }
        DynamicArray(const int capacity){
            if(capacity > 0) this->capacity = capacity;
            array = new T[this->capacity];
        }
        ~DynamicArray(){
            delete this->array;
            array = nullptr;
        }
        //getters
        int Capacity() const{
            return this->capacity;
        }
        int Size() const{
            return this->size;
        }
        //mehtods
        void add(T obj){
            if(this->size >= this->capacity){
                Grow();
            }
            array[size] = obj;
            size++;
        }
        void Insert(int index, T obj){
            if(this->size >= this->capacity){
                Grow();
            }
            for(int i = this->size; i > index; i--){
                array[i] = array[i - 1];
            }
            array[index] = obj;
            size++;
        }        
        void Delete(T obj){
            for(int i = 0; i < this->size; i++){
                if(this->array[i] == obj){
                    for(int j = 0; j < this->size - i - 1; j++){
                        array[i + j] = array[i + j + 1];
                    }
                    array[this->size - 1] = 0;
                    this->size--;
                    if(size <= (int)(this->capacity/3)){
                        Shrink();
                    }
                    return;
                }
            }
        } 
        int LinearSearch(const T obj){
            for(int i = 0; i < this->size; i++){
                if(this->array[i] == obj){
                    return i;
                }
            }
            return -1;
        }
        int BinarySearch(const T obj){
            int min = 0;
            int max = this->size - 1;
            int middle;
            while (true)
            {
                middle = (int) min + (max - min)/2;
                if(this->array[middle] < obj){
                    min = middle + 1;
                }
                else if(this->array[middle] > obj){
                    max = middle - 1;
                }
                else return middle;
            }
            return -1;
        }
        void BubbleSort(){
            T temp;
            for(int i = 0; i < this->size - 1; i++){
                for(int j = 0; j < this->size - i - 1; j++){
                    if(this->array[j] > this->array[j + 1]){
                        temp = array[j];
                        array[j] = array[j+1];
                        array[j + 1] = temp;
                    }
                }
            }
        }
        void Grow(){
            int newCapacity = (int)this->capacity * 2;
            T* newArray = new T[newCapacity];
            for(int i = 0; i < this->size; i++){
                newArray[i] = this->array[i];
            }
            delete[] this->array;
            array = newArray;
            this->capacity = newCapacity;
        }
        void Shrink(){
            int newCapacity = (int)this->capacity / 2;
            T* newArray = new T[newCapacity];
            for(int i = 0; i < this->size; i++){
                newArray[i] = this->array[i];
            }
            delete[] this->array;
            array = newArray;
            this->capacity = newCapacity;
        }
        bool Empty(){
            return this->size == 0;
        }
};

template<typename V>
std::ostream& operator<<(std::ostream& cout, const DynamicArray<V>& darray){
    if(darray.Size() == 0){
        return cout<<"ZERO OBJECTS IN COLLECTION";
    }
    for(int i = 0; i < darray.Size(); i++){
        if(i == darray.Size() - 1){
            cout<<"[index "<<i<<": "<<darray.array[i]<<"].";
            continue;
        }
        cout<<"[index "<<i<<": "<<darray.array[i]<<"], ";
    }
    return cout;
}

int main(){
    DynamicArray<double> myNums(5);
    myNums.add(13.6);
    myNums.add(123.7);
    myNums.Insert(0, 3.6);
    myNums.add(14.6);
    myNums.add(16.78);
    myNums.BubbleSort();
    myNums.Insert(0, 1.345);
    std::cout<<"Print dynamic array:"<<std::endl;
    std::cout<<myNums<<std::endl;
    std::cout<<"capacity array: "<<myNums.Capacity()<<std::endl;
    std::cout<<"size of array: "<<myNums.Size()<<std::endl;
    std::cout<<"dynamic array is empty? "<<myNums.Empty()<<std::endl;
    std::cout<<"Linear search \"123.7\": "<<myNums.LinearSearch(123.7)<<std::endl;
    std::cout<<"Binary search \"123.7\": "<<myNums.BinarySearch(123.7)<<std::endl;
    std::cout<<"------------------------------------------------------------------\n";
    myNums.Delete(13.6);
    myNums.Delete(123.7);
    myNums.Delete(3.6);
    myNums.Delete(14.6);
    std::cout<<"Print dynamic array:"<<std::endl;
    std::cout<<myNums<<std::endl;
    std::cout<<"capacity array: "<<myNums.Capacity()<<std::endl;
    std::cout<<"size of array: "<<myNums.Size()<<std::endl;
    std::cout<<"dynamic array is empty? "<<myNums.Empty()<<std::endl;
    std::cout<<"Linear search if \"123.7\": "<<myNums.LinearSearch(123.7)<<std::endl;

    return 0;
}
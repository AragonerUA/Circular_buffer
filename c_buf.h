#pragma once
#include <iterator>
template<class T> class circular_buff;
template<class T> class Iterator;

template<class T>
        T minimum(T a, T b) {
            return (((a)<(b))?(a):(b));
        }
//Класс самого буффера
template<class T>
class circular_buff {
public:
    unsigned int size;
    T *array;
    unsigned int head = 0;
    unsigned int tail = 0;
    unsigned int counter = 0;
    unsigned int iter_index = head;

    explicit circular_buff(int buf_size);
    ~circular_buff() = default;
    void push_end(T elem); // Вставка в конец
    void push_begin(T elem); // Вставка в начало
    void add_iterator(int elementh); // Вставка в произвольное место по итератору
    void pop_iterator(); // Удаление из произвольного места по итератору
    void print_buffer(); // Вывод буффера
    void change_capacity(unsigned new_size); // Изменение размера буффера
    T pop_begin(); // удаление из начала
    T access_begin(); // доступ в начало
    T pop_end(); // удаление из конца
    T access_end(); // доступ в конец
    T& operator[](unsigned int index); // перегрузка оператора
    Iterator<T> begin();
    Iterator<T> end();
};

//Класс random_access_iterator с иерархией перегрузок операторов
template<class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>{
public:
    T* index_position;
    T* array;
    T* start;
    T* end;
    unsigned int size;
    Iterator(T* pos, T* arr, unsigned int arr_size, T* begin, T* finish);
    explicit Iterator(T* pos);
    ~Iterator() = default;
    T& operator*() {
        return *index_position;
    };
    T* operator->() {
        return index_position;
    }
    Iterator& operator++(){
        ++index_position;
        return *this;
    }
    Iterator operator++(int) { //NOLINT
        Iterator tmp(*this);
        operator++();
        return tmp;
    }
    Iterator& operator--() {
        index_position--;
        return *this;
    }
    Iterator operator--(int) { //NOLINT
        Iterator tmp(*this);
        operator--();
        return *this;
    }
    Iterator operator-(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        return Iterator(index_position - it);
    }
    bool operator==(const Iterator& next) const {
        return index_position == next.index_position;
    }
    bool operator!=(const Iterator& next) const {
        return index_position != next.index_position;
    }
    typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const Iterator<T>& it) {
        return index_position - it.index_position;
    }
    typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator+(Iterator& it) {
        return index_position + it.index_position;
    }
    Iterator operator+(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        return Iterator(index_position + it);
    }
    bool operator<(const Iterator& next) {
        return index_position < next.index_position;
    }
    bool operator<(T* p) {
        return index_position < p;
    }
    bool operator>(T* p) {
        return index_position > p;
    }
    bool operator<=(T* p) {
        return index_position <= p;
    }
    bool operator>=(T* p) {
        return index_position >= p;
    }
    bool operator<=(const Iterator& next) {
        return index_position <= next.index_position;
    }
    bool operator>(const Iterator& next) {
        return index_position > next.index_position;
    }
    bool operator>=(const Iterator& next) {
        return index_position >= next.index_position;
    }
    Iterator& operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        index_position += it;
        return *this;
    }
    Iterator& operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        index_position -= it;
        return *this;
    }
    Iterator& operator= (const Iterator& it) {
        index_position = it.index_position;
        return *this;
    }
    Iterator& operator=(T* it) {
        index_position = it;
        return *this;
    }
};

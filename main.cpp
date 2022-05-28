#include <iostream>
#include <algorithm>
#include "c_buf.h"
#include "c_buf.cpp"

int main() {
    circular_buff<int> MyBuffer(10);

    MyBuffer.push_end(10);
    MyBuffer.push_end(-41);
    MyBuffer.push_end(327);
    MyBuffer.push_end(-983);
    MyBuffer.push_end(9);
    MyBuffer.push_end(-1);
    MyBuffer.push_end(15);

    MyBuffer.print_buffer();

    std::cout << "Сортируем буффер std сортом:" << std::endl;
    std::sort(MyBuffer.begin(), MyBuffer.end());
    MyBuffer.print_buffer();

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Переполнение:" << std::endl;
    for (int i = 0; i < 14; i++) {
        MyBuffer.push_end(1 + i*5);
        MyBuffer.print_buffer();
    }
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Проверка вставки в начало:" << std::endl;
    MyBuffer.push_begin(999);
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Удаление из начала:" << std::endl;
    MyBuffer.pop_begin();
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Первый элемент буффера(проверка доступа в начало):" << std::endl;
    std::cout << MyBuffer.access_begin() << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Удаление из конца:" << std::endl;
    MyBuffer.pop_end();
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Последний элемент буффера(проверка доступа в конец):" << std::endl;
    std::cout << MyBuffer.access_end() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    //Доступ по итератору
    std::cout << "Доступ по итератору в рандомное место:" << std::endl;
    MyBuffer.add_iterator(555);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(777);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(999);
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(12345);
    MyBuffer.print_buffer();
    MyBuffer.pop_iterator();
    MyBuffer.print_buffer();
    MyBuffer.pop_iterator();
    MyBuffer.print_buffer();
    MyBuffer.add_iterator(987);
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    //Изменяем размер
    std::cout << "Меняем размер:" << std::endl;
    MyBuffer.change_capacity(12);
    for (int i = 8; i < 12; i++) {
        MyBuffer.push_end(i);
    }
    MyBuffer.print_buffer();
    std::cout << "Пытаемся добавить элементы в буффер сверх его размера:" << std::endl;
    MyBuffer.push_end(12);
    MyBuffer.print_buffer();
    MyBuffer.push_end(13);
    MyBuffer.print_buffer();
    MyBuffer.push_end(14);
    MyBuffer.print_buffer();
    MyBuffer.push_end(15);
    MyBuffer.print_buffer();
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Добавляем элементы в начало:" << std::endl;
    MyBuffer.push_begin(989);
    MyBuffer.print_buffer();
    MyBuffer.push_begin(898);
    MyBuffer.print_buffer();
}

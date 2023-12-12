#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

class ByteBuffer {
public:
    // Конструктор, инициализирующий буфер с указанным размером
    ByteBuffer(size_t size) : size(size) {
        data = static_cast<uint8_t*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANonymous, -1, 0));

        if (data == MAP_FAILED) {
            perror("Failed to allocate memory using mmap");
            exit(EXIT_FAILURE);
        }
    }

    // Деструктор, освобождающий выделенную память
    ~ByteBuffer() {
        if (munmap(data, size) == -1) {
            perror("Failed to deallocate memory using munmap");
            exit(EXIT_FAILURE);
        }
    }

    // Метод для получения указателя на данные
    uint8_t* getData() const {
        return data;
    }

    // Метод для получения размера буфера
    size_t getSize() const {
        return size;
    }

private:
    uint8_t* data;  // Указатель на данные
    size_t size;    // Размер буфера
};

int main() {
    // Пример использования
    size_t bufferSize = 1024;  // Размер буфера, например, 1 килобайт

    ByteBuffer buffer(bufferSize);

    // Используйте buffer.getData() для доступа к данным
    // Используйте buffer.getSize() для получения размера буфера

    std::cout << "ByteBuffer created with size: " << buffer.getSize() << " bytes" << std::endl;

    return 0;
}


#include <iostream>
#include <cstring>
#include <sys/mman.h>
#include <unistd.h>

class ByteBuffer {
public:
    // Конструктор по умолчанию
    ByteBuffer() : data(nullptr), size(0) {}

    // Конструктор, инициализирующий буфер с указанным размером
    explicit ByteBuffer(size_t size) : size(size) {
        data = static_cast<uint8_t*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0));

        if (data == MAP_FAILED) {
            perror("Failed to allocate memory using mmap");
            exit(EXIT_FAILURE);
        }
    }

    // Конструктор перемещения
    ByteBuffer(ByteBuffer&& other) noexcept : data(other.data), size(other.size) {
        // Не забываем обнулить данные у временного объекта
        other.data = nullptr;
        other.size = 0;
    }

    // Оператор перемещения
    ByteBuffer& operator=(ByteBuffer&& other) noexcept {
        if (this != &other) {
            // Освобождаем текущие ресурсы
            if (data != nullptr) {
                if (munmap(data, size) == -1) {
                    perror("Failed to deallocate memory using munmap");
                    exit(EXIT_FAILURE);
                }
            }

            // Перемещаем ресурсы
            data = other.data;
            size = other.size;

            // Обнуляем данные у временного объекта
            other.data = nullptr;
            other.size = 0;
        }

        return *this;
    }

    // Деструктор
    ~ByteBuffer() {
        if (data != nullptr) {
            if (munmap(data, size) == -1) {
                perror("Failed to deallocate memory using munmap");
                exit(EXIT_FAILURE);
            }
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

    // Метод для изменения размера выделенной области памяти
    void resize(size_t newSize) {
        uint8_t* newData = static_cast<uint8_t*>(mremap(data, size, newSize, MREMAP_MAYMOVE));

        if (newData == MAP_FAILED) {
            perror("Failed to resize memory using mremap");
            exit(EXIT_FAILURE);
        }

        data = newData;
        size = newSize;
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

    // Изменение размера буфера
    size_t newBufferSize = 2048;
    buffer.resize(newBufferSize);

    std::cout << "ByteBuffer resized to: " << buffer.getSize() << " bytes" << std::endl;

    return 0;
}


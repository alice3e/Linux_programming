#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

void check(int result, const char* message) {
    if (result == -1) {
        std::cerr << message << ": " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

class File {
private:
    int fd_;
public:
    File(const char* filename) {
        fd_ = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        check(fd_, "open");
    }

    ~File() {
        close(fd_);
    }

    void write(const char* data, size_t size) {
        ssize_t result = ::write(fd_, data, size);
        check(result, "write");
    }

    void read(char* buffer, size_t size) {
        ssize_t result = ::read(fd_, buffer, size);
        check(result, "read");
    }

    off_t tell() { // возвращает текущую позицию в файле, используя функцию lseek с флагом SEEK_CUR
        off_t result = lseek(fd_, 0, SEEK_CUR);
        check(result, "lseek");
        return result;
    }

    void seek(off_t offset) { // Метод seek устанавливает позицию в файле, используя функцию lseek с флагом SEEK_SET и смещение
        off_t result = lseek(fd_, offset, SEEK_SET);
        check(result, "lseek");
    }

    File(const File& other) { // Конструктор копирования создает новый экземпляр класса File, который является копией переданного объекта
        if (other.fd_ != -1) {
            fd_ = dup(other.fd_);
            check(fd_, "dup");
        } else {
            fd_ = -1;
        }
    }

    File& operator=(const File& other) { // Оператор присваивания выполняет аналогичные действия для копирования объекта, но только после закрытия файла, связанного с текущим объектом.
        if (this != &other) {
            if (fd_ != -1) {
                close(fd_);
            }
            if (other.fd_ != -1) {
                fd_ = dup(other.fd_);
                check(fd_, "dup");
            } else {
                fd_ = -1;
            }
        }
        return *this;
    }

    File(File&& other) noexcept { // Конструктор перемещения переносит файловый дескриптор из другого объекта и устанавливает файловый дескриптор этого объекта на -1
        fd_ = other.fd_;
        other.fd_ = -1;
    }

    File& operator=(File&& other) noexcept { // Оператор перемещения выполняет аналогичные действия конструктору перемещения, но только после закрытия файла, связанного с текущим объектом.
        if (this != &other) {
            if (fd_ != -1) {
                close(fd_);
            }
            fd_ = other.fd_;
            other.fd_ = -1;
        }
        return *this;
    }
};

int main() {
    File file("test.txt");

    file.write("Helloaa, World!", 14);

    char buffer[14];
    file.seek(0);
    file.read(buffer, 14);
    buffer[13] = '\0';
    std::cout << buffer << std::endl;

    return 0;
}


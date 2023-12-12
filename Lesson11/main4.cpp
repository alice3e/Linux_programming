#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

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

    off_t tell() {
        off_t result = lseek(fd_, 0, SEEK_CUR);
        check(result, "lseek");
        return result;
    }

    void seek(off_t offset) {
        off_t result = lseek(fd_, offset, SEEK_SET);
        check(result, "lseek");
    }

    File(const File& other) {
        if (other.fd_ != -1) {
            fd_ = dup(other.fd_);
            check(fd_, "dup");
        } else {
            fd_ = -1;
        }
    }

    File& operator=(const File& other) {
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

    File(File&& other) noexcept {
        fd_ = other.fd_;
        other.fd_ = -1;
    }

    File& operator=(File&& other) noexcept {
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

class ByteBuffer {
private:
    char* data_;
    size_t size_;
    File file_;

public:
    ByteBuffer(size_t size) : size_(size), data_(static_cast<char*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0))), file_("temp_file.bin") {
        check(reinterpret_cast<intptr_t>(data_), "mmap");
    }

    ByteBuffer(const char* filename) : file_(filename) {
        size_ = static_cast<size_t>(file_.tell());
        data_ = static_cast<char*>(mmap(nullptr, size_, PROT_READ | PROT_WRITE, MAP_PRIVATE, file_.tell(), 0));
        check(reinterpret_cast<intptr_t>(data_), "mmap");
    }

    ~ByteBuffer() {
        if (msync(data_, size_, MS_SYNC) == -1) {
            perror("Failed to sync memory to file");
            exit(EXIT_FAILURE);
        }

        if (munmap(data_, size_) == -1) {
            perror("Failed to deallocate memory using munmap");
            exit(EXIT_FAILURE);
        }
    }

    uint8_t* getData() const {
        return reinterpret_cast<uint8_t*>(data_);
    }

    size_t getSize() const {
        return size_;
    }
};

int main() {
    // Пример использования
    size_t bufferSize = 1024;  // Размер буфера, например, 1 килобайт

    ByteBuffer buffer(bufferSize);

    // Используйте buffer.getData() для доступа к данным
    // Используйте buffer.getSize() для получения размера буфера

    std::cout << "ByteBuffer created with size: " << buffer.getSize() << " bytes" << std::endl;

    // Пример использования конструктора из файла
    ByteBuffer fileBuffer("test.txt");

    // Используйте fileBuffer.getData() и fileBuffer.getSize() для работы с данными из файла

    return 0;
}


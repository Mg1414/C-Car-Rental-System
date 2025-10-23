#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class Resource {
public:
    Resource() : name_("default"), data_(new int(42)) {
        std::cout << "Resource '" << name_ << "' acquired (default)\n";
    }

    explicit Resource(std::string name) : name_(std::move(name)), data_(new int(0)) {
        std::cout << "Resource '" << name_ << "' acquired (custom)\n";
    }

    Resource(const Resource& other) : name_(other.name_ + " copy"), data_(new int(*other.data_)) {
        std::cout << "Resource '" << name_ << "' copied\n";
    }

    Resource(Resource&& other) noexcept : name_(std::move(other.name_)), data_(other.data_) {
        other.data_ = nullptr;
        std::cout << "Resource '" << name_ << "' moved\n";
    }

    Resource& operator=(const Resource& other) {
        if (this != &other) {
            Resource temp(other);
            swap(temp);
        }
        return *this;
    }

    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete data_;
            name_ = std::move(other.name_);
            data_ = other.data_;
            other.data_ = nullptr;
            std::cout << "Resource '" << name_ << "' move-assigned\n";
        }
        return *this;
    }

    ~Resource() {
        std::cout << "Resource '" << name_ << "' released\n";
        delete data_;
    }

    void swap(Resource& other) noexcept {
        std::swap(name_, other.name_);
        std::swap(data_, other.data_);
    }

private:
    std::string name_;
    int* data_;
};

class FileGuard {
public:
    explicit FileGuard(const std::string& path) : file_(path) {
        if (!file_.is_open()) {
            throw std::runtime_error("Failed to open file: " + path);
        }
        std::cout << "File opened: " << path << '\n';
    }

    ~FileGuard() {
        if (file_.is_open()) {
            std::cout << "File closed automatically\n";
        }
    }

    std::fstream& stream() { return file_; }

private:
    std::fstream file_;
};

int main() {
    Resource a;
    Resource b{"network"};
    Resource c = a;           // copy
    Resource d = std::move(b); // move

    c = d;                    // copy assignment
    d = Resource{"temporary"}; // move assignment

    try {
        FileGuard guard{"lesson03_temp.txt"};
        guard.stream() << "Writing to file using RAII" << std::endl;
    } catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }

    std::cout << "End of main -- destructors will run now\n";
}

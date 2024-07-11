#include <iostream>
#include <string>
#include <cctype>
bool is_palindrome(const std::string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (!std::isalpha(str[start])) {
        return is_palindrome(str, start + 1, end);
    } else if (!std::isalpha(str[end])) {
        return is_palindrome(str, start, end - 1);
    } else if (std::tolower(str[start]) != std::tolower(str[end])) {
        return false;
    } else {
        return is_palindrome(str, start + 1, end - 1);
    }
}
int main() {
    std::string line;
    int i = 1;
    while (true) {
        std::getline(std::cin, line);
        if (line.empty()) {
            std::cout << "true\n";
            break;
        }
        if (is_palindrome(line, 0, line.size() - 1)) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }
        ++i;
    }
    return 0;
}

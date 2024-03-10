#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

int FindFourthFromEndDotIndexRecursive(char* str, int len, int currentIndex, int dotCount) {
    if (currentIndex < 0) {
        return -1;
    }

    if (str[currentIndex] == '.') {
        ++dotCount;
        if (dotCount == 4) {
            return currentIndex;
        }
    }

    return FindFourthFromEndDotIndexRecursive(str, len, currentIndex - 1, dotCount);
}

void ReplaceDotsWithStarsRecursive(char* str, int len, int currentIndex) {
    if (currentIndex >= len) {
        return;
    }

    if (str[currentIndex] == '.') {
        str[currentIndex] = '*';
        str[currentIndex + 1] = '*';
    }

    ReplaceDotsWithStarsRecursive(str, len, currentIndex + 1);
}

int main() {
    SetConsoleOutputCP(1251);
    char str[101];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 100);
    int len = strlen(str);

    int fourthFromEndDotIndex = FindFourthFromEndDotIndexRecursive(str, len, len - 1, 0);
    if (fourthFromEndDotIndex != -1) {
        cout << "Місцезнаходження четвертої крапки від кінця: " << fourthFromEndDotIndex << endl;
    }
    else {
        cout << "Четвертої крапки від кінця не знайдено." << endl;
    }

    ReplaceDotsWithStarsRecursive(str, len, 0);
    cout << "Змінений рядок: " << str << endl;

    return 0;
}

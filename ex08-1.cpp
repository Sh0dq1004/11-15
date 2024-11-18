#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string line{ "1:05:12 2:07:34 3:19:22 4:33:50" };
    /* 空欄１　適切なstring stream(iss1, iss2)の定義*/
    std::istringstream iss1(line), iss2(line);


    int h, m, s;
    char c1, c2;

    //方法１：>>演算子を使用
    while (iss1>>h>>c1>>m>>c2>>s) {
        std::cout << h * 3600 + m * 60 + s << "\n";
    }

    //方法２：std::getline()を使用
    std::vector <int> seconds;
    for (std::string s; getline(iss2,s,' '); ) {
        std::istringstream iss(s);
        std::vector <int> v1;
        for (std::string s1; getline(iss,s1,':'); ) {
            v1.push_back(std::stoi(s1));
        }
        seconds.push_back(v1[0] * 3600 + v1[1] * 60 + v1[2]);
    }

    for (auto second : seconds) {
        std::cout << second << "\n";
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <cmath>

struct worker {
    std::string name = "unknown";
    std::string surname = "unknown";
    std::string date = "00:00:0000";
    int salary = 0;
};

bool correctInput(worker &w) {
    if (w.name.size() > 0 && w.surname.size() > 0 && w.salary > 0) {
        if (w.date.length() == 10 && w.date[2] == ':' && w.date[5] == ':' && w.date.substr(0, 2) > "00" && w.date.substr(0, 2) < "31" 
            && w.date.substr(3, 2) > "00" && w.date.substr(3, 2) < "12" && w.date.substr(6, 4) > "2000" 
            && w.date.substr(6, 4) < "2025") {
                return true;
            }
    }
    std::cout << "Incorrect input!" << std::endl;
    return false;
}

void list(std::ifstream &file) {
    std::string n;
    worker buff;
    while(true) {
        file >> n;
        if (n.length() == 0) {
            std::cout << "Salary list is empty!" << std::endl;
            break;
        }
        buff.name = n;
        if(file.eof())
            break;
        file >> buff.surname >> buff.date >> buff.salary;
        std::cout << buff.surname << " " << buff.name << " on date: " << buff.date << " got " 
            << buff.salary << " rubles" << std::endl;
    }
}

void add(std::ofstream &file) {
    worker employee;
    do {
        std::cin >> employee.name >> employee.surname >> employee.date >> employee.salary;
    } while(!correctInput(employee));
    file << employee.name << " " << employee.surname << " " << employee.date << " " << employee.salary << std::endl;
    // file.write((char*)&employee.name, sizeof(employee.name));
    // file.write((char*)&employee.surname, sizeof(employee.surname));
    // file.write((char*)&employee.date, sizeof(employee.date));
    // file.write((char*)&employee.salary, sizeof(employee.salary));
}

struct mathVector {
    float x, y;
};

mathVector addMathVector(mathVector first, mathVector second) {
    return {first.x + second.x, first.y + second.y};
}

mathVector subtractMathVector(mathVector first, mathVector second) {
    return {first.x - second.x, first.y - second.y};
}

void scaleMathVector(mathVector &vec, float num) {
    vec.x *= num;
    vec.y *= num;
}

float lengthMathVector(mathVector vec) {
    return std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

void normalizeMathVector (mathVector &vec) {
    float length = lengthMathVector(vec);
    vec.x /= length;
    vec.y /= length;
}


int main() {
    //21.5.1 salary list
    /*
    while(true) {
        std::string command;
        std::cout << "Command (list, add, quit):\n";
        std::cin >> command;
        if (command == "quit") {
            return 0;
        } else if (command == "list") {
            std::ifstream file("salary-list.txt");
            list(file);
            file.close();
        } else if (command == "add") {
            std::ofstream file("salary-list.txt", std::ios::app);
            add(file);
            file.close();
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
    */

    //21.5.3 math vector
    std::string command;
    while(true) {
        std::cout << "Command (add, subtract, scale, normalize, length, quit):" << std::endl;
        std::cin >> command;
        if (command == "quit")
            return 0;
        if (command == "add" || command == "subtract") {
            mathVector first;
            mathVector second;
            mathVector res;
            std::cout << "1st vector X & Y:" << std::endl;
            std::cin >> first.x >> first.y;
            std::cout << "2nd vector X & Y:" << std::endl;
            std::cin >> second.x >> second.y;
            if (command == "add") {
                res = addMathVector(first, second);
            } else {
                res = subtractMathVector(first, second);
            }
            std::cout << "Result vector x: " << res.x << " y: " << res.y << std::endl;
        } else if (command == "scale") {
            mathVector vec;
            float number;
            std::cout << "Vector X & Y:" << std::endl;
            std::cin >> vec.x >> vec.y;
            std::cout << "Number:" << std::endl;
            std::cin >> number;
            scaleMathVector(vec, number);
            std::cout << "Result vector x: " << vec.x << " y: " << vec.y << std::endl;
        } else if (command == "length") {
            mathVector vec;
            std::cout << "Vector X & Y:" << std::endl;
            std::cin >> vec.x >> vec.y;
            std::cout << "Vector length: " << lengthMathVector(vec) << std::endl;
        } else if (command == "normalize") {
            mathVector vec;
            std::cout << "Vector X & Y:" << std::endl;
            std::cin >> vec.x >> vec.y;
            normalizeMathVector(vec);
            std::cout << "Normalized vector x: " << vec.x << " y: " << vec.y 
                        << " length: " << lengthMathVector(vec) << std::endl;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }

    }

}
#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Основные функции базы данных
void addStudent(std::vector<Student>& database);
void displayStudents(const std::vector<Student>& database);
void editStudent(std::vector<Student>& database);

// Вспомогательные функции
int findStudentByName(const std::vector<Student>& database, const std::string& name);
void clearInputBuffer();
template<typename T>
T getValidatedInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);

// Функция для тестов (может быть в отдельном ifdef)
void runTests();

#endif

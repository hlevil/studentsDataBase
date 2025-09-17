#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "main.cpp" // Подключаем наш основной файл

// Тестовый класс для студенческой базы данных
class StudentDatabaseTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Настройка перед каждым тестом
        testDb.clear();
        Student s1 = {"Ivan", 20, "CS", 4.5};
        Student s2 = {"Maria", 21, "Math", 4.7};
        testDb.push_back(s1);
        testDb.push_back(s2);
    }

    void TearDown() override {
        // Очистка после каждого теста
        testDb.clear();
    }

    std::vector<Student> testDb;
};

// Тест 1: Добавление студента
TEST_F(StudentDatabaseTest, AddStudent) {
    Student newStudent = {"Alex", 22, "Physics", 4.3};
    testDb.push_back(newStudent);
    
    EXPECT_EQ(testDb.size(), 3);
    EXPECT_EQ(testDb[2].name, "Alex");
    EXPECT_EQ(testDb[2].age, 22);
    EXPECT_EQ(testDb[2].major, "Physics");
    EXPECT_DOUBLE_EQ(testDb[2].gpa, 4.3);
}

// Тест 2: Поиск студента по имени
TEST_F(StudentDatabaseTest, FindStudentByName) {
    int index = findStudentByName(testDb, "Ivan");
    EXPECT_EQ(index, 0);
    
    index = findStudentByName(testDb, "Maria");
    EXPECT_EQ(index, 1);
    
    index = findStudentByName(testDb, "NonExistent");
    EXPECT_EQ(index, -1);
}

// Тест 3: Редактирование полей студента
TEST_F(StudentDatabaseTest, EditStudentFields) {
    // Редактирование имени
    testDb[0].name = "Ivanov";
    EXPECT_EQ(testDb[0].name, "Ivanov");
    
    // Редактирование возраста
    testDb[0].age = 25;
    EXPECT_EQ(testDb[0].age, 25);
    
    // Редактирование специальности
    testDb[0].major = "Engineering";
    EXPECT_EQ(testDb[0].major, "Engineering");
    
    // Редактирование GPA
    testDb[0].gpa = 4.9;
    EXPECT_DOUBLE_EQ(testDb[0].gpa, 4.9);
}

// Тест 4: Проверка граничных значений GPA
TEST_F(StudentDatabaseTest, GPABoundaryValues) {
    // Минимальный GPA
    testDb[0].gpa = 0.0;
    EXPECT_DOUBLE_EQ(testDb[0].gpa, 0.0);
    
    // Максимальный GPA
    testDb[0].gpa = 5.0;
    EXPECT_DOUBLE_EQ(testDb[0].gpa, 5.0);
    
    // Нормальное значение
    testDb[0].gpa = 3.75;
    EXPECT_DOUBLE_EQ(testDb[0].gpa, 3.75);
}

// Тест 5: Проверка пустой базы данных
TEST_F(StudentDatabaseTest, EmptyDatabase) {
    std::vector<Student> emptyDb;
    EXPECT_TRUE(emptyDb.empty());
    
    int index = findStudentByName(emptyDb, "Any");
    EXPECT_EQ(index, -1);
}

// Тест 6: Проверка корректности данных после редактирования
TEST_F(StudentDatabaseTest, DataIntegrityAfterEdit) {
    Student& student = testDb[0];
    
    // Сохраняем оригинальные значения
    std::string originalName = student.name;
    int originalAge = student.age;
    
    // Меняем данные
    student.name = "Petr";
    student.age = 22;
    
    // Проверяем, что данные изменились корректно
    EXPECT_NE(student.name, originalName);
    EXPECT_NE(student.age, originalAge);
    EXPECT_EQ(student.name, "Petr");
    EXPECT_EQ(student.age, 22);
    
    // Проверяем, что другие данные не изменились
    EXPECT_EQ(student.major, "CS");
    EXPECT_DOUBLE_EQ(student.gpa, 4.5);
}



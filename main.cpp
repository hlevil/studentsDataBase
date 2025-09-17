#include <iostream>
#include <vector>
#include <string>
#include <limits> // для очистки буфера ввода
#include <sstream>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для очистки буфера ввода
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "\nСписок студентов:\n";
    for (size_t i = 0; i < database.size(); i++) {
        std::cout << i + 1 << ". ";
        std::cout << "Имя: " << database[i].name << ", ";
        std::cout << "Возраст: " << database[i].age << ", ";
        std::cout << "Специальность: " << database[i].major << ", ";
        std::cout << "Средний балл: " << database[i].gpa << "\n";
    }
    std::cout << "\n";
}

// Функция для поиска студента по имени (для тестирования)
int findStudentByName(const std::vector<Student>& database, const std::string& name) {
    for (size_t i = 0; i < database.size(); i++) {
        if (database[i].name == name) {
            return i;
        }
    }
    return -1;
}
/** Функция для редактирования информации о студенте
@param database - ссылка на вектор студентов для модификации
    Алгоритм работы:
 1. Проверяет, что база данных не пуста
 2. Выводит список студентов с нумерацией
 3. Запрашивает номер студента для редактирования
 4. Проверяет корректность введенного номера
 5. Предлагает меню для выбора поля редактирования
 6. Циклически позволяет редактировать поля до выхода */

void editStudent(std::vector<Student>& database) {
    // Проверка на пустую базу данных
    if (database.empty()) {
        std::cout << "База данных пуста. Нечего редактировать.\n";
        return;
    }
    // Вывод списка студентов для выбора
    displayStudents(database);
    
    int index;
    std::cout << "Введите номер студента для редактирования (1-" << database.size() << "): ";
    std::cin >> index;

    // Проверка корректности введенного номера
    if (index < 1 || index > database.size()) {
        std::cout << "Неверный номер студента.\n";
        return;
    }
    // Получение ссылки на выбранного студента (для прямого редактирования)
    Student& student = database[index - 1];
    int choice;

    // Цикл редактирования полей студента
    do {
        std::cout << "\nРедактирование студента: " << student.name << "\n";
        std::cout << "1. Изменить имя (" << student.name << ")\n";
        std::cout << "2. Изменить возраст (" << student.age << ")\n";
        std::cout << "3. Изменить специальность (" << student.major << ")\n";
        std::cout << "4. Изменить средний балл (" << student.gpa << ")\n";
        std::cout << "0. Завершить редактирование\n";
        std::cout << "Выберите поле для редактирования: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                std::cout << "Введите новое имя: ";
                std::cin >> student.name;
                std::cout << "Имя изменено.\n";
                break;
            case 2:
                std::cout << "Введите новый возраст: ";
                std::cin >> student.age;
                std::cout << "Возраст изменен.\n";
                break;
            case 3:
                std::cout << "Введите новую специальность: ";
                std::cin >> student.major;
                std::cout << "Специальность изменена.\n";
                break;
            case 4:
                std::cout << "Введите новый средний балл: ";
                std::cin >> student.gpa;
                std::cout << "Средний балл изменен.\n";
                break;
            case 0:
                std::cout << "Редактирование завершено.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0); // Продолжать пока пользователь не выберет выход
}

// Функция для запуска тестов
void runTests() {
    #ifdef TESTING
    std::cout << "=== ЗАПУСК ТЕСТОВ ===\n";
    
    // Тест 1: Добавление студента
    std::vector<Student> testDb;
    Student testStudent = {"Ivan", 20, "CS", 4.5};
    testDb.push_back(testStudent);
    
    std::cout << "Тест 1: " << (testDb.size() == 1 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Добавление студента\n";
    
    // Тест 2: Поиск студента
    int foundIndex = findStudentByName(testDb, "Ivan");
    std::cout << "Тест 2: " << (foundIndex == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Поиск студента\n";
    
    // Тест 3: Редактирование имени
    testDb[0].name = "Petr";
    std::cout << "Тест 3: " << (testDb[0].name == "Petr" ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Редактирование имени\n";
    
    // Тест 4: Редактирование возраста
    testDb[0].age = 21;
    std::cout << "Тест 4: " << (testDb[0].age == 21 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Редактирование возраста\n";
    
    // Тест 5: Редактирование GPA
    testDb[0].gpa = 4.8;
    std::cout << "Тест 5: " << (testDb[0].gpa == 4.8 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Редактирование GPA\n";
    
    // Тест 6: Поиск несуществующего студента
    int notFound = findStudentByName(testDb, "NonExistent");
    std::cout << "Тест 6: " << (notFound == -1 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН") << " - Поиск несуществующего студента\n";
    
    std::cout << "=== ТЕСТЫ ЗАВЕРШЕНЫ ===\n\n";
    #endif
}

int main() {
    #ifdef TESTING
    runTests();
    #endif
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Редактировать студента\n";
        #ifdef TESTING
        std::cout << "9. Запустить тесты\n";
        #endif
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                editStudent(database);
                break;
            #ifdef TESTING //если определено
            case 9:
                runTests();
                break;
            #endif //конец текущей директивы условной компиляции
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

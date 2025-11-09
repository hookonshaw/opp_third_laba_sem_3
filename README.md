# opp_third_laba_sem_3

# OOP_SECOND_LABA

# Условие
    ФИГУРЫ: КВАДРАТ, ПРЯМОУГОЛЬНИК, ТРАПЕЦИЯ
# Структура проекта
- `src/` - исходный код основной программы
- `tests/` - unit-тесты с использованием Google Test
- `include/` - заголовочные файлы
- `CMakeLists.txt` - конфигурация CMake

#  Сборка и запуск
```bash
# Создание директории для сборки
mkdir build
cd build

# Конфигурация CMake
cmake ..

# Сборка проекта
make

# Запуск основной программы
./geometry_figures

# Запуск тестов
./run_tests
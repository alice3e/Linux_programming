# Клонирование репозитория unistdx
git clone https://github.com/santoni7/ustd

# Переход в директорию проекта
cd ustd

# Создание директории для сборки
meson build --buildtype=release -Db_lto=true

# Переход в директорию сборки
cd build

# Запуск процесса сборки с флагами компилятора и линковщика
meson compile -march=native -O3 -flto


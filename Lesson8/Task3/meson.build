project('myprogram', 'cpp')

# Исходные файлы
sources = ['main.cc']

# Задаем зависимость от zlib
zlib_dep = dependency('zlib', required: true)

# Объектные файлы
executable('myprogram', sources, dependencies: zlib_dep)


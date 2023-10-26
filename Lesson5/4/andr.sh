#!/bin/bash

# Путь к именованному каналу
fifo_path="/tmp/my_named_pipe"

# Создаем именованный канал, если он не существует
if [ ! -p "$fifo_path" ]; then
    mkfifo "$fifo_path"
fi

# Бесконечный цикл для чтения и вывода сообщений
while true; do
    if read -r line < "$fifo_path"; then
        # Получаем текущую дату и время
        current_date=$(date "+%Y-%m-%d %H:%M:%S")
        
        # Выводим сообщение с датой
        echo "[$current_date] $line"
    fi
done


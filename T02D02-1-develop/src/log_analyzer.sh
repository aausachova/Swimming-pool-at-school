#!/bin/bash
if [ -z "$1" ]; then
    echo "Укажите путь до файла лога в качестве аргумента"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "Файл не существует или недоступен: $1"
    exit 1
fi

total_entries=$(wc -l < "$1")
unique_files=$(awk '{print $4}' "$1" | sort -u | wc -l)
changed_hashes=0
previous_hash=""

while read -r line; do
    file_hash=$(echo "$line" | awk '{print $5}')
    if [ -n "$previous_hash" ] && [ "$previous_hash" != "$file_hash" ]; then
        changed_hashes=$((changed_hashes + 1))
    fi
    previous_hash="$file_hash"
done < "$1"

echo "Rоличество записей: $total_entries"
echo "Количество уникальных файлов: $unique_files"
echo "Количество изменений хешей файлов: $changed_hashes"

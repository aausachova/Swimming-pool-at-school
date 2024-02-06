#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Исп: $0 <путь_к_файлу> <строка_для_замены> <замена>"
    exit 1
fi

file_path="$1"
search_str="$2"
replacement="$3"
log_file="files.log"
full_file_path="$PWD/$file_path"


if [ ! -f "$full_file_path" ]; then
    echo "Файл не существует: $full_file_path"
    exit 1
fi

sed -i '' "s/$search_str/$replacement/g" "$full_file_path"
file_size=`stat $file_path | awk '{print $8}'`
file_date=`date +"%Y-%m-%d %H:%M:%S"`
file_sha=`shasum -a 256 "$full_file_path" | awk '{print $1}'`

hash_algorithm="sha256"

echo "$full_file_path - $file_size - $file_date - $file_sha - $hash_algorithm" >> "$log_file"
echo "Замена. Информация в $log_file"

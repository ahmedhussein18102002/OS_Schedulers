
for file in data/*.c; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

for file in helpers/*.c; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

for file in schedulars/*.c; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

for file in *.c; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

# C - Headers
for file in interfaces/data/*.h; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

for file in interfaces/helpers/*.h; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done

for file in interfaces/schedulars/*.h; do
    echo "File: $file"
    cloc "$file"
    echo "========================="
done
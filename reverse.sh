echo "Enter a string: " 
read string

for ((i=${#string} - 1; i >= 0; i--)) 
    do
        reverse="$reverse${string:$i:1}"
    done

echo "$reverse"

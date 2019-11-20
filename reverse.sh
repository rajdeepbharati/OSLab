printf "Enter a number: "
read n

for ((i = ${#n} - 1; i >= 0; i--)); do
    reverse="$reverse${n:$i:1}"
done

echo "$reverse"

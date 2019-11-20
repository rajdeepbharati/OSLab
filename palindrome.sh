printf "Enter a string: "
read s

sRev=$(echo $s | rev)

if [ "$s" = "$sRev" ]; then
    echo "$s is a palindrome"
else
    echo "$s is not a palindrome"
fi

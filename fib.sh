echo "Enter a number: "
read n
if (($n==0 || $n==1))
then
    echo fib ${n} = $n
else
    prev=0
    curr=1
    echo fib 0 = 0
    echo fib 1 = 1
    for ((i=2; i<=${n}; i++))
        do
            fib=$((prev+curr))
            prev=$curr
            curr=$fib
            echo fib ${i} = $fib
        done
fi

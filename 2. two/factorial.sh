echo Enter a number:
read a
result=1
i=1
while [ $i -le $a ]
do
    result=$(expr $result \* $i)
    i=$(expr $i + 1)
done
echo Factorial of $a is $result
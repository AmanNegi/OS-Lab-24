# compare 3 values to find which is largest

read a;
read b;
read c;

if [ $a -gt $b -a $a -gt $c ]; then
	echo A is the greatest;
elif [ $b -gt $c -a $b -gt $c ]; then
	echo B is the greatest;
else
	echo C is the greatest;
fi

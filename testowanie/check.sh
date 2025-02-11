#!/bin/bash
R='\033[0;31m'
G='\033[0;32m'
N='\033[0;m'
Y='\033[0;33m'

for((i=1;;i++)); do 
	./gen $i > test.in
	./brut < test.in > m.out
	./main < test.in > b.out
	

	if diff -wq b.out m.out > /dev/null 2> /dev/null; then
		printf "[${G}OK${N}] ${i}\r"
	else
		echo -e "[${R}WA${N}] ${i}"
	fi
	
done

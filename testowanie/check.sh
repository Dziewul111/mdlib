#!bin/bash

R='\033[0;31m'
G='\033[0;32m'
N='\033[0;m'

for((i = 0;;i++));do
	./gen > t.in 
  	./brut < t.in > b.out 
	./main < t.in > m.out

	if diff -wq b.out m.out > /dev/null; then
		 echo -e "[${G}OK${N}] ${i}"
	else
		 echo -e "[${R}WA${N}] ${i}"
		 cat t.in 
		 echo
		 cat b.out
		 echo
		 cat m.out
		 break
	fi
done

#!/bin/bash

g++ -Wall -ansi -c Parella.cc
g++ -Wall -ansi -c Comparsa.cc -I.
g++ -Wall -ansi -c main_activitat.cc -I.
g++ -o main_activitat.exe main_activitat.o ./{Parella.o,Comparsa.o}
echo " - Test file -" > diferencies.sort

for i in 1 2 3 4 5
do
	echo "Executing test $i" >> diferencies.sort
	./main_activitat.exe < jocs_prova/jp$i.ent > jocs_prova/sort$i.sort
	diff jocs_prova/jp$i.sort jocs_prova/sort$i.sort >> diferencies.sort
done

cat diferencies.sort

#!/bin/bash

echo "Teste"

make

for mapa in lib/teste/10_10_10.txt lib/teste/50_50_10.txt lib/teste/100_100_10.txt lib/teste/100_100_20.txt; do

	echo ""
	echo "--------- MAPA $mapa ----------"
	echo ""

	echo "floodit_h1: "
	./lib/aux/floodit_h1 < $mapa 
	echo ""

	echo "floodit_h2: "
	./lib/aux/floodit_h2 < $mapa 
	echo ""

	echo "floodit_h4: "
	./lib/aux/floodit_h4 < $mapa 
	echo ""

	echo "Floodit: "
	./Floodit < $mapa 
	echo ""
done


echo "finish"
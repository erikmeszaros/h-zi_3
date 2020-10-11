#!/bin/sh


touch output.txt

./a.out Units/Unit1.json Units/Unit2.json >> output.txt
./a.out Units/Unit1.json Units/Unit3.json >> output.txt
./a.out Units/Unit2.json Units/Unit1.json >> output.txt
./a.out Units/Unit2.json Units/Unit3.json >> output.txt
./a.out Units/Unit3.json Units/Unit1.json >> output.txt
./a.out Units/Unit3.json Units/Unit2.json >> output.txt

cmp -s output.txt result.txt



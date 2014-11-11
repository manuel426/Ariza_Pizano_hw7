all: string_10.00.dat.pdf

string_10.00.dat.pdf: graph.py string_10.00.dat
	python graph.py string_10.00.dat
string_10.00.dat:string.x
	./string.x 10.00
string.x: string.c
	cc string.c -o string.x -lm

clean:
	rm string_10.00.pdf
	rm string_10.00.dat
	rm string.x

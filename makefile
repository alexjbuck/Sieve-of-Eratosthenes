norm: 
	g++ -o sieve main.cpp

all: norm opt quiet quiet_opt

opt:
	g++ -o sieve_opt main.cpp -O3

quiet:
	g++ -o sieve_quiet main.cpp -DNO_OUTPUT

quiet_opt:
	g++ -o sieve_quiet_opt main.cpp -O3 -DNO_OUTPUT
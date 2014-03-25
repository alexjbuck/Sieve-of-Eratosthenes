#include <bitset>
#include <iostream>

#define nPrimes 50000000

int main() {
	std::bitset<nPrimes> primeArray;

	// Set all to 1 (possibly prime)
	primeArray.set(); 
	// Numbers 0 and 1 are not prime
	primeArray.reset(0);
	primeArray.reset(1);
	
	int primeIndex = 0;
	int multipleIndex;
	std::cout << "Searching for primes..." << std::endl;
	// Iterate through all numbers between 2 and nPrimes
	while(primeIndex<nPrimes) {
		// Advance primeIndex until it finds the next "non-multiple" number
		primeIndex++;
		if(primeArray[primeIndex]) {		
			std::cout << primeIndex << " ";
			// Clear all multiples of primes
			multipleIndex = primeIndex * 2;
			while(multipleIndex<nPrimes) {
				primeArray.reset(multipleIndex);
				multipleIndex += primeIndex;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "Found " << primeArray.count() << " primes between 2 and " << nPrimes << std::endl;
}
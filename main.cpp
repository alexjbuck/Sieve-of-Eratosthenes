#include <bitset>
#include <iostream>
#include <time.h>

#define nArray 50000000

int main() {
	std::bitset<nArray> primeArray; // Only odd numbers since we know all evens are non-prime (Except 2)
	clock_t t1,t2;
	t1 = clock();

	// Set all to 1 (possibly prime)
	primeArray.set();
	primeArray.reset(0); // 1 is not prime.
	// Array looks like
	// 1 3 5 7 9 11 13 15 etc...
	// 0 1 2 3 4 5  6  7
	
	int primeIndex = 0;
	int prime;
	int multipleIndex;
	std::cout << "Searching for primes..." << std::endl;
	// Iterate through all numbers between 2 and nArray
	while(primeIndex<nArray) {
		// Advance primeIndex until it finds the next "non-multiple" number
		primeIndex++;
		if(primeArray[primeIndex]) {
			prime = 2*primeIndex + 1;
#ifndef NO_OUTPUT
			std::cout << prime << " ";
#endif
			// Clear all multiples of primes
			multipleIndex = primeIndex + prime ;
			while(multipleIndex<nArray) {
				primeArray.reset(multipleIndex);
				multipleIndex += prime;
			}
		}
	}
	std::cout << std::endl;
	t2 = clock();
	int primesFound = primeArray.count() + 1; // +1 for 2 being prime
	std::cout << "Found " << primesFound << " primes between 2 and " << 2*nArray+1 << std::endl;
	std::cout << "Total elapsed time: " << ((float)(t2-t1))/CLOCKS_PER_SEC << " Average " << ( ((float)(t2-t1)/CLOCKS_PER_SEC)/primesFound) << " seconds per prime." << std::endl;
}
#include <stdio.h>
#include <math.h>

long nprime(long n);
long isprime(long n);
void primesupto(long n);
long nprimesunder(long n);
long gcd(long x, long y);
long gcd2(long x, long y);
long phi(long x);

int main() {
    long x, y;
    //printf("Input: ");
    scanf("%d", &x);
    //scanf("%d", &y);
    printf("%d\n", phi(x));
    printf("%d in main\n", gcd2(90, 75));
    
    long p = 863;
    long q = 1223;
    //long n = p * q;
    
    return 0;
}

//return nth prime
long nprime(long n) {
    long primes[n];
    long prime_pointer = 0;
    
    long prime = 2;
    //loop for each prime
    while(prime_pointer < n) {
        long j;
        char prime_flag = 1;
        //break if verified to be composite
        for(j = 0; j < prime_pointer; ++j) {
            //composite check
            if(prime % primes[j] == 0) {
                ++prime;
                prime_flag = 0;
                break;
            }
        }
        if(prime_flag == 1) {
            primes[prime_pointer] = prime;
            ++prime_pointer;
        }
    }
    return primes[n - 1];
}

//returns 1 if n is prime, 0 if n is composite
long isprime(long n) {
    long primes[n];
    long prime_pointer = 0;
    
    long prime = 2;
    //loop for each prime
    while(prime_pointer < n) {
        long j;
        char prime_flag = 1;
        //break if verified to be composite
        for(j = 0; j < prime_pointer; ++j) {
            //composite check
            if(prime % primes[j] == 0) {
                ++prime;
                prime_flag = 0;
                break;
            }
        }
        if(prime_flag == 1) {
            primes[prime_pointer] = prime;
            ++prime_pointer;
        }
    }
    return primes[n - 1];
}

//prints a list of all primes up to and including n
void primesupto(long n) {
    long primes[n];
    long prime_pointer = 0;
    
    long prime = 2;
    //loop for each prime
    while(prime_pointer < n) {
        long j;
        char prime_flag = 1;
        //break if verified to be composite
        for(j = 0; j < prime_pointer; ++j) {
            //composite check
            if(prime % primes[j] == 0) {
                ++prime;
                prime_flag = 0;
                break;
            }
        }
        if(prime_flag == 1) {
            printf("%d\n", prime);
            primes[prime_pointer] = prime;
            ++prime_pointer;
        }
    }
}

//returns the approximate number of primes less than n (prime number theorem)
long nprimesunder(long n) {
    return n / log(n);
}

long gcd(long x, long y) {
    long rk, rk1, rk2;
    
    if(x > y) {
        rk2 = x;
        rk1 = y;
    }
    else {
        rk2 = y;
        rk1 = x;
    }
    
    while(rk > 0) {
        int q;
        for(q = 1; (rk2 - (rk1 * q)) > rk1; ++q)
            ;
        q = rk2 - (rk1 * q);
        rk2 = rk1;
        rk1 = q;
        rk = rk2 - rk1;
    }
    return rk1;
}

long gcd2(long x, long y) {
    if(y)
        return gcd2(y, x % y);
    else
        return x < 0 ? -x : x;
}

long phi(long x) {
    long totatives = 0;
    long i;
    printf("%d in phi\n", gcd(90, 75));
    for(i = 1; i <= x; ++i) {
        printf("%d %d -> %d\n", i, x, gcd2(i, x));
        if(gcd2(i, x) == 1) {
            //printf("%d, %d\n", i, x);
            ++totatives;
        }
    }
    return totatives;
}
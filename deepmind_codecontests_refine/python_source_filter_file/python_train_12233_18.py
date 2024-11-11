from sys import exit
from math import sqrt, floor, ceil

MAX_PRIME = int(sqrt(1e12))

n = int(input())
out = 1

sieve_last, sieve_b = 1, [True] * (MAX_PRIME + 1)
i = 2
while i <= int(sqrt(MAX_PRIME)):
    #print("!!!", i)
    k = sieve_last
    while k < min(i ** 2, MAX_PRIME):
        if sieve_b[k] and sieve_last != k:
            sieve_last = k
            if n % k == 0:
                while n % k == 0:
                    n = n // k
                out *= k
            if n == 1:
                print(out)
                exit(0)
            #print(k)

        k += 1
    while k <= MAX_PRIME:
        sieve_b[k] = False
        k += i
        #print(k)
    i += 1
    while sieve_b[i] != True:
        i += 1

print(n * out)
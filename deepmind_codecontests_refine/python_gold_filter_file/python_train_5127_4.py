import math

def f(n):
    assert n >= 2 and n <= 10**6
    
    # we try up to n^0.5, if nothing, then
    # it is prime, return n itself
    for i in range(2, math.floor(n**0.5)+1):
        if n%i == 0: # smallest divisor
            return i 
    return n


t = int(input())
for _ in range(t):
    n,k = [int(i) for i in input().split(' ')]
    if n % 2 == 0:
        print(2*k + n)
    else:
        print(2*(k-1) + n + f(n))
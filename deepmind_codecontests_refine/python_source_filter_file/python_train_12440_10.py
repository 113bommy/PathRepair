from sys import stdin
from math import sqrt
from collections import defaultdict



def prime_factors(n): 
    
    out = defaultdict(lambda : 0)

    while n % 2 == 0: 
        n = n // 2
          
    for i in range(3,int(sqrt(n))+1,2): 
          
        while n % i == 0:
            if i != 3:
                out[i] += 1 
            n = n // i 
              
    if n > 3: 
        out[n] += 1
    
    return out

def solve(n,arr):
    factors = prime_factors(arr[0])
    for i in range(1,n-1):
        if prime_factors(arr[i]) != factors:
            print("No")
            return
    
    print("Yes")

n = int(stdin.readline())
arr = list(set(map(int, stdin.readline().rstrip().split())))

solve(n,arr)

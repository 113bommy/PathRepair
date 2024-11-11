n = int (input())
from functools import lru_cache 
@lru_cache(maxsize=128, typed=False)
def fib (n):
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else: 
        return fib(n-2)+ fib(n-1)
 
l = [fib(x) for x in range (1,n+1)]

f2 = ["O" if x in l else "o" for x in range(1,n+1)  ]
print ("".join(f2))
from sys import *
from math import *
#from collections import Counter 
input = lambda:stdin.readline()

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)


def countPrimes(n):
    sieve = [True] * n
    lst = []
    for i in range(2,n):
        if sieve[i]:
            lst.append(i)
            for j in range(i*i,n,i):
                sieve[j] = False
    return lst 
        


   
lst = countPrimes(10**3+1)

n = int(input())

ans = []
for i in range(len(lst)):
    if lst[i] > n:
        break
    else:
        ind = 0
        val = lst[i] << ind
        while val <= n:
            ans.append(val)
            ind += 1
            val *= lst[i]
print(len(ans))
print(*ans)



    
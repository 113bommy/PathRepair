import math
def sieve(max):
    primes = [True] * max
    primes[0]=False
    primes[1]=False

    n = int (math.sqrt(max))
    i=2
    while  i < n :
        if primes[i]:
            j = i * i
            while j<max :
                primes[j]=False
                j+=i
        i+=1
    return primes

n,m = map(int , input().split())
flag = False
primes  = sieve(51)

if primes[m]:
    i=m-1
    while i>= n:
        if primes[i]:
            if i!= n : break
            if i==n :
                flag = True
                break;
        i-=1

if flag : print('YES')
else : print('NO')



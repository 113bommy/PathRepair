def isPrime(n) : 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True

n,m=map(int,input().split())
primes=[]
for i in range(1,500):
    if(isPrime(i)):
        primes.append(i)

r=primes.index(n)
if(m>= primes[r+1]):
    print('YES')
else:
    print('NO')
def SieveOfEratosthenes(n): 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    num = []
    for p in range(2, n+1): 
        if prime[p]: 
            num.append(p)
    return num

primes = SieveOfEratosthenes(100009)

n = int(input())
ans = [0]*(n+1)
ct = 1

for i in primes:
    if i <= n:
        ans[i] = ct
        ct += 1
    
for i in range(1, n+1):
    if ans[i] == 0:
        for j in range(len(primes)):
            if not i%primes[j]:
                ans[i] = j+1
                break
        
print(*ans[2:])
        
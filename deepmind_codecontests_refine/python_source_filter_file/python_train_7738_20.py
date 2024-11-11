
import math as ma

n, k = map(int, input().split())

#primes = array.array('b', )

primes = [True]*(n+1)
primes[0], primes[1] = [False, False]


for p in range(2, n+1):
    if (primes[p] == True):
        for l in range(p, n+1-p, p):
            primes[p+l]=False
    

prlist = []

for p in range(2, int(n+1/2)):
    if (primes[p] == True):
        prlist.append(p)
 
cnt = 0       
for t in range(0, len(prlist)-1):
    ind = prlist[t] + prlist[t+1] + 1 
    if (ind < n and primes[ind]):
        cnt+=1

if (cnt >= k):
    print("YES")
else:
    print("NO")



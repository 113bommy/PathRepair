from collections import Counter
n = int(input())
primes = [-1 for i in range(n+2)]
spf=[1 for i in range(n+2)]
primes[0] = 0
primes [1] = 0
for i in range(1,n+2):
  if(primes[i] == -1):
    for j in range(i,((n+1)//i) + 1):
      if(primes[i*j] == -1):
        spf[i*j] = i
        primes[i*j] = 0

arr= Counter(spf)
print(len(arr))
for i in range(2,n+2):
  print(spf[i], end = " ")

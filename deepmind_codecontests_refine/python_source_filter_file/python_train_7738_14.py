# C[n+1] = sum(C[i]*C[n-i]) 0 <= i <= n
# C[0] = 1
n, k = [int(p) for p in input().split()]
sieve = [True]*(n+1)
for i in range(2, n+1):
    j = 0
    while i*i + i*j < n+1:
        sieve[i*i + i*j] = False
        j += 1
prime = []
for i in range(2, len(sieve)):
    if sieve[i]:
        prime.append(i)
count = 0
for i in range(1, len(prime)):
    if prime[i] + prime[i-1] + 1 < len(sieve):
        if sieve[prime[i] + prime[i-1] + 1]:
            count += 1
if count == k:
    print('YES')
else:
    print('NO')

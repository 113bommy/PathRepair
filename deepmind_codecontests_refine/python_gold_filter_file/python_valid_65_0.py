# O(n*m*log(m))
import sys
input = sys.stdin.buffer.readline

mod = 998244353

n,m = map(int,input().split())

# sieve
primes = [0]*(m+1)
prime = [1]*(m+1)

for i in range(2,m+1):
    if prime[i]:
        for j in range(2*i,m+1,i):
            prime[j] = 0
            primes[j] += 1

for i in range(2,m+1):
    if prime[i]:
        for j in range(i*i,m+1,i*i):
            primes[j] = -1

ranges = [list(map(int,input().split())) for i in range(n)]
ways_gcd = [0]*(m+1)

for gcd in range(1,m+1):
    converted_ranges = [[(ranges[i][0]+gcd-1)//gcd,ranges[i][1]//gcd] for i in range(n)]
    dp1 = [0]*(m//gcd + 1)
    dp1[0] = 1
    dp2 = [0]*(m//gcd + 1)

    for i in range(n):
        if converted_ranges[i][0] > converted_ranges[i][1]:
            dp1,dp2 = dp2,dp1
            break

        l,r = converted_ranges[i]
        for j in range(len(dp2)-l):
            dp2[j+l] = (dp2[j+l] + dp1[j]) % mod
            if j+r+1 < len(dp2):
                dp2[j+r+1] = (dp2[j+r+1] - dp1[j] + mod) % mod

        for i in range(1,len(dp2)):
            dp2[i] = (dp2[i] + dp2[i-1]) % mod

        dp1,dp2 = dp2,dp1
        dp2 = [0]*len(dp2)

    ways_gcd[gcd] = sum(dp1) % mod


ans = ways_gcd[1]

for i in range(2,m+1):
    if primes[i] >= 2 or prime[i]:
        if prime[i] or primes[i]&1:
            ans = (ans - ways_gcd[i] + mod) % mod
        else:
            ans = (ans + ways_gcd[i]) % mod

print(ans)
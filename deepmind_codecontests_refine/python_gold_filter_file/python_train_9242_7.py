import math

n,k = list(map(int, input().split(" ")))
nums  = list(map(int, input().split(" ")))
nums.sort()

mod = 10**9 + 7
f = [1]
for i in range(1,10**5+1):
    f.append(f[-1] * i % mod)

def nCr(n,r):
    return f[n] * pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod

minSum = 0
maxSum = 0

for i in range(n-k+1):
    minSum += nums[i] * nCr(n-1-i, k-1)
    maxSum += nums[-i-1] * nCr(n-1-i,k-1)

print((maxSum - minSum + mod) % mod)
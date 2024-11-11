n = int(input())
mod = 10**9 + 7
x = pow(2, n, mod) - 1

res = (6*pow(4, x-1, mod))%mod
print(res)
n = int(input())
a = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))
mult = []
mod = 998244353
for i in range(n):
    mult.append(a[i]*(i+1)*(n-i))
mult = sorted(mult)
b = sorted(b, reverse=True)
res = 0
for i in range(n):
    res = (res + (((mult[i] % mod) * b[i]) % mod) % mod)
print(res)
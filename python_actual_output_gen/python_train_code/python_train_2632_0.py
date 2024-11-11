import sys
n, k = map(int, input().split())

mod = 10 ** 9 + 7
f = [1]
for i in range(1,2*n+1):
    f.append((f[-1] * i) % mod)
def comb(n,r):
    return f[n] * (pow(f[r], mod-2, mod) * pow(f[n-r], mod-2, mod) % mod) % mod

ans = comb(2*n-1, n)
if n-1 <= k:
    print(ans)
    sys.exit()

j = 0
for i in range(k+1,n)[::-1]:
    ans -= (comb(n,n-i) * comb(i+j,j)) % mod
    ans % mod
    j += 1

print(ans)
    
    


import sys
input = sys.stdin.readline

n = int(input())
mod = 998244353
def modinv(n):
    return pow(n, mod-2, mod)
if n == 1:
    print(modinv(2))
    exit()

u = [0]*(n+1)
u[0] = 1
u[1] = 1
u[2] = 1
k = pow(2,n,mod)
acum = [0]*(n+1)
acum[0] = 1
acum[1] = 2
acum[2] = 3

for i in range(3,n+1):
    acum[i] = (acum[i-2]+acum[i-1])%mod
print((acum[-3]*modinv(k))%mod)

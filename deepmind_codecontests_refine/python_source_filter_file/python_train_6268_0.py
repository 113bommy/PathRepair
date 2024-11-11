import sys
mod = 998244353 
chk = [0] * 1000001
numk = [0] * 1000001
n = int(input())
for j in range(n):
    d = [int(i) for i in sys.stdin.readline().split()]
    ddd = d[0]
    f = pow(ddd, mod-2, mod)
    for i in range(1, ddd + 1):
        dd = d[i]
        numk[dd] += 1
        chk[dd] = (chk[dd] + f)%mod
ansn = 0
for i in range(1, 1000001):
    if numk[i]:
        ansn = (ansn + numk[i] * chk[i])%mod
ansn = ansn * pow((n*n)%mod, mod-2, mod)    
print(ansn)
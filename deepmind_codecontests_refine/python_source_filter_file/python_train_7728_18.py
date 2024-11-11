MOD=998244353
n=int(input())
a=[0]
b=[10]
sumb=10

for i in range(n-1):
    a.append((b[-1]*9+a[-1]*10)%MOD)
    b.append(sumb*9%MOD)
    sumb=(sumb+b[-1])%MOD


c=[a[i]+b[i] for i in range(n)]
print(*c[::-1])
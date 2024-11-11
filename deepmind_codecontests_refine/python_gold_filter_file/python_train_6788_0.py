mod = 998244353
n = int(input())
a = [n]
for i in range(n-1,1,-1):
    a.append((i*a[-1])%mod)
if n==1:
    print(1)
else:
    print((a[-1]*n-sum(a))%mod)
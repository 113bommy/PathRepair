MOD = 998244353
n =  int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

for i in range(n):
    a[i]*=((i+1)*(n-i))%MOD
a.sort()
b.sort(reverse=True)
ans = 0
for i in range(n):
    ans = (ans + (a[i]*b[i])%MOD)%MOD

print(ans%MOD)

s = int(input())
a = [0]*2001
a[3] = 1
for i in range(4,s+1):
    a[i] = a[i-3] + a[i-1]
mod = 10**9+7
print(a[s]%mod)
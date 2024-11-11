S=int(input())
a = [0]*(S+1)
a[3]=1
for i in range(4, S+1):
  a[i] = a[i-3] + a[i-1]
mod=10**9+7
print(a[S]%mod)
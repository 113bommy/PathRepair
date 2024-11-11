n,k = map(int,input().split())
l = list(map(int,input().split()))
mod = 10**9+7
a = 0
for i in range(n):
  b = l[i]
  t = (len([1 for m in l if  m<b])%mod)*(int( (k-1)%mod*k/2)%mod)%mod
 # print(i,b,t)
  s = (len([1 for m in l[i:] if m<b])%mod)*k%mod
#  print(s)
  a += (s+t)%mod
print(a%mod)
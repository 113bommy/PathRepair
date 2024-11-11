mod=2019
a=input()

N=len(a)
t=[0]*mod
t[0]=1

w=1
u=0

for i in range(N):
  u=int(a[N-1-i]) * w + u
  v=u % mod
  t[v] += 1
  w *=10
  w %= mod

ans=0
for i in t:
  ans += (i-1)*i//2

print(ans)
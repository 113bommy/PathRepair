n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
ar=[0]*60
for i in a:
  for j in range(60):
    if i&(1<<j):
      ar[j]+=1


for i ,j in enumerate(ar):
  b=n-j
  ans+= j*b*1<<i

print(ans)
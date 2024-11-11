N=int(input())
A=list(map(int,input().split()))

l=[0]*60
for i in A:
  for j in range(60):
    if i&(1<<j):l[j]+=1
ans=0
for i in range(60):
  ans+=l[i]*(N-l[i])*(1<<i)
  ans%=10**9+7
print(ans)
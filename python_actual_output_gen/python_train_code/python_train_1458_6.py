n,ans=int(input()),-10000
a=list(map(int,input().split()))
for i in range(n):
  s=0
  for j in range(i,n):
    s^=a[j]
  ans=max(ans,s)
print(ans)
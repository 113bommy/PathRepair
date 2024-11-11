n=int(input())
A=list(map(int,input().split()))
ans=0
for i in range(1,n):
  d=A[i-1]-A[i]
  if d>0:
    ans += d
    A[i]+=d
print(ans)
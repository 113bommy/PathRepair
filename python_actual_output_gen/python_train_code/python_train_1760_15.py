N=int(input())
A=list(map(int, input().split()))
ans=0
for i in range(N):
  if A[a[i-1]-1]==i+1:
    ans+=1
print(ans//2)
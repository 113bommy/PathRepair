import bisect
n=int(input())
l=sorted(map(int,input().split()))
ans=0
for i in range(n):
  for j in range(i+1,n):
    idx=bisect.bisect_left(l,l[i]+l[j])
    ans=max(0,idx-j-1)
    
print(ans)
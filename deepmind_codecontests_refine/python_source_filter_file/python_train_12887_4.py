import bisect
n=int(input())
l=list(map(int,input().split()))
l.sort()
ans=0
for i in range(n-1,1,-1):
  for j in range(i-1,0,-1):
    ans+=j-bisect.bisect_right(l,l[i]-l[j]+1,hi=j)
print(ans)
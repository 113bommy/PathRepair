A=int(input())
n_l=list(map(int,input().split()))
import collections
ans=0
n_l=collections.Counter(n_l)
for i in range(1,100001):
   ans=max(ans,n_l[i]+n_l[i+1]+n_l[i+2])
print(ans)
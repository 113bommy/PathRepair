n=int(input())
from collections import Counter as co
l=co(map(int,input().split()))
ans=set()
for k in l:
    if l[k]>=2:ans.add(k)
    for j in range(2*k,2*10**5+1,k):
        if j in l:
            ans.add(j)
        
        
print(n-len(ans))
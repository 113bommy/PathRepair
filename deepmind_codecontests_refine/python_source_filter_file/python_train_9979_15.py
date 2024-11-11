n=int(input())
array=[]
for i in range(2,n+1):
    s=i
    while s!=1:
        turn=0
        for j in range(2,s+1):
            if s%j==0:
                s=s//j
                array.append(j)
                break
ans=1
import collections
c=collections.Counter(array)
l=list(c.values())
print(l)
for i in range(len(l)):
    ans*=l[i]+1
print(ans%(10**9+7))
 
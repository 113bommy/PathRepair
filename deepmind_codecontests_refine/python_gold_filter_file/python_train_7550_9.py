n=int(input())
s=list(input())
import collections
q=collections.Counter(s)

    
s=0
for i in q:
    if q[i]>1:
        s+=q[i]-1
if s>26-len(q):
    print(-1)
else:
    print(s)

    

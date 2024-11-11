from collections import*
n,*a=map(int,open(0).read().split())
d=defaultdict(int)
l=[]
for i in a:
    if d[i]==1:l.append(i)
    d[i]+=1
if len(l)>1:
    *_,a,b=sorted(l)
    print(a*b)
else:
    print(0)
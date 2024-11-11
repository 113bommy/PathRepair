from sys import exit
from itertools import accumulate,chain
n,*s=open(0).read().split()
t=[2*i.count("(")-len(i) for i in s]
if sum(t)!=0:
    print("No");exit()
st=[[min(accumulate(s_,lambda a,b: a+(1 if b=="(" else -1),initial=0)),t_] for s_,t_ in zip(s,t)]
now=0
for c in chain(sorted([x for x in st if x[1]>=0])[::-1],sorted([x for x in st if x[1]<0],lambda z:z[1]-z[0])[::-1]):
    if now+c[0]<0:
        print("No");exit()
    now+=c[1]
print("Yes")
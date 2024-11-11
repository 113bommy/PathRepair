from sys import exit
from itertools import accumulate,chain
n,*s=open(0).read().split()
t=map(lambda x:2*x.count("(")-len(x),s)
if sum(t)!=0:
    print("No")
    exit()
#pypyではinitialだめ
st=[[t_,min(accumulate(s_,lambda a,b: a+(1 if b=="(" else -1),initial=0))] for s_,t_ in zip(s,t)]

now=sum(map(lambda x:x[0],filter(lambda x:x[1]>=0,st)))
v=list(filter(lambda x:x[1]<0 and x[0]>=0,st))
w=list(filter(lambda x:x[1]<0 and x[0]<0,st))
v.sort(reverse=True,key=lambda z:z[1])
w.sort(key=lambda z:z[0]-z[1],reverse=True)

for sub in chain(v,w):
    if now+sub[1]<0:
        print("No");exit()
    now+=sub[0]
print("Yes")
import sys
from functools import reduce
n=int(input())
s=[input() for i in range(n)]
t=[2*(i.count("("))-len(i) for i in s]
if sum(t)!=0:
    print("No")
    sys.exit()
st=[[t[i]] for i in range(n)]

for i in range(n):
    now,mi=0,0
    for j in s[i]:
        if j=="(":
            now+=1
        else:
            now-=1
        mi=min(mi,now)
    st[i].append(mi)

now2=sum(map(lambda x:x[0],filter(lambda x:x[1]>=0,st)))
v,w=list(filter(lambda x:x[1]<0 and x[0]>=0,st)),list(filter(lambda x:x[1]<0 and x[0]<0,st))
v.sort(reverse=True,key=lambda z:z[1])
w.sort(key=lambda z:z[0]-z[1],reverse=True)
#print(now2)
for vsub in v:
    if now2+vsub[1]<0:
        print("No")
        sys.exit()
    now2+=vsub[0]
for wsub in w:
    if now2+wsub[1]<0:
        print("No")
        sys.exit()
    now2+=wsub[0]
print("Yes")
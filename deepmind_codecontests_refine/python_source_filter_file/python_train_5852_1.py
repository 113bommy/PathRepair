import sys
input=sys.stdin.readline
from collections import defaultdict as dd
n,m=map(int,input().split())
d=dd(int)
for i in range(m):
    u,v,val=map(int,input().split())
    d[u]+=val
    d[v]-=val
p=[]
n=[]
for i in d:
    if(d[i]<0):
        n.append((d[i],i))
    elif(d[i]>0):
        p.append((d[i],i))
n.sort()
p.sort(reverse=True)
i=0
j=0
res=[]
#print(d,n,p)
while i<len(n) and j<len(p):
    a,b=n[i][1],p[j][1]
    aa,bb=d[a],d[b]
    aa=-aa
    if(aa<bb):
        res.append((b,a,aa))
        d[b]-=aa
        i+=1
    elif(aa>bb):
        res.append((b,a,bb))
        d[a]-=bb
        j+=1
    else:
        res.append((b,a,aa))
        i+=1
        j+=1
print(len(res))
for i in res:
    print(*i)
        
                   
        
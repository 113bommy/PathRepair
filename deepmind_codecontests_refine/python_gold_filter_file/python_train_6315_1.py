import sys
from collections import Counter
from queue import PriorityQueue
read=lambda:map(int,sys.stdin.buffer.readline().split())
n,m=read()
v=[tuple(read())+tuple([i+1]) for i in range(m)]
v.sort(key=lambda x:(x[1],x[0],x[2]))
s=Counter()
for x in v: s[x[1]]+=1
pre=0
q=PriorityQueue()
ans=True
res={}
for t in v:
    if t[1] in s and s[t[1]]>1: ans=False;break
    res[t[1]]=m+1
    for i in range(pre+1,t[1]):
        if i not in s: q.put(i)
    pre=t[1]
    q1=[]
    tmp=t[2]
    while not q.empty():
        x=q.get()
        if x in res: continue
        if x<t[0]: q1.append(x)
        else: tmp-=1;res[x]=t[3]
        if tmp==0: break
    for x in q1: q.put(x)
    if tmp: ans=False;break
if not ans: print(-1)
else:
    for i in range(1,n+1):
        if i in res: print(res[i],end=" ")
        else: print(0,end=" ")
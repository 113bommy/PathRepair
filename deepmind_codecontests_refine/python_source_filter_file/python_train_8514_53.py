s=input()
t=input()
from bisect import bisect
points=[[]for i in range(26)]
a=ord("a")
for i,c in enumerate(s):
    points[ord(c)-a].append(i)
for p in points:
    p.append(10**9)

n=len(s)
idx=0
stage=0
for c in t:
    c=ord(c)-a
    p=points[c]
    if len(p)==1:
        stage=0
        idx=-2
        break#あとで帰る
    idx = p[bisect(p,idx)]
    if idx>10**6:
        idx=p[0]
        stage+=1
print(stage*n+idx+1)
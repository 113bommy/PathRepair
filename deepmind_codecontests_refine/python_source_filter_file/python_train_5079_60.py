from bisect import bisect_left as bl
n,d,a=map(int,input().split())
s=sorted([list(map(int,input().split()))for i in range(n)])
c=0
p=[0]
q=[0]
for i in range(n):
    a=bl(q,s[i][0])
    s[i][1]-=p[-1]-p[a-1]
    if s[i][1]>0:
        t=((s[i][1]-1)//a+1)
        c+=t
        p.append(p[-1]+t)
        q.append(s[i][0]+2*d)
print(c)
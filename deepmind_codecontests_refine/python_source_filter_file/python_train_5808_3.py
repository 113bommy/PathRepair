n,a,b,c = map(int, input().split())
s=[input() for i in range(n)]
ans=[]
from collections import defaultdict
d = defaultdict(int)
d["a"]=a
d["b"]=b
d["c"]=c
def add(c1,c2):
    global d
    ans.append(c1)
    d[c1]+=1
    d[c2]-=1

for i in range(n):
    que = s[i]
    nxt="NONE"
    if i!=n-1:
        nxt = s[i+1]

    q1,q2=que

    if d[q1]==d[q2]==0:
        print("No")
        exit()
    if d[q1]==d[q2]==1:
        if q1 in nxt:
            add(q1,q2)
        else:
            add(q2,q1)
    elif d[q1]>=d[q2]:
        add(q2,q1)
    else:
        add(q1,q2)

print("Yes")
for a in ans:
    print(a)
from itertools import combinations
n=int(input())
cb=[]
p=set()
for i in range(n):
    c=list(map(int,input().split()))
    cb.append(c)
    for a in c:
        p.add(a)
if n >= 2:
    t=combinations(range(n),2)
    for a,b in t:
        for t in cb[a]:
            for k in cb[b]:
                p.add(int(str(t)+str(k)))
                p.add(int(str(k)+str(t)))
if n>=3:
    for a in cb[0]:
        for b in cb[1]:
            for c in cb[2]:
                p.add(int(str(a)+str(b)+str(c)))
                p.add(int(str(a)+str(c)+str(b)))
                p.add(int(str(b)+str(a)+str(c)))
                p.add(int(str(b)+str(c)+str(a)))
                p.add(int(str(c)+str(b)+str(a)))
                p.add(int(str(c)+str(a)+str(b)))
k=list(sorted(p))+[-4]
if k[0] == 1 or k[1] == 1:
    for i in range(len(k)-1):
        if k[i]+1 != k[i+1]:
            print(k[i])
            break
else:
    print(0)

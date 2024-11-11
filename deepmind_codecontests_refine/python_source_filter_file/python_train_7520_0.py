import sys
def f():
    return map(int,sys.stdin.readline().split())
n=int(input())
val=[]
bit=[]
for i in range(n):
    v,a,b=f()
    val.append((v,i))
    bit.append(a-b)
val.sort()
go=[set() for _ in range(n)]
for _ in range(n-1):
    a,b=f()
    a-=1
    b-=1
    go[a].add(b)
    go[b].add(a)
if sum(bit)!=0:
    print(-1)
    exit()
q=[0]
while len(q)!=0:
    now=q.pop()
    for x in go[now]:
        go[x].remove(now)
        q.append(x)
ans=0
for v,i in val:
    pos=neg=0
    q=[i]
    while len(q)!=0:
        now=q.pop()
        for x in go[now]:
            if bit[x]>0:
                pos+=bit[x]
            else:
                neg+=bit[x]
            bit[x]=0
            q.append(x)
        go[now]=[]
    if bit[i]>0:
        pos+=bit[i]
    else:
        neg+=bit[i]
    ans+=v*min(pos,-neg)*2
    bit[now]=pos+neg
print(ans)
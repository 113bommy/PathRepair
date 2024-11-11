import sys
input=sys.stdin.readline
n,q=map(int, input().split())
*c,=map(int, input().split())

qu=[list(map(int, input().split())) +[i] for i in range(q)]
qu.sort(key=lambda x:x[1])
bit=[0]*(n+1)

last=[-1]*(n+1)

def add(t,x):
    while t<=n:
        bit[t]+=x
        t += t&(-t)

def query(t):
    res=0
    while t:
        res+=bit[t]
        t-=t&(-t)
    return res

used=1
ans=[0]*q
for l,r,i in qu:
    while used<=r:
        add(used,1)
        if last[c[used-1]]>=0:
            add(last[c[used-1]],-1)
        last[c[used-1]]=used
        used+=1
    ansi=query(r)-query(l-1)
    ans[i]=ansi
for ansi in ans:
    print(ansi)

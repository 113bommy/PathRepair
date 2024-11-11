n,m=map(int,input().split())
t=[]
for i in range(m):
    a,b=map(int,input().split())
    c=list(map(int,input().split()))
    d=0
    for i in c:
        d+=2**(i-1)
    t.append([a,d])
e=[float("INF")]*(2**n)
e[0]=0
for i,j in t:
    for h in range(2**n):
        e[h|j]=min(i+e[h],e[h|j])
print(e[-1] if e[-1]!=float("INF") else -1)

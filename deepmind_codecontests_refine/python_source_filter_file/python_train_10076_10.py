N=int(input())
P=list(map(int,input().split()))
m=10**5
a=0
for p in P:
    if p<=m:
        a+=1
    m=min(m,p)
print(a)
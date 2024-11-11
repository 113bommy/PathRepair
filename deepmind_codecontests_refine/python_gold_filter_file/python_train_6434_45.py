n,m=map(int,input().split())
L=1
R=n
for _ in range(m):
    l,r=map(int,input().split())
    if l>L:
        L=l
    if r<R:
        R=r
print(max(0,R-L+1))
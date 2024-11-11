n,m=map(int,input().split())
L=0
R=n
for i in range(m):
    l,r=map(int,input().split())
    if l>L:
        L=l
    if r<R:
        R=r
print(R-L+1)
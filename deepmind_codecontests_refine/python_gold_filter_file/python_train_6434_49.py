N,M=map(int,input().split())
L=0
R=N
for i in range(M):
    l,r=map(int,input().split())
    if L<l:
        L=l
    if r<R:
        R=r

print(max(0,R-L+1))
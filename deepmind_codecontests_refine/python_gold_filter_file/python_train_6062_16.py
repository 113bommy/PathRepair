col=int(input())
for _ in range(col):
    n,m=input().split();n=int(n);m=int(m)
    L=list(map(int,input().split()))
    if sum(L)>m:print(m)
    else:print(sum(L))
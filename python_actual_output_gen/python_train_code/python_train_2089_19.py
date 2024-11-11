col=int(input())
for _ in range(col):
    n,m=input().split();n=int(n);m=int(m)
    L=list(map(int,input().split()))
    if m-sum(L)<=0:print(m)
    else:print(m-sum(L))
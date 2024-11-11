n,d = list(map(int,input().split()))

s=list(map(int,input().split()))

if sum(s)+(10*(n-1))>d:
    print(-1)
else:
    d-=(sum(s))
    
    print(d//5)

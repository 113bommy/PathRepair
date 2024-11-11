n,d = list(map(int,input().split()))

s=list(map(int,input().split()))

if sum(s)+(10*len(s)-1)>d:
    print(-1)
else:
    d-=(sum(s))
    
    print(d//5)

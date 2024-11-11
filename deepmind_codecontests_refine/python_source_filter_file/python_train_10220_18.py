t= int(input())
for i in range(t):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    l.sort()
    if max(l)-min(l)>=2*k :
        print(min(l)+k)
    else:
        print(-1)

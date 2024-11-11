t=int(input())
for i in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    s=sum(l)
    m=max(l)
    s-=m
    print(m + s/(len(l)-1))
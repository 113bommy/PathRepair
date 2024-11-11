n=int(input())
a=list(map(int,input().split()))
a=sorted(a)
if(a.count(a[0])==2*n):
    print(-1)
else:
    print(*a)

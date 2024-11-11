n=int(input())
a=list(map(int,input().split()))
a.sort()
if(len(set(a))==1):
    print(-1)
else:
    print(*a)
n=int(input())
li=list(map(int,input().split()))
if len(set(li))==1:
    print(-1)
else:
    print(*sorted(li))
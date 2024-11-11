a,b=map(int,input().split())
if b<=(a//2):
    l=[i for i in range(2,(a-b)+1)]+[1]+[i for i in range((a-b)+1,a+1)]
    print(*l)
else:
    print(-1)
import math
t=int(input())
for _ in range(t):
    a,b=map(int, input().split())
    l=list(map(int, input().split()))
    ind=math.ceil(a/2)
    x=0
    ans=0
    for i in range(1, b+1):
        x=x+1
        w=l[-(ind+(math.ceil(a/2)-math.floor(a/2)))*x]
        ans=ans+w
    print(ans)
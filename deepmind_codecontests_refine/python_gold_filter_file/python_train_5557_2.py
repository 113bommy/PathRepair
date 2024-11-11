from sys import stdin,stdout
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))
for _ in range(1):#nmbr()):
    n=nmbr()
    a=[lst() for _ in range(n)]
    ans=0
    for p,b in a:
        cnt=1
        power=4
        while power<b:
            power*=4
            cnt+=1
        ans=max(cnt+p,ans)
    print(ans)
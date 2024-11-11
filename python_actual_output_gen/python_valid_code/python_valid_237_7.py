t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    ans=1
    for i in range(n):
        if a[i]<=i+1:
            ans+=2;
    print(ans)
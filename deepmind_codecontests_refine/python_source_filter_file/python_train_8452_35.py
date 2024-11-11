for t in range(int(input())):
    n,x,a,b = map(int,input().split())
    diff=abs(a-b)
    ans=diff+x
    if(ans>n):
        ans=n-1
    print(ans)
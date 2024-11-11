t=int(input())
for _ in range(t):
    x,y,n=map(int,input().split())
    l=0
    h=n
    ans=0
    m=0
    diff=n%x
    if(diff==y):
        print(n)
    elif(diff<y):
        n-=diff
        n-=(x-diff)-1
        print(n)
    else:
        diff-=x
        n-=diff
        print(n)
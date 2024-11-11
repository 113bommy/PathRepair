q=int(input())
while(q):
    n,a,b=map(int,input().split())
    if n%2==0:
        if a*n<b*(n//2):
            x=a*n
        else:
            x=b*(n//2)
    else:
        if a*n<(int(n//2)*b)+a:
            x=a*n
        else:
            x=(int(n//2)*b)+a
    print(x)
    q=q-1
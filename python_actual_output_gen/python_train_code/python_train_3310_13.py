t=int(input())
for i in range(t):
    a,b,c,d=map(int,input().split())
    ans=b
    if(a>b):
        if(d>=c):
            ans=-1
        else:
            r=a-b
            s=c-d
            if(r%s==0):
                n=r//s
            else:
                n=r//s+1
                ans=ans+(n*c)
    print(ans)

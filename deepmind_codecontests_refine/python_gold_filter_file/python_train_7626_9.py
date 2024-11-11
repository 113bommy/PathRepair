from sys import stdin, stdout
for _ in range(int(input())):
    p,f=map(int,input().split())
    s,x=map(int,input().split())
    sw,xw=map(int,input().split())

    if f>p:
        p,f=f,p

    if xw<sw:
        sw,xw=xw,sw
        s,x=x,s
    ans=0
    for i in range(s+1):
        temp=0
        f1=f
        p1=p
        s1=s
        x1=x
        if(i*sw<=p1):
            temp+=i
            p1-=i*sw
            s1-=i
        c=min(p1//xw,x1)
        x1-=c
        temp+=c

        c=min(f1//sw, s1)
        f1-=c*sw
        temp+=c
        temp+=min(f1//xw,x1)
        ans=max(ans,temp)
    print(ans)

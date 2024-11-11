t=int(input())
for _ in range(t):
    n,a,b=map(int,input().split())
    s=input()
    if(b>=0):
        ans=n*(a+b)
        print(ans)
    else:
        ans=b
        i=s[0]
        j=i
        n=n*a
        for c in s:
            if(c!=i and j!=c):
                ans+=b
            j=c
        print(n+ans)

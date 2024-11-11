n,h,a,b,k=map(int,input().split())
for i in range(n):
    ta,fa,tb,fb=map(int,input().split())
    if ta==tb:
        print(abs(fa-fb))
    else:
        ans=abs(ta-tb)
        if fa<a:
            ans+=(a-fa)
            fa=a
        else:
            if fa>b:
                ans+=(fa-b)
                fa=b
        if fb<a:
            ans+=(a-fb)
            fb=a
        else:
            if fb>b:
                ans+=(fb-b)
                fb=b
        ans+=abs(fb-fa)
        print(ans)
            

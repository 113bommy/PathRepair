for i in range(int(input())):
    a,b,c=map(int,input().split())
    cir=abs(a-b)*2
    ch=abs(a-b)
    if a>cir or b>cir or c>cir or (ch%2 and max(a,b)>2):
        print(-1)
    else:
        ans=c-ch
        if ans<=0:
            ans+=cir
        print(ans)
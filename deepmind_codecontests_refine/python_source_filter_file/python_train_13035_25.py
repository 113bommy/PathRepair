from bisect import bisect_right as br,bisect_left as bl
for _ in range(int(input())):
    n,s,k=map(int,input().split())
    a=sorted(list(map(int,input().split())))
    ans1=0
    a=set(a)
    i=0
    fl1=0
    while True:
        if s+i in a and s+i<=n:
            ans1+=1
            i+=1
        else:
            if s+i!=n:
                fl1=1
            break
    ans2=0
    i=0
    fl2=0
    while True:
        if s-i in a and s-i>0:
            ans2+=1
            i+=1
        else:
            if s-i>0:
                fl2=1
            break
    if fl1 and fl2:
        print(min(ans1,ans2))
    elif fl1:
        print(ans1)
    else:
        print(ans2)
            
            
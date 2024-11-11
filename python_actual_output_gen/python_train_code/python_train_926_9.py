m,t,r=[int(x) for x in input().split()]
x=[int(x) for x in input().split()]
if t<r:
    print(-1)
else:
    s=[-t-1]
    w=0
    for c in x :
        a=len(s)-1
        k=0
        while s[a]+t-1>=c:
            k+=1
            a-=1
        if k>=r:
            continue
        else:
            for i in range(r-k):
                s.append(c-i-1)
                w+=1
    print(w)
    

t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    s=list(set(l))
    f=0
    res=0
    for i in range(0,100):
        cnt=l.count(i)
        if cnt==0 and f==0:
            res=2*i
            break 
        elif cnt<=1:
            if f==0:
                res+=i
                f=1 
            elif f==1 and cnt==0:
                res+=i
                break
    print(res)
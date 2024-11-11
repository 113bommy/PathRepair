t=int(input())
for _ in range(0,t):
    n,s,k=map(int,input().split())
    a=list(map(int,input().split()))
    if s not in a:
        print(0)
    else:
        p=0
        d=0
        for i in range(s,n+1):
            if i not in a:
                p=i-s
                break
        for i in range(1,s):
            if i not in a:
                d=s-i
                break
        
        if p==0:
            print(d)
        elif d==0:
            print(p)
        else:
            print(min(p,d))
           

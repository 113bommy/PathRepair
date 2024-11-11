t=int(input())
for _ in range(t):
    n,s,k=map(int,input().split())
    l=list(map(int,input().split()))
    for i in range(1000):
        if (s-i)>0:
            c=l.count(s-i)
            if c!=0:
                pass
            else:
                print(i)
                break
        if s+i<=n:
            p=l.count(s+i)
            if p!=0:
                pass
            else:
                print(i)
                break

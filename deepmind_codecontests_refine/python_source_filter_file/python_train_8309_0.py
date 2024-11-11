n,q=map(int,input().split())
if n==1:
    for i in range(q):
        v,w=map(int,input().split())
        print(min(v,w))
else:
    for i in range(q):
        v,w=map(int,input().split())
        while v!=w:
            if v>w:v,w=w,v
            w=(w+n-2)//n
        print(v)
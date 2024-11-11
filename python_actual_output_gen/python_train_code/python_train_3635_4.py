a,b,c,d = map(int,input().split())
h = min(c,d)
res=0
if h>a:
    print(a*256,2222222)
else:
    res=res+h*256
    a-=h
    e = min(a,b)
    res=res+e*32
    print(res)
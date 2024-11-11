n,d=map(int,input().split())
l=list(map(int,input().split()))
s=sum(l)
if n*10<=d:
    res=(d-s)//5
    print(res)
else:
    print(-1)
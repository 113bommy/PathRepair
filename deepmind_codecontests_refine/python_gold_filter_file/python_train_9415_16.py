n,d=map(int,input().split())
l=list(map(int,input().split()))
s=sum(l)
if (n-1)*10+s<=d:
    res=(d-s)//5
    print(res)
else:
    print(-1)
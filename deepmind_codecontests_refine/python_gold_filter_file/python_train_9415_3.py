n,d=map(int,input().split())
a=list(map(int,input().split()))
ss=sum(a)
total=ss+10*(n-1)
if total>d:
    print(-1)
else:
    print((d-ss)//5)












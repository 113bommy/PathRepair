n,m=map(int,input().split())
p1=n
p2=m//2
if p1>p2:
    print(p2)
else:
    delta=p2-p1
    print(delta//2+p1)
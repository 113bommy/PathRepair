N,M,X,Y=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
x2=max(x)
y2=min(y)
if X <= x2 < y2 <= Y:
    print('No War')
else:
    print('War')
n,k=map(int,input().split())
x,y=map(int,input().split())
s=0
for i in range(n-1):
    xx,yy=map(int,input().split())
    s+=(((x-xx)**2+(y-yy)**2)**0.5)/50
    x,y=xx,yy
print(s)
